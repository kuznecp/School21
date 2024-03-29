/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuriko <myuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:11:35 by myuriko           #+#    #+#             */
/*   Updated: 2022/10/23 19:11:36 by myuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
# define Dog_HPP
# define UINT unsigned int
# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
private:
	Brain			*brain;
protected:
	std::string		name;

public:
	Dog();
	Dog(std::string name);
	Dog(Dog const &inst);
	~Dog();

	Dog 				&operator=(Dog const &inst);

	const std::string	&getName(void) const;
	void				makeSound(void) const;
	std::string			&getIdea(int i);
	void				setIdea(int i, std::string value);
};

std::ostream			&operator<<(std::ostream &out, const Dog &inst);

#endif
