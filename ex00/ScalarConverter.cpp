#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "this is Destructor" << std::endl;
}

void ScalarConverter::convert(const std:: string &literal)
{
    if(literal == "nan" || literal == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return ;
    }
    else if(literal == "-inf" || literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return ;
    }
    else if(literal == "+inf" || literal == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return ;
    }
    else if(literal == "inf" || literal == "inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
        return ;
    }
    else if(!isdigit(static_cast<unsigned char>(literal[0])) &&  literal.length() == 1)
    {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        int i = static_cast<int>(c);
        std::cout << "int: " << i << std::endl;
        float f = static_cast<float>(c);
        std::cout << "float: " << f << ".0f" << std::endl;
        double d = static_cast<double>(c);
        std::cout << "double: " << d << ".0"<< std::endl;
        return ;
    }
    long long intger;
    std::stringstream parse(literal);
    if(parse >> intger && parse.eof())
    {
        double val = static_cast<double>(intger);
        if(val < 0 || val > 127)
        {
            std::cout << "char: impossible" << std::endl;
        }
        else if(val < 32 || val == 127)
        {
            std::cout << "char: Non displayable" << std::endl;
        }
        else 
        {
            std::cout << "char: '" << static_cast<char>(val) << "'"<< std::endl;
        }
        if(intger >= INT_MIN && intger <= INT_MAX)
        {
            std::cout << "int: " << static_cast<int>(val) << std::endl;
        }
        else 
        {
            std::cout << "int: impossible" << std::endl;
        }
        std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
        std::cout << "double: " << val <<  ".0" << std::endl;
        return ;
    }
    if(!literal.empty() && literal.back() == 'f' && literal.find('.') != std::string::npos)
    {
        float value;
        std::string number = literal.substr(0, literal.size() - 1);
        std::stringstream parse(number);
        if(parse >> value && parse.eof())
        {
            if(value < 0 || value > 127)
            {
                std::cout << "char: impossible" << std::endl;
            }
            else if(value < 32 || value == 127)
            {
                std::cout << "char: Non displayable" << std::endl;
            }
            else
            {
                std::cout << "char: '" << static_cast<char>(value) << "'"<< std::endl;
            }
            if(value >= INT_MIN && value <= INT_MAX)
            {
                std::cout << "int: " << static_cast<int>(value) << std::endl;
            }
            else 
            {
                std::cout << "int: impossible" << std::endl;
            }
            std::cout << "float: " << value;
            if(std::fabs(value - static_cast<int>(value)) < 1e-6)
            {
                std::cout << ".0";
            }
            std::cout << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(value);
            if(std::fabs(value - static_cast<int>(value)) < 1e-6)
            {
                std::cout << ".0";
            }
            std::cout << std::endl;
            return ;
        }
    }
    if(literal.find('.') != std::string::npos)
    {
        double val;
        std::stringstream ss(literal);
        if(ss >> val && ss.eof())
        {
            if(val < 0 || val > 127)
            {
                std::cout << "char: impossible" << std::endl;
            }
            else if(val < 32 || val == 127)
            {
                std::cout << "char: Non displayable" << std::endl;
            }
            else 
            {
                std::cout << "char: '" << static_cast<char>(static_cast<int>(val)) << "'"<< std::endl;
            }
            if(val >= INT_MIN && val <= INT_MAX)
            {
                std::cout << "int: " << static_cast<int>(val) << std::endl;
            }
            else 
            {
                std::cout << "int: impossible" << std::endl;
            }
            if(val >= -FLT_MAX && val <= FLT_MAX)
            {
                std::cout << "float: " << static_cast<float>(val);
                if(std::fabs(val - static_cast<int>(val)) < 1e-6)
                {
                    std::cout << ".0";
                }
                std::cout << "f" << std::endl;
            }
            else 
            {
                std::cout << "float: impossible" << std::endl;
            }
            std::cout << "double: " << val;
            if(std::fabs(val - static_cast<int>(val)) < 1e-6)
            {
                std::cout << ".0";
            }
            std::cout << std::endl;
            return ;
        }
    }
    
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
    return ;
}
