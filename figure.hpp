//
// Created by nikita on 16.12.2020.
//

#ifndef OOP_EXERCISE_07_FIGURE_HPP
#define OOP_EXERCISE_07_FIGURE_HPP
#include<vector>
using namespace std;
template <typename T>
class Figure {
private:
    using vertex_t = std::pair<T,T>;
    vector<vertex_t> points;
public:
    virtual ~Figure() {}
};

template<class T1, class T2>
std::ostream & operator << (std::ostream & out, const std::pair<T1, T2> & p) {
    out << " " << p.first << " " << p.second << " ";
    return out;
}

//Подсчёт расстояния между точками
double distance (std::pair<double, double> first, std::pair<double, double> second){
    double res = sqrt(pow((second.first - first.first),2) + pow((second.second - first.second),2));
    res = round(res*100)/100;
    return res;
}
#endif //OOP_EXERCISE_07_FIGURE_HPP
