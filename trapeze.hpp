//
// Created by Nikita on 25.11.2020.
//

#ifndef OOP_EXERCISE_07_Trapeze_HPP
#define OOP_EXERCISE_07_Trapeze_HPP
#include <iostream>
template <typename T>
class Trapeze : public Figure{
    using vertex_t = std::pair<T,T>;
    vertex_t points[0], points[1], points[2], points[3];
    Trapeze()
    {
        points[0] = {0, 0};
        points[1] = {0, 0};
        points[2] = {0, 0};
        points[3] = {0, 0};
    }
    Trapeze(T const& p11, T const& p12, T const& p21, T const& p22, T const& p31, T const& p32, T const& p41, T const& p42)
    {
        points[0] = {p11, p12};
        points[1] = {p21, p22};
        points[2] = {p31, p32};
        points[3] = {p41, p42};
    }
};

//Оператор ввода
template<typename T>
std::istream& operator>>(std::istream& is, Trapeze<T>& tr)
{
    while(true)
    {
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
            tr.points[0] = { static_cast<T>(d[0]), static_cast<T>(d[1]) };
            tr.points[1] = { static_cast<T>(d[2]), static_cast<T>(d[3]) };
            tr.points[2] = { static_cast<T>(d[4]), static_cast<T>(d[5]) };
            tr.points[3] = { static_cast<T>(d[6]), static_cast<T>(d[7]) };
            double diff_y_0 = static_cast<double>(tr.points[2].second-tr.points[1].second);
            double diff_y_1 = static_cast<double>(tr.points[3].second-tr.points[0].second);
            double diff_x_0 = static_cast<double>(tr.points[2].first-tr.points[1].first);
            double diff_x_1 = static_cast<double>(tr.points[3].first-tr.points[0].first);
            if(diff_y_0/diff_x_0 != diff_y_1/diff_x_1) {
                throw std::exception();
            }
            return is;
        }
        catch(const std::exception& e) { std::cerr << e.what() << "\n"; }
    }
}

//Оператор вывода
template<typename T>
std::ostream& operator<<(std::ostream& os, Trapeze<T>& tr)
{
    os << "Trapeze\n";
    os << " " << tr.points[0].first << " " << tr.points[0].second << " ";
    os << " " << tr.points[1].first << " " << tr.points[1].second << " ";
    os << " " << tr.points[2].first << " " << tr.points[2].second << " ";
    os << " " << tr.points[3].first << " " << tr.points[3].second << "\n";
    return os;
}
#endif //OOP_EXERCISE_07_Trapeze_HPP
