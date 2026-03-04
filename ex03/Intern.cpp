/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhabin- <muhabin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 07:57:05 by muhabin-          #+#    #+#             */
/*   Updated: 2026/03/04 08:12:03 by muhabin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

Intern::Intern(){}
Intern::Intern(const Intern &copy)
{
	*this = copy;
}
Intern::~Intern(){}
Intern& Intern::operator=(const Intern &copy)
{
	(void)copy;
	return(*this);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	// need to create array
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout<< GREEN << "Intern creates " << formName << RESET << std::endl;

			// then switch index to create form
			switch (i)
			{
			case 0: return new ShrubberyCreationForm(target);
			case 1: return new RobotomyRequestForm(target);
			case 2: return new PresidentialPardonForm(target);
			}
		}
	}
	// if no match is found
	std::cout << RED << "Error: Unknown form name \"" << formName << "\"" << RESET <<std::endl;
	return NULL;
}
