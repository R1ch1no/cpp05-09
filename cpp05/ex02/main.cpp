/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:09:00 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/01 14:55:35 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    // Constructors
    std::cout << "\033[32mConstructing:\033[0m\n";
    std::cout << "----------------------------" << std::endl;

    Bureaucrat test1("Bob", 1);
    std::cout << "----------------------------" << std::endl;
    Bureaucrat test2("Bill", 142);
    std::cout << "----------------------------" << std::endl;
    PresidentialPardonForm test3("president");
    std::cout << "----------------------------" << std::endl;
    Bureaucrat bob (test1);
    std::cout << "----------------------------" << std::endl;
    Bureaucrat bill(test2);
    std::cout << "----------------------------" << std::endl;
    ShrubberyCreationForm shrub ("shrub");
    std::cout << "----------------------------" << std::endl;
    RobotomyRequestForm robo("robo");
    std::cout << "----------------------------" << std::endl;
    PresidentialPardonForm president(test3);
    std::cout << "----------------------------" << std::endl;
    //-----------------------Shrubbery------------------------------

    std::cout << "-------------------------------" << std::endl;

    std::cout << std::endl;
    std::cout << "\033[33mUnsigned\033[0m\n";
    std::cout << std::endl;
   
    bob.executeForm(shrub);
    std::cout << std::endl;
    bob.signForm(shrub);

    std::cout << std::endl;
    std::cout << "\033[33mSigned\033[0m\n";
    std::cout << std::endl;
   
    bob.executeForm(shrub);

    std::cout << std::endl;
    std::cout << "\033[33mGrade too low exception\033[0m\n";
    std::cout << std::endl;
   
    bill.executeForm(shrub);
    std::cout << std::endl
              << std::endl;
    //-----------------------Robotomy------------------------------

    std::cout << "-------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "\033[33mUnsigned\033[0m\n";
    std::cout << std::endl;
    bob.executeForm(robo);
    std::cout << std::endl;
    bob.signForm(robo);

    std::cout << std::endl;
    std::cout << "\033[33mSigned. Drilling sounds should happend 3x\033[0m\n";
    std::cout << std::endl;
   
    bob.executeForm(robo);
    std::cout << std::endl;
   
    bob.executeForm(robo);
    std::cout << std::endl;
   
    bob.executeForm(robo);
    std::cout << std::endl;
   
    bob.executeForm(robo);
    std::cout << std::endl;
   
    bob.executeForm(robo);
    std::cout << std::endl;
   
    bob.executeForm(robo);

    std::cout << std::endl;
    std::cout << "\033[33mGrade too low exception\033[0m\n";
    std::cout << std::endl;
    
    bill.executeForm(robo);
    std::cout << std::endl
              << std::endl;
    //-----------------------PresidentialPardon------------------------------

    std::cout << "-------------------------------" << std::endl;

    std::cout << std::endl;
    std::cout << "\033[33mUnsigned\033[0m\n";
    std::cout << std::endl;
    bob.executeForm(president);
    
    bob.signForm(president);
    std::cout << std::endl;
    std::cout << "\033[33mSigned\033[0m\n";
    std::cout << std::endl;
   
    bob.executeForm(president);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "\033[33mGrade too low exception\033[0m\n";
    std::cout << std::endl;
   
    bill.executeForm(president);
    std::cout << std::endl
              << std::endl;
    //-----------------------------------------------------

    std::cout << std::endl;
    std::cout << "\033[31mDestructing:\033[0m\n";
    std::cout << "----------------------------" << std::endl;
    return (0);
    //-------------------------------------------------------
}