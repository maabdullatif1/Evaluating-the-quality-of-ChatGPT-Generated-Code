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
    string time;
};
 
class HealthCareSystem {
private:
    vector<Patient> patients;
    vector<Appointment> appointments;
    int nextPatientId = 1;
    int nextAppointmentId = 1;
 
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
        Patient newPatient = {nextPatientId++, name, age};
        patients.push_back(newPatient);
    }
 
    void deletePatient(int id) {
        for (auto it = patients.begin(); it != patients.end(); ++it) {
            if (it->id == id) {
                patients.erase(it);
                break;
            }
        }
    }
 
    void updatePatient(int id, string name, int age) {
        Patient* patient = findPatientById(id);
        if (patient) {
            patient->name = name;
            patient->age = age;
        }
    }
 
    Patient* searchPatient(int id) {
        return findPatientById(id);
    }
 
    void displayPatients() {
        for (const auto& patient : patients) {
            cout << "ID: " << patient.id << ", Name: " << patient.name << ", Age: " << patient.age << endl;
        }
    }
 
    void addAppointment(int patientId, string date, string time) {
        Appointment newAppointment = {nextAppointmentId++, patientId, date, time};
        appointments.push_back(newAppointment);
    }
 
    void deleteAppointment(int id) {
        for (auto it = appointments.begin(); it != appointments.end(); ++it) {
            if (it->id == id) {
                appointments.erase(it);
                break;
            }
        }
    }
 
    void updateAppointment(int id, int patientId, string date, string time) {
        Appointment* appointment = findAppointmentById(id);
        if (appointment) {
            appointment->patientId = patientId;
            appointment->date = date;
            appointment->time = time;
        }
    }
 
    Appointment* searchAppointment(int id) {
        return findAppointmentById(id);
    }
 
    void displayAppointments() {
        for (const auto& appointment : appointments) {
            cout << "Appointment ID: " << appointment.id 
                 << ", Patient ID: " << appointment.patientId 
                 << ", Date: " << appointment.date 
                 << ", Time: " << appointment.time << endl;
        }
    }
};
 
int main() {
    HealthCareSystem system;
    system.addPatient("John Doe", 30);
    system.addPatient("Jane Smith", 25);
    system.displayPatients();
 
    system.addAppointment(1, "2023-12-01", "10:00am");
    system.addAppointment(2, "2023-12-02", "11:00am");
    system.displayAppointments();
 
    system.updatePatient(1, "John Doe", 31);
    Patient* patient = system.searchPatient(1);
    if (patient) {
        cout << "Found patient: ID" << patient->id << ", Name: " << patient->name << endl;
    }
    system.updateAppointment(1, 1, "2023-12-01", "10:30am");
    system.displayAppointments();
 
    system.deletePatient(2);
    system.displayPatients();
    system.deleteAppointment(2);
    system.displayAppointments();
 
    return 0;
}
