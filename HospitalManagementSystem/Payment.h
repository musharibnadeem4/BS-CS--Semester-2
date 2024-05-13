#ifndef PAYMENT_H
#define PAYMENT_H
#include <iostream>
using namespace std;
#include <string>
class Payment
{
private:
    string paymentType;
    int payment;

public:
    string getPaymentType()
    {
        return paymentType;
    }

    void setPaymentType(string type)
    {
        paymentType = type;
    }

    int getPay()
    {
        return payment;
    }

    void setPay(int p)
    {
        payment = p;
    }
    void chargepayment()
    {
        cout << "Select The Payment Method" << endl;
        cout << "1. EasyPaisa" << endl;
        cout << "2. Jazzcash" << endl;
        cout << "3. PayPak" << endl;
        cout << "4. UnionPay" << endl;
        cout << "5. Bank Transfer" << endl;
        cout << "Enter ";
        int num;
        string temp;
        cin >> num;
        switch (num)
        {
        case 1:
            cout << "Enter EasyPaisa Number ";
            cin >> temp;
            cout << payment << " has been charged";
            paymentType = "EasyPaisa";
            break;
        case 2:
            cout << "Enter Jazzcash Number ";
            cin >> temp;
            cout << payment << " has been charged";
            paymentType = "Jazzcash";
            break;
        case 3:
            cout << "Enter PayPak Number ";
            cin >> temp;
            cout << "Enter PIN ";
            paymentType = "PayPak";
            cin >> temp;
            cout << payment << " has been charged";
            break;
        case 4:
            cout << "Enter UnionPay Number ";
            cin >> temp;
            cout << "Enter PIN ";
            cin >> temp;
            cout << payment << " has been charged";
            paymentType = "UnionPay";
            break;
        case 5:
            cout << "Enter Bank Number ";
            cin >> temp;
            cout << payment << " has been charged";
            paymentType = "Bank";
            break;
        default:
            cout << "Invalid";
            break;
        }
        return;
    }
};
#endif