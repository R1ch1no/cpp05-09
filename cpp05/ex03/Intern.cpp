/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:02:15 by rkurnava          #+#    #+#             */
/*   Updated: 2023/10/31 18:45:08 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern()
{
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(Intern const &other)
{
    *this = other;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &other)
{
    (void)other;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::makeShrubbery(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomy(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidential(std::string target)
{
    return (new PresidentialPardonForm(target));
}

typedef AForm * (Intern::*FnPtr)(std::string target);

AForm * Intern::makeForm(std::string formName, std::string target)
{
    AForm *newForm = NULL;
    FnPtr forms[3] = {&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresidential};
    std::string form[3] = {"shrubbery", "robotomy", "presidential"};
    for (int i = 0; i < 3; i++)
    {
        if (formName == form[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            newForm = (this->*forms[i])(target);
            return (newForm);
        }
    }
    std::cout << "Intern cannot create " << formName << std::endl;
    return (NULL);
}