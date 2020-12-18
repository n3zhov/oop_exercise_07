//
// Created by nikita on 17.12.2020.
//

#pragma once
#include <vector>
#include <stack>
#include <fstream>

#include "factory.hpp"
enum type {
    trapeze = 1,
    rhomb = 2,
    pentagon = 3
};
template<class SCALAR_TYPE>
class Document {
private:
    struct Action;

    using figure_pointer = shared_ptr<Figure<SCALAR_TYPE>>;
    using action_pointer = shared_ptr<Action>;
    using const_iterator = typename vector< figure_pointer >::const_iterator;

    vector< figure_pointer > FiguresList;
    stack< action_pointer > ActionStack;

    struct Action {
        virtual void PerformAction(Document & fact) = 0;
        virtual ~Action() {}
    };

    class DeleteAction : public Action {
    private:
        size_t DeletePos;
    public:
        DeleteAction(const size_t & pos) : DeletePos(pos) {}
        void PerformAction(Document & fact) override {
            fact.Delete(DeletePos);
        }
    };

    class AddAction : public Action {
    private:
        size_t AddPos;
        figure_pointer AddFigure;
    public:
        AddAction(const size_t & pos, const figure_pointer & fig) : AddPos(pos), AddFigure(fig) {}
        void PerformAction(Document & fact) override {
            fact.AddFigure(AddPos, AddFigure);
        }
    };
public:
    void CreateNew() {
        while (!ActionStack.empty()) {
            ActionStack.pop();
        }
        FiguresList.clear();
    }

    void Add(const size_t & pos, const unsigned int & figureID, istream &in) {
        if (figureID == trapeze) {
            AddFigure(pos, Factory<SCALAR_TYPE, Trapeze<SCALAR_TYPE> >::CreateFigure(in));
        }
        else if (figureID == rhomb) {
            AddFigure(pos, Factory<SCALAR_TYPE, Rhomb<SCALAR_TYPE> >::CreateFigure(in));
        }
        else if (figureID == pentagon) {
            AddFigure(pos, Factory<SCALAR_TYPE, Pentagon<SCALAR_TYPE> >::CreateFigure(in));
        }
    }

    void AddFigure(const size_t & pos, const figure_pointer & fig) {
        if (pos > FiguresList.size()) {
            FiguresList.push_back(fig);
            auto delAct = new DeleteAction(FiguresList.size());
            ActionStack.push(action_pointer(delAct));
        }
        else {
            size_t cur = 0;
            const_iterator it = FiguresList.begin();
            while (cur < pos) {
                ++cur;
                ++it;
            }
            FiguresList.insert(it, fig);
            auto delAct = new DeleteAction(pos + 1);
            ActionStack.push(action_pointer(delAct));
        }
    }

    void Delete(const size_t & pos) {
        if (FiguresList.empty()) {
            cout << "Nothing to delete!" << "\n";
            return;
        }
        if (pos > FiguresList.size()) {
            auto addAct = new AddAction(FiguresList.size() - 1, FiguresList.back());
            ActionStack.push(action_pointer(addAct));
            FiguresList.pop_back();
        }
        else {
            size_t cur = 1;
            const_iterator it = FiguresList.begin();
            while (cur < pos) {
                ++cur;
                ++it;
            }
            auto addAct = new AddAction(cur - 1, *it);
            ActionStack.push(action_pointer(addAct));
            FiguresList.erase(it);
            cout << "Figure deleted" << "\n";
        }
    }

    void Undo() {
        if (ActionStack.empty()) {
            cout << "Nothing to undo!" << "\n";
        }
        else {
            ActionStack.top()->PerformAction(*this);
            ActionStack.pop();
            ActionStack.pop();
        }
    }

    template<class U>
    friend ostream & operator << (ostream & os, const Document<U> & fact) {
        if(!fact.FiguresList.size()){
            cout << "Document is empty!" << "\n";
            return os;
        }
        cout << "Printing document:" << "\n";
        for (size_t i = 0; i < fact.FiguresList.size(); ++i) {
            (*fact.FiguresList[i]).Write(os);
        }
        return os;
    }

    template<class U>
    friend ostream & operator << (ofstream & of, const Document<U> & fact) {
        of << fact.FiguresList.size() << "\n";
        for (size_t i = 0; i < fact.FiguresList.size(); ++i) {
            (*fact.FiguresList[i]).Write(of);
        }
        return of;
    }

    template<class U>
    friend istream & operator >> (ifstream &in, Document<U> & fact) {
        fact.CreateNew();
        size_t n;
        in >> n;
        for (size_t i = 0; i < n; ++i) {
            unsigned int type;
            in >> type;
            if (type == trapeze) {
                fact.FiguresList.push_back(Factory< SCALAR_TYPE, Trapeze<SCALAR_TYPE> >::Read(in));
            }
            else if (type == rhomb) {
                fact.FiguresList.push_back(Factory< SCALAR_TYPE, Rhomb<SCALAR_TYPE> >::Read(in));
            }
            else if (type == pentagon) {
                fact.FiguresList.push_back(Factory< SCALAR_TYPE, Pentagon<SCALAR_TYPE> >::Read(in));
            }
        }
        return in;
    }
};
