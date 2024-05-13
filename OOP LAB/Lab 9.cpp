#include <iostream>
#include <string>
using namespace std;

// Question 1
class Time {
public:
    Time();
    Time(int, int);
    void setTime(int, int);
    void getTime(int&, int&);
    void printTime();
private:
    int hr;
    int min;
};

class Date {
public:
    Date();
    Date(int day, int month, int year);
    void setDate(int day = 0, int month = 0, int year = 2020);
    void getDate(int& dd, int& mm, int& yy);
    void printDate();
private:
    int month;
    int day;
    int year;
};

class Events {
public:
    Events(int hours = 2, int minutes = 32, int mm = 10, int dd = 15, int yy = 1905, string name = "Christmas");
    void setEventData(int hours, int minutes, int m, int d, int y, string name);
    void printEventData();
private:
    string eventName;
    Time eventTime;
    Date eventDate;
};

Time::Time() {
    hr = 0;
    min = 0;
}

Time::Time(int hour, int minutes) {
    hr = hour;
    min = minutes;
}

void Time::getTime(int& hour, int& minutes) {
    hour = hr;
    minutes = min;
}

void Time::setTime(int hour, int minutes) {
    hr = hour;
    min = minutes;
}

void Time::printTime() {
    int hr, min;
    getTime(hr, min);
    cout << hr << ":";
    if (min == 0 || min < 60)
        cout << "0" << min;
}

Date::Date() {
    day = 0;
    month = 0;
    year = 2020;
}

Date::Date(int day, int month, int year) {
}

void Date::getDate(int& mm, int& dd, int& yy) {
    mm = month;
    dd = day;
    yy = year;
}

void Date::setDate(int mm, int dd, int yy) {
    month = mm;
    day = dd;
    year = yy;
}

void Date::printDate() {
    int dd, mm, yy;
    getDate(dd, mm, yy);
    getDate(mm, dd, yy);
    if (mm < 10)
        cout << mm << "/";
    if (dd < 10)
        cout << dd << "/";
    if (yy < 100) cout << "20";
    cout << year;
    cout << endl;
}

Events::Events(int hour, int minute, int month, int day, int year, string name) : eventTime(hour, minute), eventDate(month, day, year) {
    eventName = name;
}

void Events::setEventData(int hr, int min, int mon, int day, int yr, string name) {
    eventName = name;
    eventTime.setTime(hr, min);
    eventDate.setDate(mon, day, yr);
}

void Events::printEventData() {
    cout << eventName << " Happens to be on : ";
    eventDate.printDate();
    cout << "at ";
    eventTime.printTime();
}

// Question 2
class Engine {
public:
    int cnum;
    Engine(int cnum = 555) {
        this->cnum = cnum;
    }
};

class Wheel {
public:
    string company;
    int pressure;
    Wheel(string company = "Yokohama", int pressure = 14) {
        this->company = company;
        this->pressure = pressure;
    }
};

class Window {
public:
    int num;
    Window(int num = 2) {
        this->num = num;
    }
};

class Door {
public:
    int dr;
    Door(int dr = 2) {
        this->dr = dr;
    }
};

class Car {
public:
    Engine* engine;
    Wheel* wheel;
    Window* window;
    Door* door;
private:
    string name;
    int model;
    Car(string name, int model) {
        this->name = name;
        this->model = model;
    }
    void display() {
        cout << "Chesis Number of Engine is " << engine->cnum << ", Wheels of " << wheel->company << " and pressure is " << wheel->pressure << ", has " << window->num << " windows and has " << door->dr << " doors. Car is " << name << " and is year " << model << " model." << endl;
    }
};

// Question 3
class Address {
public:
    int hnum, street;
    string area, city, state;
    Address(int hnum, int street, string area, string city, string state) {
        this->hnum = hnum;
        this->street = street;
        this->area = area;
        this->city = city;
        this->state = state;
    }
};

class Person {
private:
    Address* address;
public:
    string name;
    Person(string name, Address* address) {
        this->name = name;
        this->address = address;
    }
    void display() {
        cout << "Name: " << name << ", House No.: " << address->hnum << ", Street: " << address->street << ", Area: " << address->area << ", City: " << address->city << ", State: " << address->state << endl;
    }
};

// Question 4
class Teacher {
public:
    string name;
    Teacher(string name) {
        this->name = name;
    }
    ~Teacher() {
        cout << "Teacher Destroyed" << endl;
    }
};

class Student {
private:
    Teacher* teacher;
public:
    string name;
    Student(string name, Teacher* teacher) {
        this->name = name;
        this->teacher = teacher;
    }
    void display() {
        cout << "Student Name: " << name << ", Teacher Name: " << teacher->name << endl;
    }
    void destroyteacher() {
        delete teacher;
    }
};

int main() {
    // Testing Question 1
    Events eve(5, 30, 8, 10, 2005, "Earthquake Day");
    eve.printEventData();
    cout << endl;
    eve.setEventData(5, 30, 8, 10, 2005, "Earthquake Day");
    eve.printEventData();
    cout << endl;

    // Testing Question 2
    class Car {
    public: // Change access specifier to public
        Engine* engine;
        Wheel* wheel;
        Window* window;
        Door* door;
        string name;
        int model;
        Car(string name, int model) {
            this->name = name;
            this->model = model;
        }
        void display() {
            cout << "Chesis Number of Engine is " << engine->cnum << ", Wheels of " << wheel->company << " and pressure is " << wheel->pressure << ", has " << window->num << " windows and has " << door->dr << " doors. Car is " << name << " and is year " << model << " model." << endl;
        }
    };
    Car c = Car("Mustang", 2008);
    c.display();

    // Testing Question 3
    Address add(34, 4, "Millat Town", "Faisalabad", "Punjab");
    Person p1 = Person("Musharib", &add);
    Person p2 = Person("Usama", &add);
    Person p3 = Person("Abdullah", &add);
    p1.display();
    p2.display();
    p3.display();

    // Testing Question 4
    Teacher T1 = Teacher("Muharib");
    Student P1 = Student("Hassan", &T1);
    P1.display();
    P1.destroyteacher();

    return 0;
}
