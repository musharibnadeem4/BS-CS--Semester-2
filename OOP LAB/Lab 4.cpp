//Problem 1:
//Musharib
//i201764
#include <iostream>
using namespace std;

void hanoi(int x,char from_peg,char to_peg, char temp_peg)
{
  if (x == 1)
  {
    return;
  }
  hanoi(x - 1, from_peg, temp_peg, to_peg);
  cout << "Move disk " << x << " from rod " << from_peg <<
                " to rod " << to_peg << endl;
  hanoi(x - 1, temp_peg, to_peg, from_peg);
}
int main()
{
  int x = 4; 
  hanoi(x, 'C', 'B', 'D'); 
  return 0;
  system("pause");
}
 

//Problem 2:
#include <iostream>
using namespace std;

struct Car
{
char carName[20];
char carModel[20];
int yearModel;
double cost;
};
Car c1={"Toyota","Mustang",2000,25000};
Car c2={"City","Honda",2000,15000};
	
int main(){
	cout<<"Data through CAR 1: "<<endl;
    cout<<"Name :"<<c1.carName<<endl;
    cout<<"Car Model :"<<c1.carModel<<endl;
    cout<<"Make Year:"<<c1.yearModel<<endl;
    cout<<"Cost :"<<c1.cost<<endl;
    cout<<"Data through CAR 2: "<<endl;
     cout<<"Name :"<<c2.carName<<endl;
    cout<<"Car Model :"<<c2.carModel<<endl;
    cout<<"Make Year:"<<c2.yearModel<<endl;
    cout<<"Cost :"<<c2.cost<<endl;
    if(c1.cost>c2.cost)
    cout<<"Car with highest cost is :"<<c1.carName<<endl;
    else
    cout<<"Car with highest cost is :"<<c2.carName<<endl;
    
    return 0;
    
}
 

//Problem 3:
//Musharib
//Nadeem
#include <iostream>
using namespace std;

struct Distance
{	
    int feet;
	float inches;
};
Distance d1;
Distance d2= {10, 5.25};


int main()
{
	Distance sum;
	Distance d3;
	cout<<"Enter distance **Feets**"<<endl;
	cin>>d1.feet;
	cout<<"Enter distance **Inches**"<<endl;
	cin>>d1.inches;
	cout<<"d1("<<d1.feet<<","<<d2.feet<<")"<<endl;
	sum.feet = d1.feet + d2.feet;
	
    sum.inches = d1.inches + d2.inches;
     if(sum.inches > 12) {
        // extra feet
        int temp = sum.inches / 12;

        sum.feet += temp;
        sum.inches -= (temp * 12);
      cout << endl << "Sum of distances = " << sum.feet << " feet  " << sum.inches << " inches";
      d3.feet = sum.feet;
      d3.inches = sum.inches;

      cout << endl << "d3(" << d3.feet << "," << d3.inches << ")" << endl;

    return 0;
}		
}
 

//Problem 4:
//Musharib
//i201764
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct SDM {
	string name;
	double cost;
	int number;
};

int main()
{

	SDM drinks[4];

	drinks[0].name = "Cola";
	drinks[0].cost = 0.75;
	drinks[0].number = 20;
	drinks[1].name = "Root Beer";
	drinks[1].cost = 0.75;
	drinks[1].number = 20;
	drinks[2].name = "Grape Soda";
	drinks[2].cost = 0.80;
	drinks[2].number = 20;
	drinks[3].name = "Cream Soda";
	drinks[3].cost = 0.80;
	drinks[3].number = 20;

	double money = 0.0;
	double change = 0.0;
	double total_money = 0.0;

	bool flag = 1;
	while (flag)
	{
		for (int i = 0; i < 4; i++)
		{
			cout << i+1 << " " << drinks[i].name << endl;
		}
		cout << "1.If you want to quit press 1\n2.If you want to pick a drink, Pick by number\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 0:
			goto label1;
		case 1:
			cout << "Enter Money You Want to Put in Machine" << endl;
			cin >> money;
			while (money < 0 || money < 1)
			{
				cin >> money;
			}
			int x = choice;
			cout << "You have opted " << drinks[x].name << endl;
			total_money = total_money + drinks[x].cost;
			change = money - drinks[x].cost;
			cout << "Your Change is " << change;
			drinks[x].number--;
			cout << "Total Number of Drinks of " << drinks[x].name << " left are : " << drinks[x].number << endl;
		}
		cout << "Do you want to visit Machine Again Press 1 else Press 0";
		cin >> flag;
	}
	label1:
	cout << "Total Money Machine Earned Today : " << total_money;
return 0;
}
 
//Problem 5(I):
//Musharib
//i201764
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Players
{
	string name;
	int runs;
	int hits;
};
void displayMenu()
{
	cout << "1.Search and Update Player Contents\n2.Do You Want to Store it in File : " << endl;
}
void input(Players p1[3])
{
	for (int i = 0; i < 3; i++)
	{
		cout << "-------Enter Player " << i << " Data-------------" << endl;
		cout << "Enter the Name of " << i << " Player :" << endl;
		cin >> p1[i].name;
		cout << "Enter the Runs of " << i << " Player :" << endl;
		cin >> p1[i].runs;
		cout << "Enter the Hits of " << i << " Player :" << endl;
		cin >> p1[i].hits;
	}
}
void output(Players p1[3])
{
	for (int i = 0; i < 3; i++)
	{
		cout << "-------Player " << i << " Data-------------" << endl;
		cout << "The Name of " << i << " Player " << endl;
		cout << p1[i].name;
		cout << endl;
		cout << "The Runs of " << i << " Player " << endl;
		cout << p1[i].runs;
		cout << endl;
		cout << "The Hits of " << i << " Player " << endl;
		cout << p1[i].hits;
		cout << endl;

	}
}
void search(Players p1[3],string tempname)
{
	for (int i = 0; i < 3; i++)
	{
		if (tempname == p1[i].name)
		{
			cout << "Enter the Updated Name of " << i << " Player :" << endl;
			cin >> p1[i].name;
			cout << "Enter the Updated Runs of " << i << " Player :" << endl;
			cin >> p1[i].runs;
			cout << "Enter the Updated Hits of " << i << " Player :" << endl;
			cin >> p1[i].hits;

		}
	}
}
int main()
{
	Players p1[3];
	string tempname;

	input(p1);
	
	cout << endl;

	output(p1);

	displayMenu();

	int choice;
	cin >> choice;
	
	switch (choice)
	{ 
		case 1:
		{
			cout << "Enter the name of Player you want to Update : " << endl;
			cin >> tempname;

			search(p1, tempname);
			
		}
		case 2:
		{
			cout << "Enter Y to Store it in File and N not to" << endl;
			char x;
			cin >> x;
			if (x == 'Y' || x == 'y')
			{
				cout << "Data Stored in File" << endl;
			}
			else
				cout << "Data not stored" << endl;
		}
	}
}
 
 
//Problem 5(II):
//Musharib
//i201764
#include <iostream>
#include<string>
using namespace std;
struct Address {

int house_num;
int street_num;
char city[20];
char province[20];
};
struct student
{
string name;
int age;
int gpa;
Address address;
};
student input();
void output(student s);
int main() {

int size;
cout << "Enter size :" << endl;
cin >> size;
// cout << "Enter size :" << endl;
student *ptr = new student[size];


for (int i = 0; i < size; i++) {
cout << "Enter data of Student " << i + 1<<endl;
cout<<endl;
ptr[i] = input();
cout << endl;
}
for (int i = 0; i < size; i++) {
cout << " Data of Student " << i + 1 << endl;
cout<<endl;

output(ptr[i]);
cout << endl;
}

system("pause");
return 0;
}
student input() {
student s;
cout << "Enter name of student :" << endl;
cin >> s.name;
cout << "Enter House Number :" << endl;
cin >> s.address.house_num;
cout << "Enter street Number :" << endl;
cin >> s.address.street_num;
cout << "Enter city Name :" << endl;
cin>>s.address.city;
cout << "Enter Province Name :" << endl;
cin>>s.address.province, 20;
cout << "Enter Age of student" << endl;
cin >> s.age;
cout << "Enter GPA of student" << endl;
cin >> s.gpa;
return s;
}
/*Printing out details*/
void output(student s) {
cout << "Name of student :" << s.name << endl;
cout << "House Num :" << s.address.house_num << endl;
cout << "Street Num :" << s.address.street_num << endl;
cout << "City  :" << s.address.city << endl;
cout << "Province  :" << s.address.province << endl;
cout << "Age  :" << s.age << endl;
cout << "GPA  :" << s.gpa << endl;
}
 
 
    
   
    
    
    
    

	
	



