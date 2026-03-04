/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhabin- <muhabin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:14:54 by muhabin-          #+#    #+#             */
/*   Updated: 2026/03/03 10:30:25 by muhabin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include<iostream>
#include<string>
#include<exception>

#define GREEN	"\033[32m"
#define RED		"\033[31m"
#define BLUE	"\033[0;34m"
#define YELLOW  "\033[33m"
#define WHITE	"\033[0;37m"
#define RESET	"\033[0m"

class AForm;

class Bureaucrat{
	private:
		std::string const	_name;
		int					_grade;

	public:
	// Constructor & Destructor
		Bureaucrat();
		Bureaucrat(std::string const &name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator = (const Bureaucrat &other);

	// Getter
	std::string const	&getName() const; // Double const get the result and the function cannot change
	int			getGrade() const;

	// Grade modification
	void incrementGrade();
	void decrementGrade();

	// Form Interaction
	void signForm(AForm &aform); // cheack whether the aform is signed successfully or not
	void executeForm(AForm const &form) const;

	// Exceptions
	class GradeTooHighException: public std::exception{
		public:
			virtual char const *what(void) const throw();
	};
	class GradeTooLowException: public std::exception{
		public:
			virtual char const *what(void) const throw();
	};
};
std::ostream& operator<<(std::ostream &str, Bureaucrat const &bureaucrat);

#endif
