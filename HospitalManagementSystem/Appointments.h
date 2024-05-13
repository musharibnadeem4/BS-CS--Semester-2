#ifndef APPOINTMENTS_H
#define APPOINTMENTS_H
#include <iostream>
#include <string>
#include <fstream>
#include "Payment.h"
using namespace std;

class Appointment
{
private:
    string did;
    string pid;
    string time;
    string location;
    string type;
    string date;
    string status = "Pending";
    Payment payment;

public:
    Payment getPayment()
    {
        return payment;
    }

    void setPayment(int charges)
    {
        if (type == "Physical")
            payment.setPay(charges);
        if (type == "Online")
            payment.setPay(charges - (charges * 30 / 100));
    }
    string getpid()
    {
        return pid;
    }

    void setpid(string id)
    {
        pid = id;
    }

    string getdid()
    {
        return did;
    }

    void setdid(string id)
    {
        did = id;
    }

    string GetType()
    {
        return type;
    }

    void SetType(string t)
    {
        type = t;
    }
    void setTime(string t)
    {
        time = t;
    }
    string getStatus()
    {
        return status;
    }

    void setStatus(string s)
    {
        status = s;
    }
    void writeAppointment()
    {
        fstream out;
        out.open("appoint", ios::app);
        out << did << " " << pid << " " << location << " " << type << " " << date << " " << time << " " << status << " " << payment.getPay() << " " << payment.getPaymentType() << endl;
        out.close();
    }
    void bookAppointment(string pay)
    {
        string temp;
        int n;
        cout << "Enter Location ";
        cin >> temp;
        location = temp;
        cout << "\nEnter Appointment Type (Physical/Online) ";
        cin >> temp;
        type = temp;
        cout << "Enter Date: ";
        cin >> temp;
        date = temp;
        cout << "Enter Time ";
        cin >> temp;
        time = temp;
        payment.setPay(stoi(pay));
        payment.chargepayment();
        writeAppointment();
    }
    void storeAppoinment(string d_id, string p_id)
    {
        string temp, doctor, patient, text;
        ifstream in;
        in.open("appoint");
        while (!in.eof())
        {
            in >> doctor;
            in >> patient;
            if (doctor == d_id && patient == p_id)
            {
                did = d_id;
                pid = p_id;
                in >> temp;
                location = temp;
                in >> temp;
                type = temp;
                in >> temp;
                date = temp;
                in >> temp;
                time = temp;
                in >> temp;
                status = temp;
                in >> temp;
                payment.setPay(stoi(temp));
                in >> temp;
                payment.setPaymentType(temp);
                getline(in, text);
                return;
            }
            else
                getline(in, text);
        }
        in.close();
    }
    void display()
    {
        cout << "Appointment Details" << endl;
        cout << "Doctor ID: " << did << endl;
        cout << "Patient ID: " << pid << endl;
        cout << "Location: " << location << " Hospital" << endl;
        cout << "Type: " << type << endl;
        cout << "Date: " << date << " of This Month" << endl;
        cout << "Time: " << time << " o'clock" << endl;
        cout << "Payment: " << payment.getPay() << endl;
        cout << "Payment Type: " << payment.getPaymentType() << endl;
        cout << "Status: " << status << endl;
    }

    bool displayAppointmnet(string id, string type)
    {
        string txt, temp, temp2;
        ifstream in1;
        bool check = false;
        in1.open("appoint");
        while (!in1.eof())
        {
            in1 >> temp;
            in1 >> temp2;
            getline(in1, txt);
            if (type == "doctor")
            {
                cout << temp << endl;
                if (id == temp)
                {
                    check = true;
                    storeAppoinment(temp, temp2);
                    display();
                }
            }
            if (type == "patient")
            {
                if (id == temp2)
                {
                    check = true;
                    storeAppoinment(temp, temp2);
                    display();
                }
            }
        }
        in1.close();
        if (check == false)
        {
            cout << "No Appointment Found.";
            return false;
        }
        else
            return true;
    }
    void deleteAppointment()
    {
        string doctor, txt, temp, temp2, txt2;
        ifstream in, in2;
        ofstream out;
        in2.open("appoint");
        in.open("appoint");
        out.open("appointment.txt");
        while (getline(in, txt))
        {
            in2 >> temp;
            in2 >> temp2;
            if (temp != did && temp2 != pid)
            {
                out << txt << "";
                getline(in2, txt2);
                cout << txt2 << endl;
            }
        }
        in.close();
        in2.close();
        out.close();
        remove("appoint");
        rename("appointment.txt", "appoint");
    }
};
#endif