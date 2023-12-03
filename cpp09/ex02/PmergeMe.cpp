/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:18:43 by rkurnava          #+#    #+#             */
/*   Updated: 2023/12/03 17:50:35 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/// Print functions

void printVectorAfter(std::vector<std::vector<int> > v)
{
    std::cout << "Vector after sorting  : ";
    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = 0; j < v[i].size(); j++)
            std::cout << v[i][j] << " ";
    }
    std::cout << std::endl;
}

void printDequeAfter(std::deque<std::deque<int> > d)
{
    std::cout << "Deque after sorting   : ";
    for (size_t i = 0; i < d.size(); i++)
    {
        for (size_t j = 0; j < d[i].size(); j++)
            std::cout << d[i][j] << " ";
    }
    std::cout << std::endl;
}

void printVectorBefore(std::vector<std::vector<int> > v)
{
    std::cout << "Vector before sorting : ";
    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = 0; j < v[i].size(); j++)
            std::cout << v[i][j] << " ";
    }
    std::cout << std::endl;
}

void printDequeBefore(std::deque<std::deque<int> > d)
{
    std::cout << "Deque before sorting  : ";
    for (size_t i = 0; i < d.size(); i++)
    {
        for (size_t j = 0; j < d[i].size(); j++)
            std::cout << d[i][j] << " ";
    }
    std::cout << std::endl;
}
//////////////////////////////////////////////////////////////////

/// Fill functions

void fillVector(std::vector<std::vector<int> > &v, std::string *input, size_t size)
{
    for (size_t i = 0; i + 1 < size; i += 2)
    {
        std::vector<int> tmp;
        std::istringstream num(input[i]);
        int number;
        num >> number;
        tmp.push_back(number);
        std::istringstream num2(input[i + 1]);
        int number2;
        num2 >> number2;
        tmp.push_back(number2);
        v.push_back(tmp);
    }
    if (size % 2 != 0)
    {
        std::vector<int> tmp;
        std::istringstream num(input[size - 1]);
        int number;
        num >> number;
        tmp.push_back(number);
        v.push_back(tmp);
    }
}

void fillDeque(std::deque<std::deque<int> > &d, std::string *input, size_t size)
{
    for (size_t i = 0; i + 1 < size; i += 2)
    {
        std::deque<int> tmp;
        std::istringstream num(input[i]);
        int number;
        num >> number;
        tmp.push_back(number);
        std::istringstream num2(input[i + 1]);
        int number2;
        num2 >> number2;
        tmp.push_back(number2);
        d.push_back(tmp);
    }
    if (size % 2 != 0)
    {
        std::deque<int> tmp;
        std::istringstream num(input[size - 1]);
        int number;
        num >> number;
        tmp.push_back(number);
        d.push_back(tmp);
    }
}

//////////////////////////////////////////////////////////////////

/// Program logic
void vectorOperations(std::vector<std::vector<int> > &v, std::string *input, size_t size)
{
    fillVector(v, input, size);
    printVectorBefore(v);
/*     mergeSortVector(v);
    binaryInsertionSortV(v); */
    printVectorAfter(v);
}

void dequeOperations(std::deque<std::deque<int> > &d, std::string *input, size_t size)
{
    fillDeque(d, input, size);
    printDequeBefore(d);
/*     mergeSortDeque(d);
    binaryInsertionSortD(d); */
    printDequeAfter(d);
}
//////////////////////////////////////////////////////////////////
