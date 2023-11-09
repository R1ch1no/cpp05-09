/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:31:26 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/09 11:28:53 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Constructors and destructor

int ScalarConverter::char_displayable = 0;
int ScalarConverter::int_overflow = 0;
char ScalarConverter::char_res = 0;
int ScalarConverter::int_res = 0;
float ScalarConverter::float_res = 0.0f;
double ScalarConverter::double_res = 0.0;

ScalarConverter::ScalarConverter() { std::cout << "ScalarConverter constructor called" << std::endl; }
ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    *this = other;
}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
    std::cout << "ScalarConverter copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->char_res = other.char_res;
        this->int_res = other.int_res;
        this->float_res = other.float_res;
        this->double_res = other.double_res;
    }
    return (*this);
}
ScalarConverter::~ScalarConverter() { std::cout << "ScalarConverter destructor called" << std::endl; }

////////////////////////////////////////////////////////////////////////////////

// Member functions

// Printing functions
void ScalarConverter::displayNan()
{
    std::cout << "char   : impossible" << std::endl;
    std::cout << "int    : impossible" << std::endl;
    std::cout << "float  : nanf" << std::endl;
    std::cout << "double : nan" << std::endl;
}

void ScalarConverter::displayNULL()
{
    std::cout << "char   : Non displayable" << std::endl;
    std::cout << "int    : 0" << std::endl;
    std::cout << "float  : 0.0f" << std::endl;
    std::cout << "double : 0.0" << std::endl;
}

void ScalarConverter::displaynull()
{
    std::cout << "char   : '\\0'" << std::endl;
    std::cout << "int    : 0" << std::endl;
    std::cout << "float  : 0.0f" << std::endl;
    std::cout << "double : 0.0" << std::endl;
}

void ScalarConverter::displayPosInf()
{
    std::cout << "char   : impossible" << std::endl;
    std::cout << "int    : impossible" << std::endl;
    std::cout << "float  : inff" << std::endl;
    std::cout << "double : inf" << std::endl;
}

void ScalarConverter::displayNegInf()
{
    std::cout << "char   : impossible" << std::endl;
    std::cout << "int    : impossible" << std::endl;
    std::cout << "float  : -inff" << std::endl;
    std::cout << "double : -inf" << std::endl;
}

void ScalarConverter::displayFloat()
{
    std::stringstream fd;
    fd << float_res;
    if (std::fmod(float_res, 1.0) != 0.0 && std::string::npos == fd.str().find("e"))
        std::cout << "float  : " << std::fixed << std::setprecision(4) << float_res << "f" << std::endl;
    else if (std::string::npos != fd.str().find("e"))
        std::cout << "float  : " << float_res << "f" << std::endl;
    else
        std::cout << "float  : " << float_res << ".0f" << std::endl;
}

void ScalarConverter::displayDouble()
{
    std::stringstream fd;
    fd << double_res;
    if (std::string::npos == fd.str().find("e") && std::fmod(double_res, 1.0) != 0.0)
        std::cout << "double : " << std::fixed << std::setprecision(4) << double_res << std::endl;
    else if (std::string::npos != fd.str().find("e"))
        std::cout << std::scientific << "double : " << double_res << std::endl;
    else
        std::cout << "double : " << double_res << ".0" << std::endl;
}

void ScalarConverter::displayRes()
{
    if (char_displayable)
        std::cout << "char   : "
                  << "'" << char_res << "'" << std::endl;
    else if (int_res > 127 || int_res < 0 || int_overflow)
        std::cout << "char   : impossible" << std::endl;
    else
        std::cout << "char   : Non displayable" << std::endl;
    if (int_overflow)
        std::cout << "int    : impossible" << std::endl;
    else
        std::cout << "int    : " << int_res << std::endl;
    displayFloat();
    displayDouble();
}
////////////////////////////////////////////////////////////////////////////////

// Input checking

int ScalarConverter::invalidSpecifier(std::string input, int dCount, int fCount)
{
    if (dCount == 1 && fCount == 1)
        return (1);
    if (dCount == 1)
    {
        if (input[input.length() - 1] != 'd')
            return (1);
    }
    if (fCount == 1)
    {
        if (input[input.length() - 1] != 'f')
            return (1);
    }
    if (dCount == 0 && fCount == 0)
    {
        if (!isdigit(input[input.length() - 1]))
            return (1);
    }
    return (0);
}

int ScalarConverter::afterCommaCheck(std::string input, int dotCount, unsigned int dotPos)
{
    if (dotCount == 0)
        return (0);
    for (unsigned int i = dotPos; i < input.length() - 1; i++)
    {
        if (i == dotPos)
            i++;
        if (!isdigit(input[i]))
            return (1);
    }
    return (0);
}

int ScalarConverter::beforeCommaCheck(std::string input, int minusCount, int plusCount)
{
    if (minusCount >= 1 && plusCount >= 1)
        return (1);
    for (unsigned int i = 0; i < input.length(); i++)
    {
        if (i == 0 && (minusCount == 1 || plusCount == 1) && (input[0] == '-' || input[0] == '+'))
            i++;
        if (input[i] == '.')
            break;
        if (!isdigit(input[i]))
            return (1);
    }
    return (0);
}

int ScalarConverter::inputCheck(std::string input)
{
    int dotCount = 0;
    int dotPos = 0;
    int plusCount = 0;
    int minusCount = 0;
    int fCount = 0;
    int dCount = 0;
    std::string delimiters = "0123456789.-+fd";
    size_t found = input.find_first_not_of(delimiters);
    if (found != std::string::npos)
        return (1);
    for (unsigned int i = 0; i < input.length(); i++)
    {
        if (int(input[i]) == 46)
        {
            if (dotCount == 0)
                dotPos = i;
            dotCount += 1;
        }
        if (int(input[i]) == 43)
            plusCount++;
        if (int(input[i]) == 45)
            minusCount++;
        if (int(input[i]) == 102)
            fCount++;
        if (int(input[i]) == 100)
            dCount++;
        if (dotCount > 1 || plusCount > 1 || minusCount > 1 || fCount > 1 || dCount > 1)
            return (1);
    }
    if (invalidSpecifier(input, dCount, fCount))
        return (1);
    intOverflowCheck(input);
    if (beforeCommaCheck(input, plusCount, minusCount))
        return (1);
    if (afterCommaCheck(input, dotCount, dotPos))
        return (1);
    return (0);
}

void ScalarConverter::intOverflowCheck(std::string input)
{
    unsigned long digitCount = 0;
    for (unsigned long i = 0; i < input.length(); i++)
    {
        if (input[i] == '+' || input[i] == '-')
            i++;
        while (input[i] == '0')
            i++;
        if (input[i] == '.')
            break;
        if (std::isdigit(input[i]))
            digitCount++;
        long overflow = static_cast<long>(std::atol(input.c_str()));
        if (overflow > INT_MAX || overflow < INT_MIN)
            int_overflow = 1;
        if (digitCount > 10 || int_overflow)
        {
            int_overflow = 1;
            break;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////

// Conversion functions
void ScalarConverter::charConvert(std::string input)
{
    if (std::isprint(input[0]))
    {
        char_displayable = 1;
        char_res = static_cast<char>(input[0]);
        int_res = static_cast<int>(char_res);
        float_res = static_cast<float>(char_res);
        double_res = static_cast<double>(char_res);
    }
    else
    {
        char_displayable = 0;
        int_res = static_cast<int>(std::atoi(input.c_str()));
        float_res = static_cast<float>(std::atof(input.c_str()));
        double_res = static_cast<double>(std::atof(input.c_str()));
    }
}

void ScalarConverter::intConvert(std::string input)
{
    intOverflowCheck(input);
    if (!int_overflow)
    {
        int_res = static_cast<int>(std::atoi(input.c_str()));
        if (int_res >= 0 && int_res <= 127 && std::isprint(int_res))
            char_displayable = 1;
        else
            char_displayable = 0;
        char_res = static_cast<char>(int_res);
        float_res = static_cast<float>(int_res);
        double_res = static_cast<double>(int_res);
    }
    else
    {
        char_displayable = 0;
        float_res = static_cast<float>(std::atof(input.c_str()));
        double_res = static_cast<double>(std::atof(input.c_str()));
    }
}

void ScalarConverter::floatConvert(std::string input)
{
    float_res = static_cast<float>(std::atof(input.c_str()));
    intOverflowCheck(input);
    int_res = static_cast<int>(float_res);
    if (!int_overflow && int_res >= 0 && int_res <= 127 && std::isprint(int_res))
        char_displayable = 1;
    else
        char_displayable = 0;
    char_res = static_cast<char>(float_res);
    double_res = static_cast<double>(float_res);
}

void ScalarConverter::doubleConvert(std::string input)
{
    double_res = static_cast<double>(std::atof(input.c_str()));
    intOverflowCheck(input);
    int_res = static_cast<int>(double_res);
    if (!int_overflow && int_res >= 0 && int_res <= 127 && std::isprint(int_res))
        char_displayable = 1;
    else
        char_displayable = 0;
    char_res = static_cast<char>(double_res);
    float_res = static_cast<float>(double_res);
}

////////////////////////////////////////////////////////////////////////////////

int ScalarConverter::typeCheck(std::string input)
{
    if (input.length() == 1 && !std::isdigit(input[0]))
    {
        std::cout << "input was a char" << std::endl;
        charConvert(input);
        return (1);
    }
    if (inputCheck(input))
    {
        std::cerr << "Invalid input" << std::endl;
        return (0);
    }
    if (std::string::npos == input.find(".") && std::string::npos == input.find("d") && std::string::npos == input.find("f"))
    {
        std::cout << "input was an int" << std::endl;
        intConvert(input);
        return (1);
    }
    if ((std::string::npos != input.find("f")) || (std::string::npos != input.find(".") && std::string::npos != input.find("f")))
    {
        std::cout << "input was a float" << std::endl;
        floatConvert(input);
        return (1);
    }
    if ((std::string::npos != input.find("d")) || (std::string::npos != input.find(".") && std::string::npos != input.find("d")) || (std::string::npos != input.find(".") && std::string::npos == input.find("d")))
    {
        std::cout << "input was a double" << std::endl;
        doubleConvert(input);
        return (1);
    }
    return (0);
}

void ScalarConverter::convert(std::string input)
{
    if ((input == "inf" && input.length() == 3) || (input == "+inf" && input.length() == 4) || (input == "inff" && input.length() == 4) || (input == "+inff" && input.length() == 5))
        return (displayPosInf());
    if ((input == "-inf" && input.length() == 4) || (input == "-inff" && input.length() == 5))
        return (displayNegInf());
    if ((input == "nan" && input.length() == 3) || (input == "nanf" && input.length() == 4))
        return (displayNan());
    if (input == "NULL" && input.length() == 4)
        return (displayNULL());
    if (input == "null" && input.length() == 4)
        return (displaynull());
    if (!typeCheck(input))
        return;
    displayRes();
}
