#include <iostream>
#include <vector>
using namespace std;

class PatientRecord {
    string ID, name, dateOfBirth;
    vector<string> history;
    vector<string> currentTreatments;
    vector<string> billingDetails;

    public:
    PatientRecord(string id, string n, string dob) : ID(id), name(n), dateOfBirth(dob) {}

    void getPublicData()    {
        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
    }
    void getMedicalData() {
        cout << "Treatment History: " << endl;
        for (int i=0; i < history.size(); i++) {
            cout << history[i] << endl;
        }
        cout << "\nCurrent Treatments: " << endl;
        for (int i=0; i < currentTreatments.size(); i++) {
            cout << currentTreatments[i] << endl;
        }
    }
    void addHistoryRecord(string treatment) {
        history.push_back(treatment);
    }
    void addBillingRecord(string bill) {
        billingDetails.push_back(bill);
    }
};

class Doctor {
    string dID;

    public:
    Doctor(string id) : dID(id) {}

    void updateMedicalHistory(PatientRecord& patient, string treatment) {
        patient.addHistoryRecord(treatment);
    }

};

class Billing {
    public:
    Billing() {}

    void addBillingDetails(PatientRecord& patient, string bill) {
        patient.addBillingRecord(bill);
    } 

};