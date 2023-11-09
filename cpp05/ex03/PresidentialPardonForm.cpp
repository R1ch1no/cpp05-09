/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:12:19 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/01 18:07:04 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5, target)
{
    std::cout << "PresidentialPardonForm is constructed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other): AForm(other)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        std::cout << "PresidentialPardonForm copy assignemnt operator called" << std::endl;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

int PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getToExecute())
    {
        throw GradeTooLowException();
        return (0);
    }
    if (!this->getIsSigned())
    {
        std::cout << "PresidentialPardonForm is not signed, cant be executed" << std::endl;
        return (0);
    }
    else if (executor.getGrade() <= this->getToExecute())
    {
        std::cout << executor.getName() << " has been pardoned by Zaphod Beelebrox" << std::endl;
        return (1);
    }
    return (0);
}