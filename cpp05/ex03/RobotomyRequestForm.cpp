/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:12:23 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/01 18:07:12 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45, target)
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other): AForm(other)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        std::cout << "RobotomyRequestForm copy assignemnt operator called" << std::endl;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

int RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    static int random = 0;
    if (executor.getGrade() > this->getToExecute())
    {
        throw GradeTooLowException();
        return (0);
    }
    else if (!this->getIsSigned())
    {
        std::cout << "RobotomyRequestForm is not signed, cant be executed !" << std::endl;
        return (0);
    }
    else if (executor.getGrade() <= this->getToExecute())
    {
        if (!random)
        {
            std::cout << "driliiiing" << std::endl;
            random = 1;
            return (1);
        }
        else
        {
            random = 0;
            std::cout << "Robotomy request failed!" << std::endl;
            return (0);
        }
    }
    return (0);
}
