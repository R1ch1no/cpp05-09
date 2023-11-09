/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:02:17 by rkurnava          #+#    #+#             */
/*   Updated: 2023/10/22 18:19:51 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
private:
    std::string const name;
    int grade;
public:
    Bureaucrat(std::string name = "Anonymus", int grade = 150);
    Bureaucrat(Bureaucrat const & other);
    Bureaucrat & operator=(Bureaucrat const & other);
    ~Bureaucrat();
    std::string getName() const;
    int getGrade() const;
    void increaseGrade(int num = 1);
    void decreaseGrade(int num = 1);
    class GradeTooHighException : public std::exception{virtual const char*  what() const throw();};
    class GradeTooLowException : public std::exception{virtual const char*  what() const throw();};
    class GradeIncreaseTooMuch : public std::exception{virtual const char*  what() const throw();};
    class GradeDecreaseTooMuch : public std::exception{virtual const char*  what() const throw();};
    
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &other);

#endif