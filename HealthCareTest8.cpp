#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
struct Patient {
    int id;
    string name;
    int age;
};
 
struct Appointment {
    int id;
    int patientId;
    string date;
    string description;
};
 
vector<Patient> patients;
vector<Appointment> appointments;
 
void addPatient() {
    Patient p;
    cout << "Enter patient ID: ";
    cin >> p.id;
    cout << "Enter patient name: ";
    cin.ignore();
    getline(cin, p.name);
    cout << "Enter patient age: ";
    cin >> p.age;
    patients.push_back(p);
}
 
void deletePatient() {
    int id;
    cout << "Enter patient ID to delete: ";
    cin >> id;
    for (auto it = patients.begin(); it != patients.end(); ++it) {
        if (it->id == id) {
            patients.erase(it);
            break;
        }
    }
}
 
void updatePatient() {
    int id;
    cout << "Enter patient ID to update: ";
    cin >> id;
    for (auto &p : patients) {
        if (p.id == id) {
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, p.name);
            cout << "Enter new age: ";
            cin >> p.age;
            return;
        }
    }
}
 
void searchPatient() {
    int id;
    cout << "Enter patient ID to search: ";
    cin >> id;
    for (const auto &p : patients) {
        if (p.id == id) {
            cout << "Patient ID: " << p.id << ", Name: " << p.name << ", Age: " << p.age << endl;
            return;
        }
    }
    cout << "Patient not found\n";
}
 
void displayPatients() {
    for (const auto &p : patients) {
        cout << "Patient ID: " << p.id << ", Name: " << p.name << ", Age: " << p.age << endl;
    }
}
 
void addAppointment() {
    Appointment a;
    cout << "Enter appointment ID: ";
    cin >> a.id;
    cout << "Enter patient ID for appointment: ";
    cin >> a.patientId;
    cout << "Enter appointment date: ";
    cin.ignore();
    getline(cin, a.date);
    cout << "Enter appointment description: ";
    getline(cin, a.description);
    appointments.push_back(a);
}
 
void deleteAppointment() {
    int id;
    cout << "Enter appointment ID to delete: ";
    cin >> id;
    for (auto it = appointments.begin(); it != appointments.end(); ++it) {
        if (it->id == id) {
            appointments.erase(it);
            break;
        }
    }
}
 
void updateAppointment() {
    int id;
    cout << "Enter appointment ID to update: ";
    cin >> id;
    for (auto &a : appointments) {
        if (a.id == id) {
            cout << "Enter new patient ID: ";
            cin >> a.patientId;
            cout << "Enter new date: ";
            cin.ignore();
            getline(cin, a.date);
            cout << "Enter new description: ";
            getline(cin, a.description);
            return;
        }
    }
}
 
void searchAppointment() {
    int id;
    cout << "Enter appointment ID to search: ";
    cin >> id;
    for (const auto &a : appointments) {
        if (a.id == id) {
            cout << "Appointment ID: " << a.id << ", Patient ID: " << a.patientId;
            cout << ", Date: " << a.date << ", Description: " << a.description << endl;
            return;
        }
    }
    cout << "Appointment not found\n";
}
 
void displayAppointments() {
    for (const auto &a : appointments) {
        cout << "Appointment ID: " << a.id << ", Patient ID: " << a.patientId;
        cout << ", Date: " << a.date << ", Description: " << a.description << endl;
    }
}
 
int main() {
    int choice;
    do {
        cout << "1. Add Patient\n2. Delete Patient\n3. Update Patient\n4. Search Patient\n";
        cout << "5. Display Patients\n6. Add Appointment\n7. Delete Appointment\n";
        cout << "8. Update Appointment\n9. Search Appointment\n10. Display Appointments\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) addPatient();
        else if (choice == 2) deletePatient();
        else if (choice == 3) updatePatient();
        else if (choice == 4) searchPatient();
        else if (choice == 5) displayPatients();
        else if (choice == 6) addAppointment();
        else if (choice == 7) deleteAppointment();
        else if (choice == 8) updateAppointment();
        else if (choice == 9) searchAppointment();
        else if (choice == 10) displayAppointments();
    } while (choice != 0);
    
    return 0;
}
