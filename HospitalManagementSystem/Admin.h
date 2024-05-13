#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <string>
#include <ctime>
#include "Doctors.h"
using namespace std;

class Admin
{
private:
    string name;
    string password;
    string id;

public:
    string getPassword()
    {
        return password;
    }

    void setPassword(string p)
    {
        password = p;
    }

    string getid()
    {
        return id;
    }

    void setid(string i)
    {
        id = i;
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
        out.open("admin.txt", ios::app);
        out << id << " " << name << " " << password << endl;
        out.close();
        storeadmin(to_string(id));
        writeadmin();
    }
    void display()
    {
        cout << "Admin Details";
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Password: " << password << endl;
    }
    void log()
    {
        string id, temp, line, str, password;
        cout << "Login:" << endl;
        cout << "Enter ID ";
        cin >> id;
        ifstream in;
        in.open("admin.txt");
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
                storeadmin(id);
                return;
            }
        }
        cout << "No User Found Please Register." << endl;
        in.close();
        reg();
        return;
    }
    void storeadmin(string id)
    {
        string temp, text;
        ifstream in;
        in.open("admin.txt");
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
            }
            else
                getline(in, text);
        }
        in.close();
    }
    void deleteAdmin()
    {
        string line, temp, line2;
        ifstream in, in2;
        ofstream out;
        in2.open("admin.txt");
        in.open("admin.txt");
        out.open("admins.txt");
        while (getline(in, line))
        {
            in2 >> temp;
            if (temp != id)
            {
                out << line << endl;
                getline(in2, line2);
            }
        }
        in.close();
        in2.close();
        out.close();
        remove("admin.txt");
        rename("admins.txt", "admin.txt");
    }
    void writeadmin()
    {
        ofstream out;
        out.open("admin.txt", ios::app);
        out << endl
            << id << " " << name << " " << password;
        out.close();
    }
};
#endif