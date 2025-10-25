#include <iostream>
#include <string>
#include <array>

int main() {
    double userPickedTemp;
    const std::array<std::string, 3> temperatureUnit = {"Celsius", "Fahrenheit", "Kelvin"};
    const std::array<std::string, 3> temperatureUnitChar = {"C", "F", "K"};
    int userPickedTempUnit;
    int userDesiredTempUnit;

    std::cout << "Hello, please enter the current temperature: ";
    std::cin >> userPickedTemp;

    for (int i = 0; i < temperatureUnit.size(); i++) {
        std::cout << (i+1) << "."<< temperatureUnit[i] << std::endl;
    }
    std::cout << "What is the temperature unit: ";
    std::cin >> userPickedTempUnit;

    if (userPickedTempUnit >= (temperatureUnit.size() + 1) ||
        userPickedTempUnit <= (temperatureUnit.size() - temperatureUnit.size())) {
        std::cout << "You entered an invalid desired temperature unit." << std::endl;
        return 0;
    }

    for (int i = 0; i < temperatureUnit.size(); i++) {
        std::cout << (i+1) << "."<< temperatureUnit[i] << std::endl;
    }
    std::cout << "What is the desired temperature unit: ";
    std::cin >> userDesiredTempUnit;

    if (userDesiredTempUnit >= (temperatureUnit.size() + 1) ||
        userDesiredTempUnit <= (temperatureUnit.size() - temperatureUnit.size())) {
        std::cout << "You entered an invalid desired temperature unit." << std::endl;
        return 0;
    }

    const std::string& userPickedTempString = temperatureUnit[userPickedTempUnit - 1];
    const std::string& desiredPickedTempString = temperatureUnit[userDesiredTempUnit - 1];
    const std::string& tempChar = temperatureUnitChar[userDesiredTempUnit - 1];


    if (userPickedTempString == desiredPickedTempString ) {
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