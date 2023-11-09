/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:33:29 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/07 17:20:04 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Wrong number of arguments!" << std::endl;
        return (1);
    }
    std::string input = argv[1];
    if (!input.length())
    {
        std::cerr << "Empty argument!" << std::endl;
        return (1);
    }
    ScalarConverter::convert(input);
    return (0);
}
