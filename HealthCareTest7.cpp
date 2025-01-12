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
    int patient_id;
    string date;
    string time;
};
 
class HealthCareSystem {
public:
    void addPatient(int id, const string& name, int age);
    void deletePatient(int id);
    void updatePatient(int id, const string& name, int age);
    void displayPatients();
    void searchPatient(int id);
    void addAppointment(int id, int patient_id, const string& date, const string& time);
    void deleteAppointment(int id);
    void updateAppointment(int id, int patient_id, const string& date, const string& time);
    void displayAppointments();
    void searchAppointment(int id);
 
private:
    vector<Patient> patients;
    vector<Appointment> appointments;
};
 
void HealthCareSystem::addPatient(int id, const string& name, int age) {
    patients.push_back({id, name, age});
}
 
void HealthCareSystem::deletePatient(int id) {
    for (auto it = patients.begin(); it != patients.end(); ) {
        if (it->id == id) {
            it = patients.erase(it);
        } else {
            ++it;
        }
    }
}
 
void HealthCareSystem::updatePatient(int id, const string& name, int age) {
    for (auto& patient : patients) {
        if (patient.id == id) {
            patient.name = name;
            patient.age = age;
            break;
        }
    }
}
 
void HealthCareSystem::displayPatients() {
    for (const auto& patient : patients) {
        cout << "ID: " << patient.id << ", Name: " << patient.name << ", Age: " << patient.age << endl;
    }
}
 
void HealthCareSystem::searchPatient(int id) {
    for (const auto& patient : patients) {
        if (patient.id == id) {
            cout << "ID: " << patient.id << ", Name: " << patient.name << ", Age: " << patient.age << endl;
            return;
        }
    }
    cout << "Patient not found" << endl;
}
 
void HealthCareSystem::addAppointment(int id, int patient_id, const string& date, const string& time) {
    appointments.push_back({id, patient_id, date, time});
}
 
void HealthCareSystem::deleteAppointment(int id) {
    for (auto it = appointments.begin(); it != appointments.end(); ) {
        if (it->id == id) {
            it = appointments.erase(it);
        } else {
            ++it;
        }
    }
}
 
void HealthCareSystem::updateAppointment(int id, int patient_id, const string& date, const string& time) {
    for (auto& appointment : appointments) {
        if (appointment.id == id) {
            appointment.patient_id = patient_id;
            appointment.date = date;
            appointment.time = time;
            break;
        }
    }
}
 
void HealthCareSystem::displayAppointments() {
    for (const auto& appointment : appointments) {
        cout << "ID: " << appointment.id << ", Patient ID: " << appointment.patient_id 
             << ", Date: " << appointment.date << ", Time: " << appointment.time << endl;
    }
}
 
void HealthCareSystem::searchAppointment(int id) {
    for (const auto& appointment : appointments) {
        if (appointment.id == id) {
            cout << "ID: " << appointment.id << ", Patient ID: " << appointment.patient_id 
                 << ", Date: " << appointment.date << ", Time: " << appointment.time << endl;
            return;
        }
    }
    cout << "Appointment not found" << endl;
}
 
int main() {
    HealthCareSystem system;
    system.addPatient(1, "John Doe", 30);
    system.addPatient(2, "Jane Smith", 25);
    system.displayPatients();
    system.addAppointment(101, 1, "2023-10-15", "10:00");
    system.addAppointment(102, 2, "2023-10-16", "11:00");
    system.displayAppointments();
    return 0;
}
