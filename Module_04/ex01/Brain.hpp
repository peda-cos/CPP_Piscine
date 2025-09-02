/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 01:53:34 by peda-cos          #+#    #+#             */
/*   Updated: 2025/09/02 03:15:07 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
  private:
	std::string ideas[100];

  public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	void setIdea(int index, const std::string &idea);
	const std::string &getIdea(int index) const;
	void printIdeas(int start, int count) const;
};

#endif
