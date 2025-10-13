#include<bits/stdc++.h>
using namespace std; 

void kmToMiles();
void milesToKm();
void kgToLbs();
void lbsToKg();
void celsiusToFahrenheit();
void fahrenheitToCelsius();

int main() {
int choice;

    cout << "==============================\n";
    cout << "       UNIT CONVERTER\n";
    cout << "==============================\n";
    cout << "1. Kilometers to Miles\n";
    cout << "2. Miles to Kilometers\n";
    cout << "3. Kilograms to Pounds\n";
    cout << "4. Pounds to Kilograms\n";
    cout << "5. Celsius to Fahrenheit\n";
    cout << "6. Fahrenheit to Celsius\n";
    cout << "0. Exit\n";
    cout << "==============================\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: kmToMiles(); break;
            case 2: milesToKm(); break;
            case 3: kgToLbs(); break;
            case 4: lbsToKg(); break;
            case 5: celsiusToFahrenheit(); break;
            case 6: fahrenheitToCelsius(); break;
            case 0: cout << "End of Program.\n";
            break;
            default: cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
} 

void kmToMiles() {
    double km;
    cout << "Enter distance in kilometers: ";
    cin >> km;
    cout << km << " km = " << km * 0.621371 << " miles\n";
}

void milesToKm() {
    double miles;
    cout << "Enter distance in miles: ";
    cin >> miles;
    cout << miles << " miles = " << miles * 1.60934 << " km\n";
}

void kgToLbs() {
    double kg;
    cout << "Enter weight in kilograms: ";
    cin >> kg;
    cout << kg << " kg = " << kg * 2.20462 << " lbs\n";
}

void lbsToKg() {
    double lbs;
    cout << "Enter weight in pounds: ";
    cin >> lbs;
    cout << lbs << " lbs = " << lbs * 0.453592 << " kg\n";
}

void celsiusToFahrenheit() {
    double c;
    cout << "Enter temperature in Celsius: ";
    cin >> c;
    cout << c << "°C = " << (c * 9/5) + 32 << "°F\n";
}

void fahrenheitToCelsius() {
    double f;
    cout << "Enter temperature in Fahrenheit: ";
    cin >> f;
    cout << f << "°F = " << (f - 32) * 5/9 << "°C\n";
}
