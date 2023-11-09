/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:14:46 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/09 11:24:08 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <climits>
#include <sstream>
#include <iomanip>

class ScalarConverter
{
private:
    // variables
    static int char_displayable;
    static int int_overflow;
    static char char_res;
    static int int_res;
    static float float_res;
    static double double_res;

    // constructors and destructor
    ScalarConverter();
    ScalarConverter(ScalarConverter const &other);
    ScalarConverter &operator=(ScalarConverter const &other);
    ~ScalarConverter();

    // private member functions
    // display functions
    static void displayNan();
    static void displayNULL();
    static void displaynull();
    static void displayPosInf();
    static void displayNegInf();
    static void displayRes();
    static void displayFloat();
    static void displayDouble();
    // converting functions
    static void charConvert(std::string input);
    static void intConvert(std::string input);
    static void floatConvert(std::string input);
    static void doubleConvert(std::string input);
    // checking functions
    static int typeCheck(std::string input);
    static int inputCheck(std::string input);
    static void intOverflowCheck(std::string input);
    static int invalidSpecifier(std::string input, int dCount, int fCount);
    static int afterCommaCheck(std::string input, int dotCount, unsigned int dotPos);
    static int beforeCommaCheck(std::string input, int plusCount, int minusCount);

    // public member function
public:
    static void convert(std::string input);
};

#endif
