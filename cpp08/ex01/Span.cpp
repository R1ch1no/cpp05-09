/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:06:39 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/21 14:21:29 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>

// Constructors, destructor, operator=, copy constructor

Span::Span(void)
{
    throw invalidObjectInitialisationException();
}

Span::Span(unsigned int const n) : maxSize(n), currentSize(0) {}

Span &Span::operator=(Span const &other)
{
    this->maxSize = other.maxSize;
    this->currentSize = other.currentSize;
    this->ints = other.ints;
    return (*this);
}

Span::Span(Span const &other) { *this = other; }

Span::~Span(void) {}

///////////////////////////////////////////////////////////////

// Member functions

void Span::addNumber(int const n)
{
    if (this->currentSize == this->maxSize)
        throw maxReachedException();
    this->ints.push_back(n);
    this->currentSize++;
}

void Span::addNumber(int const start, int const end)
{
    if (this->currentSize + (end - start) > this->maxSize)
        throw maxReachedException();
    for (long i = start; i <= end; i++)
        addNumber(i);
}

void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    if (this->currentSize + (end - start) > this->maxSize)
        throw maxReachedException();
    for (std::vector<int>::iterator it = start; it != end; it++)
        addNumber(*it);
}

void print(int i)
{
    std::cout << i << std::endl;
}

int incerement(int i)
{
    return (i++);
}


int Span::shortestSpan(void)
{
    unsigned long res = ULONG_MAX;
    unsigned long i = 0;
    std::vector<int>::iterator tmp;
    if (this->currentSize <= 1)
        throw noSpanException();
    for (std::vector<int>::iterator it = this->ints.begin(); it != this->ints.end(); it++)
    {
        tmp = std::upper_bound(this->ints.begin(), it, *it);
        if (*tmp == *it)
        {
            it++;
            tmp = std::upper_bound(it, this->ints.end(), *it);
        }
        if (tmp == this->ints.end())
            break;
        i = *tmp - *it;
        if (res > i)
            res = i;
    }
    return (res);
}

int Span::longestSpan(void)
{
    unsigned long max = *std::max_element(this->ints.begin(), this->ints.end());
    unsigned long min = *std::min_element(this->ints.begin(), this->ints.end());
    unsigned long res = max - min;
    return (res);
}
