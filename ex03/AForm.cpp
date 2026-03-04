/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhabin- <muhabin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:53:39 by muhabin-          #+#    #+#             */
/*   Updated: 2026/03/02 14:48:52 by muhabin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _isSigned(0), _gradeSign(30), _gradeExec (50){}
AForm::AForm(std::string const &name, int const gradeSign, int const gradeExec) : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw (AForm::GradeTooHighException());
	if (gradeSign > 150 || gradeExec > 150)
		throw (AForm::GradeTooLowException());
}
AForm::~AForm(){}
AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec){}
AForm& AForm::operator=(const AForm &other)
{
	if (this != &other){
		this->_isSigned = other._isSigned;
	}
	return (*this);
}
//getter
std::string const &AForm::getName() const
{
	return (this->_name);
}
bool const &AForm::getIsSigned()const{
	return(this->_isSigned);
}
int const &AForm::getGradeSign()const
{
	return(this->_gradeSign);
}
int const &AForm::getGradeExec()const
{
	return(this->_gradeExec);
}
// Member Funtion
void AForm::beSigned(Bureaucrat &bureaucrat)
{
	//if the grade <  GradeSign it suppose to work
	// so we work the opposite
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw(AForm::GradeTooLowException());
	this->_isSigned = true;
}
void AForm::execute(const Bureaucrat  &executor)const
{
	// safety check
	if (!this->_isSigned)
		throw AForm::AFormNotSignedException();
	// check the bureaucrat grade enought to execute
	if (executor.getGrade() > this->_gradeExec)
		throw AForm::GradeTooLowException();
	// now it safe to call action()
	this->action();

}
// Exception Class
char const *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}
char const *AForm::GradeTooLowException::what(void)const throw()
{
	return("Grade is too Low");
}
char const *AForm::AFormNotSignedException::what(void)const throw()
{
	return("AForm is not Signed!!");
}
std::ostream& operator<<(std::ostream &str, AForm const &aform)
{
	return (str << aform.getName() << " aform, signed: " << aform.getIsSigned()
			<< ", sign grade: " << aform.getGradeSign()
			<< ", exec grade: " << aform.getGradeExec());
}
