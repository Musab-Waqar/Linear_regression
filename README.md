# Linear Regression — C++ & Qt

A simple linear regression tool built from scratch in C++ and Qt. No ML libraries — just least squares math, wrapped in a native desktop GUI with live charting.

![C++](https://img.shields.io/badge/C%2B%2B-17-blue?logo=cplusplus)
![Qt](https://img.shields.io/badge/Qt-6-green?logo=qt)
![CMake](https://img.shields.io/badge/build-CMake-informational?logo=cmake)
![License](https://img.shields.io/badge/license-MIT-lightgrey)
![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey)

---

## Preview

![App Preview](https://placehold.co/700x420/1e1e2e/4fc3f7?text=Linear+Regression+App+%E2%80%94+Screenshot+Here)

*Drag-and-drop CSV loading, live scatter plot, fitted regression line, and predicted point shown in red.*

---

## Architecture

![Architecture Diagram](https://mermaid.ink/img/CmdyYXBoIExSCiAgICBBW0NTViBGaWxlXSAtLT58ZHJhZyAmIGRyb3B8IEJbTWFpbldpbmRvdyAtIFF0IEdVSV0KICAgIEIgLS0-fGxvYWRGcm9tQ3N2fCBDW0xpbmVhclJlZ3Jlc3Npb24gTW9kZWxdCiAgICBDIC0tPnxmaXR8IERbQ29tcHV0ZSBtLCBjLCBSMl0KICAgIEQgLS0-IEVbUXRDaGFydHMgVmlld10KICAgIEIgLS0-fHByZWRpY3QgeHwgQwogICAgQyAtLT58cHJlZGljdGVkIHl8IEUKICAgIEUgLS0-IEYoKFJlZCBQcmVkaWN0ZWQgUG9pbnQpKQo=)

The core math lives in a plain C++ class (`LinearRegression`) — no Qt dependency, no external ML library. The Qt layer (`MainWindow`) only handles input/output: reading the CSV, drawing the chart, and displaying results. Model logic and GUI logic are fully decoupled.

---

## Features

- 📂 **Drag-and-drop CSV loading** — drop a two-column CSV (X, Y) straight onto the window
- 📐 **Least squares regression** — computes slope, intercept, and R² from scratch
- 📊 **Live charting** — data points, regression line, and R² rendered via QtCharts
- 🔴 **Prediction tool** — type any X, get the predicted Y, plotted live on the chart in red

---

## The Math

```
m = (n·Σ(xy) − Σx·Σy) / (n·Σ(x²) − (Σx)²)
c = (Σy − m·Σx) / n

y_predicted = m·x + c

R² = 1 − (SS_res / SS_tot)
```

---

## Requirements

- Qt 6 (with the **Charts** module)
- CMake 3.16+
- A C++17-compatible compiler

---

## Build & Run

```bash
git clone https://github.com/Musab-Waqar/linear_regression.git
cd linear_regression
```

Open `CMakeLists.txt` in Qt Creator, configure with a Qt 6 kit that includes Charts, then build and run (**Ctrl+R**).

---

## Usage

1. Drag and drop a CSV file (two columns: `X`, `Y`, no header) onto the window.
2. Click **Compute Regression** — fits the line and shows R².
3. Type an X value in the input box and click **Predict** — the predicted Y appears as a red point on the chart.

---

## Tech Stack

| Layer         | Tool                                 |
|---------------|---------------------------------------|
| Language      | C++17                                  |
| GUI Framework | Qt 6 (Widgets + Charts)               |
| Build System  | CMake                                  |
| Math          | Custom least-squares implementation    |

---

## License

MIT — free to use, modify, and learn from.
