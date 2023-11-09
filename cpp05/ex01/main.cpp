/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:13:15 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/01 14:04:05 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat *bur1 = NULL;
    Bureaucrat *bur2 = NULL;
    Form *form1 = NULL;
    try
    {
        form1 = new Form("Report wild Karen", 50);
        if (form1 == NULL)
            throw std::bad_alloc();
        std::cout << std::endl;
        std::cout << *form1;
        std::cout << std::endl;
        try
        {
            bur1 = new Bureaucrat("Betty White", 98);
            if (bur1 == NULL)
                throw std::bad_alloc();
            std::cout << *bur1;
            bur1->signForm(*form1);
        }
        catch (std::exception &e)
        {
            std::cout << "Error Bettty: " << e.what() << std::endl;
        }
        std::cout << std::endl;
        std::cout << *form1;
        std::cout << std::endl;
        try
        {
            bur2 = new Bureaucrat("Ariana Grande", 30);
            if (bur2 == NULL)
                throw std::bad_alloc();
            std::cout << *bur2;
            bur2->signForm(*form1);
        }
        catch (std::exception &e)
        {
            std::cout << "Error Ariana: " << e.what() << std::endl;
        }
        std::cout << std::endl;
        std::cout << *form1;
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    delete bur1;
    delete bur2;
    delete form1;
}