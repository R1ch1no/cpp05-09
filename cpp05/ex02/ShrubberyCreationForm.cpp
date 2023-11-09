/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:12:04 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/01 18:06:38 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137, target)
{
    std::cout << "ShrubberyCreationForm is constructed called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other): AForm(other)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        std::cout << "ShrubberyCreationForm copy assignemnt operator called" << std::endl;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

int ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    std::string fileName = this->getTarget() + "_shrubbery.form";
    if (!this->getIsSigned())
    {
        std::cout << "ShrubberyCreationForm is not signed, cant be executed" << std::endl;
        return (0);
    }
    if (executor.getGrade() > this->getToExecute())
    {
        throw GradeTooLowException();
        return (0);
    }
    else if (executor.getGrade() <= this->getToExecute())
    {
        std::ofstream outFile(fileName.c_str());
        if (!outFile.is_open())
        {
            std::cerr << "Error creating a file!" << std::endl;
            return (0);
        }
        outFile << "     ^" << std::endl;
        outFile << "    ^^^" << std::endl;
        outFile << "   ^^^^^" << std::endl;
        outFile << "  ^^^^^^^" << std::endl;
        outFile << " ^^^^^^^^^" << std::endl;
        outFile << "^^^^^^^^^^^" << std::endl;
        outFile << "    |||" << std::endl;
        outFile << "    |||" << std::endl;
        outFile.close();
        return (1);
    }
    return (0);
}