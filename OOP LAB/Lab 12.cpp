//Question 1:
#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
	return a + b;

}
template <typename T2>
T2 mult(T2 a, T2 b) {
	return a * b;
}
int main() {
	int a = 2, b = 4;
	float x = 2.4, y = 4.2;
	double r = 2.465, t = 4.3652;

	cout << "Sum of numbers is :" << add(a, b) << "\n"<<add(x, y) << "\n"<<add(r, t) << endl;
	cout <<"Product of numbers is :"<< mult(a, b) << "\n"<<mult(x, y) <<"\n"<< mult(r, t) << endl;


}


 

//Question 2:

#include <iostream>
using namespace std;

template <typename T>
double ave(T arr[], T size) {
	
	double sum = 0;
	for (int i = 0; i < size; i++)
		sum += arr[i];
	return sum / (double)size;

}
int main() {
	
	int a[] = {1,1,2,2,5};
	long l[] = {145121,545121,65451,65981,548652};
	double d[] = { 1.854,6.325,7.855,9.14,9.256 };
	char chars[] = { 'b','c','r','t','u'};

	cout << "Average of integers is :" << ave<int>(a, 5) << endl;
	cout << "Average of floats is :"<<ave<long>(l, 5) << endl;
	cout<< "Average of doubles is :"<<ave<double>(d, 5) << endl;
	cout << "Average of characters is :"<<ave<char>(chars, 5) << endl;
	return 0;

}

 

//Question 3:

#include <iostream>
using namespace std;
template<typename T>
void swap(int& a,int &  b) {
    T c = a;
    a = b;
    b = c;
}
int main() {
    int a = 5, b = 8;
    float x = 6.2, y = 8.9;
    double r = 3.26589, t = 2.26548;
    long f = 4544561, g = 5452154;
    char c = 'b', d = 'f';
  //  cout<< a, b;

    cout << "Before swapping"  << endl;
    cout << a <<"::" << b << endl;
    cout << x << "::" << y << endl;
    cout << r << "::" << t << endl;
    cout << f << "::" << g << endl;
    cout << c << "::" << d << endl;
 

    cout << "After swapping" << endl;
    swap(a, b);
    swap(x, y);
    swap(r, t);
    swap(f, g);
    swap(c, d);
    cout << a << "::" << b << endl;
    cout << x << "::" << y << endl;
    cout << r << "::" << t << endl;
    cout << f << "::" << g << endl;
    cout << c << "::" << d << endl;
   
    return 0;
}
 
//Question 4:

#include <iostream>
using namespace std;

template <class T>
class Triangle
{
    T length, width;

public:
    Triangle(T l, T w)
    {
        length = l;
        width = w;
    }
    T Area()
    {
        return length * width;
    }
    T Perimeter()
    {
        return 2 * (length + width);
    }
};

int main()
{
    Triangle<int> t1(2, 3);
    Triangle<float> t2(2.5, 3.5);
    Triangle<double> t3(3.5, 4.5);

    cout << "Area in integer value: "<<t1.Area() << endl;
    cout << "Area in float value: " << t2.Area() << endl;
    cout << "Area in double value: " << t3.Area() << endl;

    cout << "Perimeter in integer value: " << t1.Perimeter() << endl;
    cout << "Perimeter in float value: " << t2.Perimeter() << endl;
    cout << "Perimeter in double value: " << t3.Perimeter() << endl;

    return 0;
}
 
//Question 5:

#include <iostream> 
#include<math.h>
using namespace std;

template <class X, class Y>
class Calculator {
public:

    X Addition(X a, Y b)
    {
        return a + b;
    }


    X Subtraction(X a, Y b)
    {
        return a - b;
    }

    X Multiplication(X a, Y b)
    {
        return a * b;
    }

    X Division(X a, Y b)
    {
        return a / b;
    }

    X SquareRoot(X a)
    {
        return sqrt(a);
    }
};

int main()
{
    Calculator<int, int> cInt;
    Calculator<int, float> cIF;
    Calculator<float, float> cFloat;
    Calculator<float, int> cFI;

    cout << "Addition (int , int ): " << cInt.Addition(5, 6) << endl;
    cout << "Addition (float , float )" << cFloat.Addition(5.6, 6.5) << endl;
    cout << "Subtraction (int, int  ) :" << cInt.Subtraction(6, 5) << endl;
    cout << "Subtraction (float, float  ) :" << cFloat.Subtraction(5.8, 6.3) << endl;
    cout << "Multiplcation (int,int)" << cInt.Multiplication(5, 6) << endl;
    cout << "Multiplcation (float,float)" << cFloat.Multiplication(5.1, 6.6) << endl;
    cout << "Division (int, int) :" << cInt.Division(50, 5) << endl;
    cout << "Division (float, float) :" << cFloat.Division(9, 1) << endl;
    cout << "Square root(int)" << cInt.SquareRoot(5) << endl;
    cout << "Square root(int)" << cFloat.SquareRoot(5) << endl;
    cout << "Addition (float , int )" << cFI.Addition(4.2, 5) << endl;
    cout << "Multiplcation (float,int) :" << cFI.Multiplication(5.5, 6) << endl;
    cout << "Subtraction (float, int  ) :" << cFI.Subtraction(7.5, 6) << endl;
    cout << "Division (float, int) :" << cFI.Division(8, 2) << endl;
    cout << "Addition (int , float )" << cIF.Addition(4.2, 5) << endl;
    cout << "Multiplcation (int,int) : " << cIF.Multiplication(5.5, 6) << endl;
    cout << "Subtraction (int , float )" << cIF.Subtraction(7.5, 6) << endl;
    cout << "Division (int, float) :" << cIF.Division(8, 2) << endl;






    return 0;
}

 
