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
    vector<Appointment> appointments;
};
 
vector<Patient> patients;
int currentPatientId = 1;
int currentAppointmentId = 1;
 
Patient* findPatient(int id) {
    for (auto &patient : patients) {
        if (patient.id == id) return &patient;
    }
    return nullptr;
}
 
Appointment* findAppointment(Patient& patient, int appointmentId) {
    for (auto &appointment : patient.appointments) {
        if (appointment.id == appointmentId) return &appointment;
    }
    return nullptr;
}
 
void addPatient() {
    Patient patient;
    patient.id = currentPatientId++;
    cout << "Enter patient name: ";
    cin >> patient.name;
    cout << "Enter patient age: ";
    cin >> patient.age;
    patients.push_back(patient);
    cout << "Patient added successfully.\n";
}
 
void deletePatient() {
    int id;
    cout << "Enter patient ID to delete: ";
    cin >> id;
    auto it = remove_if(patients.begin(), patients.end(), [id](const Patient& p) { return p.id == id; });
    if (it != patients.end()) {
        patients.erase(it, patients.end());
        cout << "Patient removed successfully.\n";
    } else {
        cout << "Patient not found.\n";
    }
}
 
void updatePatient() {
    int id;
    cout << "Enter patient ID to update: ";
    cin >> id;
    Patient* patient = findPatient(id);
    if (patient) {
        cout << "Update patient name: ";
        cin >> patient->name;
        cout << "Update patient age: ";
        cin >> patient->age;
        cout << "Patient updated successfully.\n";
    } else {
        cout << "Patient not found.\n";
    }
}
 
void displayPatients() {
    for (const auto &patient : patients) {
        cout << "ID: " << patient.id << ", Name: " << patient.name << ", Age: " << patient.age << endl;
        for (const auto &appointment : patient.appointments) {
            cout << "\tAppointment ID: " << appointment.id << ", Date: " << appointment.date << ", Time: " << appointment.time << ", Doctor: " << appointment.doctor << endl;
        }
    }
}
 
void addAppointment() {
    int patientId;
    cout << "Enter patient ID to add appointment for: ";
    cin >> patientId;
    Patient* patient = findPatient(patientId);
    if (patient) {
        Appointment appointment;
        appointment.id = currentAppointmentId++;
        cout << "Enter appointment date: ";
        cin >> appointment.date;
        cout << "Enter appointment time: ";
        cin >> appointment.time;
        cout << "Enter doctor name: ";
        cin >> appointment.doctor;
        patient->appointments.push_back(appointment);
        cout << "Appointment added successfully.\n";
    } else {
        cout << "Patient not found.\n";
    }
}
 
void deleteAppointment() {
    int patientId, appointmentId;
    cout << "Enter patient ID: ";
    cin >> patientId;
    Patient* patient = findPatient(patientId);
    if (patient) {
        cout << "Enter appointment ID to delete: ";
        cin >> appointmentId;
        auto it = remove_if(patient->appointments.begin(), patient->appointments.end(), [appointmentId](const Appointment& a) { return a.id == appointmentId; });
        if (it != patient->appointments.end()) {
            patient->appointments.erase(it, patient->appointments.end());
            cout << "Appointment removed successfully.\n";
        } else {
            cout << "Appointment not found.\n";
        }
    } else {
        cout << "Patient not found.\n";
    }
}
 
void updateAppointment() {
    int patientId, appointmentId;
    cout << "Enter patient ID: ";
    cin >> patientId;
    Patient* patient = findPatient(patientId);
    if (patient) {
        cout << "Enter appointment ID to update: ";
        cin >> appointmentId;
        Appointment* appointment = findAppointment(*patient, appointmentId);
        if (appointment) {
            cout << "Update appointment date: ";
            cin >> appointment->date;
            cout << "Update appointment time: ";
            cin >> appointment->time;
            cout << "Update doctor name: ";
            cin >> appointment->doctor;
            cout << "Appointment updated successfully.\n";
        } else {
            cout << "Appointment not found.\n";
        }
    } else {
        cout << "Patient not found.\n";
    }
}
 
void searchPatient() {
    int id;
    cout << "Enter patient ID to search: ";
    cin >> id;
    Patient* patient = findPatient(id);
    if (patient) {
        cout << "ID: " << patient->id << ", Name: " << patient->name << ", Age: " << patient->age << endl;
        for (const auto &appointment : patient->appointments) {
            cout << "\tAppointment ID: " << appointment.id << ", Date: " << appointment.date << ", Time: " << appointment.time << ", Doctor: " << appointment.doctor << endl;
        }
    } else {
        cout << "Patient not found.\n";
    }
}
 
int main() {
    int choice;
    do {
        cout << "1. Add Patient\n";
        cout << "2. Delete Patient\n";
        cout << "3. Update Patient\n";
        cout << "4. Display Patients\n";
        cout << "5. Add Appointment\n";
        cout << "6. Delete Appointment\n";
        cout << "7. Update Appointment\n";
        cout << "8. Search Patient\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addPatient(); break;
            case 2: deletePatient(); break;
            case 3: updatePatient(); break;
            case 4: displayPatients(); break;
            case 5: addAppointment(); break;
            case 6: deleteAppointment(); break;
            case 7: updateAppointment(); break;
            case 8: searchPatient(); break;
            case 9: break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 9);
    return 0;
}
