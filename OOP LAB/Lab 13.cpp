//Question1:
//(a):
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter two integers: ";
    cin >> a;
    cin >> b;
    try
    {
        if (b == 0)
        {
            throw "Divide by zero is not possible";
        }
        else
        {
            cout << a / b;
        }
    }
    catch (char* m)
    {
        cout << m;
    }
    return 0;
}
 
//(b):
#include<iostream>
using namespace std;

int main()
{
    float str = 1.5;
    try
    {
        throw 1;
    }
   catch (int i)
    {
       cout << "Exception thrown: " << i << endl;
    }
    try
    {
        throw str;
    }
    catch (float f)
    {
        cout << "Exception thrown: " << f << endl;
    }
    try
    {
        throw "abc";
    }
    catch (const char* s)
    {
        cout << "Exception thrown: " << s << endl;
    }
    try
    {
        throw 'a';
    }
    catch (char c)
    {
        cout << "Exception thrown: " << c << endl;
    }
    return 0;
}

 
//Question 2:

#include<iostream>
using namespace std;

void addFractions(int num1, int den1, int num2, int den2, int result_num, int result_den)
{
	try {
		cout << "Enter first fraction: ";
		cin >> num1 >> den1;
		throw invalid_argument("Entered Number is not Valid");
		cout << "Enter second fraction: ";
		cin >> num2 >> den2;
		throw invalid_argument("Entered Number is not Valid");
		result_num = num1 * den2 + num2 * den1;
		result_den = den1 * den2;
		cout << "The sum of the two fractions is " << result_num << "/" << result_den;
	}
	catch (exception eObj)
	{
		cout << "Exception: " << eObj.what() << endl;
	}
}
void SubFraction(int num1, int den1, int num2, int den2, int result_num, int result_den)
{

	try {
		cout << "Enter first fraction: ";
		cin >> num1 >> den1;
		throw invalid_argument("Invalid Input");
		cout << "Enter second fraction: ";
		cin >> num2 >> den2;
		throw invalid_argument("Invalid Input");
		result_num = num1 * den2 - num2 * den1;
		result_den = den1 * den2;
		cout << "To subtract the equation we get:  " << result_num << "/" << result_den;
	}
	catch (exception eObj)
	{
		cout << "Exception: " << eObj.what() << endl;
	}
}




void multiplyFractions(int num1, int den1, int num2, int den2, int result_num, int result_den)
{

	cout << "Enter first fraction: ";
	cin >> num1 >> den1;

	cout << "Enter second fraction: ";
	cin >> num2 >> den2;

	result_num = num1 * num2;
	result_den = den1 * den2;

	cout << "To subtract the equation we get:  " << result_num << "/" << result_den;
}

void divideFractions(int num1, int den1, int num2, int den2, int result_num, int result_den)
{
	
	cout << "Enter first fraction: ";
	cin >> num1 >> den1;

	cout << "Enter second fraction: ";
	cin >> num2 >> den2;
	try {
		if (den1 == 0 || den2 == 0) {
			throw exception("Cannot divide by zero.");

		}
		result_num = num1 * den2;
		cout << result_num << endl;
		result_den = den1 * num2;
		cout << result_den << endl;
		cout << "Division of two Fraction we get: " << result_num << "/" << result_den << endl;
	}
	catch (exception eObj)
	{
		cout << "Exception: " << eObj.what() << endl;
	}
}
void multFractions(int num1, int den1, int num2, int den2, int result_num, int result_den)
{
	try {

		cout << "Enter first fraction: ";
		cin >> num1 >> den1;
		throw invalid_argument("Entered Number is not valid");
		cout << "Enter second fraction: ";
		cin >> num2 >> den2;
		throw invalid_argument("Entered Number is not valid");
		result_num = num1 * num2;
		result_den = den1 * den2;

		cout << "Multiplication of two Fraction we get: " << result_num << "/" << result_den;
	}
	catch (invalid_argument& obj)
	{
		cout << obj.what() << endl;
	}

}
void display(int& choice) {
	cout << "Enter what which operations do you want to perform" << endl;
	cout << " 1) Addition" << endl;
	cout << " 2) Subtraction" << endl;
	cout << " 3) Division" << endl;
	cout << " 4) Multiplication" << endl;
	cin >> choice;
}

int main()
{
	int num1 = 0, num2 = 0, den1 = 0, den2 = 0;
	int result_num = 0;
	int result_den = 0;
	int choice;

	display(choice);
	switch (choice)
	{
	case 1:
		addFractions(num1, den1, num2, den2, result_num, result_den);
		break;
	case 2:
		SubFraction(num1, den1, num2, den2, result_num, result_den);
		break;
	case 3:
		divideFractions(num1, den1, num2, den2, result_num, result_den);
		break;
	case 4:
		multFractions(num1, den1, num2, den2, result_num, result_den);
		break;
		return 0;
	}
}

 

//Question 3:
#include <iostream>
using namespace std;
int main() {
	int lowerLimit = 50;
	try
	{
		cout << "Entering the try block." << endl;
		if (lowerLimit < 100)
			throw exception("Lower limit violation.");
		cout << "Exiting the try block." << endl;
	}
	catch (exception eObj)
	{
		cout << "Exception: " << eObj.what() << endl;
	}
	cout << "After the catch block" << endl;
}
 
#include <iostream>
using namespace std;
int main() {
	int lowerLimit = 150;
	try
	{
		cout << "Entering the try block." << endl;
		if (lowerLimit < 100)
			throw exception("Lower limit violation.");
		cout << "Exiting the try block." << endl;
	}
	catch (exception eObj)
	{
		cout << "Exception: " << eObj.what() << endl;
	}
	cout << "After the catch block" << endl;
}
 

//Question 4:
#include <iostream>
using namespace std;

int main()
{
    double feet, inches, centimeter;
    bool invalidInput = true;
    while (invalidInput)
    {
        try
        {
            cout << "Enter a length in feet and inches: ";
            cin >> feet;
            cin >> inches;
            if (feet < 0 || inches < 0 )
            {
                throw invalid_argument("Negative value exception");
            }
           invalidInput = false;
        }
        catch (invalid_argument& obj)
        {
            cout << obj.what() << endl;
        }
    }
    centimeter = (feet * 12) * (2.54 + inches) * 2.54;
    cout << "The length in centimeters is " << centimeter << endl;
    return 0;
}

 
//Question 5:
#include<iostream>
using namespace std;
class invalidHr
{
public:
    invalidHr()
    {
        cout << "Invalid Hour are entered" << endl;
    }
};
class invalidMin
{
public:
    invalidMin()
    {
        cout << "Invalid Minutes  are entered" << endl;
    }
};
class invalidSec
{
public:
    invalidSec()
    {
        cout << "Invalid seconds are entered" << endl;
    }
};

int main()
{
    int h, m, s;
    cout << "Enter Time in h/min/sec format" << endl;
    cin >> h >> m >> s;
    try
    {
        if (h < 0 || h>12)
        {
            throw invalidHr();
        }
        else if (m < 0 || m>60)
        {
            throw invalidMin();
        }
        else if(s < 0 || s >60)
        {
            throw invalidSec();
        }
        else {
            cout << "Time is " << h+12 << ":" << m << ":" << s << endl;
        }
    }
    catch (invalidHr h){}
    catch (invalidMin m) {}
    catch(invalidSec s){}
}
 

//Question 6:
#include<iostream>
using namespace std;
class invalidDay
{
public:
    invalidDay()
    {
        cout << "Invalid Day is entered" << endl;
    }
};
class invalidMonth
{
public:
    invalidMonth()
    {
        cout << "Invalid Month is entered" << endl;
    }
};
class invalidyear {
public:
    invalidyear() {
        cout << "Invalid year is entered" << endl;
    }
};
int main()
{
    int d, m, y;
    cout << "Enter Birth Date in dd/mm/yyyy format" << endl;
    cin >> d >> m >> y;
    try
    {
        if (d < 0 || d>31)
        {
            throw invalidDay();
        }
        else if (m < 0 || m>12)
        {
            throw invalidMonth();
        }
        else if (y < 0 ) {
            throw invalidyear();
        }
        else
        {
            cout << "Date of Birth is " << d << "/" << m << "/" << y << endl;
        }
    }
    catch (invalidDay d) {}
    catch (invalidMonth m) {}
    catch (invalidyear y) {}
}
 

