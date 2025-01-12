#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
struct Appointment {
    int id;
    string date;
    string time;
    string doctor;
};
 
struct Patient {
    int id;
    string name;
    int age;
    string gender;
    vector<Appointment> appointments;
};
 
vector<Patient> patients;
int patientCounter = 0;
int appointmentCounter = 0;
 
void addPatient() {
    Patient patient;
    patient.id = ++patientCounter;
    cout << "Enter patient name: ";
    cin >> patient.name;
    cout << "Enter patient age: ";
    cin >> patient.age;
    cout << "Enter patient gender: ";
    cin >> patient.gender;
    patients.push_back(patient);
    cout << "Patient added successfully.\n";
}
 
void displayPatients() {
    for (const auto& patient : patients) {
        cout << "Patient ID: " << patient.id << " Name: " << patient.name
             << " Age: " << patient.age << " Gender: " << patient.gender << endl;
        for (const auto& appointment : patient.appointments) {
            cout << "  Appointment ID: " << appointment.id 
                 << " Date: " << appointment.date 
                 << " Time: " << appointment.time 
                 << " Doctor: " << appointment.doctor << endl;
        }
    }
}
 
void updatePatient() {
    int id;
    cout << "Enter patient ID to update: ";
    cin >> id;
    for (auto& patient : patients) {
        if (patient.id == id) {
            cout << "Enter new name: ";
            cin >> patient.name;
            cout << "Enter new age: ";
            cin >> patient.age;
            cout << "Enter new gender: ";
            cin >> patient.gender;
            cout << "Patient updated successfully.\n";
            return;
        }
    }
    cout << "Patient not found.\n";
}
 
void deletePatient() {
    int id;
    cout << "Enter patient ID to delete: ";
    cin >> id;
    for (auto it = patients.begin(); it != patients.end(); ++it) {
        if (it->id == id) {
            patients.erase(it);
            cout << "Patient deleted successfully.\n";
            return;
        }
    }
    cout << "Patient not found.\n";
}
 
void searchPatient() {
    int id;
    cout << "Enter patient ID to search: ";
    cin >> id;
    for (const auto& patient : patients) {
        if (patient.id == id) {
            cout << "Patient ID: " << patient.id << " Name: " << patient.name
                 << " Age: " << patient.age << " Gender: " << patient.gender << endl;
            for (const auto& appointment : patient.appointments) {
                cout << "  Appointment ID: " << appointment.id 
                     << " Date: " << appointment.date 
                     << " Time: " << appointment.time 
                     << " Doctor: " << appointment.doctor << endl;
            }
            return;
        }
    }
    cout << "Patient not found.\n";
}
 
void addAppointment() {
    int patientId;
    cout << "Enter patient ID to add appointment: ";
    cin >> patientId;
    for (auto& patient : patients) {
        if (patient.id == patientId) {
            Appointment appointment;
            appointment.id = ++appointmentCounter;
            cout << "Enter appointment date: ";
            cin >> appointment.date;
            cout << "Enter appointment time: ";
            cin >> appointment.time;
            cout << "Enter doctor's name: ";
            cin >> appointment.doctor;
            patient.appointments.push_back(appointment);
            cout << "Appointment added successfully.\n";
            return;
        }
    }
    cout << "Patient not found.\n";
}
 
int main() {
    int choice;
    while (true) {
        cout << "1. Add Patient\n2. Display Patients\n3. Update Patient\n4. Delete Patient\n5. Search Patient\n6. Add Appointment\n0. Exit\nChoose an option: ";
        cin >> choice;
        switch(choice) {
            case 1:
                addPatient();
                break;
            case 2:
                displayPatients();
                break;
            case 3:
                updatePatient();
                break;
            case 4:
                deletePatient();
                break;
            case 5:
                searchPatient();
                break;
            case 6:
                addAppointment();
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
