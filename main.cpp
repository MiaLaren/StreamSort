// =====================================================

// Name: Mia Santos

// Course: ITSE 2359 C++ Programming

// Project: StreamSort++ (Units 14-16 Integration)

// File: main.cpp

// =====================================================


#include <iostream>
#include <limits>
#include "StreamQueue.h"

using namespace std;



void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    StreamQueue queue;
    int choice;

    while (true) {
        cout << "\n=== StreamSort++ Queue Manager ===\n";
        cout << "1. Add show\n2. Remove show\n3. Display all\n";
        cout << "4. Sort\n5. Search\n6. Sum ratings\n";
        cout << "7. Top show\n8. Exit\n";
        cout << "Choice: ";

        cin >> choice;

        if (cin.fail()) {
            cout << "ERROR: Invalid input. Please enter a number.\n";
            clearInput();
            continue;
        }

        clearInput();

        if (choice == 1) {
            string title;
            double rating;

            cout << "Title: ";
            getline(cin, title);

            cout << "Rating (0-10): ";
            cin >> rating;

            if (cin.fail()) {
                cout << "ERROR: Invalid rating input.\n";
                clearInput();
                continue;
            }

            try {
                queue.addShow(title, rating);
                cout << "Added: " << title << " (" << rating << ")\n";
            }
            catch (const invalid_argument&) {
                cout << "ERROR: Rating must be between 0.0 and 10.0.\n";
            }

        }
        else if (choice == 2) {
            int index;
            cout << "Index to remove: ";
            cin >> index;

            try {
                queue.removeShow(index);
                cout << "Show removed.\n";
            }
            catch (const out_of_range&) {
                cout << "ERROR: Invalid index.\n";
            }

        }
        else if (choice == 3) {
            queue.displayAll();
        }
        else if (choice == 4) {
            queue.sortByRating();
            cout << "Sorted by rating (highest first).\n";
        }
        else if (choice == 5) {
            string title;
            cout << "Enter title: ";
            getline(cin, title);
            queue.searchByTitle(title);
        }
        else if (choice == 6) {
            double sum = queue.sumRatings(0);
            cout << "Sum of all ratings: " << sum
                 << " (via recursion)\n";
        }
        else if (choice == 7) {
            if (cin.fail()) clearInput();

            cout << "Top show index: " << queue.findHighest(0) << endl;
        }
        else if (choice == 8) {
            cout << "Exiting program...\n";
            break;
        }
        else {
            cout << "Invalid menu choice.\n";
        }
    }

    return 0;
}


