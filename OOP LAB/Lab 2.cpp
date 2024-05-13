//Problem1:
//Musharib
//i201764
#include <iostream>
#include<ctime>
using namespace std;

	void sort() {

	int arr[10];
	int i, j;
	srand(time(0));
	int temp;
	for (i = 0; i < 10; i++) 
	{
		arr[i] = 100 + (rand() % 999);
	}
	/*Print Random Number before sorting*/
	cout << "Numbers Before Sorting" << endl;
	for (i = 0; i < 10 ; i++)
	 {
		cout << arr[i];
		cout << endl;
    }
	/*Sorting in ascending  order*/
	for (i = 0; i<10; i++)
	{
		for (j = i + 1; j<10; j++)
		{
			if (arr[i]>arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	cout << "Numbers after sorting " << endl;
	for (i = 0; i < 10; i++)
	{
		cout << arr[i];
		cout << endl;
	}

}

	
int main(){

	sort();
	system("pause");
}
 

//Problem 2:
//Musharib
//i201764
#include <iostream>
using namespace std;
void linearSearch(int arr[]) {
	int x, max, min;

	cout << "\t\t\t\tLinear Searching" << endl;
	cout << "Enter the number to find" << endl;
	cin >> x;

	for (int i = 0; i < 10; i++)
	{
		if (x == arr[i])
		{
			cout << "Number Found At Index:  " << i << endl;
			goto label1;
		}
	}

	cout << "Number Not founnd" << endl;
label1:
	for (int i = 0; i < 10; i++)
	{
		max = arr[0];
		for (i = 0; i < 10; i++)
		{
			if (max < arr[i])
				max = arr[i];
		}
		min = arr[0];
		for (i = 0; i < 10; i++)
		{
			if (min > arr[i])
				min = arr[i];
		}
		cout << "Largest element : " << max << endl;

		cout << "Smallest element : " << min << endl;

	}

}
void binarysearch(int arr[]) 
{
	int start = 0, end = 9, mid, x;
	mid = (start + end) / 2;

	cout << "\t\t\t\Binary Searching" << endl;
	cout << "Enter the number to find" << endl;
	cin >> x;

	while (start <= end)
	{
		if (x > arr[mid])
		{
			start = mid + 1;
		}
		else if (x==arr[mid])
		{
			cout << "Value found at Index " << mid + 1<< endl;
			break;
		}
		else
		{
			end = mid - 1;
		}
		mid = (start + end) / 2;
	}
	if (start > end)
	{
		cout << "Value Not Found" << endl << endl;
	}

	int max, min;
	for (int i = 0; i < 10; i++)
	{
		max = arr[0];
		for (i = 0; i < 10; i++)
		{
			if (max < arr[i])
				max = arr[i];
		}
		min = arr[0];
		for (i = 0; i < 10; i++)
		{
			if (min > arr[i])
				min = arr[i];
		}
		cout << "Largest element : " << max << endl;
		cout << "Smallest element : " << min << endl;
	}

}
int main() {

	int arr[10];

	cout << "Please Enter 10 numbers" << endl;
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}

	linearSearch(arr);
	binarysearch(arr);
	system("pause");
}
 

//Problem 3:
//Musharib
//i201764
#include<iostream>
using namespace std;

int main() {
	int x = 5;
	int y = 15;
	
//Address of first and second value

	int* p1 = &x;
	int* p2 = &y;

	cout << "address of firstvalue	" << p1 << endl;
	cout << "address of secondvalue	" << p2 << endl;
	
//Value pointed by p1

	*p1 = 10;

	cout << " value pointed by p1 " << *p1 << endl;
	
//value pointed by p2 = value pointed by p1

	*p2 = *p1;

	cout << "value pointed by p2 = value pointed by p1 :	" << *p2;
	cout << endl;

// p1 = p2 (address of pointer is copied)

	p1 = p2;

	cout << "address of pointer is copied :	"<<p1 << endl;

// value pointed by p1 = 20

	*p1 = 20;

	cout << "value pointed by p1 : " << *p1 << endl;


// print firstvalue, secondvalue

	*p1 = 10;

	cout << "print firstvalue, secondvalue p1 : " << *p1 << " p2 = " << *p2 << endl;

}
 

//Problem 4:
//Musharib
//i201764
#include <iostream>
using namespace std;

int main(){
	double balance[5] = {1000.0, 2.01, 3.4, 17.0, 50.40};
   double *p;

   p = balance;
  
   cout << "Array values using pointer " << endl;  
   for ( int i = 0; i < 5; i++ ) {
      cout << *(p + i) << endl;
   
}
}
 
//Problem 5:
//Musharib
//i201764
#include <iostream>
#include <string.h>
using namespace std;
int main()
{

    int l;
	char *start_ptr, *end_ptr, ch;  
	char str[100] = "Musharib";
	cout<<"Real String : Musharib"<<endl;

	start_ptr = str;
	end_ptr = str;

	for (int i = 0; i < l - 1; i++)
		end_ptr++;
	for (int i = 0; i < l / 2; i++) {

		/* swap character  */
		ch = *end_ptr;
		*end_ptr = *start_ptr;
		*start_ptr = ch;

		start_ptr++;
		end_ptr--;
	}

     cout<<"String after reverse: "<<str;

	return 0;
}
 

//Problem 6:

//Musharib
//i201764
#include <iostream>
using namespace std;

int main() {

	int arr[] = { 3,9,1,15,3 };
	int* p = arr;


	//Using increment operator
	
	cout << "Values on index :" << endl;
	for (int i = 0; i < 5; i++) {
		cout << *(p+i) << " ";
	}
	cout << endl;
	cout << "Adresses of data :" << endl;
	for (int i = 0; i < 5; i++) {
		cout << &(*(p+i)) << endl;
	}

	cout << endl;
	//Using decrement operator 



	cout << "Values on index :" << endl;
	for (int i = 4; i >= 0; i--)
	{
		cout << *(p + i) << " ";
	}	
	cout << endl;
		cout << "Adresses of data :" << endl;
	
	for (int i = 5; i > 0; i--) 
	{
		cout << &(*(p+i)) << endl;
	}
	
} 

//Problem 7:
//Musharib
//i201764
#include<iostream>
using namespace std;
int CheckPrime(int* x)
{
	int p = *x / 2;
	bool flag=0;
	int i = 0;

	for (i = 2; i <= p; i++)
	{
		if (*x % i == 0)
		{
			cout << "Number is not Prime." << endl;
			return false;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		cout << "Number is Prime." << endl;
	return true;

}

int main() {
	int a = 0;

	cout << "Enter The Number to check prime or not " << endl;
	cin >> a;

	int* x = &a;

	cout << CheckPrime(x);



}
 

//Problem 7II:
//Musharib
//i201764
#include<iostream>
using namespace std;

int main() {
	int x = 5;
	int y = 15;
	
//Address of first, second, third and fourth value

	int* p1 = &x;
	int* p2 = &y;
	int** p3 = &p1;
	int** p4 = &p2;

	cout << "address of firstvalue	" << p1 << endl;
	cout << "address of secondvalue	" << p2 << endl;
	cout << "address of first pointer	" << &p1 << endl;
	cout << "address of second pointer  " << &p2 << endl;
	
//Value pointed by p1

	*p1 = 10;

	cout << " value pointed by p1 " << *p1 << endl;
	
//value pointed by p2 = value pointed by p1

	*p2 = *p1;

	cout << "value pointed by p2 = value pointed by p1 :	" << *p2;
	cout << endl;

// p1 = p2 (address of pointer is copied)

	p1 = p2;

	cout << "address of pointer is copied :	"<<p1 << endl;
	
// p3 = p4 (address of pointer is copied)

    p3 = p4;
    
	cout << "address of pointer is copied : "<< p2 <<endl; 	

// value pointed by p1 = 20

	*p1 = 20;

	cout << "value pointed by p1 : " << *p1 << endl;


// print firstvalue, secondvalue

	*p1 = 10;

	cout << "print firstvalue, secondvalue p1 : " << *p1 << " p2 = " << *p2 << endl;

}
 

//Problem 8:
//Musharib
//i201764
#include <iostream>
using namespace std;

int main()
{
	double i;
	//(a)
	double arr[]={0.0,1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9};
	//(b)
	double *nptr =0 ;
	//(c)
	for(int i=0.0; i>10 ; i++){
		cout<<i<<arr[i]<<"\n";
	}
	//(d)
	nptr = arr;
	//(e)
	for (  i = 0.0; i < 9; i++ ) {
      cout << *(nptr += 1) << endl;
  }
      //(h)
      cout <<"Address at 8th index : "<< &(*(nptr + 8)) << endl;
      //(i)
      cout<<"Adress at index 5 : " << &(*(nptr-=4))<<endl;
      //(j)
      cout<<"Value at index 5 : "<< *(nptr-=4)<<endl;
      
      
}
 

//Problem 9:
//Musharib
//i201764
#include <iostream>
using namespace std;

void DoublePointer(int** matrix,int row,int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = j;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    int row=3, col=3;

    int** matrix;
    matrix = new int* [row];

    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[col];   //3x3 k liye 3 rows hongi aur 3 coloumns ban jayeingy
    }
    DoublePointer(matrix, row, col);
}
 
//Problem 10 :
//Musharib
//i201764
#include <iostream>
using namespace std;
int main()
{
	
   int  *a;
   a=new int[5];
for (int i=3; i<20  ; i+=4){
	a[i]=i;
	cout<<a[i]<<endl;
	void printArray();
}
}
void printArray(int a[],int n){
	for(int i=0;i<n;i++)
      cout<<a[i]<<" ";
  	cout<<endl;
} 
