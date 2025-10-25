#include <iostream>
#include <string>
#include <array>

int main() {
    int userPickedTemp;
    const std::array<std::string, 3> temperatureUnit = {"Celsius", "Fahrenheit", "Kelvin"};
    const std::array<char, 3> temperatureUnitChar = {'C', 'F', 'K'};
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





    return 0;
}