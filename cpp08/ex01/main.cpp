/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:54:18 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/21 19:31:56 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    std::deque<int> tmp(5);
    Span *tmp2 = NULL;
    Span *test = NULL;
    Span *sp = NULL;
    tmp[0] = 9;
    tmp[1] = 5;
    tmp[2] = 25;
    tmp[3] = 20;
    tmp[4] = 21;
    try
    {
        tmp2 = new Span(20000);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        tmp2->addNumber(1, 200001);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        test = new Span(5);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        test->addNumberIter(tmp.begin(), tmp.end());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        sp = new Span(5);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        sp->addNumber(6);
        sp->addNumber(3);
        sp->addNumber(17);
        sp->addNumber(-11);
        sp->addNumber(-9);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "Sp shortest span   (should be 2)    : " << sp->shortestSpan() << std::endl;
        std::cout << "Sp longest span    (should be 28)   : " << sp->longestSpan() << std::endl;
        std::cout << "Test shortest span (should be 1)    : " << test->shortestSpan() << std::endl;
        std::cout << "Test longest span  (should be 20)   : " << test->longestSpan() << std::endl;
        std::cout << "Tmp2 shortest span (should be 1)    : " << tmp2->shortestSpan() << std::endl;
        std::cout << "Tmp2 longest span  (should be 19999): " << tmp2->longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    delete sp;
    delete test;
    delete tmp2;
    return 0;
}
