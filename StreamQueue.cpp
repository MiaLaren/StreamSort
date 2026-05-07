// =====================================================

// Name: Mia Santos

// Course: ITSE 2359 C++ Programming

// Project: StreamSort++ (Units 14-16 Integration)

// File: StreamQueue.cpp

// =====================================================


#include "StreamQueue.h"
#include <iostream>
#include <stdexcept>
#include <cctype>



// helper- convert the  string to lowercase
static std::string toLower(const std::string& s) {
    std::string result = s;
    for (char& c : result) c = std::tolower(c);
    return result;
}


void StreamQueue::addShow(const std::string& title, double rating) {
    if (rating < 0.0 || rating > 10.0) {
        throw std::invalid_argument("Rating must be between 0.0 and 10.0");
    }

    titles.push_back(title);
    ratings.push_back(rating);
}


void StreamQueue::removeShow(int index) {
    if (index < 0 || index >= (int)titles.size()) {
        throw std::out_of_range("Invalid index");
    }

    titles.erase(titles.begin() + index);
    ratings.erase(ratings.begin() + index);
}


void StreamQueue::displayAll() const {
    if (titles.empty()) {
        std::cout << "No shows in queue.\n";
        return;
    }

    for (int i = 0; i < (int)titles.size(); i++) {
        std::cout << i << ". " << titles[i]
                  << " (" << ratings[i] << ")\n";
    }
}



void StreamQueue::sortByRating() {
    for (int i = 0; i < (int)ratings.size() - 1; i++) {
        int maxIdx = i;

        for (int j = i + 1; j < (int)ratings.size(); j++) {
            if (ratings[j] > ratings[maxIdx]) {
                maxIdx = j;
            }
        }

        std::swap(ratings[i], ratings[maxIdx]);
        std::swap(titles[i], titles[maxIdx]);
    }
}



void StreamQueue::searchByTitle(const std::string& title) const {
    std::string target = toLower(title);

    for (int i = 0; i < (int)titles.size(); i++) {
        if (toLower(titles[i]) == target) {
            std::cout << "Found: " << titles[i]
                      << " (" << ratings[i] << ")\n";
            return;
        }
    }

    std::cout << "Show not found.\n";
}



double StreamQueue::sumRatings(int index) const {
    if (index >= (int)ratings.size()) {
        return 0.0;
    }
    return ratings[index] + sumRatings(index + 1);
}



int StreamQueue::findHighest(int index) const {
    if (index == (int)ratings.size() - 1) {
        return index;
    }

    int bestInRest = findHighest(index + 1);

    if (ratings[index] > ratings[bestInRest]) {
        return index;
    }
    return bestInRest;
}




