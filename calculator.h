// calculator.h
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
using namespace std;

// ─── Data Structures ───────────────────────────────────────
struct UserData {
    double weight_kg;
    double height_cm;
    int    age;
    char   gender;      // 'M' or 'F'
    int    activityChoice;
};

struct Results {
    double bmr;
    double tdee;
    double lose;
    double gain;
};

// ─── Function Declarations ─────────────────────────────────
void   getUserInput(UserData& user);
double getActivityMultiplier(int choice);
double calcBMR_Mifflin(const UserData& user);
double calcBMR_Harris(const UserData& user);
Results calcResults(double bmr, double multiplier);
void   displayResults(const UserData& user, const Results& res, double multiplier);
void   displayActivityTable(double bmr);

#endif
