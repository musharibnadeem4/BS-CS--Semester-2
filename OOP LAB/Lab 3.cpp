#include <iostream>
using namespace std;

int main() {
    // Problem (a)
    int* number;
    cout << number << endl;
    // Problem (b)
    double* realPtr;
    long* integerPtr;

    char s[] = "this is a character array";
    for (; *s != '\0'; s[26]++){
        cout << *s << ' ';
    }

    char s2[] = "this is a character array";
    for (int i = 0; s2[i] != '\0'; i++)
        cout << s2[i] << ' ';
    short* numPtr, result;

    double x = 19.34;
    double* xPtr = &x;
    cout << *xPtr << endl;
    // Error: None. 

    return 0;
}


//Problem 2:
//Musharib
//i201764
#include <iostream>
using namespace std;

void Print(float *floPtr) 
{
	for (int i = 0; i < 10; i++)
	{
		cout << floPtr[i]  << " ";
	}
}

int main() {

	float* floPtr = new float[10];

	for (int i = 0; i < 10; i++) 
	{
		cout << "Enter " << i << " Element : ";
		cin >> floPtr[i];
	}
	cout << endl;
	Print(floPtr);

	delete floPtr;

}
 
//Problem 3:
//Musharib
//i201764
#include <iostream>
using namespace std;

void Print(float *floPtr) 
{
	for (int i = 0; i < 10; i++)
	{
		cout << floPtr[i]  << " ";
	}
}

int main() {

	float* floPtr = new float[10];

	for (int i = 0; i < 10; i++) 
	{
		cout << "Enter " << i << " Element : ";
		cin >> floPtr[i];
	}
	cout << endl;
	Print(floPtr);

	delete floPtr;

}
 

//Problem 4:
//Musharib
//i201764
#include<iostream>
using namespace std;
int main()
{
	int rows, col;
	cout << "Enter the number of rows: ";
	cin >> rows;
	int** arr = new int*[rows];
	int* colSize = new int[rows];

	for (int i = 0; i < rows; i++)
	{
		cout << "Enter the number of columns for row " << i + 1 << " : ";
		cin >> col;
		arr[i] = new int[col];
		colSize[i] = col;
		cout << "Enter elements for row " << i + 1 << " : ";
		for (int j = 0; j < col; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	cout << "\n\nThe matrix is " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colSize[i]; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < rows; i++)    //To delete the inner arrays
		delete[] arr[i];
	delete[] arr;


}
 

//Problem 5(I):
//Musharib
//i201764
#include <iostream>
using namespace std;

// Function to check sum of digit using recursion
int sum(int num)
{
  if (num == 0)
  return 0;
  return (num % 10 + sum(num / 10));
}

int main()
{
  int num ;
  cout<<"Enter Number "<<endl;
  cin>>num;
  int result = sum(num);
  cout << "Sum of digits in "<< num
  <<" is "<<result << endl;
  
  
  return 0;
}
 

//Problem 5:
//Musharib
//i201764
#include <iostream>
using namespace std;
int fseries(int num) {
   if((num==1)||(num==0)) {
      return(num);
   }else {
      return(fseries(num-1)+fseries(num-2));
   }
}
int main() {
   int num , x=0;
   cout << "Enter the number of terms of series : ";
   cin >> num;
   cout << "\nFibonnaci Series : ";
   while(x < num) {
      cout << " " << fseries(x);
      x++;
   }
   return 0;
}
 









