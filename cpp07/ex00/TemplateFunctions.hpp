/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TemplateFunctions.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:56:56 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/05 18:32:30 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef TEMPLATEFUNCTIONS_HPP
# define TEMPLATEFUNCTIONS_HPP

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(T const a, T const b)
{
    if (a < b)
        return (a);
    if (b < a)
        return (b);
    if (a == b)
        return (b);
    return (0);
}

template <typename T>
T max(T const a, T const b)
{
    if (a > b)
        return (a);
    if (b > a)
        return (b);
    if (a == b)
        return (b);
    return (0);
}

#endif
