/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:54:18 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/13 17:56:56 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    std::vector<int>tmp(5);
    tmp[0] = 9;
    tmp[1] = 5;
    tmp[2] = 25;
    tmp[3] = 20;
    tmp[4] = 21;
    Span test = Span(5);
    Span sp = Span(5);
    test.addNumber(tmp.begin(), tmp.end());
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << test.shortestSpan() << std::endl;
    std::cout << test.longestSpan() << std::endl;
    return 0;
}
