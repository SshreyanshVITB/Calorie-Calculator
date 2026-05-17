// main.cpp
#include "calculator.h"
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

void showMenu() {
    cout << "\n+==============================+\n";
    cout << "|   CalcFit -- C++ Calorie     |\n";
    cout << "|        Calculator            |\n";
    cout << "+==============================+\n";
    cout << "|  1. Mifflin-St Jeor (Best)   |\n";
    cout << "|  2. Harris-Benedict          |\n";
    cout << "|  3. Compare Both Formulas    |\n";
    cout << "|  4. Exit                     |\n";
    cout << "+==============================+\n";
    cout << "  Choose (1-4): ";
}

int main() {
    int menuChoice;
    char again;

    do {
        showMenu();
        cin >> menuChoice;

        if (menuChoice == 4) {
            cout << "\n  Goodbye! Stay healthy. 💪\n\n";
            break;
        }

        UserData user;
        getUserInput(user);
        double multiplier = getActivityMultiplier(user.activityChoice);

        if (menuChoice == 1) {
            // Mifflin-St Jeor only
            double bmr = calcBMR_Mifflin(user);
            Results res = calcResults(bmr, multiplier);
            cout << "\n  [Formula: Mifflin-St Jeor]\n";
            displayResults(user, res, multiplier);
            displayActivityTable(bmr);

        } else if (menuChoice == 2) {
            // Harris-Benedict only
            double bmr = calcBMR_Harris(user);
            Results res = calcResults(bmr, multiplier);
            cout << "\n  [Formula: Harris-Benedict]\n";
            displayResults(user, res, multiplier);
            displayActivityTable(bmr);

        } else if (menuChoice == 3) {
            // Compare both
            double bmr1 = calcBMR_Mifflin(user);
            double bmr2 = calcBMR_Harris(user);
            Results r1  = calcResults(bmr1, multiplier);
            Results r2  = calcResults(bmr2, multiplier);

            cout << "\n══════════ MIFFLIN-ST JEOR ═══════════\n";
            displayResults(user, r1, multiplier);

            cout << "\n══════════ HARRIS-BENEDICT ════════════\n";
            displayResults(user, r2, multiplier);

            cout << "\n┌─────────────────────────────────────┐\n";
            cout << "│           DIFFERENCE                │\n";
            cout << "│  BMR  Δ : " << setw(6) << (int)(bmr2 - bmr1) << " kcal/day          │\n";
            cout << "│  TDEE Δ : " << setw(6) << (int)(r2.tdee - r1.tdee) << " kcal/day          │\n";
            cout << "└─────────────────────────────────────┘\n";
        }

        cout << "\n  Calculate again? (y/n): ";
        cin  >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}

