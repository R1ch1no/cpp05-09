/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:09:00 by rkurnava          #+#    #+#             */
/*   Updated: 2023/10/31 18:55:24 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    // Constructors
    std::cout << "\033[32mConstructing:\033[0m\n";
    std::cout << "----------------------------" << std::endl;

    Intern const test;
    Intern intern (test);
    AForm *robo_form = NULL;
    AForm *shrub_form = NULL;
    AForm *president_form = NULL;
    AForm *unknown_form = NULL;
    std::cout << "----------------------------" << std::endl;
    //-----------------------------------------------------

    std::cout << std::endl;
    std::cout << "INTERN TESTS:" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << std::endl;
    robo_form = intern.makeForm("robotomy", "robo");
    std::cout << std::endl;
    president_form = intern.makeForm("presidential", "president");
    std::cout << std::endl;
    shrub_form = intern.makeForm("shrubbery", "shrub");
    std::cout << std::endl;
    unknown_form = intern.makeForm("driving licence", "drive");
    std::cout << std::endl;
    std::cout << "\033[31mDestructing:\033[0m\n";
    std::cout << "----------------------------" << std::endl;
    delete robo_form;
    delete shrub_form;
    delete president_form;
    delete unknown_form;
    return (0);
    //-------------------------------------------------------
}