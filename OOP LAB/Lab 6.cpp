#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string id;
    string name;
    string dep;
    string acc;
    int grade;
public:
    Employee() {
        id = "";
        name = "";
        dep = "";
        acc = "";
        grade = 0;
    }

    Employee(string id, string name, string dep, string acc, int grade) {
        this->id = id;
        this->name = name;
        this->dep = dep;
        this->acc = acc;
        this->grade = grade;
    }

    void input() {
        cout << "Enter your id: "; cin >> id;
        cout << "Enter your name: "; cin >> name;
        cout << "Enter your department: "; cin >> dep;
        cout << "Enter your account number: "; cin >> acc;
        cout << "Enter your grade: "; cin >> grade;
        while (grade < 1 || grade > 8) {
            cout << "Enter grade between 1 to 8: "; cin >> grade;
        }
    }

    void display() {
        cout << "Id: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << dep << endl;
        cout << "Account number: " << acc << endl;
        cout << "Grade: " << grade << endl;
    }

    ~Employee() {
        cout << "Destructor called" << endl;
    }
};

class Person {
protected:
    const string name;
    const string dob;
    int static count;
    const int cnic;
public:
    Person(string n, string d, int c) : name(n), dob(d), cnic(c) {
        count++;
    }

    string getdob() {
        return dob;
    }

    int getCNIC() {
        return cnic;
    }

    string getName() {
        return name;
    }

    void display() {
        cout << "Count: " << count << endl;
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "CNIC No.: " << cnic << endl;
    }
};

class MarriedPerson : public Person {
private:
    string marital;
public:
    MarriedPerson(string n, string d, int c, string m) : Person(n, d, c), marital(m) {}

    string getmarital() {
        return marital;
    }

    void display() {
        cout << "Count: " << count << endl;
        cout << "Name: " << getName() << endl;
        cout << "Date of Birth: " << getdob() << endl;
        cout << "CNIC No.: " << getCNIC() << endl;
        cout << "Marital Status: " << marital << endl;
    }
};

class Definition {
public:
    void display() {
        cout << "1. Const variables" << endl;
        cout << "2. Constant function parameters" << endl;
        cout << "3. Constant return type" << endl;
        cout << "4. Pointer to Const variable" << endl;
        cout << "5. Constant Data Members of Class" << endl;
        cout << "6. Constant Member Function of Class" << endl;
        cout << "7. Const pointer" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Value of variable does not change once initialized, ex: const c = 1" << endl;
            cout << "Example : \nconst int x = 4" << endl;
            break;
        case 2:
            cout << "A constant parameter is declared in the case when it is necessary that the value of the transferred object remains unchanged in the body of the called function." << endl;
            cout << "Example : \nvoid SetValue(const bool b) { my_val_ = b; }" << endl;
            break;
        case 3:
            cout << "Returns a constant value, but cannot be updated" << endl;
            cout << "Example : \nconst Object myFunc(){ return myObject}" << endl;
            break;
        case 4:
            cout << "Pointer through which the value of the variable that the pointer points cannot be changed." << endl;
            cout << "Example : \nconst int x { 5 }; // x is now const   \n int* ptr { &x };  \n // compile error: cannot convert from const int* to int*return 0;" << endl;
            break;
        case 5:
            cout << "The const member functions are the functions which are declared as constant in the program. The object called by these functions cannot be modified." << endl;
            cout << "Example :\n datatype function_name const();" << endl;
            break;
        case 6:
            cout << "Const Pointer:" << endl;
            cout << "If you make the pointer a constant, you cannot change the pointer. This means that the pointer always points to the same address, but you can change the value of that address" << endl;
            cout << "Example : " << endl;
            cout << "int x = 4" << endl;
            cout << "int* const ptr = &x;" << endl;
            break;
        }
    }
};

class Account {
private:
    double balance;
    double interestRate;
    double interest;
    int transactions;
    static int count;
public:
    Account(int bal, int interest, int ir, int trs, int count) {
        balance = bal;
        this->interest = interest;
        this->transactions = trs;
        this->count = count;
    }

    void makeDeposit(int deposit) {
        balance = balance + deposit;
    }

    int withdraw(int cash) {
        if (balance < cash) {
            cout << "Sorry! Insufficient balance" << endl;
            return 0; // or any other appropriate value
        }
        balance = balance - cash;
    }

    void findInterest(int interest) {
        interest = (balance / 100) * interestRate;
        balance = balance + interest;
    }

    void Count() {
        count++;
    }

    int getCount() {
        return count;
    }

    double getInterestRate() {
        return interestRate;
    }

    double getBalance() {
        return balance;
    }

    double getInterest() {
        return interest;
    }

    int getTransactions() {
        return transactions;
    }
};

int main() {
    // Testing Employee class
    Employee emp1("001", "John Doe", "Engineering", "ACCT12345", 7);
    emp1.display();

    // Testing Person class
    Person person1("Alice", "01-01-1990", 123456789);
    person1.display();

    // Testing MarriedPerson class
    Account acc(0, 0, 0, 0, 0);
    acc.makeDeposit(1000);
    acc.withdraw(200);
    cout << "Balance: " << acc.getBalance() << endl;
    cout << "Interest: " << acc.getInterest() << endl;

    return 0;
}
