/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:18:06 by rkurnava          #+#    #+#             */
/*   Updated: 2023/12/20 11:39:13 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <exception>
#include <fstream>
#include <sstream>
#include <iomanip>

class BitcoinExchange
{
private:
    std::map<std::string, float> data;
    
public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &other);
    BitcoinExchange &operator=(BitcoinExchange const &other);
    ~BitcoinExchange();
    void checkInputFile(std::string);
    void printRate(std::ifstream &inputFile);
    int checkLine(std::string line);
    int checkDate(int, int, int, float, std::string);
    class invalidFileException : public std::exception{const char *what() const throw();};
    class noAccess : public std::exception{const char *what() const throw();};
    class dataBankMissingException : public std::exception { const char *what() const throw(); };
};

#endif
