/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhabin- <muhabin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:49:09 by muhabin-          #+#    #+#             */
/*   Updated: 2026/01/28 14:20:00 by muhabin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150){}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name){

	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	if (this != &other){
		this->_grade = other._grade;
	}
	return(*this);
}
Bureaucrat::~Bureaucrat(){}

std::string const &Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}
void Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}
void Bureaucrat::decrementGrade()
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
}

std::ostream& operator<< (std::ostream &str, Bureaucrat const &bureaucrat){

	return(str << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}

char const *Bureaucrat::GradeTooHighException::what(void) const throw(){
	return ("Grade is too High");
}
char const *Bureaucrat::GradeTooLowException::what(void) const throw(){
	return ("Grade is too Low");
}
