/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:06:39 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/10 19:51:01 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//Constructors, destructor, operator=, copy constructor

Span::Span(void)
{
    throw invalidObjectInitialisationException();
}

Span::Span(unsigned int const n) : maxSize(n), currentSize(0){}

Span &Span::operator=(Span const &other)
{
    this->maxSize = other.maxSize;
    this->currentSize = other.currentSize;
    this->ints = other.ints;
    return (*this);
}

Span::Span(Span const &other){ *this = other;}

Span::~Span(void){}

///////////////////////////////////////////////////////////////

//Member functions

void Span::addNumber(int const n)
{
    if (this->currentSize == this->maxSize)
        throw maxReachedException();
    this->ints.push_back(n);
    this->currentSize++;
}

void print(int i)
{
    std::cout << i << std::endl;
}

int incerement(int i)
{
    return (i++);
}

void Span::addNumber(int const start, int const end)
{
    if (this->currentSize + (end - start) > this->maxSize)
        throw maxReachedException();
}

int Span::shortestSpan(void)
{
    if (this->currentSize <= 1)
        throw noSpanException();
    return (0);
}

int Span::longestSpan(void)
{
    if (this->currentSize <= 1)
        throw noSpanException();
    return (0);
}
