#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Structure to store student information
struct Student {
    string name;
    int rollNo;
    float marks[5]; // Marks for 5 subjects
    float total;
    float average;
    char grade;
};

// Function prototypes
void inputStudentData(Student &s);
void calculateResult(Student &s);
void displayReportCard(const Student &s);
char calculateGrade(float avg);

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student students[n];

    // Input details for each student
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Student " << i + 1 << ":\n";
        inputStudentData(students[i]);
        calculateResult(students[i]);
    }

    // Display report cards
    cout << "\n==========================================\n";
    cout << "             REPORT CARDS                 \n";
    cout << "==========================================\n";
    for (int i = 0; i < n; i++) {
        displayReportCard(students[i]);
        cout << "------------------------------------------\n";
    }

    return 0;
}

// Function to input student data
void inputStudentData(Student &s) {
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter Roll Number: ";
    cin >> s.rollNo;

    cout << "Enter marks for 5 subjects (out of 100):\n";
    for (int i = 0; i < 5; i++) {
        cout << "Subject " << i + 1 << ": ";
        cin >> s.marks[i];
    }
}

// Function to calculate total, average, and grade
void calculateResult(Student &s) {
    s.total = 0;
    for (int i = 0; i < 5; i++) {
        s.total += s.marks[i];
    }
    s.average = s.total / 5.0;
    s.grade = calculateGrade(s.average);
}

// Function to determine grade based on average
char calculateGrade(float avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 80) return 'B';
    else if (avg >= 70) return 'C';
    else if (avg >= 60) return 'D';
    else return 'F';
}

// Function to display student report card
void displayReportCard(const Student &s) {
    cout << "\nName: " << s.name << endl;
    cout << "Roll No: " << s.rollNo << endl;
    cout << "Marks: ";
    for (int i = 0; i < 5; i++)
        cout << s.marks[i] << " ";
    cout << endl;
    cout << fixed << setprecision(2);
    cout << "Total Marks: " << s.total << endl;
    cout << "Average: " << s.average << endl;
    cout << "Grade: " << s.grade << endl;
}



