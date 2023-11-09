/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:07:01 by rkurnava          #+#    #+#             */
/*   Updated: 2023/10/31 18:29:01 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string str, int grade, int execGrade) : name(str), isSigned(false), keyGrade(grade), toExecute(execGrade)
{
    if (grade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (grade > 150 || execGrade > 150)
        throw GradeTooLowException();
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(Form const &other) : name(other.name), isSigned(other.isSigned), keyGrade(other.keyGrade), toExecute(other.toExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(Form const &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
        std::cout << "Form copy assignment constructor called" << std::endl;
    }
    return (*this);
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const { return (this->name); }
bool Form ::getIsSigned() const { return (this->isSigned); }
int Form::getKeyGrade() const { return (this->keyGrade); }
int Form::getToExecute() const { return (this->toExecute); }

void Form::beSigned(Bureaucrat const & other)
{
    if (other.getGrade() > this->keyGrade)
    {
        throw GradeTooLowException();
        return;
    }
    this->isSigned = true;
}

const char * Form::GradeTooHighException::what() const throw()
{
    return ("Form : Too high grade / execution grade");
}

const char * Form::GradeTooLowException::what() const throw()
{
    return ("Form : Too low grade / execution grade");
}

std::ostream &operator<<(std::ostream &out, Form const &other)
{
    out << "Form name                       : " << other.getName() << std::endl;
    out << "Is form signed                  : " << std::boolalpha << other.getIsSigned() << std::endl;
    out << "Min grade to sign the form      : " << other.getKeyGrade() << std::endl;
    out << "Grade to execute form behaviour : " << other.getToExecute() << std::endl;
    return (out);
}