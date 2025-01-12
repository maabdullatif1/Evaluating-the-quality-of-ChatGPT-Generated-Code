#include <iostream>
#include <vector>
#include <string>
 
struct Appointment {
    int appointmentID;
    std::string date;
    std::string time;
    std::string doctor;
};
 
struct Patient {
    int patientID;
    std::string name;
    int age;
    std::vector<Appointment> appointments;
};
 
class HealthCareSystem {
private:
    std::vector<Patient> patients;
 
    Patient* findPatient(int patientID) {
        for (auto& patient : patients) {
            if (patient.patientID == patientID)
                return &patient;
        }
        return nullptr;
    }
 
    Appointment* findAppointment(Patient& patient, int appointmentID) {
        for (auto& appointment : patient.appointments) {
            if (appointment.appointmentID == appointmentID)
                return &appointment;
        }
        return nullptr;
    }
 
public:
    void addPatient(int id, const std::string& name, int age) {
        patients.push_back({id, name, age, {}});
    }
 
    void deletePatient(int id) {
        patients.erase(std::remove_if(patients.begin(), patients.end(), [&](const Patient& p) {
            return p.patientID == id;
        }), patients.end());
    }
 
    void updatePatient(int id, const std::string& name, int age) {
        Patient* patient = findPatient(id);
        if (patient) {
            patient->name = name;
            patient->age = age;
        }
    }
 
    void searchPatient(int id) {
        Patient* patient = findPatient(id);
        if (patient) {
            std::cout << "Patient ID: " << patient->patientID << ", Name: " << patient->name << ", Age: " << patient->age << std::endl;
            for (const auto& appointment : patient->appointments) {
                std::cout << "Appointment ID: " << appointment.appointmentID << ", Date: " << appointment.date << ", Time: " << appointment.time << ", Doctor: " << appointment.doctor << std::endl;
            }
        } else {
            std::cout << "Patient not found" << std::endl;
        }
    }
 
    void addAppointment(int patientID, int appointmentID, const std::string& date, const std::string& time, const std::string& doctor) {
        Patient* patient = findPatient(patientID);
        if (patient) {
            patient->appointments.push_back({appointmentID, date, time, doctor});
        }
    }
 
    void deleteAppointment(int patientID, int appointmentID) {
        Patient* patient = findPatient(patientID);
        if (patient) {
            patient->appointments.erase(std::remove_if(patient->appointments.begin(), patient->appointments.end(), [&](const Appointment& a) {
                return a.appointmentID == appointmentID;
            }), patient->appointments.end());
        }
    }
 
    void updateAppointment(int patientID, int appointmentID, const std::string& date, const std::string& time, const std::string& doctor) {
        Patient* patient = findPatient(patientID);
        if (patient) {
            Appointment* appointment = findAppointment(*patient, appointmentID);
            if (appointment) {
                appointment->date = date;
                appointment->time = time;
                appointment->doctor = doctor;
            }
        }
    }
 
    void displayAllPatients() {
        for (const auto& patient : patients) {
            std::cout << "Patient ID: " << patient.patientID << ", Name: " << patient.name << ", Age: " << patient.age << std::endl;
            for (const auto& appointment : patient.appointments) {
                std::cout << "Appointment ID: " << appointment.appointmentID << ", Date: " << appointment.date << ", Time: " << appointment.time << ", Doctor: " << appointment.doctor << std::endl;
            }
        }
    }
};
 
int main() {
    HealthCareSystem system;
 
    system.addPatient(1, "John Doe", 30);
    system.addAppointment(1, 101, "2023-05-15", "10:00 AM", "Dr. Smith");
    system.addPatient(2, "Jane Smith", 25);
    system.addAppointment(2, 102, "2023-05-16", "11:00 AM", "Dr. Doe");
 
    system.searchPatient(1);
    system.updatePatient(1, "John Doe Jr.", 31);
    
    system.displayAllPatients();
    
    system.deleteAppointment(1, 101);
    system.deletePatient(2);
 
    system.displayAllPatients();
 
    return 0;
}
