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

	# So think this exercise as filling up a goverment form(but got some requirement)
	# From the subject pdf:
	 :	a class named Form:
	 	# have a constant name (cannot be modify)
		# has a boolean to detemined whether it sign or not (should starts with not signed)
		# so to signed it should has a grade
		# and to execute the form it should also have grade
	# This attribute should be in private (so have to have getter and setter)
	# The grade in the Form also need to follow the rules in Bureaucrat exceptions
	# Need the Overload insertion to prints the the form's information
	# Member Functions :
		# Form class gets > beSigned(): when a Bureaucrat tries to signed to form, it check whether the grade is enough to signed
			if not throw exception
		# Bereaucrat class gets > signForm(): if the form is signed successfully should prints something,if not aslo need something with reason
