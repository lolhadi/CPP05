/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhabin- <muhabin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:39:45 by muhabin-          #+#    #+#             */
/*   Updated: 2026/01/29 15:07:39 by muhabin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void){

	// i want a valid creation(normal Bureaucrat)
	std::cout << GREEN << "---- TEST 1: VALID BUREAUCRAT ----" << RESET << std::endl;
	try
	{
		Bureaucrat bob("BOB", 5);
		std::cout << bob << std::endl;
		// nak cuba incremenet
		bob.incrementGrade();
		std::cout << bob << std::endl;
		// try to decrement
		bob.decrementGrade();
		std::cout << bob << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught:" << e.what() << RESET << std::endl;
	}
	// then i want a invalid(low grade)
	std::cout << GREEN << "---- TEST 2: INVALID BUREAUCRAT(LOW) ----" << RESET << std::endl;
	try
	{
		Bureaucrat notvalid("Ned", 151);
		std::cout << notvalid << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	// i want a invalid(high)
	std::cout << GREEN << "---- TEST 3: INVALID BUREAUCRAT(HIGH) ----" << RESET << std::endl;
	try
	{
		Bureaucrat invalid("Nad", 0);
		std::cout << invalid << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	// then i want a increasing and decreasing until outrange
	std::cout << GREEN << "---- TEST 4: OUTRANGE BUREAUCRAT ----" << RESET << std::endl;
	try
	{
		Bureaucrat Range("high",1);
		std::cout << Range << std::endl;
		Range.incrementGrade();
		std::cout << Range << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	try
	{
		Bureaucrat HRange("LOW" , 150);
		std::cout<< HRange << std::endl;
		HRange.decrementGrade();
		std::cout<< HRange << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
}
