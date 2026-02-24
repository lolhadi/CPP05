/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhabin- <muhabin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:57:18 by muhabin-          #+#    #+#             */
/*   Updated: 2026/02/24 14:43:51 by muhabin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include<iostream>
#include<string>
#include<exception>

#define GREEN	"\033[32m"
#define RED		"\033[31m"
#define BLUE	"\033[0;34m"
#define YELLOW  "\033[33m"
#define WHITE	"\033[0;37m"
#define RESET	"\033[0m"

class Bureaucrat;

class Form
{
	// all my private stuff
	private:
		std::string const	_name;
		bool				_isSigned;
		int	const			_gradeSign;
		int	const			_gradeExec;

	public:
		// constructor
		Form();
		Form(std::string  const &name, int const gradeSign, int const gradeExec);
		~Form();
		Form(const Form &other);
		Form& operator = (const Form &other);
	// getter
		std::string	const	&getName() const;
		bool	const		&getIsSigned()const;
		int	const			&getGradeSign()const;
		int	const			&getGradeExec()const;

		// Member Function
		void beSigned(Bureaucrat &bureaucrat);

		// Exception
		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const *what(void) const throw();
		};
	class GradeTooLowException: public std::exception
		{
			public:
				virtual char const *what(void) const throw();
		};
};
std::ostream& operator<<(std::ostream &str, Form const &form);
#endif
