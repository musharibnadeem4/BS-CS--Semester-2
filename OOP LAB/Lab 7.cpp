//Question 2:

//Musharib
//20i-1764
#include <iostream>
using namespace std;
class Employee {
public:
	string name;
	int age;
	float salary;

	void setname() {
		cout << "Enter Name" << endl;
		cin >> name;
	}
	string getname() {
		return name;
	}

	void setname1() {
		cout << "Enter Second Name : " << endl;
		cin >> name;
	}
	string getname1() {
		return name;
	}
	Employee operator +(Employee obj)
	{
		Employee emp;
		emp.name = this->name + obj.name;
		return emp;

	}

	void setage() {
		cout << "Enter age : " << endl;
		cin >> age;
	}
	int getage() {
		return age;
	}
	void setage1() {
		cout << "Enter second employee's age : " << endl;
		cin >> age;
	}
	int getage1() {
		return age;
	}
	Employee operator <(Employee obj) {
		if (getage() < getage1()) {
			cout << "Age of 1st employee is less than age of employee 2" << endl;
		}
		else {
			cout << "Age of 2nd employee is less than first one" << endl;
		}
		if (getsalary() < getsalary1()) {
			cout << "Age of 1st employee is less than age of employee 2" << endl;
		}
		else {
			cout << "Age of 2nd employee is less than first one" << endl;
		}

	}
	void setsalary() {
		cout << "Enter salary of first employee" << endl;
		cin >> salary;
	}
	float getsalary() {
		return age;
	}

	void setsalary1() {
		cout << "Enter salary of 2nd employee" << endl;
		cin >> salary;
	}
	float getsalary1() {
		return salary;
	}
	};

	int main() {
		Employee obj1;
		Employee obj2;
		Employee e3;
		obj1.setname();
		obj2.setname1();
		obj1.setage();
		obj2.setage1();
		obj1.setsalary();
		obj2.setsalary1();
		cout << "After Concatenation : " << obj1.getname() + obj2.getname1() << endl;
		if (obj1.getage() < obj2.getage1()) {
			cout << "Age of 1st employee is less tan age of employee 2" << endl;
		}
		else {
			cout << "Age of 1st employee is more than age of employee 2" << endl;
		}
		if (obj1.getsalary() < obj2.getsalary()) {
			cout << "Salary of  1st employee is less than 2nd employee's salary" << endl;
		}
		else {
			cout << "Salary of  1st employee is more than 2nd employee's salary" << endl;
		}



		return 0;
}


 

//Question 3:
#include <iostream>
using namespace std;

class factorial {

public:

	int fact;
	
	
	factorial(int num)
	{
		fact = num;
	}
	
	int  operator!(){
		int num = 1;
	
		for (int i = 1; i <=fact; ++i) {
			num =num* i;
		
		}
		return num;
	}
	int getfact() {
		return fact;
	}
};
	int main(){
		int n;
		cout << "enter a number";
		cin >> n;
		factorial f(n);
		cout << !f;
		return 0;
	 }

 

//Question 4:

#include<iostream>
#include<conio.h>
using namespace std;
class matrix
{
private:long matr[5][5];
       int rows;
       int cols;
public:void getdata();
      int operator ==(matrix);
      matrix operator+(matrix);
      matrix operator-(matrix);
      friend ostream& operator << (ostream&, matrix&);
};
int matrix::operator==(matrix ord)
{
    if (rows == ord.rows && cols == ord.cols)
    {
        return 1;
    }
    return 0;
}
void matrix::getdata()
{
    cout << "Enter the number of rows"<<endl;
    cin >> rows;
    cout << "Enter the number of columns"<<endl;
    cin >> cols;
    cout << "Enter the elements of the matrix"<<endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matr[i][j];
        }
    }
}
matrix matrix::operator+(matrix am)
{
    matrix temp;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp.matr[i][j] = matr[i][j] + am.matr[i][j];
        }
        temp.rows = rows;
        temp.cols = cols;
    }
    return temp;
}
matrix matrix::operator-(matrix sm)
{
    matrix temp;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp.matr[i][j] = matr[i][j] - sm.matr[i][j];
        }
        temp.rows = rows;
        temp.cols = cols;
    }
    return temp;
}

ostream& operator <<(ostream& oout, matrix& d)
{
    for (int i = 0; i < d.cols; i++)
    {
        for (int j = 0; j < d.cols; j++)
        {
            oout << d.matr[i][j];
            cout << " ";
        }
        cout << endl;
    }
    return oout;
}
int  main()
{
    matrix mat1;
    matrix mat2;
    matrix mat3;
    matrix mat4;
    mat1.getdata();
    mat2.getdata();
    if (mat1 == mat2)
    {
        mat3 = mat1 + mat2;
        mat4 = mat1 - mat2;
        cout << "Addition of matrices"<<endl;
        cout << "the result is"<<endl;
        cout << mat3;
        cout << "subtraction of matrices"<<endl;
        cout << "The result is "<<endl;
        cout << mat4;
    }
    else
    {
        cout << "order of the input matrices is not identical"<<endl;
    }
    return 0;
}
 
