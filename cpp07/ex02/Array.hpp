/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:50:45 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/13 19:12:41 by rkurnava         ###   ########.fr       */
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
    unsigned int len;

public:
    // Constructors, destructor and operator= overload
    Array()
    {
        this->array = new T[0];
        this->len = 0;
    }
    Array(unsigned int n)
    {
        this->array = new T[n];
        this->len = n;
    }
    Array(Array const &other)
    {
        this->len = other.len;
        this->array = new T[this->len];
        for (unsigned int i = 0; i < this->len; i++)
            this->array[i] = other.array[i];
    }
    Array &operator=(Array const &other)
    {
        if (this != &other)
        {
            delete this->array;
            this->array = new T[other.len];
            for (unsigned int i = 0; i < other.len; i++)
                this->array[i] = other.array[i];
            this->len = other.len;
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
        if (n >= this->len || this->array == NULL)
            throw invalidIndex();
        return (this->array[n]);
    }
    unsigned int size(void) const
    {
        return (this->len);
    }
};

#endif
