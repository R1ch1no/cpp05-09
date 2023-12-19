/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:18:43 by rkurnava          #+#    #+#             */
/*   Updated: 2023/12/19 19:25:03 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <unistd.h>
/// Print functions

void printVectorAfter(std::vector<int> v)
{
    std::cout << "Vector after sorting  : ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "\n"
              << std::endl;
}

void printVectorBefore(std::vector<std::vector<int> > v)
{
    std::cout << "Vector before sorting : ";
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i][0] << " ";
        if (v[i].size() == 2)
            std::cout << v[i][1] << " ";
    }
    std::cout << "\n"
              << std::endl;
}

void printDequeAfter(std::deque<int> d)
{
    std::cout << "Deque after sorting  : ";
    for (size_t i = 0; i < d.size(); i++)
        std::cout << d[i] << " ";
    std::cout << "\n"
              << std::endl;
}

void printDequeBefore(std::deque<std::deque<int> > d)
{
    std::cout << "Deque before sorting : ";
    for (size_t i = 0; i < d.size(); i++)
    {
        std::cout << d[i][0] << " ";
        if (d[i].size() == 2)
            std::cout << d[i][1] << " ";
    }
    std::cout << "\n"
              << std::endl;
}

//////////////////////////////////////////////////////////////////

/// Fill functions

void fillVector(std::vector<std::vector<int> > &v, std::string *input, size_t size)
{
    for (size_t i = 0; i + 1 < size - size % 2; i += 2)
    {
        std::vector<int> tmp;
        tmp.push_back(atoi(input[i].c_str()));
        tmp.push_back(atoi(input[i + 1].c_str()));
        v.push_back(tmp);
    }
    if (size % 2)
    {
        std::vector<int> tmp;
        tmp.push_back(atoi(input[size - 1].c_str()));
        v.push_back(tmp);
    }
}

void fillDeque(std::deque<std::deque<int> > &d, std::string *input, size_t size)
{
    for (size_t i = 0; i + 1 < size - size % 2; i += 2)
    {
        std::deque<int> tmp;
        tmp.push_back(atoi(input[i].c_str()));
        tmp.push_back(atoi(input[i + 1].c_str()));
        d.push_back(tmp);
    }
    if (size % 2)
    {
        std::deque<int> tmp;
        tmp.push_back(atoi(input[size - 1].c_str()));
        d.push_back(tmp);
    }
}
//////////////////////////////////////////////////////////////////

/// Pairs sort functions

void sortPairsVector(std::vector<std::vector<int> > &v, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (v[i][0] < v[i][1])
            std::swap(v[i][0], v[i][1]);
    }
}

void sortPairsDeque(std::deque<std::deque<int> > &d, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (d[i][0] < d[i][1])
            std::swap(d[i][0], d[i][1]);
    }
}

//////////////////////////////////////////////////////////////////

/// Merge sort functions

void mergeVector(std::vector<std::vector<int> > &left, std::vector<std::vector<int> > &right, std::vector<std::vector<int> > &v)
{
    while (left.size() > 0 && right.size() > 0)
    {
        if (left[0][0] < right[0][0])
        {
            v.push_back(left[0]);
            left.erase(left.begin());
        }
        else
        {
            v.push_back(right[0]);
            right.erase(right.begin());
        }
    }
    while (left.size() > 0)
    {
        v.push_back(left[0]);
        left.erase(left.begin());
    }
    while (right.size() > 0)
    {
        v.push_back(right[0]);
        right.erase(right.begin());
    }
}

void sortChainVector(std::vector<std::vector<int> > &v)
{
    if (v.size() <= 1)
        return;
    std::vector<std::vector<int> > left;
    std::vector<std::vector<int> > right;
    for (size_t i = 0; i < v.size(); i++)
    {
        if (i < v.size() / 2)
            left.push_back(v[i]);
        else
            right.push_back(v[i]);
    }
    sortChainVector(left);
    sortChainVector(right);
    v.clear();
    return (mergeVector(left, right, v));
}

void mergeDeque(std::deque<std::deque<int> > &left, std::deque<std::deque<int> > &right, std::deque<std::deque<int> > &d)
{
    while (left.size() > 0 && right.size() > 0)
    {
        if (left[0][0] < right[0][0])
        {
            d.push_back(left[0]);
            left.erase(left.begin());
        }
        else
        {
            d.push_back(right[0]);
            right.erase(right.begin());
        }
    }
    while (left.size() > 0)
    {
        d.push_back(left[0]);
        left.erase(left.begin());
    }
    while (right.size() > 0)
    {
        d.push_back(right[0]);
        right.erase(right.begin());
    }
}

void sortChainDeque(std::deque<std::deque<int> > &d)
{
    if (d.size() <= 1)
        return;
    std::deque<std::deque<int> > left;
    std::deque<std::deque<int> > right;
    for (size_t i = 0; i < d.size(); i++)
    {
        if (i < d.size() / 2)
            left.push_back(d[i]);
        else
            right.push_back(d[i]);
    }
    sortChainDeque(left);
    sortChainDeque(right);
    d.clear();
    return (mergeDeque(left, right, d));
}

//////////////////////////////////////////////////////////////////

/// Binary search functions

int binarySearchV(std::vector<int> v, int high, int key)
{
    int l = 0;
    int h = high;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (mid > 0 && v[mid] > key && v[mid - 1] < key)
            return mid;
        if (v[mid] < key)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return l;
}

int binarySearchD(std::deque<int> d, int high, int key)
{
    int l = 0;
    int h = high;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (mid > 0 && d[mid] > key && d[mid - 1] < key)
            return mid;
        if (d[mid] < key)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return l;
}

//////////////////////////////////////////////////////////////////

/// Binary Tree functions

void sortingAlgorithmVector(std::vector<int> &mainChain, std::vector<std::vector<int> > &v, int pos, int pedantSize, int odd, std::vector<int> oddV)
{
    int jacobStahlNumbers[19] = {0, 2, 4, 10, 20, 42, 84, 170, 340, 682, 1364, 2730, 5460, 10922, 21844, 43690, 87380, 174762, 349524};
    mainChain.insert(mainChain.begin(), v[0][1]);
    int JSNpos = 1;
    int inserted = 0;
    int finalSize = pedantSize * 2;
    if (odd)
        finalSize++;
    while ((int)mainChain.size() != finalSize)
    {
        if (odd && jacobStahlNumbers[JSNpos] > pedantSize - 1 && !inserted)
        {
            int index = binarySearchV(mainChain, mainChain.size() - 1, oddV[0]);
            mainChain.insert(mainChain.begin() + index, oddV[0]);
            pos = pedantSize - 1;
            inserted = 1;
        }
        else if (jacobStahlNumbers[JSNpos] > pedantSize - 1)
            pos = pedantSize - 1;
        else
            pos = jacobStahlNumbers[JSNpos];
        int i = 0;
        while (i < (int)v.size() && i != pos)
            i++;
        while (i > jacobStahlNumbers[JSNpos - 1])
        {
            int j = 0;
            while (mainChain[j] != v[i][0])
                j++;
            int index = binarySearchV(mainChain, j, v[i][1]);
            mainChain.insert(mainChain.begin() + index, v[i][1]);
            i--;
        }
        JSNpos++;
    }
}

void sortingAlgorithmDeque(std::deque<int> &mainChain, std::deque<std::deque<int> > &d, int pos, int pedantSize, int odd, std::deque<int> oddD)
{
    int jacobStahlNumbers[19] = {0, 2, 4, 10, 20, 42, 84, 170, 340, 682, 1364, 2730, 5460, 10922, 21844, 43690, 87380, 174762, 349524};
    mainChain.insert(mainChain.begin(), d[0][1]);
    int JSNpos = 1;
    int inserted = 0;
    int finalSize = pedantSize * 2;
    if (odd)
        finalSize++;
    while ((int)mainChain.size() != finalSize)
    {
        if (odd && jacobStahlNumbers[JSNpos] > pedantSize - 1 && !inserted)
        {
            int index = binarySearchD(mainChain, mainChain.size() - 1, oddD[0]);
            mainChain.insert(mainChain.begin() + index, oddD[0]);
            pos = pedantSize - 1;
            inserted = 1;
        }
        else if (jacobStahlNumbers[JSNpos] > pedantSize - 1)
            pos = pedantSize - 1;
        else
            pos = jacobStahlNumbers[JSNpos];
        int i = 0;
        while (i < (int)d.size() && i != pos)
            i++;
        while (i > jacobStahlNumbers[JSNpos - 1])
        {
            int j = 0;
            while (mainChain[j] != d[i][0])
                j++;
            int index = binarySearchD(mainChain, j, d[i][1]);
            mainChain.insert(mainChain.begin() + index, d[i][1]);
            i--;
        }
        JSNpos++;
    }
}

//////////////////////////////////////////////////////////////////

/// Program logic
double vectorOperations(std::vector<std::vector<int> > &v, std::string *input, size_t size)
{
    std::cout << std::endl;
    clock_t start = clock();
    fillVector(v, input, size);
    printVectorBefore(v);
    int odd = (int)v[v.size() - 1].size() % 2;
    std::vector<int> mainChainVector;
    std::vector<int> oddV;
    if (odd)
    {
        oddV.push_back(v[v.size() - 1][0]);
        v.pop_back();
    }
    sortPairsVector(v, v.size());
    sortChainVector(v);
    for (size_t i = 0; i < v.size(); i++)
        mainChainVector.push_back(v[i][0]);
    if (odd)
        sortingAlgorithmVector(mainChainVector, v, 0, mainChainVector.size(), 1, oddV);
    else
        sortingAlgorithmVector(mainChainVector, v, 0, mainChainVector.size(), 0, oddV);
    clock_t end = clock();
    printVectorAfter(mainChainVector);
    v.clear();
    mainChainVector.clear();
    return ((double)(end - start) / CLOCKS_PER_SEC);
}

double dequeOperations(std::deque<std::deque<int> > &d, std::string *input, size_t size)
{
    std::cout << std::endl;
    clock_t start = clock();
    fillDeque(d, input, size);
    printDequeBefore(d);
    int odd = (int)d[d.size() - 1].size() % 2;
    std::deque<int> mainChainDeque;
    std::deque<int> oddD;
    if (odd)
    {
        oddD.push_back(d[d.size() - 1][0]);
        d.pop_back();
    }
    sortPairsDeque(d, d.size());
    sortChainDeque(d);
    for (size_t i = 0; i < d.size(); i++)
        mainChainDeque.push_back(d[i][0]);
    if (odd)
        sortingAlgorithmDeque(mainChainDeque, d, 0, mainChainDeque.size(), 1, oddD);
    else
        sortingAlgorithmDeque(mainChainDeque, d, 0, mainChainDeque.size(), 0, oddD);
    clock_t end = clock();
    printDequeAfter(mainChainDeque);
    d.clear();
    mainChainDeque.clear();
    return ((double)(end - start) / CLOCKS_PER_SEC);
}

//////////////////////////////////////////////////////////////////
