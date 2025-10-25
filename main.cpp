#include <iostream>
#include <string>
#include <array>


class TemperatureConverter {
    const std::array<std::string, 3> temperatureUnits = {"Celsius", "Fahrenheit", "Kelvin"};
    const std::array<std::string, 3> temperatureUnitChar = {"C", "F", "K"};
    std::string userPickedTempString;
    std::string desiredPickedTempString;
    std::string tempChar;
    double userPickedTemp = 0;

    void outputTemperatureChoose(const int &offset = 0) const {
        for (int i = 0; i < this->temperatureUnits.size(); i++) {
            std::cout << (i+offset) << "."<< this->temperatureUnits[i] << std::endl;
        }
    }

    void validateUserPicked(const int &offset = 0) const {
        if (this->userPickedTemp >= (this->temperatureUnits.size() + offset) ||
            this->userPickedTemp <= (this->temperatureUnits.size() - this->temperatureUnits.size())){
                std::cout << "You entered an invalid desired temperature unit." << std::endl;
            }
    }

    void userChoose() {
        int userPickedTempUnit;
        int userDesiredTempUnit;


        std::cout << "Hello, please enter the current temperature: ";
        std::cin >> userPickedTemp;

        this->outputTemperatureChoose(1);
        std::cout << "What is the temperature unit: ";
        std::cin >> userPickedTempUnit;
        this->validateUserPicked(1);

        this->outputTemperatureChoose(1);
        std::cout << "What is the desired temperature unit: ";
        std::cin >> userDesiredTempUnit;
        this->validateUserPicked(1);

        userPickedTempString = this->temperatureUnits[userPickedTempUnit - 1];
        desiredPickedTempString = this->temperatureUnits[userDesiredTempUnit - 1];
        tempChar = this->temperatureUnitChar[userDesiredTempUnit - 1];
    }

    void outputDesiredTemperature() const {
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
    }


public:
    TemperatureConverter() {
        userChoose();
        outputDesiredTemperature();
    };
};


int main() {
    TemperatureConverter temperatureConverter;

    return 0;
}