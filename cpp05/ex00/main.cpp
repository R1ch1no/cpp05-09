/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:13:15 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/01 13:55:09 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat const test ("Betty White", 98);
        Bureaucrat betty(test);
        std::cout << betty;
    }
    catch (std::exception &e)
    {
        std::cout << "Error Bettty: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "\nNext try->catch test. Grade -98 \n" << std::endl;
    std::cout << std::endl;
    try
    {
        Bureaucrat beyonce("Beyonce", -98);
        std::cout << beyonce;
    }
    catch (std::exception &e)
    {
        std::cout << "Error Beyonce: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "\nNext try->catch test. Grade 2000\n" << std::endl;
    std::cout << std::endl;
    try
    {
        Bureaucrat overachiever("Underachiever", 2000);
        std::cout << overachiever;
    }
    catch (std::exception &e)
    {
        std::cout << "Error Underachiever: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "\nNext try->catch test. Grade 12 \n" << std::endl;
    std::cout << std::endl;
    try
    {
        Bureaucrat const test ("Margaret", 12);
        Bureaucrat margaret;
        margaret = test;
        std::cout << margaret;
        margaret.increaseGrade(10);
        std::cout << margaret;
        margaret.increaseGrade();
        std::cout << margaret;
        margaret.increaseGrade();
        std::cout << margaret;
    }
    catch (std::exception &e)
    {
        std::cout << "Error Margaret: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "\nNext try->catch test. Grade 139 \n" << std::endl;
    std::cout << std::endl;
    try
    {
        Bureaucrat james("James Bond", 139);
        std::cout << james;
        james.decreaseGrade(10);
        std::cout << james;
        james.decreaseGrade();
        std::cout << james;
        james.decreaseGrade();
        std::cout << james;
    }
    catch (std::exception &e)
    {
        std::cout << "Error James Bond : " << e.what() << std::endl;
    }
}