/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseClass.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:15:59 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/07 17:20:10 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASECLASS_HPP
#define BASECLASS_HPP

class BaseClass
{
public:
    virtual ~BaseClass();
};

BaseClass *generate(void);
void identify(BaseClass *p) ;
void identify(BaseClass &p) ;

#endif
