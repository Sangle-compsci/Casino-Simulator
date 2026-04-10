# 🎲 Monte Carlo Casino Simulation
### Martingale vs. Flat Betting Strategy

![C++](https://img.shields.io/badge/C%2B%2B-17-blue?style=flat-square&logo=c%2B%2B)
![Python](https://img.shields.io/badge/Python-3.10-yellow?style=flat-square&logo=python)

A financial risk simulation analyzing the Martingale strategy versus Flat (Safe) Betting using the Monte Carlo method.

---

## 🚀 Key Features

* **Multi-threading Engine:**
  - Maximizes CPU utilization across 16 threads.
  - Simulates millions of betting rounds in mere seconds.
* **Object-Oriented Design (OOP):**
  - **Strategy Pattern:** Enables flexible management and swapping of betting algorithms.
  - **Factory Pattern:** Streamlines player object initialization.
* **Automated Data Pipeline:**
  - C++ engine handles heavy logic computation and outputs raw CSV data.
  - Automatically triggers a Python script for data parsing and chart plotting.

---

## 🛠️ System Architecture

### 1. C++ Core (Simulation Layer)
* **Probability:** Implements a standard Casino House Edge (48.6% win rate).
* **Randomness:** Utilizes the high-quality `mt19937` (Mersenne Twister) random number generator.
* **Performance:** Features a **No-Mutex** architecture to avoid thread bottlenecks and optimize file I/O speed.

### 2. Python Analysis (Visualization)
* **Statistics:** Calculates Expected Value (EV) across 16 independent parallel universes.
* **Visualization:** Automatically plots a 3-chart comparison panel showing rapid bankruptcy (worst-case), prolonged survival (best-case), and the mathematical average.

---

## 📈 Simulation Results

### Result Analysis:
1. **Martingale:** Yields frequent small wins but is highly susceptible to instant bankruptcy when hitting a long losing streak.
2. **Flat Betting:** Results in slow, steady capital depletion due to the built-in house edge.
3. **Conclusion:** All paths eventually converge to $0 (The Gambler's Ruin).

---

## ⚙️ Setup & Usage

### 1. Prerequisites
Create an empty `data/` folder in the root directory of the project to store output logs.

### 2. Python Dependencies
Run the following command in your terminal to install the required libraries:

```bash
pip install pandas matplotlib numpy
```

### 3. Execution
* Open the `.sln` file using Visual Studio (2022 recommended).
* Press **F5** or click **Local Windows Debugger** to build and run.
* Wait a few seconds for the C++ engine to finish compiling and running; the Python charts will pop up automatically.

---
> **Disclaimer:** This project is strictly for educational purposes and probability research. It does not encourage or promote gambling.

**Author:** [Sangle]