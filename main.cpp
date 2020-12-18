#include "document.hpp"
#include <fstream>
using namespace std;
/*
 * Ежов Н П М80-204Б-19
 * Спроектировать простейший «графический» векторный редактор.
 * Требование к функционалу редактора:
 * - создание нового документа;
 * - импорт документа из файла;
 * - экспорт документа в файл;
 * - создание графического примитива (согласно варианту задания);
 * - удаление графического примитива;
 * - отображение документа на экране (печать перечня графических
 *   объектов и их характеристик в cout);
 * - реализовать операцию undo, отменяющую последнее сделанное
 *   действие. Должно действовать для операций добавления/удаления
 *   фигур.
 * Требования к реализации:
 * - Создание графических примитивов необходимо вынести в
 *   отдельный класс – Factory;
 * - Сделать упор на использовании полиморфизма при работе с
 *   фигурами;
 * - Взаимодействие с пользователем (ввод команд) реализовать в
 *   функции main.
 */

int main() {
    Document<int> doc;
    string s;
    ifstream in;
    ofstream out;
    while (cin >> s) {
        if (s == "n") {
            doc.CreateNew();
            cout << "Created new document" << "\n";
        }
        else if (s == "o") {
            cin >> s;
            in = ifstream(s);
            if (in.bad()) {
                cout << "No such file on directory" << "\n";
            }
            else {
                in >> doc;
                cout << "Loaded document from " << s << "\n";
                in.close();
            }
        }
        else if (s == "s") {
            cin >> s;
            out = ofstream(s);
            out << doc;
            cout << "Saved document to " << s << "\n";
            out.close();

        }
        else if (s == "+") {
            size_t pos;
            unsigned short type;
            cout << "Enter position of figure and type" << "\n";
            cin >> pos >> type;
            ++pos;
            doc.Add(pos, type, cin);
        }
        else if (s == "-") {
            size_t pos;
            cout << "Enter position of figure" << "\n";
            cin >> pos;
            ++pos;
            doc.Delete(pos);
        }
        else if (s == "p") {
            cout << doc;
        }
        else if (s == "u") {
            doc.Undo();
        }
        else if (s == "h") {
            cout << "\'n\' - create new document" << "\n";
            cout << "\'o\' - open document" << "\n";
            cout << "\'s\' - save document" << "\n";
            cout << "\'+\' - add a figure" << "\n";
            cout << "\'-\' - remove a figure" << "\n";
            cout << "\'p\' - print document" << "\n";
            cout << "\'u\' - undo changes" << "\n";
            cout << "\'h\' - show this message" << "\n";
            cout << "Figure types" << "\n";
            cout << "1 - Trapeze" << "\n";
            cout << "2 - Rhomb" << "\n";
            cout << "3 - Pentagon" << "\n";
        } 
        else {
            cout << "Unknown command. Type \'h\' to show help" << "\n";
        }
    }
    return 0;
}