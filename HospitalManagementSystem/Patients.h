#ifndef PATIENTS_H
#define PATIENTS_H
#include "Doctors.h"
#include "Feedback.h"
using namespace std;

class Patient : public Doctor
{
private:
    string id;
    string name;
    string password;
    int balance;
    Feedback feedback;

public:
    Patient()
    {
        balance = 3500;
    }

    Feedback getfeedback()
    {
        return feedback;
    }
    string getid()
    {
        return id;
    }
    void setid(string i)
    {
        id = id;
    }
    int getbalance()
    {
        return balance;
    }
    string getname()
    {
        return name;
    }
    string getpassword()
    {
        return password;
    }
    void setpassword(string i)
    {
        password = i;
    }
    void setbalance(int b)
    {
        balance = b;
    }
    void updateBalance()
    {
        int pay = Doctor::getappointment()->getPayment().getPay();
        balance = balance - pay;
    }
    void log()
    {
        string id, temp, line, str, password;
        cout << "Login:" << endl;
        cout << "Enter ID ";
        cin >> id;
        ifstream in;
        in.open("pat.txt");
        while (!in.eof())
        {
            in >> temp;
            in >> str;
            in >> password;
            getline(in, line);
            if (temp == id)
            {
                cout << "User Found!";
                cout << "Enter Password ";
                cin >> temp;
                getline(in, line);
                while (temp != password)
                {
                    cout << "Wrong Password! Enter Again: ";
                    cin >> temp;
                }
                cout << "Login Successful" << endl;
                storePatient(id);
                return;
            }
        }
        cout << "No User Found Please Register." << endl;
        in.close();
        reg();
        return;
    }
    void storePatient(string i)
    {
        string temp, text;
        ifstream in;
        in.open("pat.txt");
        while (!in.eof())
        {
            in >> temp;
            if (temp == i)
            {
                id = temp;
                in >> temp;
                name = temp;
                in >> temp;
                password = temp;
                in >> temp;
                balance = stoi(temp);
            }
            else
                getline(in, text);
        }
    }
    void writepatient(string id)
    {
        string temp, text;
        ifstream in;
        in.open("pat.txt");
        while (!in.eof())
        {
            in >> temp;
            if (temp == id)
            {
                id = temp;
                in >> temp;
                name = temp;
                in >> temp;
                password = temp;
                in >> temp;
                balance = stoi(temp);
            }
            else
                getline(in, text);
        }
    }
    void reg()
    {
        string name, password;
        int id;
        srand(time(0));
        id = rand() % 100;
        cout << "Enter your Name: ";
        cin >> name;
        cout << "Enter your Password: ";
        cin >> password;
        while (password.length() != 8)
        {
            cout << "Password must be of 8 digits.Enter Password ";
            cin >> password;
        }
        cout << "Your Registration id " << id << endl;
        ofstream out;
        out.open("pat.txt", ios::app);
        out << id << " " << name << " " << password << " " << balance << endl;
        out.close();
        storePatient(to_string(id));
        writepatient();
    }
    void display()
    {
        cout << "Patient Details" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Password: " << password << endl;
        cout << "Balance: " << balance << endl;
    }
    void deletePatient()
    {
        string doctor, txt, temp, txt2;
        ifstream in, in2;
        ofstream out;
        in2.open("pat.txt");
        in.open("pat.txt");
        out.open("patient.txt");
        while (getline(in, txt))
        {
            in2 >> temp;
            if (temp != id)
            {
                out << txt << "\n";
                getline(in2, txt2);
            }
        }
        in.close();
        in2.close();
        out.close();
        remove("pat.txt");
        rename("patient.txt", "pat.txt");
    }
    void writepatient()
    {
        ofstream out;
        out.open("pat.txt", ios::app);
        out << endl
            << id << " " << name << " " << password << " " << balance;
        out.close();
    }
};
#endif