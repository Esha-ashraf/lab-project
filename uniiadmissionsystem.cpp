#include <iostream>
#include <string>
using namespace std;

int main() {
    // Constants
    const int maxPrograms = 3;
    const int maxStudents = 100;
    const int maxSeats = 3;

    // Program details
    string programNames[maxPrograms] = {"BS AI", "BS SE", "BS CS"};
    int programEligibility[maxPrograms] = {600, 700, 800};
    int programSeats[maxPrograms] = {maxSeats, maxSeats, maxSeats};

    // Student details
    string studentNames[maxStudents];
    string studentEmails[maxStudents];
    string studentCnics[maxStudents];
    string appliedPrograms[maxStudents];
    string studentStatuses[maxStudents];
    string studentRejectionReasons[maxStudents];
    int studentPreviousMarks[maxStudents];
    int totalStudents = 0;

    // Admin credentials
    const string adminUsername = "admin";
    const string adminPassword = "password";

    int choice;

    // Main Menu
    while (true) {
        cout << "\nUniversity Admission Management System\n";
        cout << "1. Admin login\n";
        cout << "2. Student login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Admin Login
        if (choice == 1) {
            string enteredUsername, enteredPassword;
            cout << "Enter Admin Username: ";
            cin >> enteredUsername;
            cout << "Enter Admin Password: ";
            cin >> enteredPassword;

            if (enteredUsername == adminUsername && enteredPassword == adminPassword) {
                cout << "Admin Login Successful.\n";
                int adminChoice;
                cout << "1. View Programs\n2. View Applications\n3. Logout\n";
                cout << "Enter your choice: ";
                cin >> adminChoice;

                if (adminChoice == 1) {
                    cout << "\nPrograms Available:\n";
                    for (int i = 0; i < maxPrograms; i++) {
                        cout << programNames[i] << " (Eligibility: " << programEligibility[i]
                             << ", Seats: " << programSeats[i] << ")\n";
                    }
                } else if (adminChoice == 2) {
                    if (totalStudents > 0) {
                        cout << "\nApplications:\n";
                        for (int i = 0; i < totalStudents; i++) {
                            cout << "Student Name: " << studentNames[i] << "\n";
                            cout << "Applied Program: " << appliedPrograms[i] << "\n";
                            cout << "Status: " << studentStatuses[i] << "\n";
                            if (studentStatuses[i] == "Rejected") {
                                cout << "Reason: " << studentRejectionReasons[i] << "\n";
                            }
                            cout << "----------------------\n";
                        }
                    } else {
                        cout << "No applications submitted yet.\n";
                    }
                } else {
                    cout << "Logging out...\n";
                }
            } else {
                cout << "Invalid credentials. Try again.\n";
            }
        } 
        // Student Login
        else if (choice == 2) {
            if (totalStudents >= maxStudents) {
                cout << "Maximum student limit reached. Cannot accept more applications.\n";
                continue;
            }

            cout << "Enter your Name: ";
            cin >> studentNames[totalStudents];
            cout << "Enter your Email: ";
            cin >> studentEmails[totalStudents];
            cout << "Enter your CNIC: ";
            cin >> studentCnics[totalStudents];
            cout << "Enter your Previous Marks (out of 1000): ";
            cin >> studentPreviousMarks[totalStudents];

            cout << "\nAvailable Programs:\n";
            for (int i = 0; i < maxPrograms; i++) {
                cout << i + 1 << ". " << programNames[i]
                     << " (Eligibility: " << programEligibility[i]
                     << ", Seats: " << programSeats[i] << ")\n";
            }

            int programChoice;
            cout << "Enter your Program Preference (1, 2, or 3): ";
            cin >> programChoice;

            if (programChoice >= 1 && programChoice <= maxPrograms) {
                int programIndex = programChoice - 1;
                appliedPrograms[totalStudents] = programNames[programIndex];
                if (studentPreviousMarks[totalStudents] >= programEligibility[programIndex] &&
                    programSeats[programIndex] > 0) {
                    studentStatuses[totalStudents] = "Accepted";
                    programSeats[programIndex]--;
                } else {
                    studentStatuses[totalStudents] = "Rejected";
                    studentRejectionReasons[totalStudents] =
                        (studentPreviousMarks[totalStudents] < programEligibility[programIndex])
                            ? "Does not meet eligibility criteria."
                            : "No seats available.";
                }
            } else {
                appliedPrograms[totalStudents] = "Invalid Program";
                studentStatuses[totalStudents] = "Rejected";
                studentRejectionReasons[totalStudents] = "Invalid program choice.";
            }

            // Output result
            cout << "\nApplication Status: " << studentStatuses[totalStudents] << "\n";
            if (studentStatuses[totalStudents] == "Rejected") {
                cout << "Reason: " << studentRejectionReasons[totalStudents] << "\n";
            }
            totalStudents++;
        } 
        else if (choice == 3) {
            cout << "Exiting the system.\n";
            break;
        } 
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
