//
// Created by Yulin on 30/04/2023.
//

#include "TuringTape.h"

using namespace std;

//Create indexed copy constructors for deep copy to prevent iterator dangling pointer
TuringTape::TuringTape(const TuringTape &turing_ref) {
    n_m = turing_ref.n_m;
    if (n_m == -1) {
        infinite_mode = true;
        tape = turing_ref.tape;
        tape.resize(1, 0);
        current_position = tape.begin();
        most_right = tape.begin();
    } else {
        tape = turing_ref.tape;
        current_position = tape.begin();
        most_right = tape.begin();
    }
}

TuringTape::TuringTape(int n) {
    if (n == -1) {
        n_m = n;
        infinite_mode = true;
        tape.resize(1, 0);
    } else {
        n_m = n;
        tape.resize(n, 0);
        current_position = tape.begin();
        most_right = tape.begin();
    }
    
}

bool TuringTape::moveRight() {
    current_position++;
    if (!infinite_mode) {
        if (current_position == tape.end()) {
            return false;
        }
    }
    //Update most_right iterator
    if (current_position >= most_right) {
        most_right = current_position;
        if (infinite_mode) {
            tape.push_back(0);
            current_position = tape.end()-2;
            most_right= tape.end()-2;
        }
    }
    return true;
}

bool TuringTape::moveLeft() {
    current_position--;
    if (current_position < tape.begin()) {
        return false;
    }
    return true;
}

int TuringTape::getContent() {
    if (current_position < tape.begin() || current_position >= tape.end()) {
        return 0;
    }
    return *current_position;
}

void TuringTape::setContent(int c) {
    if (current_position >= tape.begin() && current_position < tape.end()) {
        *current_position = c;
    }
}

//Use the distance function to calculate the distance
// between the start and the current position of the iterator to get the position
int TuringTape::getPosition() {
    return distance(tape.begin(), current_position);
}

ostream &operator<<(ostream &out, const TuringTape &T) {
    for (auto i = T.tape.begin(); i != T.most_right + 1; i++) {
        out << *i;
    }
    return out;
}


