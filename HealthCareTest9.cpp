#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
struct Patient {
    int id;
    string name;
    int age;
    string address;
};
 
struct Appointment {
    int id;
    int patientId;
    string date;
    string time;
};
 
class HealthCareSystem {
private:
    vector<Patient> patients;
    vector<Appointment> appointments;
    int nextPatientId = 1;
    int nextAppointmentId = 1;
 
public:
    void addPatient(string name, int age, string address) {
        Patient patient = {nextPatientId++, name, age, address};
        patients.push_back(patient);
    }
 
    void addAppointment(int patientId, string date, string time) {
        Appointment appointment = {nextAppointmentId++, patientId, date, time};
        appointments.push_back(appointment);
    }
 
    void deletePatient(int id) {
        for (auto it = patients.begin(); it != patients.end(); ++it) {
            if (it->id == id) {
                patients.erase(it);
                break;
            }
        }
    }
 
    void deleteAppointment(int id) {
        for (auto it = appointments.begin(); it != appointments.end(); ++it) {
            if (it->id == id) {
                appointments.erase(it);
                break;
            }
        }
    }
 
    void updatePatient(int id, string name, int age, string address) {
        for (auto &patient : patients) {
            if (patient.id == id) {
                patient.name = name;
                patient.age = age;
                patient.address = address;
                break;
            }
        }
    }
 
    void updateAppointment(int id, string date, string time) {
        for (auto &appointment : appointments) {
            if (appointment.id == id) {
                appointment.date = date;
                appointment.time = time;
                break;
            }
        }
    }
 
    Patient* searchPatient(int id) {
        for (auto &patient : patients) {
            if (patient.id == id) {
                return &patient;
            }
        }
        return nullptr;
    }
 
    Appointment* searchAppointment(int id) {
        for (auto &appointment : appointments) {
            if (appointment.id == id) {
                return &appointment;
            }
        }
        return nullptr;
    }
 
    void displayPatients() {
        for (const auto &patient : patients) {
            cout << "ID: " << patient.id << ", Name: " << patient.name 
                 << ", Age: " << patient.age << ", Address: " << patient.address << endl;
        }
    }
 
    void displayAppointments() {
        for (const auto &appointment : appointments) {
            cout << "ID: " << appointment.id << ", Patient ID: " << appointment.patientId 
                 << ", Date: " << appointment.date << ", Time: " << appointment.time << endl;
        }
    }
};
 
int main() {
    HealthCareSystem system;
    system.addPatient("John Doe", 29, "123 Elm St");
    system.addAppointment(1, "2023-11-01", "10:00");
 
    system.displayPatients();
    system.displayAppointments();
 
    system.updatePatient(1, "John Smith", 30, "456 Oak St");
 
    Patient* patient = system.searchPatient(1);
    if (patient) {
        cout << "Found patient: " << patient->name << endl;
    }
 
    system.deleteAppointment(1);
    system.displayAppointments();
    
    return 0;
} 
