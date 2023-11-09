/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:50:45 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/07 12:28:42 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>

class Array
{
private:
    T *array;
    unsigned int size;

public:
    // Constructors, destructor and operator= overload
    Array()
    {
        this->array = new T[0];
        this->size = 0;
    }
    Array(unsigned int n)
    {
        this->array = new T[n];
        this->size = n;
    }
    Array(Array const &other)
    {
        this->size = other.size;
        this->array = new T[this->size];
        for (unsigned int i = 0; i < this->size; i++)
            this->array[i] = other.array[i];
    }
    Array &operator=(Array const &other)
    {
        if (!other)
            return (*this);
        if (this != &other)
        {
            delete this->array;
            this->array = new T[other.size];
            for (unsigned int i = 0; i < other.size; i++)
                this->array[i] = other.array[i];
            this->size = other.size;
        }
        return (*this);
    }
    ~Array()
    {
        if (this->array)
            delete[] this->array;
    }
    ///////////////////////////////////////////////////////////
    class invalidIndex : public std::exception
    {
        virtual const char *what() const throw()
        {
            return ("Invalid index");
        }
    };
    T &operator[](unsigned int n)
    {
        if (n >= this->size || this->array == NULL)
            throw invalidIndex();
        return (this->array[n]);
    }
};

#endif
