/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:56:54 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/05 19:31:50 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T arr[], unsigned int len, void (*f)(T &))
{
    for (unsigned int i = 0; i < len; i++)
        f(arr[i]);
}

#endif
