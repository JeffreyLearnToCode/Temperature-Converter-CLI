#include <iostream>
#include <string>
#include <array>


bool validateUserPicked(const double &userPickedTemperature, const int &userChooseSize, const int &chooseOffset = 0) {
    return userPickedTemperature >= (userChooseSize + chooseOffset) ||
        userPickedTemperature <= (userChooseSize - userChooseSize);
}

void temperatureChooseShowCase(std::array<std::string, 3> units, const int &chooseOffset = 0) {
    for (int i = 0; i < units.size(); i++) {
        std::cout << (i+chooseOffset) << "."<< units[i] << std::endl;
    }
}

int main() {
    double userPickedTemp;
    const std::array<std::string, 3> temperatureUnit = {"Celsius", "Fahrenheit", "Kelvin"};
    const std::array<std::string, 3> temperatureUnitChar = {"C", "F", "K"};
    int userPickedTempUnit;
    int userDesiredTempUnit;

    std::cout << "Hello, please enter the current temperature: ";
    std::cin >> userPickedTemp;

    temperatureChooseShowCase(temperatureUnit, 1);
    std::cout << "What is the temperature unit: ";
    std::cin >> userPickedTempUnit;

    if (validateUserPicked(userPickedTempUnit, temperatureUnit.size(), 1)) {
        std::cout << "You entered an invalid desired temperature unit." << std::endl;
        return 0;
    }

    temperatureChooseShowCase(temperatureUnit, 1);
    std::cout << "What is the desired temperature unit: ";
    std::cin >> userDesiredTempUnit;

    if (validateUserPicked(userPickedTempUnit, temperatureUnit.size(), 1)) {
        std::cout << "You entered an invalid desired temperature unit." << std::endl;
        return 0;
    }

    const std::string& userPickedTempString = temperatureUnit[userPickedTempUnit - 1];
    const std::string& desiredPickedTempString = temperatureUnit[userDesiredTempUnit - 1];
    const std::string& tempChar = temperatureUnitChar[userDesiredTempUnit - 1];

    if (userPickedTempString == desiredPickedTempString) {
        std::cout << "Your desired temperature: " << userPickedTemp << "°" << tempChar<< std::endl;
    }

    if (userPickedTempString == "Celsius" && desiredPickedTempString == "Fahrenheit") {
        std::cout << "Your desired temperature: " << (userPickedTemp * 9 / 5) + 32 << "°" << tempChar<< std::endl;
    } else if (userPickedTempString == "Fahrenheit" && desiredPickedTempString == "Celsius") {
        std::cout << "Your desired temperature: " << (userPickedTemp - 32) * 5 / 9 << "°" << tempChar<< std::endl;
    } else if (userPickedTempString == "Celsius" && desiredPickedTempString == "Kelvin") {
        std::cout << "Your desired temperature: " << userPickedTemp + 273.15 << "°" << tempChar<< std::endl;
    } else if (userPickedTempString == "Kelvin" && desiredPickedTempString == "Celsius") {
        std::cout << "Your desired temperature: " << userPickedTemp - 273.15 << "°" << tempChar<< std::endl;
    } else if (userPickedTempString == "Fahrenheit" && desiredPickedTempString == "Kelvin") {
        std::cout << "Your desired temperature: " << (userPickedTemp - 32) * 5 / 9 + 273.15 << "°" << tempChar<< std::endl;
    } else if (userPickedTempString == "Kelvin" && desiredPickedTempString == "Fahrenheit") {
        std::cout << "Your desired temperature: " << (userPickedTemp - 273.15) * 9 / 5 + 32 << "°" << tempChar<< std::endl;
    }

    return 0;
}