/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:55:45 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/05 19:37:47 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>
#include <cctype>

void increment(int &n)
{
    n+= 5;
}

void changebool(bool &b)
{
    if (b)
        b = false;
    else
        b = true;
}

void toupper(char &c)
{
    c = std::toupper(c);
}

int main (void)
{
    std::cout << "Testing with int array: " << std::endl;
    int numbers[10] = {0,1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < 10; i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;
    ::iter(numbers, 10, &increment);
    std::cout << "After iter: " << std::endl;
    for (int i = 0; i < 10; i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    std::cout << std::endl;

    std::cout << "Testing with booleans array: " << std::endl;
    bool bools[10] = {0,1,0,1,0,1,0,1,0,1};
    for (int i = 0; i < 10; i++)
        std::cout << std::boolalpha << bools[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;
    ::iter(bools, 10, &changebool);
    std::cout << "After iter: " << std::endl;
    for (int i = 0; i < 10; i++)
        std::cout << std::boolalpha << bools[i] << " ";
    std::cout << std::endl;

    std::cout << std::endl;

    std::cout << "Testing with strd::string" << std::endl;
    char small_chars[30] = "abcdefghijklmnopqrstuvwxyz";
    std::cout << "Small chars before iter: " << small_chars << std::endl;
    std::cout << std::endl;
    ::iter(small_chars, 27 , &toupper);
    std::cout << "Small chars after iter: " << small_chars << std::endl;
    std::cout << std::endl;

    return (0);
}
