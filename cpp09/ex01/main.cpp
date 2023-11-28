/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:18:29 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/28 15:07:24 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "RPN.hpp"

 int main(int argc, char **argv)
 {
    if (argc != 2)
    {
        std::cerr << "Error : Invalid number of arguments" << std::endl;
        return (0);
    }
    std::string input = argv[1];
    RPN calculation(input);
    return (0);
 }
