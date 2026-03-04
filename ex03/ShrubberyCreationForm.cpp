/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ShrubberyCreationForm.cpp						  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: muhabin- <muhabin-@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/03/03 08:55:29 by muhabin-		  #+#	#+#			 */
/*   Updated: 2026/03/03 09:44:51 by muhabin-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation", 145, 137), _target("default"){}
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
		 : AForm("Shurbbery Creation", 145, 137), _target(target){}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target){}
ShrubberyCreationForm::~ShrubberyCreationForm(){}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy); // Used based class assigment cause derived class cannot copy private member so need to used based class operator to allow it
		_target = copy._target;
	}
	return (*this);
}

// Action function - This will create the file with Ascii tree
void ShrubberyCreationForm::action()const
{
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str()); // output string file

	if (!file.is_open()) // cannot open
	{
		std::cerr<< RED << "Error: Could not create file " << filename << RESET << std::endl;
		return;
	}

	// the ascii tree
	file << "		 v\n";
	file << "		>X<\n";
	file << "		 A\n";
	file << "		d$b\n";
	file << "	  .d\\$$b.\n";
	file << "	.d$i$$\\$$b.\n";
	file << "	   d$$@b\n";
	file << "	  d\\$$$ib\n";
	file << "	.d$$$\\$$$b\n";
	file << "  .d$$@$$$$\\$$ib.\n";
	file << "	  d$$i$$b\n";
	file << "	 d\\$$$$@$b\n";
	file << "  .d$@$$\\$$$$$@b.\n";
	file << ".d$$$$i$$$\\$$$$$$b.\n";
	file << "		###\n";
	file << "		###\n";
	file << "		###\n";

	file.close();
	std::cout << GREEN << "Shrubbery created at " <<filename << RESET << std::endl;
}
