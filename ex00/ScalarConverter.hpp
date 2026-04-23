#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <limits>
#include <iomanip>
#include <cfloat>
class ScalarConverter 
{
    private : 
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();
    public :
    static void convert(const std:: string &literal);
};
#endif