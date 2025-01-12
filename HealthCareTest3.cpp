#include <iostream>
#include <string>
#include <vector>
 
class Patient {
public:
    int id;
    std::string name;
    int age;
    
    Patient(int id, const std::string& name, int age) 
        : id(id), name(name), age(age) {}
};
 
class Appointment {
public:
    int id;
    int patientId;
    std::string date;
    std::string time;
    
    Appointment(int id, int patientId, const std::string& date, const std::string& time) 
        : id(id), patientId(patientId), date(date), time(time) {}
};
 
class HealthCareSystem {
private:
    std::vector<Patient> patients;
    std::vector<Appointment> appointments;
    int patientIdCounter = 1;
    int appointmentIdCounter = 1;
    
public:
    void addPatient(const std::string& name, int age) {
        patients.push_back(Patient(patientIdCounter++, name, age));
    }
    
    void deletePatient(int id) {
        for(auto it = patients.begin(); it != patients.end(); ++it) {
            if(it->id == id) {
                patients.erase(it);
                break;
            }
        }
    }
    
    void updatePatient(int id, const std::string& newName, int newAge) {
        for(auto& patient : patients) {
            if(patient.id == id) {
                patient.name = newName;
                patient.age = newAge;
                break;
            }
        }
    }
 
    Patient* searchPatient(int id) {
        for(auto& patient : patients) {
            if(patient.id == id) {
                return &patient;
            }
        }
        return nullptr;
    }
 
    void addAppointment(int patientId, const std::string& date, const std::string& time) {
        if(searchPatient(patientId) != nullptr) {
            appointments.push_back(Appointment(appointmentIdCounter++, patientId, date, time));
        }
    }
    
    void deleteAppointment(int id) {
        for(auto it = appointments.begin(); it != appointments.end(); ++it) {
            if(it->id == id) {
                appointments.erase(it);
                break;
            }
        }
    }
 
    void updateAppointment(int id, const std::string& newDate, const std::string& newTime) {
        for(auto& appointment : appointments) {
            if(appointment.id == id) {
                appointment.date = newDate;
                appointment.time = newTime;
                break;
            }
        }
    }
 
    Appointment* searchAppointment(int id) {
        for(auto& appointment : appointments) {
            if(appointment.id == id) {
                return &appointment;
            }
        }
        return nullptr;
    }
    
    void displayPatients() {
        for(const auto& patient : patients) {
            std::cout << "ID: " << patient.id << ", Name: " << patient.name << ", Age: " << patient.age << "\n";
        }
    }
 
    void displayAppointments() {
        for(const auto& appointment : appointments) {
            std::cout << "ID: " << appointment.id << ", Patient ID: " << appointment.patientId
                      << ", Date: " << appointment.date << ", Time: " << appointment.time << "\n";
        }
    }
};
 
int main() {
    HealthCareSystem system;
    
    system.addPatient("John Doe", 30);
    system.addPatient("Jane Smith", 25);
    
    system.addAppointment(1, "2023-11-01", "09:00 AM");
    system.addAppointment(2, "2023-11-02", "10:00 AM");
 
    std::cout << "Patients:\n";
    system.displayPatients();
 
    std::cout << "\nAppointments:\n";
    system.displayAppointments();
 
    return 0;
}
