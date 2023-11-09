/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:01:36 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/01 13:28:38 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string who, int num):name(who), grade(num)
{
    if (num < 1)
    {
        throw GradeTooHighException();
    }
    if (num > 150)
    {
        throw GradeTooLowException();
    }
    std::cout << "Bureaucrat constructor called" << std::endl;
}


Bureaucrat::Bureaucrat(Bureaucrat const & other):name(other.name), grade(other.grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    if (this != &other)
    {
        this->grade = other.grade;
        std::cout << "Bureaucrat copy assignment constructor called" << std::endl;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(){std::cout << "Bureaucrat destructor called" << std::endl;}

//////////////////////////////////////////////////////////////////////

int Bureaucrat::getGrade() const { return (this->grade);}

std::string Bureaucrat::getName() const { return (this->name);}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &other)
{
    out << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
    return (out);
}

void Bureaucrat::decreaseGrade(int num)
{
    if (this->getGrade() + num > 150)
        throw GradeDecreaseTooMuch();
    this->grade +=num;
}

void Bureaucrat::increaseGrade(int num)
{
    if (this->getGrade() - num < 1)
        throw GradeIncreaseTooMuch();
    this->grade -= num;
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{ return ("Bureaucrat grade would be too high, highest grade is 1!");}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{ return ("Bureaucrat grade would be too low, lowest grade is 150!");}

const char * Bureaucrat::GradeIncreaseTooMuch::what() const throw()
{ return ("Bureaucrat grade would be increased too much, highest grade is 1!");}

const char * Bureaucrat::GradeDecreaseTooMuch::what() const throw()
{ return ("Bureaucrat grade would be decreased too much, lowest grade is 150!");}

