#include <iostream>
#include <string>
#include <limits>
#include <array>

enum Unit {
    C = 1,
    F,
    K
};

constexpr double ZERO_C_TO_KELVIN = 273.15;

constexpr std::array<std::string_view, 3> unitsName = {"Celsius", "Fahrenheit", "Kelvin"};
constexpr std::array<std::string_view, 3> unitsSymbol = {"C", "F", "K"};

void printUnitNames(const int offset = 0) {
    for (int i = 0; i < static_cast<int>(unitsName.size()); i++) {
        std::cout << (i+offset) << "." << unitsName[i] << std::endl;
    }
}

int readCurrentUnitPick(const int low, const int high) {
    for (;;) {

        if (int unit; std::cin >> unit
            && unit >= low && unit <= high) return unit;

        // Error handling
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a valid temperature unit between " << low << " and " << high << ": ";
    }
}


double readCurrentTempPick() {
    for (;;) {
        if (double d; std::cin >> d) return d;

        // Error handling
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a valid temperature: ";
    }
}

constexpr double toKelvin(const Unit &u, const double &t) {
    switch (u) {
        case C: return (t + ZERO_C_TO_KELVIN);
        case F: return (t - 32) * 5/9 + ZERO_C_TO_KELVIN;
        case K: return t;
    }
    return t;
}

constexpr double fromKelvin(const Unit &u, const double &k) {
    switch (u) {
        case C: return (k - ZERO_C_TO_KELVIN);
        case F: return (k - ZERO_C_TO_KELVIN) * 9/5 + 32;
        case K: return k;
    }
    return k;
}

constexpr double convert(const double &temp, const Unit &to, const Unit &from) {
    if (to == from) return temp;

    return fromKelvin(to, toKelvin(from, temp));
}


int main() {
    // Get current temperature picked
    std::cout << "Please enter the current temperature: ";
    const double userCurrentTempPick = readCurrentTempPick();

    // This is used to set the desired offset for the printed option
    constexpr int offset = 1;

    // Get current temperature unit
    printUnitNames(offset);
    std::cout << "Please picked the current temperature unit: ";
    const int userCurrentTempUnit = readCurrentUnitPick(offset, unitsName.size());

    // Get desired temperature unit
    printUnitNames(offset);
    std::cout << "Please picked the desired temperature unit: ";
    const int userDesiredTempUnit = readCurrentUnitPick(offset, unitsName.size());

    const Unit to = static_cast<Unit>(userDesiredTempUnit);
    const Unit from = static_cast<Unit>(userCurrentTempUnit);

    // Convert temperature
    const double convertTemperature = convert(userCurrentTempPick, to, from);
    std::cout << "Your desired temperature: " << convertTemperature << "°" << unitsSymbol[userDesiredTempUnit - 1] << std::endl;

    return 0;
}