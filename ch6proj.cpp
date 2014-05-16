#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <cmath>

void pointer_intro();
int q1();
struct grades
{
	double quiz1, quiz2, midterm, final, raw_score;
};
void get_grades(grades& student_grade);
class Counter
{
public:
	Counter(int max);
	Counter();
	void reset();
	void incr1();
	void incr10();
	void incr100();
	void incr1000();
	bool overflow();
	void get_digits();
private:
	int maximum;
	int digits;	
};
int q9();
class Rationals
{
public:
	Rationals();
	Rationals(int whole_number); // Constructor with single int parameter
	Rationals(int a, int b); // Constructors that make objects out of paris of int values
	void add(Rationals b);
	void sub(Rationals b);
	void mul(Rationals b);
	void div(Rationals b);
	bool less(Rationals b);
	void input(std::istream& in); // Takes istream argument and feches rational numbers in form x/y from keyboard, i.e., 'cin'. Public or private?
	void output(std::ostream& out); // Takes ostream argument and writes rational numbrs in form x/y to screen, i.e., 'cout'. Could be private.
private:
	int numerator;
	int denominator;
};

int main()
{
	Rationals a, b;
	a.input(std::cin);
	b.input(std::cin);

	a.output(std::cout);
	std::cout << std::endl;
	b.output(std::cout);

	//Rationals a(5, 10); // Alternately a = Rationals(5, 10)
	//Rationals b(3, 7);

	/*a.add(b);
	std::cout << std::endl;
	a.sub(b);
	std::cout << std::endl;
	a.mul(b);
	std::cout << std::endl;
	a.div(b);
	std::cout << std::endl;
	if (a.less(b) == true)
	{ 
		std::cout << "'a' is less than 'b'" << std::endl;
	}
	else
	{
		std::cout << "'a' is not less than 'b'" << std::endl;
	}*/

	_getch();
	return 0;
}

Rationals::Rationals()
{
	// Default constructor intentionally left blank
}

Rationals::Rationals(int whole_number)
{
	numerator = whole_number;
	denominator = 1;
}

Rationals::Rationals(int a, int b)
{
	numerator = a;
	denominator = b;
}

void Rationals::add(Rationals b)
{
	numerator = (numerator*b.denominator) + (denominator*b.numerator);
	denominator = (denominator*b.denominator);
	if (denominator < 0)
	{
		numerator = numerator*(-1);
		denominator = denominator*(-1);
	}
	output(std::cout);
}

void Rationals::sub(Rationals b)
{
	numerator = (numerator*b.denominator) - (denominator*b.numerator);
	denominator = (denominator*b.denominator);
	if (denominator < 0)
	{
		numerator = numerator*(-1);
		denominator = denominator*(-1);
	}
	output(std::cout);
}

void Rationals::mul(Rationals b)
{
	numerator = (numerator*b.numerator);
	denominator = (denominator*b.denominator);
	if (denominator < 0)
	{
		numerator = numerator*(-1);
		denominator = denominator*(-1);
	}
	output(std::cout);
}

void Rationals::div(Rationals b)
{
	numerator = (numerator*b.denominator);
	denominator = (b.numerator*denominator);
	if (denominator < 0)
	{
		numerator = numerator*(-1);
		denominator = denominator*(-1);
	}
	output(std::cout);
}

bool Rationals::less(Rationals b)
{
	if ((numerator*b.denominator) < (b.numerator*denominator))
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

void Rationals::input(std::istream& in)
{
	char a = '0'; // where 'a' is the character in the stream being read, initialized as zero in order to allow the while loop to run once
	int z; // where 'n' is the power position and 'z' is the ASCII value subtracted by the appropriate constant (48) to return the numerical value
	int neg = 1;

	numerator = 0;
	denominator = 0;

	in.get(a);
	if (a == '-')
	{
		neg = -1;
		in.get(a);
	}
	while (a != '/')
	{
		z = a - 48;
		numerator = (numerator*10) + z;
		in.get(a);
	}
	numerator = numerator*neg;

	a = 0;
	neg = 1;

	in.get(a); // running this again here basically throws away the '/'
	if (a == '-')
	{
		neg = -1;
		in.get(a);
	}
	while (a != '\n')
	{
		z = a - 48;
		denominator = (denominator*10) + z;
		in.get(a);
	}
	numerator = numerator*neg; // b/c specs said that numerator always carries the negative, if any

	// Stream parsing function

}

void Rationals::output(std::ostream& out)
{
	out << numerator << "/" << denominator;

}

int q9()
{
	Counter red1(9999);
	// Above is equivalent to "red1 = Counter();"

	std::cout << "Counter initial number: ";
	red1.get_digits();
	std::cout << std::endl;

	char x = 'm';

	std::cout << "Input 'a' to add 1000, 's' to add 100, 'd' to add 10, 'f' to add 1, 'o' to check overflow, and 'z' to quit." << std::endl;
	while (x != 'z')
	{
		std::cin >> x;
		if (x == 'a')
		{
			red1.incr1000();
		}
		else if (x == 's')
		{
			red1.incr100();
		}
		else if (x == 'd')
		{
			red1.incr10();
		}
		else if (x == 'f')
		{
			red1.incr1();
		}
		else if (x == 'o')
		{
			if (red1.overflow() == true)
			{
				std::cout << "There is overflow. The counter will reset. Bitch." << std::endl;
				red1.reset();
			}
			else
			{
				std::cout << "No overflow. Continue on your way citizen." << std::endl;
			}
		}
		else if (x == 'z')
		{
			return 0;
		}
		else
		{
			std::cout << "Command not recognized. Try again." << std::endl;
		}
		
	}
	_getch();
	return 0;
}

Counter::Counter(int max)
{
	digits = 0;
	maximum = max;
}

Counter::Counter() : digits(0)
{
	// Intentionally left blank
	// Note: Constructor with no arguments is the default constructor and is usually called as a class type without parentheses in main.
}

void Counter::reset()
{
	digits = 0;	
}

void Counter::incr1()
{
	digits++;
	if (Counter::overflow() == true)
	{
		std::cout << "Check overflow." << std::endl;
	}
	else
	{
		std::cout << digits;	
	}
}

void Counter::incr10()
{
	digits = digits + 10;
	if (Counter::overflow() == true)
	{
		std::cout << "Check overflow." << std::endl;
	}
	else
	{
		std::cout << digits;	
	}
}

void Counter::incr100()
{
	digits = digits + 100;
	if (Counter::overflow() == true)
	{
		std::cout << "Check overflow." << std::endl;
	}
	else
	{
		std::cout << digits;	
	}
}

void Counter::incr1000()
{
	digits = digits + 1000;
	if (Counter::overflow() == true)
	{
		std::cout << "Check overflow." << std::endl;
	}
	else
	{
		std::cout << digits;	
	}
}

bool Counter::overflow()
{
	if (digits > maximum)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

void Counter::get_digits()
{
	std::cout << digits << std::endl;
	std::cout << "Maximum count: " << maximum << std::endl;
}

int q1()
{
	grades guy;
	get_grades(guy);

	guy.raw_score = (guy.quiz1 * .125) + (guy.quiz2 * .125) + (guy.midterm * .25) + (guy.final * .5);
	std::cout << "Your raw score is " << guy.raw_score << std::endl;
	if (guy.raw_score >= 90)
	{
		std::cout << "Your final grade is an A." << std::endl;
		_getch();
		exit(0);
	}
	else if ((guy.raw_score >= 80) && (guy.raw_score < 90))
	{
		std::cout << "Your final grade is a B." << std::endl;
		_getch();
		exit(0);
	}
	else if ((guy.raw_score >= 70) && (guy.raw_score < 80))
	{
		std::cout << "Your final grade is a C." << std::endl;
		_getch();
		exit(0);
	}
	else if ((guy.raw_score >= 60) && (guy.raw_score < 70))
	{
		std::cout << "Your final grade is a D." << std::endl;
		_getch();
		exit(0);
	}
	else if ((guy.raw_score < 60))
	{
		std::cout << "You're a failure and disgrace." << std::endl;
		_getch();
		exit(0);
	}
}

void get_grades(grades& student_grade)
{
	std::cout << "Type in your grades for your two quizzes, followed by your midterm grade and your final exam grade." << std::endl;
	std::cin >> student_grade.quiz1 >> student_grade.quiz2 >> student_grade.midterm >> student_grade.final;
}


void pointer_intro()
{
	int i;
	int* a = &i;

	std::cout << "Memory location 'a' is = " << a;

	_getch();
	return;
}