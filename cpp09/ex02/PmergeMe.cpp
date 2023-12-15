/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:18:43 by rkurnava          #+#    #+#             */
/*   Updated: 2023/12/15 17:58:39 by rkurnava         ###   ########.fr       */
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
    for (size_t i = 0; i < size; i++)
    {
        std::vector<int> tmp;
        std::istringstream num(input[i]);
        int number;
        num >> number;
        tmp.push_back(number);
        v.push_back(tmp);
    }
}

void fillDeque(std::deque<std::deque<int> > &d, std::string *input, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::deque<int> tmp;
        std::istringstream num(input[i]);
        int number;
        num >> number;
        tmp.push_back(number);
        d.push_back(tmp);
    }
}

//////////////////////////////////////////////////////////////////

/// Make pairs functions

void makePairsVector(std::vector<std::vector<int> > &v, size_t size)
{
    std::vector<std::vector<int> > tmpV;
    for (size_t i = 0; i + 1 < size; i += 2)
    {
        std::vector<int> tmp;
        tmp.push_back(v[i][0]);
        tmp.push_back(v[i + 1][0]);
        tmpV.push_back(tmp);
    }
    if (size % 2)
    {
        std::vector<int> tmp;
        tmp.push_back(v[size - 1][0]);
        tmpV.push_back(tmp);
    }
    v.clear();
    v = tmpV;
}

void makePairsDeque(std::deque<std::deque<int> > &d, size_t size)
{
    std::deque<std::deque<int> > tmpD;
    for (size_t i = 0; i + 1 < size; i += 2)
    {
        std::deque<int> tmp;
        tmp.push_back(d[i][0]);
        tmp.push_back(d[i + 1][0]);
        tmpD.push_back(tmp);
    }
    if (size % 2)
    {
        std::deque<int> tmp;
        tmp.push_back(d[size - 1][0]);
        tmpD.push_back(tmp);
    }
    d.clear();
    d = tmpD;
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
    for (size_t i = 0; i + 1 < size; i++)
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
    for (size_t i = 0; i + 1 < v.size(); i++)
    {
        if (v[i][0] > v[i + 1][0])
            return (0);
    }
    return (1);
}

int isSortedDeque(std::deque<std::deque<int> > d)
{
    for (size_t i = 0; i + 1 < d.size(); i++)
    {
        if (d[i][0] > d[i + 1][0])
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
    if (d[size - 1][0] < d[size - 1][1])
    {
        int tmp = d[size - 1][0];
        d[size - 1][0] = d[size - 1][1];
        d[size - 1][1] = tmp;
    }
    sortPairsDeque(d, --size);
}

//////////////////////////////////////////////////////////////////

/// Merge sort functions

void mergeSortVector(std::vector<std::vector<int> > &v, size_t size)
{
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
    if (isDequeChainSorted(d, d.size()))
        return;
    for (size_t i = 0; i + 1 < size; i++)
    {
        if (d[i][0] > d[i + 1][0])
        {
            std::swap(d[i], d[i + 1]);
            mergeSortDeque(d, size);
        }
    }
}

//////////////////////////////////////////////////////////////////

/// Binary search functions

int binarySearchV(std::vector<std::vector<int> > v, int high, int key)
{
    int l = 0;
    int h = high;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (mid == 0)
        {
            if (v[mid][0] < key)
                return (0);
        }
        else if (v[mid][0] > key && v[mid - 1][0] < key)
            return mid;
        if (v[mid][0] < key)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return l;
}

int binarySearchD(std::deque<std::deque<int> > d, int high, int key)
{
    int l = 0;
    int h = high;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (mid == 0)
        {
            if (d[mid][0] < key)
                return (0);
        }
        else if (d[mid][0] > key && d[mid - 1][0] < key)
            return mid;
        if (d[mid][0] < key)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return l;
}

//////////////////////////////////////////////////////////////////

/// Binary Tree functions

void binaryTreeV(std::vector<std::vector<int> > &v, int pos, int pedantSize, int odd, std::vector<int> oddV)
{
    int jacobStahlNumbers[] = {0, 2, 4, 10, 20, 42, 84, 170, 340, 682, 1364, 2730, 5460, 10922, 21844, 43690, 87380, 174762, 349524};
    std::vector<int> tmp;
    tmp.push_back(v[0][1]);
    tmp.push_back(-1);
    v.insert(v.begin(), tmp);
    v[1][1] = -1;
    int JSNpos = 1;
    pos = jacobStahlNumbers[JSNpos];
    if (pos >= (int)v.size() - 1)
        pos = v.size() - 1;
    while ((int)v.size() != pedantSize * 2)
    {
        int i = 0;
        int j = 0;
        while (i < (int)v.size() && j <= pos)
        {
            if (v[i].size() == 2 && v[i][1] != -1)
                j++;
            i++;
        }
        while (j > jacobStahlNumbers[JSNpos - 1] && i > 0)
        {
            if (v[i].size() == 2 && v[i][1] != -1)
            {
                int index = binarySearchV(v, i, v[i][1]);
                std::vector<int> tmp;
                tmp.push_back(v[i][1]);
                v.insert(v.begin() + index, tmp);
                if (index < i)
                    v[i + 1][1] = -1;
                else
                    v[i][1] = -1;
                j--;
            }
            while (i > - 1 && v[i].size() != 2)
                i--;
        }
        JSNpos++;
        if (pos == pedantSize - 1)
            break;
        if (jacobStahlNumbers[JSNpos] > pedantSize)
            pos = pedantSize - 1;
        else
            pos = jacobStahlNumbers[JSNpos];
    }
    if (odd)
    {
        int index = binarySearchV(v, v.size() - 1, oddV[0]);
        v.insert(v.begin() + index, oddV);
    }
}

void binaryTreeD(std::deque<std::deque<int> > &d, int pos, int pedantSize, int odd, std::deque<int> oddD)
{
    int jacobStahlNumbers[] = {0, 2, 4, 10, 20, 42, 84, 170, 340, 682, 1364, 2730, 5460, 10922, 21844, 43690, 87380, 174762, 349524};
    std::deque<int> tmp;
    tmp.push_back(d[0][1]);
    tmp.push_back(-1);
    d.insert(d.begin(), tmp);
    d[1][1] = -1;
    int JSNpos = 1;
    pos = jacobStahlNumbers[JSNpos];
    if (pos >= (int)d.size() - 1)
        pos = d.size() - 1;
    while ((int)d.size() != pedantSize * 2)
    {
        int i = 0;
        int j = 0;
        while (i < (int)d.size() && j <= pos)
        {
            if (d[i].size() == 2 && d[i][1] != -1)
                j++;
            i++;
        }
        while (j > jacobStahlNumbers[JSNpos - 1] && i > 0)
        {
            if (d[i].size() == 2 && d[i][1] != -1)
            {
                int index = binarySearchD(d, i, d[i][1]);
                std::deque<int> tmp;
                tmp.push_back(d[i][1]);
                d.insert(d.begin() + index, tmp);
                if (index < i)
                    d[i + 1][1] = -1;
                else
                    d[i][1] = -1;
                j--;
            }
            while (i > - 1 && d[i].size() != 2)
                i--;
        }
        JSNpos++;
        if (pos == pedantSize - 1)
            break;
        if (jacobStahlNumbers[JSNpos] > pedantSize)
            pos = pedantSize - 1;
        else
            pos = jacobStahlNumbers[JSNpos];
    }
    if (odd)
    {
        int index = binarySearchD(d, d.size() - 1, oddD[0]);
        d.insert(d.begin() + index, oddD);
    }
}

//////////////////////////////////////////////////////////////////

/// Program logic
void dequeOperations(std::deque<std::deque<int> > &d, std::string *input, size_t size)
{
    fillDeque(d, input, size);
    printDequeBefore(d);
    int odd = d.size() % 2;
    std::deque<int> oddD;
    if (odd)
    {
        oddD.push_back(d[d.size() - 1][0]);
        d.pop_back();
    }
    if (!isSortedDeque(d))
    {
        makePairsDeque(d, d.size());
        sortPairsDeque(d, d.size());
        mergeSortDeque(d, d.size());
        if (odd)
            binaryTreeD(d, 0, d.size(), 1, oddD);
        else
            binaryTreeD(d, 0, d.size(), 0, oddD);
    }
    printDequeAfter(d);
}

void vectorOperations(std::vector<std::vector<int> > &v, std::string *input, size_t size)
{
    fillVector(v, input, size);
    printVectorBefore(v);
    int odd = v.size() % 2;
    std::vector<int> oddV;
    if (odd)
    {
        oddV.push_back(v[v.size() - 1][0]);
        v.pop_back();
    }
    if (!isSortedVector(v))
    {
        makePairsVector(v, v.size());
        sortPairsVector(v, v.size());
        mergeSortVector(v, v.size());
        if (odd)
            binaryTreeV(v, 0, v.size(), 1, oddV);
        else
            binaryTreeV(v, 0, v.size(), 0, oddV);
    }
    printVectorAfter(v);
}

//////////////////////////////////////////////////////////////////
