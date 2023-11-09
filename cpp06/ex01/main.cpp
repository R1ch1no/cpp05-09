/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:19:14 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/07 17:20:06 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data *data;
    Data *test;
    uintptr_t raw;

    try
    {
        data = new Data;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    data->a = 42;
    data->b = false;
    data->c = 'c';
    data->d = 42.42;
    data->f = 42.42f;
    data->str = "Hello World!";
    std::cout << std::endl;
    std::cout << "Original pointer to data : " << data << std::endl;
    std::cout << "Original data values : " << std::endl;
    std::cout << data->a << std::endl;
    std::cout << std::boolalpha << data->b << std::endl;
    std::cout << data->c << std::endl;
    std::cout << data->d << std::endl;
    std::cout << data->f << std::endl;
    std::cout << data->str << std::endl;
    std::cout << std::endl;
    raw = Serializer::serialize(data);
    std::cout << "Raw pointer to data : " << raw << std::endl;
    std::cout << std::endl;
    test = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer to data : " << test << std::endl;
    std::cout << "Data values after deseliazation : " << std::endl;
    std::cout << test->a << std::endl;
    std::cout << std::boolalpha << test->b << std::endl;
    std::cout << test->c << std::endl;
    std::cout << test->d << std::endl;
    std::cout << test->f << std::endl;
    std::cout << test->str << std::endl;
    delete data;
    return (0);
}
