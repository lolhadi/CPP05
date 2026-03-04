What is the outcome?

1) Exceptions Class:-

	# This Class provide a consistent interface to handle error through throw expression (throw)
		# so instead of using if else statement to create a error we used (try, catch, throw)
	# The standard exception requierements needed:
		# a default constructor(if not provided other constructor)
		# copy constructor
		# copy assign operator
		# descturtor[virtual]
		# what member function - return an explainatory string
	# A lot of Standard Exceptions
		# Logic error: a faulty Logic  (Invalid argument, domain error, length error, out of range)
		# Runtime error: error happen while program is running,maybe by unpredictable behavior(range, overflow, underflow error)
		# Bad Cast: error when casting to a refference failed during runtime
		# Bad Alloc: when failed to allocate storage(Memory)
		# Bad Exception: it signal when an exception escape where it not supposed to.

2) Ex00()

	# class GradeTooHighException: public std::exception
		this class will inherit from exception class
	# 	virtual char const *what(void) const throw();
		# virtual: uses the vtable to use this version of what() instead of the std::exception
		# char const *what(void): return a string of error,(what()= return C-string explaining the error)
		# throw(): here is a restriction, istead of giving error, it will not create an error(its a shield)

3) Ex01()

	# So think this exercise as filling up a goverment aform(but got some requirement)
	# From the subject pdf:
	 :	a class named AForm:
	 	# have a constant name (cannot be modify)
		# has a boolean to detemined whether it sign or not (should starts with not signed)
		# so to signed it should has a grade
		# and to execute the aform it should also have grade
	# This attribute should be in private (so have to have getter and setter)
	# The grade in the AForm also need to follow the rules in Bureaucrat exceptions
	# Need the Overload insertion to prints the the aform's inaformation
	# Member Functions :
		# AForm class gets > beSigned(): when a Bureaucrat tries to signed to aform, it check whether the grade is enough to signed
			if not throw exception
		# Bereaucrat class gets > signAForm(): if the aform is signed successfully should prints something,if not aslo need something with reason

4) Ex02

	# The aform class should change into abstract class and the attributes remains private
	# Need some concrete class
		# ShrubberyCreationAForm: Create text file with ASCII art trees if (sign grade < 141 and exec grade < 137)
		# RobotomyRequestAForm: tries to turn someone into a robot(When executed got 50/50 it will success or failed) (sign grade < 72 && execute grade <45)
		# PresidentalPardonAForm: President tries to pardon someone (sign grade < 25 && execute grade < 5)
	# all the 3 aform takes one parameter:the target
		# Graded are hardcoded in each class , no in constructor, inherite from AForm
	# A Member Function
	# Execute() Function
		# It does Execute the AForm concrete class: Only execute:
			* If The AForm is signed
			* And Have a good enough grade
		# Better Put in AAForm()
			@ if all requirement pass, doAction()(do each stuff)
	# executeAForm() for the bureaucrat
		# if success print something
		# if failed print error message
	# why protected?
		# so in the subject pdf example: it uses the concrete class directly,
		# so only Aform and the concrete class(derived class can use the action())

5) Ex03
	# why the question ask makeForm() to return a Pointer* to a AForm
		# if return by value, it cannot because AForm is an abstract class
		# if return by reference, it will destroyed when the function end.
		# Why Pointer?
			> Because it will create the form with (new) on the heap
			> form still exist after function ends
			> get a pointer to the form
			> need to delete manually later
	# Valid Form Names
		> All lowercase, with spaces
	# Approach
		> Form Name(strings) in array
		> then loop through to find match(switch case)
