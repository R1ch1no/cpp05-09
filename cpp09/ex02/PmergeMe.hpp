/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:18:45 by rkurnava          #+#    #+#             */
/*   Updated: 2023/12/03 17:24:35 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <limits>
#include <sstream>

void printVectorAfter(std::vector<std::vector<int> > v);
void printDequeAfter(std::deque<std::deque<int> > d);

void printVectorBefore(std::vector<std::vector<int> > v);
void printDequeBefore(std::deque<std::deque<int> > d);

void binaryInsertionSortV(std::vector<std::vector<int> > &v);
void binaryInsertionSortD(std::deque<std::deque<int> > &d);

void mergeSortVector(std::vector<std::vector<int> > &v);
void mergeSortDeque(std::deque<std::deque<int> > &d);

void fillVector(std::vector<std::vector<int> > &v, std::string *input, size_t size);
void fillDeque(std::deque<std::deque<int> > &d, std::string *input, size_t size);

void vectorOperations(std::vector<std::vector<int> > &v, std::string *input, size_t size);
void dequeOperations(std::deque<std::deque<int> > &d, std::string *input, size_t size);

#endif
