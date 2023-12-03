/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:18:38 by rkurnava          #+#    #+#             */
/*   Updated: 2023/12/03 17:47:31 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int inputCheck(std::string str[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (str[i] == "-")
            return (std::cerr << "Error : Negative value" << std::endl, 1);
        if (std::string::npos != str[i].find_first_not_of("0123456789"))
            return (std::cerr << "Error : Invalid character" << std::endl, 1);
        if (i + 1 < size)
        {
            for (size_t j = i + 1; j < size; j++)
                if (str[i] == str[j])
                    return (std::cerr << "Error : Duplicate numbers" << std::endl, 1);
        }
        std::istringstream num(str[i]);
        long number;
        num >> number;
        if (number < std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max())
            return (std::cerr << "Error : Number : " << str[i] << " outside of INT range" << std::endl, 1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    std::vector<std::vector<int> > v;
    std::deque<std::deque<int> > d;
    if (argc <= 2)
    {
        std::cerr << "Invalid amount of arguments" << std::endl;
        return (1);
    }
    std::string *input = new std::string[argc - 1];
    for (size_t i = 1; i < (size_t)argc; i++)
        input[i - 1] = argv[i];
    if (inputCheck(input, argc - 1))
    {
        delete[] input;
        return (1);
    }
    vectorOperations(v, input, argc - 1);
    dequeOperations(d, input, argc - 1);
    delete[] input;
    return (0);
}
