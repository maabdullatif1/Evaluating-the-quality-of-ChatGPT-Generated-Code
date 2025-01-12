#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
class Patient {
public:
    int id;
    string name;
    int age;
 
    Patient(int id, string name, int age) : id(id), name(name), age(age) {}
};
 
class Appointment {
public:
    int id;
    int patientId;
    string date;
    
    Appointment(int id, int patientId, string date) : id(id), patientId(patientId), date(date) {}
};
 
class HealthCareSystem {
private:
    vector<Patient> patients;
    vector<Appointment> appointments;
    int patientIdCounter = 0;
    int appointmentIdCounter = 0;
 
    Patient* findPatientById(int id) {
        for (auto& patient : patients) {
            if (patient.id == id) return &patient;
        }
        return nullptr;
    }
    
    Appointment* findAppointmentById(int id) {
        for (auto& appointment : appointments) {
            if (appointment.id == id) return &appointment;
        }
        return nullptr;
    }
 
public:
    void addPatient(string name, int age) {
        patients.push_back(Patient(patientIdCounter++, name, age));
    }
 
    void deletePatient(int id) {
        patients.erase(remove_if(patients.begin(), patients.end(), [id](Patient& p) { return p.id == id; }), patients.end());
    }
 
    void updatePatient(int id, string name, int age) {
        Patient* patient = findPatientById(id);
        if (patient) {
            patient->name = name;
            patient->age = age;
        }
    }
 
    void searchPatient(int id) {
        Patient* patient = findPatientById(id);
        if (patient) {
            cout << "Patient ID: " << patient->id << ", Name: " << patient->name << ", Age: " << patient->age << endl;
        } else {
            cout << "Patient not found." << endl;
        }
    }
 
    void displayAllPatients() {
        for (const auto& patient : patients) {
            cout << "Patient ID: " << patient.id << ", Name: " << patient.name << ", Age: " << patient.age << endl;
        }
    }
 
    void addAppointment(int patientId, string date) {
        if (findPatientById(patientId)) {
            appointments.push_back(Appointment(appointmentIdCounter++, patientId, date));
        }
    }
 
    void deleteAppointment(int id) {
        appointments.erase(remove_if(appointments.begin(), appointments.end(), [id](Appointment& a) { return a.id == id; }), appointments.end());
    }
 
    void updateAppointment(int id, int patientId, string date) {
        Appointment* appointment = findAppointmentById(id);
        if (appointment && findPatientById(patientId)) {
            appointment->patientId = patientId;
            appointment->date = date;
        }
    }
 
    void searchAppointment(int id) {
        Appointment* appointment = findAppointmentById(id);
        if (appointment) {
            cout << "Appointment ID: " << appointment->id << ", Patient ID: " << appointment->patientId << ", Date: " << appointment->date << endl;
        } else {
            cout << "Appointment not found." << endl;
        }
    }
 
    void displayAllAppointments() {
        for (const auto& appointment : appointments) {
            cout << "Appointment ID: " << appointment.id << ", Patient ID: " << appointment.patientId << ", Date: " << appointment.date << endl;
        }
    }
};
 
int main() {
    HealthCareSystem system;
    system.addPatient("Alice", 30);
    system.addPatient("Bob", 25);
    system.addAppointment(0, "2023-11-01");
    system.displayAllPatients();
    system.displayAllAppointments();
    return 0;
}
