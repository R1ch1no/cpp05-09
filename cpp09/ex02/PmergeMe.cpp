/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:18:43 by rkurnava          #+#    #+#             */
/*   Updated: 2023/12/05 18:44:33 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <unistd.h>
/// Print functions

void printVectorAfter(std::vector<std::vector<int> > v)
{
    std::cout << "Vector after sorting  : ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i][0] << " ";
    std::cout << "\n"
              << std::endl;
}

void printDequeAfter(std::deque<std::deque<int> > d)
{
    std::cout << "Deque after sorting   : ";
    for (size_t i = 0; i < d.size(); i++)
        std::cout << d[i][0] << " ";
    std::cout << "\n"
              << std::endl;
}

void printVectorBefore(std::vector<std::vector<int> > v)
{
    std::cout << "Vector before sorting : ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i][0] << " ";
    std::cout << "\n"
              << std::endl;
}

void printDequeBefore(std::deque<std::deque<int> > d)
{
    std::cout << "Deque before sorting  : ";
    for (size_t i = 0; i < d.size(); i++)
        std::cout << d[i][0] << " ";
    std::cout << "\n"
              << std::endl;
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
    if (size % 2)
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
    if (size % 2)
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

/// Chain sorted check functions

int isVectorChainSorted(std::vector<std::vector<int> > v, size_t size)
{
    if (size % 2)
        size--;
    for (size_t i = 0; i + 1 < size; i++)
    {
        if (v[i][0] > v[i + 1][0])
            return (0);
    }
    return (1);
}

int isDequeChainSorted(std::deque<std::deque<int> > d, size_t size)
{
    if (size % 2)
        size--;
    for (size_t i = 0; i + 1 <= size; i++)
    {
        if (d[i][0] > d[i + 1][0])
            return (0);
    }
    return (1);
}
//////////////////////////////////////////////////////////////////

/// Is whole vector/deque sorted check functions

int isSortedVector(std::vector<std::vector<int> > v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = 0; j + 1 < v[i].size(); j++)
        {
            if (v[i][j] > v[i][j + 1])
                return (0);
        }
        if (i + 1 < v.size())
            if (v[i][v[i].size() - 1] > v[i + 1][0])
                return (0);
    }
    return (1);
}

int isSortedDeque(std::deque<std::deque<int> > d)
{
    for (size_t i = 0; i < d.size(); i++)
    {
        for (size_t j = 0; j + 1 < d[i].size(); j++)
        {
            if (d[i][j] > d[i][j + 1])
                return (0);
        }
        if (i + 1 < d.size())
            if (d[i][d[i].size() - 1] > d[i + 1][0])
                return (0);
    }
    return (1);
}

//////////////////////////////////////////////////////////////////

/// Pairs sort functions

void sortPairsVector(std::vector<std::vector<int> > &v, size_t size)
{
    if (size == 0)
        return;
    if (v[size - 1].size() == 1)
        (sortPairsVector(v, --size));
    if (v[size - 1][0] < v[size - 1][1])
    {
        int tmp = v[size - 1][0];
        v[size - 1][0] = v[size - 1][1];
        v[size - 1][1] = tmp;
    }
    sortPairsVector(v, --size);
}

void sortPairsDeque(std::deque<std::deque<int> > &d, size_t size)
{
    if (size == 0)
        return;
    if (d[size - 1].size() == 1)
        (sortPairsDeque(d, --size));
    if (d[size - 1].size() == 2)
    {
        if (d[size - 1][0] < d[size - 1][1])
            std::swap(d[size - 1][0], d[size - 1][1]);
        (sortPairsDeque(d, --size));
    }
}

//////////////////////////////////////////////////////////////////

/// Merge sort functions

void mergeSortVector(std::vector<std::vector<int> > &v, size_t size)
{
    if (size % 2)
    {
        size--;
        mergeSortVector(v, size);
    }
    if (isVectorChainSorted(v, v.size()))
        return;
    for (size_t i = 0; i + 1 < size; i++)
    {
        if (v[i][0] > v[i + 1][0])
        {
            std::swap(v[i], v[i + 1]);
            mergeSortVector(v, size);
        }
    }
}

void mergeSortDeque(std::deque<std::deque<int> > &d, size_t size)
{
    if (size % 2)
    {
        size--;
        mergeSortDeque(d, size);
    }
    if (isDequeChainSorted(d, d.size()))
        return;
    for (size_t i = 0; i + 1 <= size; i++)
    {
        if (d[i][0] > d[i + 1][0])
            std::swap(d[i], d[i + 1]);
    }
    mergeSortDeque(d, size);
}

//////////////////////////////////////////////////////////////////

/// Binary Tree functions
void binaryTreeV(std::vector<std::vector<int> > &v)
{
    if (v.size() == 1)
        return;
    std::vector<std::vector<int> > tmp;
    for (size_t j = 0; j + 1 < v.size(); j += 2)
    {
        std::vector<int> tmp2;
        if (v[j][0] > v[j + 1][0])
        {
            tmp2.push_back(v[j][0]);
            tmp2.push_back(v[j + 1][0]);
        }
        else
        {
            tmp2.push_back(v[j + 1][0]);
            tmp2.push_back(v[j][0]);
        }
        tmp.push_back(tmp2);
    }
    binaryTreeV(tmp);
}

//////////////////////////////////////////////////////////////////

/// Program logic
void vectorOperations(std::vector<std::vector<int> > &v, std::string *input, size_t size)
{
    fillVector(v, input, size);
    printVectorBefore(v);
    if (!isSortedVector(v))
    {
        sortPairsVector(v, v.size());
        std::cout << "Sorted pairs : " << std::endl;
        printVectorBefore(v);
        mergeSortVector(v, v.size());
        std::cout << "Main chain sorted : " << std::endl;
        printVectorBefore(v);
        std::cout << std::endl;
        if (!isSortedVector(v))
        {
            if (v.size() % 2 == 0)
                binaryTreeV(v);
        }
    }
    printVectorAfter(v);
}

void dequeOperations(std::deque<std::deque<int> > &d, std::string *input, size_t size)
{
    fillDeque(d, input, size);
    printDequeBefore(d);
    if (!isSortedDeque(d))
    {
        sortPairsDeque(d, d.size());
        mergeSortDeque(d, d.size());
        /*         if (!isSortedDeque(d))
                    binaryInsertionSortD(d, d.size(), 0, d.size() / 2); */
    }
    printDequeAfter(d);
}
//////////////////////////////////////////////////////////////////
