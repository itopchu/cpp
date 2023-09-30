/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 21:50:59 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/20 21:50:59 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() :
	Animal("Dog")
{
	this->brain = new Brain();
	putMessage(YELLOW, "Default constructor of Dog is called", 1);
}

Dog::Dog(const Dog &assign) :
	Animal(assign.getType())
{
	if (this != &assign)
	{
		delete this->brain;
		this->brain = new Brain();
		for (int i = 0; i < 100; i++)
			this->brain->ideas[i] = assign.brain->ideas[i];
	}
	putMessage(YELLOW, "A copy of ", 0);
	putMessage(YELLOW, this->getType(), 0);
	putMessage(YELLOW, " is created", 1);
	*this = assign;
}

Dog & Dog::operator=(const Dog &assign)
{
	this->_type = assign.getType();
	return *this;
}

Dog::~Dog()
{
	
	delete brain;
	putMessage(PURP, "Default destructor of Dog is called", 1);
}

void	Dog::makeSound() const
{
	putMessage(L_BLUE, "I say Hav not Woof!", 1);
}
