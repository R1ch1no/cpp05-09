/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:19:16 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/07 17:20:07 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
//Constructors and destructor

Serializer::Serializer(){}

Serializer::Serializer(Serializer const &other){*this = other;}

Serializer &Serializer::operator=(Serializer const &other){(void)other; return (*this);}

Serializer::~Serializer(){}

////////////////////////////////////////////

//Member functions

uintptr_t Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}

////////////////////////////////////////////
