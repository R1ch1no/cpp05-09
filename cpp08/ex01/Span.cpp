/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:06:39 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/21 19:29:54 by rkurnava         ###   ########.fr       */
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
    std::vector<int>tmp;
    for (long i = start; i <= end; i++)
        tmp.push_back(i);
    if (this->currentSize + tmp.size() > this->maxSize)
        throw maxReachedException();
    this->ints.insert(this->ints.end(), tmp.begin(), tmp.end());
    this->currentSize += tmp.size();
}

void print(int i)
{
    std::cout << i << std::endl;
}

int incerement(int i)
{
    return (i++);
}


unsigned long Span::shortestSpan(void)
{
    if (this->currentSize < 2)
        throw noSpanException();
    long res = LONG_MAX;
    long check;
    std::vector<int> tmp = this->ints;
    std::sort(tmp.begin(), tmp.end());
    for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
    {
        if (it + 1 != tmp.end())
        {
            check = std::abs(*it - *(it + 1));
            if (res > check)
                res = std::abs(*it - *(it + 1));
        }
    }
    return (res);
}

unsigned long Span::longestSpan(void)
{
    if (this->currentSize < 2)
        throw noSpanException();
    long max = *std::max_element(this->ints.begin(), this->ints.end());
    long min = *std::min_element(this->ints.begin(), this->ints.end());
    unsigned long res = std::abs(max - min);
    return (res);
}
