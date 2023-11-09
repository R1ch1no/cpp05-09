/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:42:00 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/07 17:20:12 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseClass.hpp"
#include <iostream>

int main (void)
{
    BaseClass *test1 = generate();
    BaseClass *test2 = generate();
    BaseClass *test3 = generate();
    BaseClass &test4 = *generate();
    BaseClass &test5 = *generate();
    BaseClass &test6 = *generate();
    BaseClass *test7 = NULL;
    identify(test1);
    identify(test2);
    identify(test3);
    identify(test4);
    identify(test5);
    identify(test6);
    identify(test7);
    delete test1;
    delete test2;
    delete test3;
    delete &test4;
    delete &test5;
    delete &test6;
    return (0);
}
