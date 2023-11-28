/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:18:36 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/28 16:21:12 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

class RPN
{
    private:
        std::stack<int> numbers;
        long tmp;
    public:
        void calculate(std::string &input);
        int checkInput(std::string &str);
        RPN(std::string &str);
        RPN(RPN const &other);
        RPN &operator=(RPN const &other);
        ~RPN(void);
};


#endif
