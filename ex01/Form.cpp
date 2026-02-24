/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhabin- <muhabin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:53:39 by muhabin-          #+#    #+#             */
/*   Updated: 2026/02/21 00:08:28 by muhabin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _isSigned(0), _gradeSign(30), _gradeExec (50){}
Form::Form(std::string const &name, int const gradeSign, int const gradeExec) : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw (Form::GradeTooHighException());
	if (gradeSign > 150 || gradeExec > 150)
		throw (Form::GradeTooLowException());
}
Form::~Form(){}
Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec){}
Form& Form::operator=(const Form &other)
{
	if (this != &other){
		this->_isSigned = other._isSigned;
	}
	return (*this);
}
//getter
std::string const &Form::getName() const
{
	return (this->_name);
}
bool const &Form::getIsSigned()const{
	return(this->_isSigned);
}
int const &Form::getGradeSign()const
{
	return(this->_gradeSign);
}
int const &Form::getGradeExec()const
{
	return(this->_gradeExec);
}
// Member Funtion
void Form::beSigned(Bureaucrat &bureaucrat)
{
	//if the grade <=  GradeSign it suppose to work
	// so we work the opposite
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw(Form::GradeTooLowException());
	this->_isSigned = true;
}
// Exception Class
char const *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}
char const *Form::GradeTooLowException::what(void)const throw()
{
	return("Grade is too Low");
}
std::ostream& operator<<(std::ostream &str, Form const &form)
{
	return (str << form.getName() << " form, signed: " << form.getIsSigned()
			<< ", sign grade: " << form.getGradeSign()
			<< ", exec grade: " << form.getGradeExec());
}
