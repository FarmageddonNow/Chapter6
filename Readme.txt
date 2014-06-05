Program Q1

"Write a grading program for a class with th efollowing grading policies:
a: There are two quizzes, each graded on the basis of 10 points.
b: There is one midterm exam and one final exam, each graded on the basis of 100 points.
c: The final exam counts for 50% of the grade, the midterm counts for 25%, and the two quizzes together count for a total of 25%. (Do not forget to normalize the quiz scores. They should be converted to a percent before they are averaged in.)

Any grade of 90 or more is an A, any grade of 80 or more (but less than 90) is a B, any grade of 70 or more (but less than 80) is a C, any grade of 60 or more (but less than 70) is a D, and any grade below 60 is an F.

The program will read in the student's scores and output the student's record, which consists of two quiz and two exam scores as well as the student's average numeric score fo the entire course and the final letter grade. Define and use a structure for the student record."

Main function

"Write a rational number class. This problem will be revisited in Chapter 8, where operator overloading will make the problem much easier. For now, we will use member functions add, sub, mul, div, and less that each carry out the operations +, -, *, /, and <. For example, a + b will be written a.add(b), and a < b will be written a.less(b). 

Define a class for rational number. A rational number is a "ratio-al" number, composed of two integers with division indicated. The division is not carried out, it is only indicated, as in 1/2, 2/3, 15/32, 65/4, 16/5. You should represent rational numbers by two int values, numerator, and denominator. A principle of abstract data type construction is that constructors must be present to create objects with any legal values. You should provide constructors to make objects out of pairs of int values, this is a constructor with two int parameters. Since every int is also rational number, as in 2/1 or 17/1, you should provide a constructor with a single int parameter.

Provide member functions input and output that take an istream and ostream argument, respectively, and fetch or write rational numbers in the form 2/3 or 37/51 to or from the keyboard (and to or from a file).

Provide member functions add, sub, mul, and div that return a rational value. Provide a function less that returns a bool value. These functions should do the operation suggested by the name. Provide a member function neg that has no parameters and returns the negative of the calling object.

Provide a main function that thoroughly tests your class implementation. Let an sign be carried by the numerator; keep the denominator positive."