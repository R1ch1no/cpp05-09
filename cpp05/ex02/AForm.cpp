/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:12:10 by rkurnava          #+#    #+#             */
/*   Updated: 2023/10/31 18:33:32 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string str, int grade, int execGrade, std::string target) : target(target), name(str), isSigned(false), keyGrade(grade), toExecute(execGrade)
{
    if (grade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (grade > 150 || execGrade > 150)
        throw GradeTooLowException();
    std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(AForm const &other) : name(other.name), isSigned(other.isSigned), keyGrade(other.keyGrade), toExecute(other.toExecute)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
        this->target = other.target;
        std::cout << "AForm copy assignemnt operator called" << std::endl;
    }
    return (*this);
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getTarget() const { return (this->target);}
std::string AForm::getName() const { return (this->name); }
bool AForm ::getIsSigned() const { return (this->isSigned); }
int AForm::getKeyGrade() const { return (this->keyGrade); }
int AForm::getToExecute() const { return (this->toExecute); }

void AForm::beSigned(Bureaucrat const &other)
{
    if (other.getGrade() > this->keyGrade)
    {
        throw GradeTooLowException();
        return;
    }
    this->isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("AForm : Too high grade / execution grade");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("AForm : Too low grade / execution grade");
}

int AForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getToExecute())
    {
        throw GradeTooLowException();
        return (0);
    }
    else
    {
        std::cout << "AForm executed" << std::endl;
        return (1);
    }
}

std::ostream &operator<<(std::ostream &out, AForm const &other)
{
    out << "AForm name                       : " << other.getName() << std::endl;
    out << "Is form signed                  : " << std::boolalpha << other.getIsSigned() << std::endl;
    out << "Min grade to sign the form      : " << other.getKeyGrade() << std::endl;
    out << "Grade to execute form behaviour : " << other.getToExecute() << std::endl;
    return (out);
}