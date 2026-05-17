// calculator.cpp
#include "calculator.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

// --- Activity Multipliers ---
double getActivityMultiplier(int choice) {
    switch (choice) {
        case 1: return 1.200;
        case 2: return 1.375;
        case 3: return 1.550;
        case 4: return 1.725;
        case 5: return 1.900;
        case 6: return 2.100;
        default: return 1.200;
    }
}

// --- BMR: Mifflin-St Jeor ---
double calcBMR_Mifflin(const UserData& user) {
    double bmr = (10.0 * user.weight_kg)
               + (6.25 * user.height_cm)
               - (5.0  * user.age);
    return (user.gender == 'M' || user.gender == 'm')
           ? bmr + 5.0
           : bmr - 161.0;
}

// --- BMR: Harris-Benedict ---
double calcBMR_Harris(const UserData& user) {
    if (user.gender == 'M' || user.gender == 'm')
        return (13.397 * user.weight_kg)
             + (4.799  * user.height_cm)
             - (5.677  * user.age)
             + 88.362;
    return (9.247  * user.weight_kg)
         + (3.098  * user.height_cm)
         - (4.330  * user.age)
         + 447.593;
}

// --- Compute Results ---
Results calcResults(double bmr, double multiplier) {
    Results r;
    r.bmr  = bmr;
    r.tdee = bmr * multiplier;
    r.lose = r.tdee - 500.0;
    r.gain = r.tdee + 500.0;
    return r;
}

// --- Get User Input ---
void getUserInput(UserData& user) {
    cout << "\n+------------------------------+\n";
    cout << "|     ENTER YOUR DETAILS       |\n";
    cout << "+------------------------------+\n\n";

    cout << "  Age (15-80)        : ";
    cin  >> user.age;

    cout << "  Gender (M/F)       : ";
    cin  >> user.gender;

    cout << "  Weight (kg)        : ";
    cin  >> user.weight_kg;

    cout << "  Height (cm)        : ";
    cin  >> user.height_cm;

    cout << "\n  Activity Level:\n";
    cout << "    1 -> Sedentary       (little/no exercise)\n";
    cout << "    2 -> Light           (1-3 days/week)\n";
    cout << "    3 -> Moderate        (4-5 days/week)\n";
    cout << "    4 -> Active          (daily or intense 3-4x/week)\n";
    cout << "    5 -> Very Active     (intense 6-7x/week)\n";
    cout << "    6 -> Extra Active    (physical job or 2x training)\n";
    cout << "\n  Your choice (1-6)  : ";
    cin  >> user.activityChoice;
}

// --- Display Results ---
void displayResults(const UserData& user, const Results& res, double multiplier) {
    string genderStr = (user.gender == 'M' || user.gender == 'm') ? "Male" : "Female";

    cout << "\n+======================================+\n";
    cout << "|         YOUR CALORIE RESULTS         |\n";
    cout << "+======================================+\n";
    cout << fixed << setprecision(0);
    cout << "|  Age      : " << setw(5) << user.age
         << " yrs                  |\n";
    cout << "|  Weight   : " << setw(5) << (int)user.weight_kg
         << " kg                   |\n";
    cout << "|  Height   : " << setw(5) << (int)user.height_cm
         << " cm                   |\n";
    cout << "+======================================+\n";
    cout << "|  BMR (at rest)  : "
         << setw(7) << (int)res.bmr  << " kcal/day       |\n";
    cout << "+======================================+\n";
    cout << "|  Lose weight    : "
         << setw(7) << (int)res.lose << " kcal/day       |\n";
    cout << "|  Maintain       : "
         << setw(7) << (int)res.tdee << " kcal/day       |\n";
    cout << "|  Gain weight    : "
         << setw(7) << (int)res.gain << " kcal/day       |\n";
    cout << "+======================================+\n";
}

// --- Activity Breakdown Table ---
void displayActivityTable(double bmr) {
    const string labels[] = {
        "Sedentary   ",
        "Light       ",
        "Moderate    ",
        "Active      ",
        "Very Active ",
        "Extra Active"
    };
    const double mults[] = {1.2, 1.375, 1.55, 1.725, 1.9, 2.1};

    cout << "\n+--------------+--------+-------------+\n";
    cout << "|   ACTIVITY   |  MULT  |  KCAL/DAY   |\n";
    cout << "+--------------+--------+-------------+\n";

    for (int i = 0; i < 6; i++) {
        cout << "| " << labels[i]
             << " | x" << fixed << setprecision(3) << mults[i]
             << " | " << setw(8) << setprecision(0) << (int)(bmr * mults[i])
             << " kcal |\n";
    }

    cout << "+--------------+--------+-------------+\n";
}
