/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhabin- <muhabin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:47:16 by muhabin-          #+#    #+#             */
/*   Updated: 2026/03/03 16:10:26 by muhabin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request" ,72, 45) , _target("default"){}
RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm("Robotomy Request", 72, 45), _target(target){}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm(copy), _target(copy._target){}
RobotomyRequestForm::~RobotomyRequestForm(){}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if(this != &copy)
	{
		AForm::operator=(copy);
		_target = copy._target;
	}
	return (*this);
}

// Action function - This will make drill noise then 50/50 if 0 then Robotomized 1 failed
void RobotomyRequestForm::action()const
{
	std::cout << GREEN << "Bzzz Bzzz Drilll Bzzz Bzzz" << RESET << std::endl;
	if (rand() % 2 == 0) // If even means Success
		std::cout << GREEN << _target << " has been robotomized successfully " << RESET << std::endl;
	else
		std::cout<< RED << _target << " failed to be robotomized " << RESET << std::endl;
}
