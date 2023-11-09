/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:56:54 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/09 19:32:50 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>
#include <cctype>

template <typename T>
void iter(T *arr, size_t len, void (*f)(T&))
{
    for (size_t i = 0; i < len; i++)
        f(arr[i]);
}

template <typename T>
void iter(T *arr, size_t len, void (*f)(T const &))
{
    for (size_t i = 0; i < len; i++)
        f(arr[i]);
}

#endif
