#include<iostream>
using namespace std;

class vehicle {
protected:
	string type;
public:
	string name;
	int model;
	void setname() {
		cout << "Enter Name of vehicle" << endl;
		cin >> name;
	}
	string getname() {
		return name;
	}
	void settype() {
		cout << "Enter Type of vehicle" << endl;
		cin >> type;
	}
	string gettype() {
		return type;
	}
	void setmodel() {
		cout << "Enter Model of vehicle : " << endl;
		cin >> model;
	}
	int getmodel() {
		return model;
	}
	virtual void display() {
		cout << "Name of vehicle : " << name << " \nModel Year of Vehicle : " <<model<<" \nType of Vehicle : "<<type <<endl;
	}


};
class car :public vehicle {
public:
	long int engine_power;
	void setname() {
		cout << "Enter Name of vehicle" << endl;
		cin >> name;
	}
	string getname() {
		return name;
	}
	void setengine_power() {
		cout << "Enter engine Power of vehicle" << endl;
		cin >> engine_power;
	}
	int getengine_power() {
		return engine_power;
	}

	virtual void display() {
		cout << "Name of vehicle:" << name << "Model Year of Vehicle :" << model << "Engine Power of Car" << endl;
	}

};
class truck :public car
{
protected:
	int engine_power;
	void setengine_power() {
		cout << "Enter Name of Truck : " << endl;
		cin >> engine_power;
	}
	int getengine_power() {
		return engine_power;
	}
public:
	virtual void display() {
		cout << "Name of vehicle : " << getname () << "\nModel Year of Vehicle : " << model << "\nEngine power of truck : " << engine_power << endl;
	}
};
class van :public car {
protected:
	int engine_power;
	void setengine_power() {
		cout << "Enter Engine Power of vehicle : " << endl;
		cin >> engine_power;
	}
	int getengine_power() {
		return engine_power;
	}
public:
	virtual void display() {
		cout << "Name of vehicle : " << name << "Model Year of Vehicle : " << model << "Engine power of Truck : " <<engine_power<< endl;
	}
};
class boat :public vehicle {
public:
	virtual void display() {
		cout << "Name of vehicle : " << name << "Model Year of Vehicle : " << model << "Boat has stun hall and gun wheel : " << endl;
	}
};
class safeboat :public boat {
public:
	virtual void display() {
		cout << "Name of vehicle:" << name << "Model Year of Vehicle :" << model << "Boat has stun hall and gun wheel" << endl;
	}
};
class yacht :public boat  {
public:
	virtual void display() {
		cout << "Name of vehicle:" << name << "Model Year of Vehicle :" << model << "Boat has stun hall and gun wheel" << endl;
	}
};
class aircraft:public vehicle {
public:
    string wings;
	string cockpit;
	int landing_gears;
	virtual void display() {
		cout << "Name of vehicle:" << name << "Model Year of Vehicle :" << model << "aerpolane has nothing because its PIA" << endl;
	}

};
class boeing :public aircraft {
public:

	virtual void display() {
		cout << "Name of vehicle:" << name << "Model Year of Vehicle :" << model << "Boeing 227 Emirates" << endl;
	}

};
class helicopter :public aircraft {
public:
	virtual void display() {
		cout << "Name of vehicle:" << name << "Model Year of Vehicle :" << model << "******Helicopter Helicopter****" << endl;
	}
};
int main() {
	//Static Binding
	vehicle v;
	v.setname();
	v.setmodel();
	v.settype();
	v.display();
	car c;
	c.setengine_power();
	c.getname();
	c.display();

	van ven;
	ven.display();
	truck trk;
	trk.display();
	aircraft air;
	air.display();
	helicopter heli;
	heli.display();
	boeing bing;
	bing.display();
	boat bt;
	bt.display();
	yacht yt;
	yt.display();
	safeboat sb;
	sb.display();



	//Dynmaic Binding
	vehicle* ptr;
	ptr = &c;
	ptr->display();
	car* cptr;
	ptr = &ven;
	ptr->display();
	ptr = &trk;
	ptr->display();
	ptr = &bt;
	ptr->display();
	ptr = &sb;
	ptr->display();
	ptr = &yt;
	ptr->display();
	ptr = &air;
	ptr->display();
	ptr = &bing;
	ptr->display();
	ptr = &heli;
	ptr->display();



}


 
