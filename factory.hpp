//
// Created by nikita on 16.12.2020.
//

#ifndef OOP_EXERCISE_07_FACTORY_HPP
#define OOP_EXERCISE_07_FACTORY_HPP
#include <memory>
#incldue "pentagon.hpp"
#include "square.hpp"
#include "trapeze.hpp"

template<class T, class Figure>
class Factory;

template<class T>
class Factory< T, Rhomb<T> > {
public:
static std::shared_ptr<Figure> CreateFigure() {
    try
    {
        std::string str[10];
        double d[10];
        std::cout << "Enter 8 values: p1(x,y), p2(x,y), p3(x,y), p4(x,y), p5(x,y)\n";
        for(size_t i = 0; i < 10; ++i) {
            is >> str[i];
        }
        for(size_t i = 0; i < 10; ++i) {
            d[i] = std::stod(str[i]);
        }
        vector<pair<T, T>> points(5);
        points[0] = { static_cast<T>(d[0]), static_cast<T>(d[1]) };
        points[1] = { static_cast<T>(d[2]), static_cast<T>(d[3]) };
        points[2] = { static_cast<T>(d[4]), static_cast<T>(d[5]) };
        points[3] = { static_cast<T>(d[6]), static_cast<T>(d[7]) };
        vector<double> sides(5);
        sides[0] = distance(points[0], points[1]);
        sides[1] = distance(points[1], points[2]);
        sides[2] = distance(points[2], points[3]);
        sides[3] = distance(points[3], points[4]);
        int ans = count_if(sides.begin(), sides.end(), [sides[0]](double &side) {
            return sides[0] == side;
        });
        if(ans != sides.size()){
            throw std::exception();
        }
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
    Rhomb<T>* sq = new Rhomb<T>(points[0].first, points[0].second, points[1].first, points[1].second,
                                      points[2].first, points[2].second, points[3].first, points[3].second);
    return std::shared_ptr<Figure>(sq);
}

static std::shared_ptr<Figure> Read(istream &fs) {
    try
    {
        std::string str[10];
        double d[10];
        for(size_t i = 0; i < 10; ++i) {
            fs >> str[i];
        }
        for(size_t i = 0; i < 10; ++i) {
            d[i] = std::stod(str[i]);
        }
        vector<pair<T, T>> points(5);
        points[0] = { static_cast<T>(d[0]), static_cast<T>(d[1]) };
        points[1] = { static_cast<T>(d[2]), static_cast<T>(d[3]) };
        points[2] = { static_cast<T>(d[4]), static_cast<T>(d[5]) };
        points[3] = { static_cast<T>(d[6]), static_cast<T>(d[7]) };
        vector<double> sides(5);
        sides[0] = distance(points[0], points[1]);
        sides[1] = distance(points[1], points[2]);
        sides[2] = distance(points[2], points[3]);
        sides[3] = distance(points[3], points[4]);
        int ans = count_if(sides.begin(), sides.end(), [sides[0]](double &side) {
            return sides[0] == side;
        });
        if(ans != sides.size()){
            throw std::exception();
        }
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
    Rhomb<T>* sq = new Rhomb<T>(points[0].first, points[0].second, points[1].first, points[1].second,
                                points[2].first, points[2].second, points[3].first, points[3].second);
    return std::shared_ptr<Figure>(sq);
}
};

template<class T>
class Factory< T, Pentagon<T> > {
public:
static std::shared_ptr<Figure> CreateFigure(std::istream& is) {
    try
    {
        std::string str[10];
        double d[10];
        std::cout << "Enter 8 values: p1(x,y), p2(x,y), p3(x,y), p4(x,y), p5(x,y)\n";
        for(size_t i = 0; i < 10; ++i) {
            is >> str[i];
        }
        for(size_t i = 0; i < 10; ++i) {
            d[i] = std::stod(str[i]);
        }
        vector<pair<T, T>> points(5);
        points[0] = { static_cast<T>(d[0]), static_cast<T>(d[1]) };
        points[1] = { static_cast<T>(d[2]), static_cast<T>(d[3]) };
        points[2] = { static_cast<T>(d[4]), static_cast<T>(d[5]) };
        points[3] = { static_cast<T>(d[6]), static_cast<T>(d[7]) };
        points[4] = { static_cast<T>(d[8]), static_cast<T>(d[9]) };
        vector<double> sides(5);
        sides[0] = distance(points[0], points[1]);
        sides[1] = distance(points[1], points[2]);
        sides[2] = distance(points[2], points[3]);
        sides[3] = distance(points[3], points[4]);
        sides[4] = distance(points[0], points[4]);
        int ans = count_if(sides.begin(), sides.end(), [sides[0]](double &side) {
            return sides[0] == side;
        });
        if(ans != sides.size()){
            throw std::exception();
        }
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
    Pentagon<T>* sq = new Pentagon<T>(points[0].first, points[0].second, points[1].first, points[1].second,
                                      points[2].first, points[2].second, points[3].first, points[3].second,
                                      points[4].first, points[4].second);
    return std::shared_ptr<Figure>(sq);
}

static std::shared_ptr<Figure> Read(istream &fs) {
    try
    {
        std::string str[10];
        double d[10];
        for(size_t i = 0; i < 10; ++i) {
            fs >> str[i];
        }
        for(size_t i = 0; i < 10; ++i) {
            d[i] = std::stod(str[i]);
        }
        vector<pair<T, T>> points(5);
        points[0] = { static_cast<T>(d[0]), static_cast<T>(d[1]) };
        points[1] = { static_cast<T>(d[2]), static_cast<T>(d[3]) };
        points[2] = { static_cast<T>(d[4]), static_cast<T>(d[5]) };
        points[3] = { static_cast<T>(d[6]), static_cast<T>(d[7]) };
        points[4] = { static_cast<T>(d[8]), static_cast<T>(d[9]) };
        vector<double> sides(5);
        sides[0] = distance(points[0], points[1]);
        sides[1] = distance(points[1], points[2]);
        sides[2] = distance(points[2], points[3]);
        sides[3] = distance(points[3], points[4]);
        sides[4] = distance(points[0], points[4]);
        int ans = count_if(sides.begin(), sides.end(), [sides[0]](double &side) {
            return sides[0] == side;
        });
        if(ans != sides.size()){
            throw std::exception();
        }
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
    Pentagon<T>* sq = new Pentagon<T>(points[0].first, points[0].second, points[1].first, points[1].second,
                                      points[2].first, points[2].second, points[3].first, points[3].second,
                                      points[4].first, points[4].second);
    return std::shared_ptr<Figure>(sq);
}
};

template<class T>
class Factory< T, Trapeze<T> > {
public:
static std::shared_ptr<Figure> CreateFigure(std::istream& is) {
    try
    {
        std::string str[8];
        double d[8];
        std::cout << "Enter 8 values: p1(x,y), p2(x,y), p3(x,y), p4(x,y), where p1,p4 - first base, p2,p3 - second base\n";
        for(size_t i = 0; i < 8; ++i) {
            is >> str[i];
        }
        for(size_t i = 0; i < 8; ++i) {
            d[i] = std::stod(str[i]);
        }
        vector <T> points(4);
        points[0] = { static_cast<T>(d[0]), static_cast<T>(d[1]) };
        points[1] = { static_cast<T>(d[2]), static_cast<T>(d[3]) };
        points[2] = { static_cast<T>(d[4]), static_cast<T>(d[5]) };
        points[3] = { static_cast<T>(d[6]), static_cast<T>(d[7]) };
        double diff_y_0 = static_cast<double>(points[2].second-points[1].second);
        double diff_y_1 = static_cast<double>(points[3].second-points[0].second);
        double diff_x_0 = static_cast<double>(points[2].first-points[1].first);
        double diff_x_1 = static_cast<double>(points[3].first-points[0].first);
        if(diff_y_0/diff_x_0 != diff_y_1/diff_x_1) {
            throw std::exception();
        }
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
    Trapeze<T>* sq = new Trapeze<T>(points[0].first, points[0].second, points[1].first, points[1].second,
                                      points[2].first, points[2].second, points[3].first, points[3].second,
                                      points[4].first, points[4].second);
    return std::shared_ptr<Figure>(sq);
}

static std::shared_ptr<Figure> Read(std::istream& fs) {
    try
    {
        std::string str[8];
        double d[8];
        for(size_t i = 0; i < 8; ++i) {
            fs >> str[i];
        }
        for(size_t i = 0; i < 8; ++i) {
            d[i] = std::stod(str[i]);
        }
        vector <T> points(4);
        points[0] = { static_cast<T>(d[0]), static_cast<T>(d[1]) };
        points[1] = { static_cast<T>(d[2]), static_cast<T>(d[3]) };
        points[2] = { static_cast<T>(d[4]), static_cast<T>(d[5]) };
        points[3] = { static_cast<T>(d[6]), static_cast<T>(d[7]) };
        double diff_y_0 = static_cast<double>(points[2].second-points[1].second);
        double diff_y_1 = static_cast<double>(points[3].second-points[0].second);
        double diff_x_0 = static_cast<double>(points[2].first-points[1].first);
        double diff_x_1 = static_cast<double>(points[3].first-points[0].first);
        if(diff_y_0/diff_x_0 != diff_y_1/diff_x_1) {
            throw std::exception();
        }
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
    Trapeze<T>* sq = new Trapeze<T>(points[0].first, points[0].second, points[1].first, points[1].second,
                                    points[2].first, points[2].second, points[3].first, points[3].second,
                                    points[4].first, points[4].second);
    return std::shared_ptr<Figure>(sq);
}
};

#endif //OOP_EXERCISE_07_FACTORY_HPP
