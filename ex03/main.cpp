/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhabin- <muhabin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 08:17:35 by muhabin-          #+#    #+#             */
/*   Updated: 2026/03/04 08:20:46 by muhabin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>  // For srand()
#include <ctime>	// For time()

int main(void)
{
	// Seed random number generator ONCE at start
	srand(time(NULL));

	std::cout << BLUE << "\n╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║   EX02: CONCRETE FORMS TEST SUITE	║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝\n" << RESET << std::endl;

	// ========== TEST 1: ShrubberyCreationForm ==========
	std::cout << YELLOW << "═══ TEST 1: ShrubberyCreationForm ═══\n" << RESET << std::endl;

	try
	{
		Bureaucrat bob("Bob", 137);  // Exactly exec grade
		Bureaucrat intern("Intern", 150);
		ShrubberyCreationForm shrub("garden");

		std::cout << shrub << std::endl;
		std::cout << bob << std::endl;

		// Test 1A: Execute unsigned form
		std::cout << BLUE << "\n--- Attempt to execute unsigned form ---" << RESET << std::endl;
		bob.executeForm(shrub);

		// Test 1B: Sign and execute successfully
		std::cout << BLUE << "\n--- Sign and execute ---" << RESET << std::endl;
		bob.signForm(shrub);
		bob.executeForm(shrub);

		// Test 1C: Low grade bureaucrat tries to execute
		std::cout << BLUE << "\n--- Intern tries to execute ---" << RESET << std::endl;
		intern.executeForm(shrub);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << "\n" << std::string(50, '-') << "\n" << std::endl;

	// ========== TEST 2: RobotomyRequestForm ==========
	std::cout << YELLOW << "═══ TEST 2: RobotomyRequestForm ═══\n" << RESET << std::endl;

	try
	{
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm robot("Bender");

		std::cout << robot << std::endl;
		std::cout << boss << std::endl;

		// Sign the form
		boss.signForm(robot);

		// Execute multiple times to see randomness
		std::cout << BLUE << "\n--- Execute 5 times (watch for randomness) ---" << RESET << std::endl;
		for (int i = 0; i < 5; i++)
		{
			std::cout << "Attempt " << i + 1 << ": ";
			boss.executeForm(robot);
		}
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << "\n" << std::string(50, '-') << "\n" << std::endl;

	// ========== TEST 3: PresidentialPardonForm ==========
	std::cout << YELLOW << "═══ TEST 3: PresidentialPardonForm ═══\n" << RESET << std::endl;

	try
	{
		Bureaucrat president("President", 1);
		Bureaucrat vicePresident("VP", 5);  // Exactly exec grade
		Bureaucrat manager("Manager", 24);  // Can sign but not exec

		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << pardon << std::endl;

		// Test 3A: Sign with manager (grade 24, needs 25)
		std::cout << BLUE << "\n--- Manager tries to sign (grade 24, needs 25) ---" << RESET << std::endl;
		manager.signForm(pardon);

		// Test 3B: Sign with VP (grade 5)
		std::cout << BLUE << "\n--- VP signs ---" << RESET << std::endl;
		vicePresident.signForm(pardon);

		// Test 3C: VP executes (exactly grade 5)
		std::cout << BLUE << "\n--- VP executes (exactly grade 5) ---" << RESET << std::endl;
		vicePresident.executeForm(pardon);

		// Test 3D: President executes
		std::cout << BLUE << "\n--- President executes ---" << RESET << std::endl;
		president.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << "\n" << std::string(50, '-') << "\n" << std::endl;

	// ========== TEST 4: Multiple Forms with One Bureaucrat ==========
	std::cout << YELLOW << "═══ TEST 4: One Bureaucrat, All Forms ═══\n" << RESET << std::endl;

	try
	{
		Bureaucrat superBoss("SuperBoss", 1);

		ShrubberyCreationForm form1("home");
		RobotomyRequestForm form2("Marvin");
		PresidentialPardonForm form3("Zaphod");

		std::cout << BLUE << "--- Signing all forms ---" << RESET << std::endl;
		superBoss.signForm(form1);
		superBoss.signForm(form2);
		superBoss.signForm(form3);

		std::cout << BLUE << "\n--- Executing all forms ---" << RESET << std::endl;
		superBoss.executeForm(form1);
		superBoss.executeForm(form2);
		superBoss.executeForm(form3);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << "\n" << std::string(50, '-') << "\n" << std::endl;

	// ========== TEST 5: Edge Cases ==========
	std::cout << YELLOW << "═══ TEST 5: Edge Cases ═══\n" << RESET << std::endl;

	try
	{
		Bureaucrat weakling("Weakling", 150);
		ShrubberyCreationForm toughForm("fortress");

		std::cout << BLUE << "--- Weakling (150) tries everything ---" << RESET << std::endl;
		weakling.signForm(toughForm);	// Should fail
		weakling.executeForm(toughForm); // Should fail
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << "\n" << BLUE << "╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║ALL TESTS COMPLETED! ✓		   ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝\n" << RESET << std::endl;

	std::cout << GREEN << "Check for 'home_shrubbery' and 'garden_shrubbery' files!" << RESET << std::endl;

	// Add to your main.cpp

std::cout << BLUE << "\n╔════════════════════════════════════════╗" << std::endl;
std::cout << "║		EX03: INTERN TEST SUITE		║" << std::endl;
std::cout << "╚════════════════════════════════════════╝\n" << RESET << std::endl;

// ========== TEST 1: Valid Form Creation ==========
std::cout << YELLOW << "═══ TEST 1: Valid Form Creation ═══\n" << RESET << std::endl;

try
{
	Intern someRandomIntern;
	Bureaucrat boss("Boss", 1);
	AForm* rrf;

	// Create RobotomyRequestForm
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	std::cout << "\n" << std::string(50, '-') << "\n" << std::endl;

	// Create ShrubberyCreationForm
	AForm* scf = someRandomIntern.makeForm("shrubbery creation", "office");
	if (scf)
	{
		std::cout << *scf << std::endl;
		boss.signForm(*scf);
		boss.executeForm(*scf);
		delete scf;
	}

	std::cout << "\n" << std::string(50, '-') << "\n" << std::endl;

	// Create PresidentialPardonForm
	AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
	if (ppf)
	{
		std::cout << *ppf << std::endl;
		boss.signForm(*ppf);
		boss.executeForm(*ppf);
		delete ppf;
	}
}
catch (std::exception &e)
{
	std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
}

std::cout << "\n" << std::string(50, '-') << "\n" << std::endl;

// ========== TEST 2: Invalid Form Name ==========
std::cout << YELLOW << "═══ TEST 2: Invalid Form Name ═══\n" << RESET << std::endl;

try
{
	Intern intern;
	AForm* unknown;

	unknown = intern.makeForm("coffee making", "intern");
	if (unknown == NULL)
		std::cout << "Form creation failed as expected" << std::endl;

	unknown = intern.makeForm("ROBOTOMY REQUEST", "Bender");  // Wrong case
	if (unknown == NULL)
		std::cout << "Form creation failed (case sensitive)" << std::endl;
}
catch (std::exception &e)
{
	std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
}

std::cout << GREEN << "\n✓ All Intern tests completed!\n" << RESET << std::endl;
	return 0;
}
