/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:18:13 by rkurnava          #+#    #+#             */
/*   Updated: 2023/12/20 11:38:32 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructor, Destructor, Copy Constructor, Assignment Operator

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

BitcoinExchange::BitcoinExchange()
{
    std::ifstream dataBank("data.csv");
    if (!dataBank.is_open())
        throw noAccess();
    std::string line;
    std::string date;
    float rate;
    if (!std::getline(dataBank, line))
        throw dataBankMissingException();
    while (std::getline(dataBank, line))
    {
        date = std::string(line.begin(), line.begin() + 10);
        std::istringstream value(std::string(line.begin() + 11, line.end()));
        value >> rate;
        this->data[date] = rate;
    }
    if (this->data.empty())
        throw dataBankMissingException();
}

////////////////////////////////////////////////////////////////////////////

// Member Functions

void BitcoinExchange::checkInputFile(std::string fileName)
{
    if (fileName.empty())
        throw invalidFileException();
    std::ifstream inputFile(fileName.c_str());
    if (!inputFile.is_open())
        throw noAccess();
    printRate(inputFile);
}

int BitcoinExchange::checkLine(std::string line)
{
    if (line.length() < 14)
    {
        std::cout << "\033[31m" << "Incorrect line : " << "\033[0m" << "\"" << line << "\"" << std::endl;
        return (1);
    }
    std::string delimiters = "0123456789 |.-";
    size_t pos = line.find_first_not_of(delimiters);
    if (pos != std::string::npos)
    {
        std::cout << "\033[31m" << "Incorrect line : " << "\033[0m" << "\"" << line << "\"" << std::endl;
        return (1);
    }
    std::string year;
    std::string month;
    std::string day;
    char dash1;
    char dash2;
    char space1;
    char space2;
    char pipe;
    std::string amount;
    std::string intDelimiters = "0123456789";
    std::string floatDelimiters = "0123456789.";
    year = std::string(line.begin(), line.begin() + 4);
    dash1 = line[4];
    month = std::string(line.begin() + 5, line.begin() + 7);
    dash2 = line[7];
    day = std::string(line.begin() + 8, line.begin() + 10);
    space1 = line[10];
    pipe = line[11];
    space2 = line[12];
    amount = std::string(line.begin() + 13, line.end());
    int dotCount = 0;
    for (size_t i = 0; i < amount.length(); i++)
    {
        if (amount[i] == '.')
            dotCount++;
        if (dotCount > 1)
        {
            std::cout << "\033[31m" << "Incorrect line : " << "\033[0m" << "\"" << line << "\"" << std::endl;
            return (1);
        }
    }
    size_t pos1 = year.find_first_not_of(intDelimiters);
    size_t pos2 = month.find_first_not_of(intDelimiters);
    size_t pos3 = day.find_first_not_of(intDelimiters);
    size_t pos4 = amount.find_first_not_of(floatDelimiters);
    if (pos1 != std::string::npos || pos2 != std::string::npos || pos3 != std::string::npos || pos4 != std::string::npos)
    {
        std::cout << "\033[31m" << "Incorrect line : " << "\033[0m" << "\"" << line << "\"" << std::endl;
        return (1);
    }
    if (dash1 != '-' || dash2 != '-' || space1 != ' ' || space2 != ' ' || pipe != '|')
    {
        std::cout << "\033[31m" << "Incorrect line : " << "\033[0m" << "\"" << line << "\"" << std::endl;
        return (1);
    }
    return (0);
}

int BitcoinExchange::checkDate(int year, int month, int day, float rate, std::string line)
{
    if (year <= 2009 && month <= 1 && day < 2) 
    {
        std::cout << "\033[31m" << "Incorrect date : " << "\033[0m" << line << " => exchange impossible" << std::endl;
        return (1);
    }
    if (year < 2009)
    {
        std::cout << "\033[31m" << "Incorrect year : " << "\033[0m" << line << " => exchange impossible" << std::endl;
        return (1);
    }
    if (month < 1 || month > 12)
    {
        std::cout << "\033[31m"  << "Incorrect month : " << "\033[0m" << line << std::endl;
        return (1);
    }
    if (day < 1 || day > 31)
    {
        std::cout << "\033[31m" << "Incorrect day : " << "\033[0m" << line << std::endl;
        return (1);
    }
    if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 2 && day > 29)
    {
        std::cout << "\033[31m" << "Incorrect day : " << "\033[0m" << line << std::endl;
        return (1);
    }
    if (!((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 2 && day > 28)
    {
        std::cout << "\033[31m" << "Incorrect day : " << "\033[0m" << line << std::endl;
        return (1);
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        std::cout << "\033[31m" << "Incorrect day : " << "\033[0m" << line << std::endl;
        return (1);
    }
    if (rate < 0 || rate > 1000)
    {
        std::cout << "\033[31m" << "Incorrect rate : " << "\033[0m" << line << std::endl;
        return (1);
    }
    return (0);
}

void BitcoinExchange::printRate(std::ifstream &input)
{
    std::string line;
    long year;
    long month;
    long day;
    float amount;
    std::getline(input, line);
    if (line != "date | value")
        std::cout << "\033[31m" << "Incorrect formating, first line should be : date | value" << "\033[0m" << std::endl;
    while (std::getline(input, line))
    {
        if (checkLine(line))
            continue;
        std::istringstream y(std::string(line.begin(), line.begin() + 4));
        std::istringstream m(std::string(line.begin() + 5, line.begin() + 7));
        std::istringstream d(std::string(line.begin() + 8, line.begin() + 10));
        std::istringstream a(std::string(line.begin() + 12, line.end()));
        y >> year;
        m >> month;
        d >> day;
        a >> amount;
        if (checkDate(year, month, day, amount, line))
            continue;
        std::string date = std::string(line.begin(), line.begin() + 10);
        std::map<std::string, float>::const_iterator it = this->data.find(date);
        if (it->first != date)
        {
            it = this->data.lower_bound(date);
            it--;
        }
        std::cout << date << " => " << amount << " = " << it->second * amount << std::endl;
    }
}

const char *BitcoinExchange::invalidFileException::what() const throw()
{
    return ("Invalid file");
}

const char *BitcoinExchange::noAccess::what() const throw()
{
    return ("File could not be accessed");
}

const char *BitcoinExchange::dataBankMissingException::what() const throw()
{
    return ("Data bank missing");
}
