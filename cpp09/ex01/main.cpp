/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:18:29 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/24 17:03:36 by rkurnava         ###   ########.fr       */
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
    RPN rpn(argv[1]);
    return (0);
 }
