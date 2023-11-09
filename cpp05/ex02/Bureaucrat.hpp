/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:12:15 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/01 14:50:48 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class Bureaucrat
{
private:
    std::string const name;
    int grade;

public:
    Bureaucrat(std::string name = "Anonymus", int grade = 150);
    Bureaucrat(Bureaucrat const &other);
    Bureaucrat &operator=(Bureaucrat const &other);
    ~Bureaucrat();
    std::string getName() const;
    int getGrade() const;
    void increaseGrade(int num = 1);
    void decreaseGrade(int num = 1);
    void executeForm(class AForm const &form) const;
    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };
    class GradeIncreaseTooMuch : public std::exception
    {
        virtual const char *what() const throw();
    };
    class GradeDecreaseTooMuch : public std::exception
    {
        virtual const char *what() const throw();
    };
    void signForm(class AForm &other) const;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &other);

#endif