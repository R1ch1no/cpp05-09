/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:18:36 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/24 18:27:10 by rkurnava         ###   ########.fr       */
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
        int checkInput(std::string const str);
        RPN(std::string const str);
        RPN(RPN const &other);
        RPN &operator=(RPN const &other);
        ~RPN(void);
};


#endif
 