#include <iostream>
#include <string>
#include <vector>
 
struct Patient {
    int id;
    std::string name;
    int age;
};
 
struct Appointment {
    int id;
    int patientId;
    std::string date;
    std::string time;
};
 
class HealthCareSystem {
private:
    std::vector<Patient> patients;
    std::vector<Appointment> appointments;
    int patientIdCounter = 1;
    int appointmentIdCounter = 1;
 
public:
    void addPatient(const std::string& name, int age) {
        patients.push_back({patientIdCounter++, name, age});
    }
 
    void deletePatient(int id) {
        patients.erase(std::remove_if(patients.begin(), patients.end(),
                    [id](Patient& p){ return p.id == id; }), patients.end());
        appointments.erase(std::remove_if(appointments.begin(), appointments.end(),
                    [id](Appointment& a){ return a.patientId == id; }), appointments.end());
    }
 
    void updatePatient(int id, const std::string& name, int age) {
        for (auto& patient : patients) {
            if (patient.id == id) {
                patient.name = name;
                patient.age = age;
                break;
            }
        }
    }
 
    Patient* searchPatient(int id) {
        for (auto& patient : patients) {
            if (patient.id == id) {
                return &patient;
            }
        }
        return nullptr;
    }
 
    void displayPatients() {
        for (const auto& patient : patients) {
            std::cout << "ID: " << patient.id << ", Name: " << patient.name << ", Age: " << patient.age << "\n";
        }
    }
 
    void addAppointment(int patientId, const std::string& date, const std::string& time) {
        appointments.push_back({appointmentIdCounter++, patientId, date, time});
    }
 
    void deleteAppointment(int id) {
        appointments.erase(std::remove_if(appointments.begin(), appointments.end(),
                    [id](Appointment& a){ return a.id == id; }), appointments.end());
    }
 
    void updateAppointment(int id, const std::string& date, const std::string& time) {
        for (auto& appointment : appointments) {
            if (appointment.id == id) {
                appointment.date = date;
                appointment.time = time;
                break;
            }
        }
    }
 
    Appointment* searchAppointment(int id) {
        for (auto& appointment : appointments) {
            if (appointment.id == id) {
                return &appointment;
            }
        }
        return nullptr;
    }
 
    void displayAppointments() {
        for (const auto& appointment : appointments) {
            std::cout << "ID: " << appointment.id << ", Patient ID: " << appointment.patientId
                      << ", Date: " << appointment.date << ", Time: " << appointment.time << "\n";
        }
    }
};
 
int main() {
    HealthCareSystem system;
 
    system.addPatient("Alice Smith", 30);
    system.addPatient("Bob Johnson", 45);
    system.displayPatients();
 
    system.addAppointment(1, "2023-10-01", "09:00");
    system.addAppointment(2, "2023-10-02", "11:00");
    system.displayAppointments();
 
    return 0;
}
