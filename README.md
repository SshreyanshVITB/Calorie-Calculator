# Calorie-Calculator
A command-line Calorie Calculator built in C++ that estimates daily caloric needs using the Mifflin-St Jeor and Harris-Benedict BMR equations. Takes age, gender, weight, height, and activity level as input and outputs calories needed to lose, maintain, or gain weight. Includes a web-based UI built with HTML, CSS, and JavaScript.
<br>
# 🔥 CalcFit — Calorie Calculator in C++

> A C++ console application that calculates BMR (Basal Metabolic Rate) and TDEE (Total Daily Energy Expenditure) using scientifically validated equations. Supports multiple activity levels and weight goals. Built as a learning project to demonstrate structs, functions, and modular programming in C++.

![C++](https://img.shields.io/badge/C++-17-blue?style=for-the-badge&logo=cplusplus)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)

---

## 📌 Table of Contents

- [About the Project](#-about-the-project)
- [Features](#-features)
- [Formulas Used](#-formulas-used)
- [Project Structure](#-project-structure)
- [How to Run](#-how-to-run)
- [Sample Output](#-sample-output)
- [Concepts Learned](#-concepts-learned)
- [Web Interface](#-web-interface)
- [Author](#-author)

---

## 📖 About the Project

CalcFit is a command-line calorie calculator built entirely in **C++**. It takes basic user information — age, gender, weight, height, and activity level — and calculates:

- **BMR** → How many calories your body burns at complete rest
- **TDEE** → Total calories burned per day including activity
- **Goal-based targets** → Calories needed to lose, maintain, or gain weight

This project was built to practice core C++ concepts like structs, modular programming, header files, and formatted console output.

---

## ✨ Features

- ✅ Two BMR formula options — **Mifflin-St Jeor** and **Harris-Benedict**
- ✅ 6 activity level multipliers (Sedentary → Extra Active)
- ✅ Full activity breakdown table
- ✅ Formula comparison mode (shows difference between both equations)
- ✅ Clean, formatted console output with borders
- ✅ Replay loop — calculate multiple times without restarting
- ✅ Web-based UI (HTML/CSS/JS) for browser use

---

## 📐 Formulas Used

### Mifflin-St Jeor (Recommended)
Most accurate modern formula for calculating BMR.

```
Male   : BMR = (10 × weight_kg) + (6.25 × height_cm) − (5 × age) + 5
Female : BMR = (10 × weight_kg) + (6.25 × height_cm) − (5 × age) − 161
```

### Harris-Benedict (Revised 1984)
Classic formula, widely used before Mifflin-St Jeor.

```
Male   : BMR = (13.397 × weight) + (4.799 × height) − (5.677 × age) + 88.362
Female : BMR = (9.247  × weight) + (3.098 × height) − (4.330 × age) + 447.593
```

### Activity Multipliers (TDEE = BMR × Multiplier)

| Level        | Description                    | Multiplier |
|--------------|--------------------------------|------------|
| Sedentary    | Little or no exercise          | × 1.200    |
| Light        | Exercise 1–3 days/week         | × 1.375    |
| Moderate     | Exercise 4–5 days/week         | × 1.550    |
| Active       | Daily or intense 3–4×/week     | × 1.725    |
| Very Active  | Intense exercise 6–7×/week     | × 1.900    |
| Extra Active | Physical job or 2× training    | × 2.100    |

---

## 🗂️ Project Structure

```
calorie-calculator/
│
├── main.cpp              ← Entry point, menu loop, program flow
├── calculator.h          ← Structs and function declarations
├── calculator.cpp        ← All formulas, logic, and display functions
├── index.html            ← Web-based UI (runs in browser)
└── README.md             ← This file
```

---

## 🚀 How to Run

### Prerequisites
- A C++ compiler (g++ recommended)
- C++17 or later

### Install g++ Compiler

| OS      | Command                          |
|---------|----------------------------------|
| Windows | Download MinGW → mingw-w64.org   |
| macOS   | `xcode-select --install`         |
| Linux   | `sudo apt install g++`           |

### Compile

```bash
g++ -std=c++17 main.cpp calculator.cpp -o calorie_calc
```

### Run

```bash
# macOS / Linux
./calorie_calc

# Windows
calorie_calc.exe
```

---

## 💻 Sample Output

```
╔══════════════════════════════╗
║   CalcFit — C++ Calorie      ║
║        Calculator            ║
╠══════════════════════════════╣
║  1. Mifflin-St Jeor (Best)   ║
║  2. Harris-Benedict          ║
║  3. Compare Both Formulas    ║
║  4. Exit                     ║
╚══════════════════════════════╝
  Choose (1–4): 1

┌──────────────────────────────┐
│     ENTER YOUR DETAILS       │
└──────────────────────────────┘

  Age (15–80)        : 22
  Gender (M/F)       : M
  Weight (kg)        : 70
  Height (cm)        : 175
  Your choice (1–6)  : 3

╔══════════════════════════════════════╗
║         YOUR CALORIE RESULTS         ║
╠══════════════════════════════════════╣
║  BMR (at rest)  :    1676 kcal/day   ║
╠══════════════════════════════════════╣
║  ⬇  Lose weight :    2097 kcal/day   ║
║  ⚖  Maintain    :    2597 kcal/day   ║
║  ⬆  Gain weight :    3097 kcal/day   ║
╚══════════════════════════════════════╝

┌─────────────────────────────────────┐
│       FULL ACTIVITY BREAKDOWN       │
├──────────────┬────────┬─────────────┤
│ Level        │  Mult  │  kcal/day   │
├──────────────┼────────┼─────────────┤
│ Sedentary    │ ×1.200 │    2011     │
│ Light        │ ×1.375 │    2304     │
│ Moderate     │ ×1.550 │    2597     │
│ Active       │ ×1.725 │    2890     │
│ Very Active  │ ×1.900 │    3184     │
│ Extra Active │ ×2.100 │    3519     │
└──────────────┴────────┴─────────────┘
```

---

## 📚 Concepts Learned

This project demonstrates the following C++ concepts:

- **Structs** — grouping related data (`UserData`, `Results`)
- **Header files** — separating declarations from implementation
- **Modular programming** — splitting code across multiple `.cpp` files
- **Functions** — input handling, calculation, display
- **`iomanip`** — formatted output with `setw`, `setprecision`, `fixed`
- **Switch statements** — activity level selection
- **Do-while loop** — replay without restarting the program
- **Pass by reference** — efficient data passing with `&`

---

## 🌐 Web Interface

A browser-based version of this calculator is included (`index.html`). Open it directly in any browser — no server needed.

**Features of the web UI:**
- Metric and Imperial unit toggle
- All 3 BMR formulas
- Live activity breakdown table
- Syntax-highlighted C++ code viewer

---

## 👤 Author

**Your Name**
- GitHub:[ [@yourusername](https://github.com/yourusername)](https://github.com/SshreyanshVITB)
- LinkedIn: [[Your LinkedIn](https://linkedin.com/in/yourprofile)](https://www.linkedin.com/in/shreyansh-singh-20aug2004/)

---

## 📄 License

This project is open source under the [MIT License](LICENSE).

---

> ⚠️ This tool is for educational purposes only. For personalized nutrition advice, consult a registered dietitian.
