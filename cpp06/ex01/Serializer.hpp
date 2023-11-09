/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:19:18 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/07 17:20:08 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
    int a;
    bool b;
    char c;
    double d;
    float f;
    std::string str;
};

class Serializer
{
    private:
    Serializer(void);
    Serializer(Serializer const &other);
    Serializer &operator=(Serializer const &other);
    ~Serializer();
    public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};



#endif
