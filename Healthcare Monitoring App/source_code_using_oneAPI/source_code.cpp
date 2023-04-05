#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <algorithm>

using namespace std;

// Define struct for patient information
struct PatientInfo {
    string name;
    int age;
    string language;
    bool hasInsurance;
    double income;
};

// Define struct for healthcare provider information
struct ProviderInfo {
    string name;
    string language;
    bool acceptsInsurance;
    bool isRemote;
};

// Generate some random patient data
vector<PatientInfo> generatePatientData(int numPatients) {
    vector<PatientInfo> patientData;
    srand(time(0));
    string languages[] = {"English", "Spanish", "Mandarin", "French", "Arabic"};
    for (int i = 0; i < numPatients; i++) {
        PatientInfo patient;
        patient.name = "Patient " + to_string(i+1);
        patient.age = rand() % 90 + 10;
        patient.language = languages[rand() % 5];
        patient.hasInsurance = rand() % 2;
        patient.income = rand() % 100000;
        patientData.push_back(patient);
    }
    return patientData;
}

// Generate some random healthcare provider data
vector<ProviderInfo> generateProviderData(int numProviders) {
    vector<ProviderInfo> providerData;
    srand(time(0));
    string languages[] = {"English", "Spanish", "Mandarin", "French", "Arabic"};
    for (int i = 0; i < numProviders; i++) {
        ProviderInfo provider;
        provider.name = "Provider " + to_string(i+1);
        provider.language = languages[rand() % 5];
        provider.acceptsInsurance = rand() % 2;
        provider.isRemote = rand() % 2;
        providerData.push_back(provider);
    }
    return providerData;
}

// Function to calculate distance between two locations
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    const double R = 6371e3; // metres
    double phi1 = lat1 * M_PI / 180; // convert to radians
    double phi2 = lat2 * M_PI / 180;
    double deltaPhi = (lat2-lat1) * M_PI / 180;
    double deltaLambda = (lon2-lon1) * M_PI / 180;

    double a = sin(deltaPhi/2) * sin(deltaPhi/2) +
            cos(phi1) * cos(phi2) *
            sin(deltaLambda/2) * sin(deltaLambda/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    double distance = R * c;
    return distance;
}

// Function to find the closest healthcare provider to a patient's location
ProviderInfo findClosestProvider(PatientInfo patient, vector<ProviderInfo> providerData) {
    double patientLat = 42.3601; // example latitude
    double patientLon = -71.0589; // example longitude
    ProviderInfo closestProvider;
    double minDistance = numeric_limits<double>::max();
    for (ProviderInfo provider : providerData) {
        double providerLat = 42.3601 + (rand() % 1000 - 500) * 0.0001; // add some random variation
        double providerLon = -71.0589 + (rand() % 1000 - 500) * 0.0001; // add some random variation
            double distance = calculateDistance(patientLat, patientLon, providerLat, providerLon);
    if (distance < minDistance && provider.acceptsInsurance == patient.hasInsurance && provider.language == patient.language) {
        minDistance = distance;
        closestProvider = provider;
    }
}
return closestProvider;

int main() {
// Generate some patient and healthcare provider data
vector<PatientInfo> patientData = generatePatientData();   //enter your data
vector<ProviderInfo> providerData = generateProviderData();//enter your data
// Find the closest healthcare provider to each patient and print the results
for (PatientInfo patient : patientData) {
    ProviderInfo closestProvider = findClosestProvider(patient, providerData);
    cout << patient.name << " is closest to " << closestProvider.name << endl;
}

return 0;
