/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:18:34 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/27 19:52:55 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//constructors and destructor

RPN::RPN(RPN const &other)
{
    *this = other;
}

RPN &RPN::operator=(RPN const &other)
{
    if (this != &other)
    {
        this->operands = other.operands;
    }
    return (*this);
}

RPN::~RPN(void)
{
}

RPN::RPN(std::string &input)
{
    if (checkInput(input))
        return;
    calculate(input);
}
///////////////////////////////////////////////////////////////

//member functions

int RPN::checkInput(std::string &input)
{
    size_t nums = 0;
    size_t ops = 0;
    //check for invalid characters
    std::string delimiters = " 0123456789+-*/";
    size_t found = input.find_first_not_of(delimiters);
    if (found != std::string::npos)
    {
        std::cerr << "Error : Invalid input" << std::endl;
        return (1);
    }
    //check if input contains only one char and if it is a digit
    if (input.length() == 1 && !isdigit(input[0]))
    {
        std::cerr << "Error : Invalid input" << std::endl;
        return (1);
    }
    else if (input.length() == 1 && isdigit(input[0]))
    {
        std::cout << input << std::endl;
        return (1);
    }
    //calculate number of digits and operators
    for (size_t i = 0; i < input.length(); i++)
    {
        if (isdigit(input[i]))
        {
            nums++;
            if (i + 1 < input.length() && isdigit(input[i + 1]))
            {
                std::cerr << "Error : Invalid input" << std::endl;
                return (1);
            }
        }
        if (input[i] == '-' || input[i] == '+' || input[i] == '*' || input[i] == '/')
            ops++;
    }
    if (ops + 1 != nums)
    {
        std::cerr << "Error : Invalid input" << std::endl;
        return (1);
    }
    //remove all the empty spaces from input
    int in = 0;
    while (input[in])
    {
        if (input[in] == ' ')
        {
            input.erase(in, 1);
            continue;
        }
        in++;
    }
}

void RPN::calculate(std::string &input)
{
    std::stack<int> operands;
    for (size_t i = 0; i < input.length(); i++)
    {
        if (std::isdigit(input[i]))
        {
            operands.push(input[i] - '0');
            continue;
        }
    }
}
