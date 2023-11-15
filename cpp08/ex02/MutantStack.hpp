/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:23:15 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/15 18:26:06 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <string>
#include <list>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        MutantStack(): std::stack<T>(){;};
        MutantStack(MutantStack const &other) : std::stack<T>(other){;};
        MutantStack &operator=(MutantStack const &other)
        {
            if (this != &other)
                std::stack<T>::operator=(other);
            return (*this);
        };
        ~MutantStack(){;};
        iterator begin() { return this->c.begin(); };
        iterator end() { return this->c.end(); };
};

#endif
