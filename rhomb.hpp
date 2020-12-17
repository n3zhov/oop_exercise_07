//
// Created by Nikita on 25.11.2020.
//

#ifndef OOP_EXERCISE_07_Rhomb_HPP
#define OOP_EXERCISE_07_Rhomb_HPP
#include <iostream>
#include "figure.hpp"
template <typename T>
class Rhomb : public Figure{
public:
    Rhomb(){
        points.resize(4);
        points[0] = {0, 0};
        points[1] = {0, 0};
        points[2] = {0, 0};
        points[3] = {0, 0};
    }
    Rhomb(T const& p11, T const& p12, T const& p21, T const& p22, T const& p31, T const& p32, T const& p41,
             T const& p42, T const& p51, T const& p52){
        points.resize(5);
        points[0] = {p11, p12};
        points[1] = {p21, p22};
        points[2] = {p31, p32};
        points[3] = {p41, p42};
    }
};

//Оператор ввода
template<typename T>
std::istream& operator>>(std::istream& is, Rhomb<T>& rb)
{
    while(true)
    {
        try
        {
            std::string str[8];
            double d[8];
            std::cout << "Enter 8 values: p1(x,y), p2(x,y), p3(x,y), p4(x,y)\n";
            for(size_t i = 0; i < 8; ++i) {
                is >> str[i];
            }
            for(size_t i = 0; i < 8; ++i) {
                d[i] = std::stod(str[i]);
            }
            rb.points[0] = { static_cast<T>(d[0]), static_cast<T>(d[1]) };
            rb.points[1] = { static_cast<T>(d[2]), static_cast<T>(d[3]) };
            rb.points[2] = { static_cast<T>(d[4]), static_cast<T>(d[5]) };
            rb.points[3] = { static_cast<T>(d[6]), static_cast<T>(d[7]) };
            vector<double> sides(5);
            sides[0] = distance(rb.points[0], rb.points[1]);
            sides[1] = distance(rb.points[1], rb.points[2]);
            sides[2] = distance(rb.points[2], rb.points[3]);
            sides[3] = distance(rb.points[3], rb.points[4]);
            int ans = count_if(sides.begin(), sides.end(), [sides[0]](double &side) {
                return sides[0] == side;
            });
            if(ans != sides.size()){
                throw std::exception();
            }
            return is;
        }
        catch(const std::exception& e) { std::cerr << e.what() << "\n"; }
    }
}

//Оператор вывода
template<typename T>
std::ostream& operator<<(std::ostream& os, Rhomb<T>& rb)
{
    os << "Rhomb\n";
    os << " " << rb.points[0].first << " " << rb.points[0].second << " ";
    os << " " << rb.points[1].first << " " << rb.points[1].second << " ";
    os << " " << rb.points[2].first << " " << rb.points[2].second << " ";
    os << " " << rb.points[3].first << " " << rb.points[3].second << "\n";
    return os;
}
#endif //OOP_EXERCISE_05_Rhomb_HPP
