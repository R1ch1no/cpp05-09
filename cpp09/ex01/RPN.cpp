/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:18:34 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/28 16:14:56 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// constructors and destructor

RPN::RPN(RPN const &other)
{
    *this = other;
}

RPN &RPN::operator=(RPN const &other)
{
    if (this != &other)
    {
        this->numbers = other.numbers;
        this->tmp = other.tmp;
    }
    return (*this);
}

RPN::~RPN(void)
{
}

RPN::RPN(std::string &input) : tmp(0)
{
    if (checkInput(input))
        return;
    calculate(input);
}
///////////////////////////////////////////////////////////////

// member functions

int RPN::checkInput(std::string &input)
{
    size_t nums = 0;
    size_t ops = 0;
    // check for invalid characters
    if (std::string::npos != input.find_first_not_of(" 0123456789+-*/"))
        return (std::cerr << "Error : Invalid characters" << std::endl, 1);
    // check if input contains only one char and if it is a digit
    if ((input.length() == 1 && !isdigit(input[0])))
        return (std::cerr << "Error : Invalid input" << std::endl, 1);
    else if (input.length() == 1 && isdigit(input[0]))
        return (std::cout << input << std::endl, 1);
    // calculate number of digits and operators
    for (size_t i = 0; i < input.length(); i++)
    {
        if (isdigit(input[i]))
            nums++;
        if (isdigit(input[i]) && i + 1 < input.length() && isdigit(input[i + 1]))
            return (std::cerr << "Error : Invalid input" << std::endl, 1);
        if (input[i] == '-' || input[i] == '+' || input[i] == '*' || input[i] == '/')
            ops++;
    }
    if (ops + 1 != nums)
        return (std::cerr << "Error : Invalid number of operands" << std::endl, 1);
    // remove all the empty spaces from input
    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
    return (0);
}

void RPN::calculate(std::string &input)
{
    for (size_t i = 0; i < input.length(); i++)
    {
        if (std::isdigit(input[i]))
            numbers.push(input[i] - '0');
        if ((input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') && numbers.size() >= 2)
        {
            tmp = numbers.top();
            numbers.pop();
            if (input[i] == '+')
                tmp += numbers.top();
            else if (input[i] == '-')
                tmp = numbers.top() - tmp;
            else if (input[i] == '*')
                tmp *= numbers.top();
            else if (input[i] == '/' && tmp != 0)
                tmp = numbers.top() / tmp;
            else
                return (std::cerr << "Error : Division by zero" << std::endl, void());
            if (tmp > INT_MAX || tmp < INT_MIN)
                return (std::cerr << "Error : INT Overflow" << std::endl, void());
            numbers.pop();
            numbers.push(tmp);
        }
    }
    if (numbers.size() > 1 )
        return (std::cerr << "Error : Invalid input" << std::endl, void());
    std::cout << tmp << std::endl;
}
