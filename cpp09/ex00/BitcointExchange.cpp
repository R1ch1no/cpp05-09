/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcointExchange.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:18:13 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/16 13:23:50 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string input)
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
    if (this != &other)
    {
        *this = other;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}
