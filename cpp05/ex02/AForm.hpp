/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:12:11 by rkurnava          #+#    #+#             */
/*   Updated: 2023/10/31 18:30:20 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class AForm
{
private:
    std::string target;
    std::string const name;
    bool isSigned;
    int const keyGrade;
    int const toExecute;

public:
    AForm(std::string name = "Some form", int keyGrade = 1, int toExecute = 20, std::string target = "none");
    AForm(AForm const &other);
    AForm &operator=(AForm const &other);
    virtual ~AForm();
    std::string getName() const;
    std::string getTarget() const;
    bool getIsSigned() const;
    int getKeyGrade() const;
    int getToExecute() const;
    void beSigned(class Bureaucrat const &other);
    virtual int execute(Bureaucrat const & executor) const = 0;
    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, AForm const &other);

#endif