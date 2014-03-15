#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main(void)
	{
	int a;
	int b;
	int holda;
	int holdb;
	int remainder;
	char pancakes;
	int number;

	// Starting info.
	cout << "Let's use the Euclidean Algorithm to find the greatest common divisor of two\nintegers." << endl;
	cout << "How many divisors are you trying to calculate? \n(For our assignment, the answer\nto this is 3.)\nThe number of divisors I'm trying to calculate is: ";
	cin >> number;
	for (int i = 1 ; i <= number ; i++)
		{
		// Ask user for their integers.
		cout << "\nPlease enter the first integer: ";
		cin >> a;
		cout << "Please enter the second integer: ";
		cin >> b;

		// It says we need a to be bigger than b, but I won't trust that the user will enter it in proper order.
		// Let's make sure a is bigger than b.
		// Simple swap mechanic.
		if (b > a)
			{
			int tmp = a;
			a = b;
			b = tmp;
			}

		holda = a;
		holdb = b;

		// Euclidean Algorithm stuff.
		remainder = a % b;
		if (remainder != 0)
			{
			while (remainder != 0)
				{
				remainder = holda % holdb;
				if (remainder == 0)
					{
					break;
					}
				holda = holdb;
				holdb = remainder;
				}
			}

		// Output the answer.
		const char filepath[] = "C:\\work\\Euclidean_Algorithm_Output.txt";
		const char ErrorMessage[] = "Can't open file location.";
		fstream OutStream(filepath, ios::out);
		if (OutStream.fail())
		  {
		  cerr << ErrorMessage << filepath;
		  cin >> pancakes;
		  exit(-1);
		  }
		OutStream << "The greatest common divisor of " << a << " and " << b << " is " << holdb << ".";
		cout << "The greatest common divisor of " << a << " and " << b << " is " << holdb << ".\n\n";
		}

	// Typical ending.
	cout << "\nYou know what it is. ";
	cin >> pancakes;
	return 0;
	}