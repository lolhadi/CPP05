/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhabin- <muhabin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 06:46:14 by muhabin-          #+#    #+#             */
/*   Updated: 2026/03/04 07:01:04 by muhabin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon", 25, 5), _target("default"){}
PresidentialPardonForm::PresidentialPardonForm(std::string const &target): AForm("Presidential Pardon", 25, 5), _target(target){}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm(copy), _target(copy._target){}
PresidentialPardonForm::~PresidentialPardonForm(){}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		_target = copy._target;
	}
	return (*this);
}

// Action Function- this will output the message
void PresidentialPardonForm::action()const
{
	std::cout <<GREEN << _target << " has been pardoned by Zaphod Beeblebrox " << RESET << std::endl;
}
