/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:12:13 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/01 14:50:37 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string who, int num) : name(who), grade(num)
{
    if (num <= 0)
    {
        throw GradeTooHighException();
    }
    if (num >= 151)
    {
        throw GradeTooLowException();
    }
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : name(other.name), grade(other.grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    if (this != &other)
    {
        this->grade = other.grade;
        std::cout << "Bureaucrat copy assignemnt operator called" << std::endl;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() { std::cout << "Bureaucrat destructor called" << std::endl; }

//////////////////////////////////////////////////////////////////////

int Bureaucrat::getGrade() const { return (this->grade); }

std::string Bureaucrat::getName() const { return (this->name); }

std::ostream &operator<<(std::ostream &out, Bureaucrat const &other)
{
    out << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
    return (out);
}

void Bureaucrat::decreaseGrade(int num)
{
    if (this->getGrade() + num > 150)
        throw GradeDecreaseTooMuch();
    this->grade += num;
}

void Bureaucrat::increaseGrade(int num)
{
    if (this->getGrade() - num < 1)
        throw GradeIncreaseTooMuch();
    this->grade -= num;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat grade would be too high, highest grade is 1!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat grade would be too low, lowest grade is 150!");
}

const char *Bureaucrat::GradeIncreaseTooMuch::what() const throw()
{
    return ("Bureaucrat grade would be increased too much, highest grade is 1!");
}

const char *Bureaucrat::GradeDecreaseTooMuch::what() const throw()
{
    return ("Bureaucrat grade would be decreased too much, lowest grade is 150!");
}

void Bureaucrat::signForm(AForm &other) const
{
    other.beSigned(*this);
    if (other.getIsSigned())
        std::cout << this->getName() << " signed " << other.getName() << " form" << std::endl;
    else
    {
        if (this->getGrade() > other.getKeyGrade())
            std::cout << this->getName() << " couldn’t sign " << other.getName() << " because their grade is too low !" << std::endl;
        else
            std::cout << this->getName() << " couldn’t sign " << other.getName() << " because of unknown reason !" << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const
{
    if (!form.getIsSigned())
        std::cout << this->getName() << " can't execute " << form.getName() << " because it's not signed !" << std::endl;
    else if (this->getGrade() > form.getToExecute())
        std::cout << this->getName() << " can't execute " << form.getName() << ". Grade too low!" << std::endl;
    else
    {
        if (form.execute(*this))
            std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
}