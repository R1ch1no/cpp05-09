/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:18:36 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/27 19:36:35 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <exception>
#include <stack>

class RPN
{
    private:
        std::stack<int> operands;
    public:
        void calculate(std::string &input);
        int checkInput(std::string &str);
        RPN(std::string &str);
        RPN(RPN const &other);
        RPN &operator=(RPN const &other);
        ~RPN(void);
};


#endif
 