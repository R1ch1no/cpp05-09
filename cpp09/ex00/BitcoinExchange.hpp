/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:18:06 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/16 14:16:30 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <list>
#include <string>
#include <iostream>

class BitcoinExchange : public std::list<int, int>
{
public:
    BitcoinExchange();
    BitcoinExchange(std::string input);
    BitcoinExchange(BitcoinExchange const &other);
    BitcoinExchange &operator=(BitcoinExchange const &other);
    ~BitcoinExchange();
};

#endif
