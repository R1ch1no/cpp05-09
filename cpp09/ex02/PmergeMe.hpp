/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:18:45 by rkurnava          #+#    #+#             */
/*   Updated: 2023/12/19 09:59:06 by rkurnava         ###   ########.fr       */
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

int isVectorChainSorted(std::vector<std::vector<int> > v, size_t size);
int isDequeChainSorted(std::deque<std::deque<int> > d, size_t size);
int isSortedVector(std::vector<std::vector<int> > v);
int isSortedDeque(std::deque<std::deque<int> > d);

void sortChainVector(std::vector<std::vector<int> > &v, size_t size);
void sortChainDeque(std::deque<std::deque<int> > &d, size_t size);

void sortPairsVector(std::vector<std::vector<int> > &v, size_t size);
void sortPairsDeque(std::deque<std::deque<int> > &d, size_t size);

void fillVector(std::vector<std::vector<int> > &v, std::string *input, size_t size);
void fillDeque(std::deque<std::deque<int> > &d, std::string *input, size_t size);

void vectorOperations(std::vector<std::vector<int> > &v, std::string *input, size_t size);
void dequeOperations(std::deque<std::deque<int> > &d, std::string *input, size_t size);

#endif
