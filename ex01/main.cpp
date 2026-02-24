#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << GREEN << "\n=== EX01: FORM TESTS ===\n" << RESET << std::endl;

	// ===== TEST 1: Valid Form Creation =====
	std::cout << YELLOW << "--- TEST 1: Valid Form Creation ---" << RESET << std::endl;
	try
	{
		Form tax("Tax Form", 50, 25);
		std::cout << tax << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	// ===== TEST 2: Invalid Form Creation =====
	std::cout << YELLOW << "\n--- TEST 2: Invalid Form Creation ---" << RESET << std::endl;
	try
	{
		Form invalid1("BadForm", 0, 50);// too high
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	try
	{
		Form invalid2("BadForm", 50, 151);// too low
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	// ===== TEST 3: Successful Signing =====
	std::cout << YELLOW << "\n--- TEST 3: Successful Signing ---" << RESET << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		Form permit("Building Permit", 50, 25);

		std::cout << permit << std::endl;// Before signing
		boss.signForm(permit);
		std::cout << permit << std::endl;// After signing
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	// ===== TEST 4: Failed Signing (Grade Too Low) =====
	std::cout << YELLOW << "\n--- TEST 4: Failed Signing ---" << RESET << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		Form topSecret("Top Secret", 1, 1);

		intern.signForm(topSecret);// Should fail and print reason
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	// ===== TEST 5: Multiple Bureaucrats, Multiple Forms =====
	std::cout << YELLOW << "\n--- TEST 5: Multiple Signing Attempts ---" << RESET << std::endl;
	try
	{
		Bureaucrat alice("Alice", 30);
		Bureaucrat bob("Bob", 100);
		Form form1("Form A", 50, 25);
		Form form2("Form B", 25, 10);

		alice.signForm(form1);// Should succeed (30 <= 50)
		bob.signForm(form1);// Should fail (100 > 50)
		alice.signForm(form2);// Should fail (30 > 25)
		bob.signForm(form2);// Should fail (100 > 25)
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	// ===== TEST 6: Edge Cases =====
	std::cout << YELLOW << "\n--- TEST 6: Edge Cases ---" << RESET << std::endl;
	try
	{
		Bureaucrat perfect("Perfect", 1);
		Form easyForm("Easy", 150, 150);
		Form hardForm("Hard", 1, 1);

		perfect.signForm(easyForm);// Grade 1 signing grade 150 requirement
		perfect.signForm(hardForm);// Grade 1 signing grade 1 requirement (exact match)
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << GREEN << "\n=== ALL TESTS COMPLETED ===\n" << RESET << std::endl;

	return 0;
}
