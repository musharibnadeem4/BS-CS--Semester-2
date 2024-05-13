#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "Doctors.h"
#include "Appointments.h"
#include "Payment.h"
#include "Patients.h"
#include "Feedback.h"
#include "Admin.h"

using namespace std;

int main()
{
    Doctor doctor;
    Admin admin;
    Patient patient;
    Appointment appointment;
    Payment payment;
    Feedback feedback;
    int opt = 9;
    while (opt != 0)
    {
    MainMenu:
        cout << "Hospital Management System" << endl;
        cout << "1. Doctor" << endl;
        cout << "2. Patient" << endl;
        cout << "3. Admin" << endl;
        cout << "0. Exit" << endl;
        cout << "\tEnter your opt: ";
        cin >> opt;
        if (opt == 0)
        {
            cout << "Bye Bye";
            break;
        }
        else if (opt == 1)
        {
        DoctorLogin:
            cout << "1. Login" << endl;
            cout << "2. Register" << endl;
            cout << "\tEnter your opt: ";
            int temp;
            cin >> temp;
            switch (temp)
            {
            case 1:
                doctor.log();
                break;
            case 2:
                doctor.reg();
                break;
            default:
                cout << "Enter a Valid opt";
                goto DoctorLogin;
                break;
            }
        DoctorMenu:
            cout << "1. Change Time" << endl
                 << "2. Change Fee" << endl
                 << "3. Change Location" << endl
                 << "4. Delete Time" << endl
                 << "5. Display Detail" << endl
                 << "6. Dispplay Appointments" << endl
                 << "7. Change Status" << endl
                 << "8. Logout" << endl
                 << "\tEnter your opt: ";
            int opte, n1, n2;
            string str1, str2;
            cin >> opte;
            switch (opte)
            {
            case 8:
                goto MainMenu;
                break;
            case 1:
                cout << "Enter New Time ";
                cin >> str1;
                cout << "Enter END Time ";
                cin >> str2;
                doctor.setstime(str1);
                doctor.setetime(str2);
                doctor.deleteDoctor();
                doctor.writeDoctor();
                break;
            case 4:
                doctor.setstime("0");
                doctor.setetime("0");
                doctor.deleteDoctor();
                doctor.writeDoctor();
                cout << "Deleted";
                break;
            case 2:
                cout << "Enter Fee ";
                cin >> str1;
                doctor.setfee(str1);
                doctor.deleteDoctor();
                doctor.writeDoctor();
                cout << "Updated";
                break;
            case 3:
                cout << "Enter City name ";
                cin >> str1;
                cout << "Enter hospital name ";
                cin >> str2;
                doctor.setarea(str1);
                doctor.sethospital(str2);
                doctor.deleteDoctor();
                doctor.writeDoctor();
                cout << "Updated";
                break;
            case 5:
                doctor.display();
                break;
            case 6:
                doctor.getappointment()->displayAppointmnet(doctor.getid(), "doctor");
                break;
            case 7:
                cout << "Enter id of patient ";
                cin >> str1;
                doctor.getappointment()->storeAppoinment(doctor.getid(), str1);
                doctor.getappointment()->setStatus("Confirmed");
                cout << "Status Confirmed" << endl;
                doctor.getappointment()->display();
                doctor.getappointment()->deleteAppointment();
                doctor.getappointment()->writeAppointment();
                cout << endl;
                break;
            default:
                cout << "Invalid";
                goto DoctorMenu;
                break;
            }
            goto DoctorMenu;
        }
        else if (opt == 2)
        {
        PatientLogin:
            cout << "1. Login" << endl;
            cout << "2. Register" << endl;
            cout << "\tEnter ";
            int temp;
            cin >> temp;
            switch (temp)
            {
            case 1:
                patient.log();
                break;
            case 2:
                patient.reg();
                break;
            default:
                cout << "Invalid";
                goto PatientLogin;
                break;
            }
        PatientMenu:
            cout << "1. Change Password" << endl;
            cout << "2. Details" << endl;
            cout << "3. Display Appointments" << endl;
            cout << "4. Change Balace" << endl;
            cout << "5. Seach Doctor" << endl;
            cout << "6. Book Appointment" << endl;
            cout << "7. Edit time" << endl;
            cout << "8. Cancel Appointment" << endl;
            cout << "9. Give Feedback" << endl;
            cout << "10. Logout" << endl;
            cout << "\tEnter your opt: ";
            int opte, num, num2;
            string str1, str2;
            cin >> opte;
            switch (opte)
            {
            case 10:
                goto MainMenu;
                break;
            case 1:
                cout << "Current Password = " << patient.getpassword();
                cout << "Enter New ";
                cin >> str1;
                patient.setpassword(str1);
                patient.deletePatient();
                patient.writepatient();
                cout << "Password changed";
                break;
            case 2:
                patient.display();
                break;
            case 3:
                patient.getappointment()->displayAppointmnet(patient.getid(), "patient");
                break;
            case 4:
                cout << "Enter Amount to add ";
                cin >> num;
                patient.setbalance(patient.getbalance() + num);
                cout << "Balance Updated" << endl;
                patient.deletePatient();
                patient.writepatient();
                break;
            case 5:
                cout << "1. By Speciality" << endl;
                cout << "2. By Area" << endl;
                cout << "3. By Hospital" << endl;
                cout << "Eneter ";
                cin >> num2;
                cout << "Enter Keyword ";
                cin >> str1;
                if (num2 == 1)
                    patient.searchDoctor(str1, "speciality");
                else if (num2 == 2)
                    patient.searchDoctor(str1, "area");
                else if (num2 == 3)
                    patient.searchDoctor(str1, "hospital");
                break;
            case 6:
                cout << "Enter Doctor ID ";
                cin >> str1;
                doctor.storeDoctor(str1);
                patient.getappointment()->setdid(str1);
                patient.getappointment()->setpid(patient.getid());
                patient.getappointment()->bookAppointment(doctor.getcharges());
                patient.updateBalance();
                cout << "Appointment Booked";
                patient.getappointment()->display();
                break;
            case 7:
                cout << "Enter Doctor ID ";
                cin >> str1;
                doctor.storeDoctor(str1);
                patient.getappointment()->storeAppoinment(str1, patient.getid());
                cout << "Enter New Time ";
                cin >> str2;
                patient.getappointment()->setTime(str2);
                patient.getappointment()->deleteAppointment();
                patient.getappointment()->writeAppointment();
                break;
            case 8:
                cout << "Enter Doctor ID ";
                cin >> str1;
                doctor.storeDoctor(str1);
                patient.getappointment()->storeAppoinment(str1, patient.getid());
                patient.getappointment()->deleteAppointment();
                break;
            case 9:
                cout << "Enter Doctor ID ";
                cin >> str1;
                doctor.storeDoctor(str1);
                patient.getappointment()->storeAppoinment(str1, patient.getid());
                cout << "Enter Feedback ";
                cin >> str2;
                cout << "Give Rating ";
                cin >> num;
                feedback.setFeed(str2);
                feedback.setRating(num);
                feedback.writeFeedback(doctor.getid(), patient.getid());
                patient.updateRating(str1, num);
                break;
            default:
                cout << "Invalid";
                goto PatientLogin;
                break;
            }
            goto PatientMenu;
        }
        else if (opt == 3)
        {
        AdminLogin:
            cout << "1. Login" << endl;
            cout << "2. Register" << endl;
            cout << "\tEnter your opt: ";
            int temp;
            cin >> temp;
            switch (temp)
            {
            case 1:
                admin.log();
                break;
            case 2:
                admin.reg();
                break;
            default:
                cout << "Invalid";
                goto AdminLogin;
                break;
            }
        AdminMenu:
            cout << "1. Change Password" << endl;
            cout << "2. View Details" << endl;
            cout << "3. Delete a Docotr" << endl;
            cout << "4. Logout" << endl
                 << "\tEnter your opt: ";
            int opte, num;
            string str1, str2;
            cin >> opte;
            switch (opte)
            {
            case 4:
                goto MainMenu;
                break;
            case 1:
                cout << "Current Password= " << admin.getPassword();
                cout << "Enter New ";
                cin >> str1;
                admin.setPassword(str1);
                admin.deleteAdmin();
                admin.writeadmin();
                cout << "Password changed" << endl;
                break;
            case 2:
                admin.display();
                break;
            case 3:
                cout << "Enter ID: ";
                cin >> str1;
                doctor.storeDoctor(str1);
                doctor.deleteDoctor();
                cout << " Deleted";
                break;
            default:
                cout << "Invalid";
                goto AdminMenu;
                break;
            }
            goto AdminMenu;
        }
        else
        {
            cout << "Invalid";
            goto MainMenu;
        }
    }
}