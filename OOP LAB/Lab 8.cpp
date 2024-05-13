#include <iostream>
#include <string>
using namespace std;

class persondata {
private:
    string firstname;
    string lastname;
    string address;
public:
    void setfname();
    void setlname();
    void setaddress();
    string getlname();
    string getfname();
    string getaddress();
};

void persondata::setfname() {
    cout << "Enter first name: " << endl;
    cin >> firstname;
}

string persondata::getfname() {
    return firstname;
}

void persondata::setlname() {
    cout << "Enter second name" << endl;
    cin >> lastname;
}

string persondata::getlname() {
    return lastname;
}

void persondata::setaddress() {
    cout << "Enter address " << endl;
    cin >> address;
}

string persondata::getaddress() {
    return address;
}

class customerdata : public persondata {
private:
    int custom_num;
    bool custom_list;
public:
    void setcnum();
    void setcl();
    int getcnum();
    bool getcl();
    void displaycd();
};

void customerdata::setcnum() {
    cout << "Enter customer Number" << endl;
    cin >> custom_num;
}

int customerdata::getcnum() {
    return custom_num;
}

void customerdata::setcl() {
    int temp;
    cout << "Mailing list" << endl;
    cin >> temp;
    if (temp == 1) {
        custom_list = true;
    }
    else {
        custom_list = false;
    }
}

bool customerdata::getcl() {
    return custom_list;
}

void customerdata::displaycd() {
    cout << "Customer First Name : " << getfname() << endl;
    cout << "Customer Last Name" << getlname() << endl;
    cout << "Customer Address " << getaddress() << endl;
    if (custom_list == 1)
        cout << " Mailing list call is True " << endl;
    else cout << "Mailing list call is False" << endl;
}

class prefferedcustom : public customerdata {
public:
    double p_amount;
    void discount_level();
    void setp_amount();
    double getp_amount();
};

void prefferedcustom::setp_amount() {
    cout << "Enter Purchase Amount" << endl;
    cin >> p_amount;
}

double prefferedcustom::getp_amount() {
    return p_amount;
}

void prefferedcustom::discount_level() {
    if (p_amount == 500) {
        cout << "Customer will get 5% discount on future purchases" << endl;
    }
    else if (p_amount == 1000) {
        cout << "Customer will get 6% discount on future purchases" << endl;
    }
    else if (p_amount == 1500) {
        cout << "Customer will get 7% discount on future purchases" << endl;
    }
    else if (p_amount == 2000) {
        cout << "Customer will get 10% discount on future purchases" << endl;
    }
}

class person {
private:
    int age = 20;
    string gender = "Male";
public:
    string name = "Musharib";
};

class employedperson : public person {
public:
    void employee();
    long int nic = 3310258084493;
};

void employedperson::employee() {
    cout << "Hi, I am Employee from Employed class" << endl;
}

class unemployed : public person {
public:
    unemployed();
};

unemployed::unemployed() {
    cout << "Hi, I am unemploy from Unemployed class" << endl;
}

class buisnessman : public employedperson {
public:
    void display();
};

void buisnessman::display() {
    cout << "Hi, I am a businessman" << endl;
}

class vehicle {
private:
    int speed = 0;
    int distance = 0;
public:
    void setspeed();
    int  getspeed();
    void setdistance();
    int getdistance();
    void computeduration();
    void display();
};

void vehicle::setspeed() {
    cout << "Enter Speed: " << endl;
    cin >> speed;
}

int vehicle::getspeed() {
    return speed;
}

void vehicle::computeduration() {
    int d;
    d = speed * distance;
    cout << "Time consumed by vehicle :" << d << endl;
}

void vehicle::setdistance() {
    cout << "Enter Distance: " << endl;
    cin >> distance;
}

int vehicle::getdistance() {
    return distance;
}

class wheelvehicle : public vehicle {
private:
    int wheels;
public:
    void setwheels();
    int getwheels();
    void display();
};

void wheelvehicle::setwheels() {
    cout << "Enter wheels of vehicle" << endl;
    cin >> wheels;
}

int wheelvehicle::getwheels() {
    return wheels;
}

void wheelvehicle::display() {
    cout << "Wheels of vehicle" << getwheels() << endl;
}

class truck : public wheelvehicle {
private:
    int carryingload;
public:
    void setcarryingwheels();
    int getcarryingwheels();
    void display();
};

void truck::setcarryingwheels() {
    cout << "Enter carrying wheels: " << endl;
    cin >> carryingload;
}

int truck::getcarryingwheels() {
    return carryingload;
}

void truck::display() {
    cout << "Load carrying wheels of Vehicle :" << getcarryingwheels() << endl;
}

int main() {
    // Testing customerdata and prefferedcustom classes
    prefferedcustom pc;
    pc.setfname();
    pc.setlname();
    //pc.setcustom_num();
    pc.setaddress();
    pc.setp_amount();
    pc.discount_level();

    // Testing employedperson and buisnessman classes
    buisnessman bm;
    unemployed unemp;
    bm.employee();

    // Testing vehicle, wheelvehicle, and truck classes
    vehicle v;
    wheelvehicle wv;
    truck tk;
    v.setdistance();
    v.setspeed();
    wv.setwheels();
    tk.setcarryingwheels();
    v.computeduration();
    v.display();
    tk.display();

    return 0;
}
