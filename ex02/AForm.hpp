/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhabin- <muhabin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:57:18 by muhabin-          #+#    #+#             */
/*   Updated: 2026/03/02 14:43:20 by muhabin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

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

class AForm
{
	// all my private stuff
	private:
		std::string const	_name;
		bool				_isSigned;
		int	const			_gradeSign;
		int	const			_gradeExec;

	protected:
		virtual void action()const = 0;

	public:
		// constructor
		AForm();
		AForm(std::string  const &name, int const gradeSign, int const gradeExec);
		virtual ~AForm();
		AForm(const AForm &other);
		AForm& operator = (const AForm &other);

		// Getter
		std::string	const	&getName() const;
		bool	const		&getIsSigned()const;
		int	const			&getGradeSign()const;
		int	const			&getGradeExec()const;

		// Member Function
		void beSigned(Bureaucrat &bureaucrat);
		void execute(Bureaucrat const &executor)const ;

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
		class AFormNotSignedException: public std::exception
		{
			public:
				virtual char const *what(void) const throw();
		};
};
std::ostream& operator<<(std::ostream &str, AForm const &aform);
#endif
