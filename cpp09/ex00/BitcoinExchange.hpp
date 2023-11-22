/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:18:06 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/22 15:05:17 by rkurnava         ###   ########.fr       */
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
    class invalidFileException : public std::exception
    {
        virtual const char* what() const throw()
        {
            return ("Invalid file");
        }
    };
    class invalidExtensionException : public std::exception
    {
        virtual const char* what() const throw()
        {
            return ("Invalid file extension");
        }
    };
    class dataBankMissingException : public std::exception
    {
        virtual const char* what() const throw()
        {
            return ("Data bank missing");
        }
    };
};

#endif
