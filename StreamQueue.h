// =====================================================

// Name: Mia Santos

// Course: ITSE 2359 C++ Programming

// Project: StreamSort++ (Units 14-16 Integration)

// File: StreamQueue.h

// =====================================================


#ifndef STREAMQUEUE_H
#define STREAMQUEUE_H

#include <vector>
#include <string>



class StreamQueue {
private:
    std::vector<std::string> titles;
    std::vector<double> ratings;

public:
    void addShow(const std::string& title, double rating);
    void removeShow(int index);
    void displayAll() const;

    void sortByRating();
    void searchByTitle(const std::string& title) const;

    // RECURSIVE FUNCTIONS
    double sumRatings(int index) const;
    int findHighest(int index) const;
};



#endif
