//
// Created by Yulin on 30/04/2023.
//

#include "TuringTape.h"

using namespace std;

TuringTape::TuringTape(const TuringTape &turing_ref) {
    tape = turing_ref.tape;
    current_position = tape.begin();
    most_right = tape.begin();
}

TuringTape::TuringTape(int n) {
    tape.resize(n, 0);
    current_position = tape.begin();
    most_right = tape.begin();
}

bool TuringTape::moveRight() {
    if (current_position == tape.end()) {
        return false;
    }
    current_position++;
    if (current_position > most_right) {
        most_right = current_position;
    }
    return true;
}

bool TuringTape::moveLeft() {
    if (current_position <= tape.begin() + 1 || current_position > tape.end()) {
        return false;
    } else {
        current_position--;
        return true;
    }
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

int TuringTape::getPosition() {
    return distance(tape.begin(), current_position);
}

ostream &operator<<(ostream &out, const TuringTape &T) {
    for (auto i = T.tape.begin(); i != T.most_right; i++) {
        out << *i << " ";
    }
    out << endl;
    return out;
}



