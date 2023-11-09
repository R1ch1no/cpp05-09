/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseClass.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:16:35 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/07 17:20:09 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseClass.hpp"
#include "AClass.hpp"
#include "BClass.hpp"
#include "CClass.hpp"
#include <cstdlib>
#include <iostream>

BaseClass::~BaseClass() {}

BaseClass *generate(void)
{
    BaseClass *random = NULL;
    int randomClass = std::rand() % 3;
    random = randomClass == 0 ? random = new AClass() : randomClass == 1 ? random = new BClass()
                                                    : randomClass == 2   ? random = new CClass()
                                                                         : NULL;
    return (random);
}

void identify(BaseClass *p)
{
    std::cout << "Identify BaseClass pointer: \n\t";
    AClass *a = dynamic_cast<AClass *>(p);
    if (a)
    {
        std::cout << "Pointer received is an AClass" << std::endl;
        return;
    }
    BClass *b = dynamic_cast<BClass *>(p);
    if (b)
    {
        std::cout << "Pointer received is an BClass" << std::endl;
        return;
    }
    CClass *c = dynamic_cast<CClass *>(p);
    if (c)
    {
        std::cout << "Pointer received is an CClass" << std::endl;
        return;
    }
    std::cout << "Pointer received is not an AClass, BClass or CClass" << std::endl;
}

void identify(BaseClass &p)
{
    std::cout << "Identify BaseClass adress: \n\t";
    try
    {
        AClass a = dynamic_cast<AClass &>(p);
        std::cout << "Adress received is an AClass" << std::endl;
        return;
    }
    catch (std::exception &e)
    {
        try
        {
            BClass b = dynamic_cast<BClass &>(p);
            std::cout << "Adress received is an BClass" << std::endl;
            return;
        }
        catch (std::exception &e)
        {
            try
            {
                CClass c = dynamic_cast<CClass &>(p);
                std::cout << "Adress received is an CClass" << std::endl;
                return;
            }
            catch (std::exception &e)
            {
                std::cout << "Adress received is not an AClass, BClass or CClass" << std::endl;
            }
        }
    }
}
