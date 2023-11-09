/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:07:10 by rkurnava          #+#    #+#             */
/*   Updated: 2023/10/30 17:10:30 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
    std::string const name;
    bool isSigned;
    int const keyGrade;
    int const toExecute;
    
public:
    Form(std::string name = "Some form", int keyGrade = 1, int toExecute = 20);
    Form(Form const &other);
    Form & operator=(Form const &other);
    ~Form();
    std::string getName() const;
    bool    getIsSigned() const;
    int     getKeyGrade() const;
    int     getToExecute() const;
    void    beSigned(class Bureaucrat const & other);
    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, Form const &other);

#endif