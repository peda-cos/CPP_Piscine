/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 01:42:58 by peda-cos          #+#    #+#             */
/*   Updated: 2025/11/08 02:00:31 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T, typename F> void iter(T *array, size_t length, F func) {
    for (size_t i = 0; i < length; i++) {
	func(array[i]);
    }
}

template <typename T>
void print(const T &x) {
    std::cout << x << " ";
}

template <typename T>
void increment(T &x) {
    x++;
}

#endif
