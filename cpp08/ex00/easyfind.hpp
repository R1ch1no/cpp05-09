/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:09:10 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/13 11:11:13 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

class numNotFoundException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return ("Number not found");
        };
};

template <typename T>
int easyfind(T const arr, int const find)
{

    typename T::const_iterator found = std::find(arr.begin(), arr.end(), find);
    if (found == arr.end())
        throw numNotFoundException();
    return (*found);
}

#endif
