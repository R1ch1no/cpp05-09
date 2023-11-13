/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:21:56 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/13 11:30:50 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <string>

class Span
{
    private:
        unsigned int maxSize;
        unsigned int currentSize;
        std::vector <int> ints;
    public:
        Span(void);
        Span(unsigned int const n);
        Span(Span const &other);
        Span &operator=(Span const &other);
        ~Span(void);
        class invalidObjectInitialisationException : public std::exception
        {
            virtual const char * what() const throw()
            {
                return ("Invalid object initialisation");
            };
        };
        class maxReachedException : public std::exception
        {
            virtual const char * what() const throw()
            {
                return ("Can't add more values, max_size reached");
            };
        };
        class noSpanException : public std::exception
        {
            virtual const char * what () const throw()
            {
                return ("Can't find span, not enough values");
            };
        };
        void addNumber(int const n);
        void addNumber(int const start, int const end);
        int shortestSpan(void);
        int longestSpan(void);
};

#endif
