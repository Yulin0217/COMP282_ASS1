//
// Created by Yulin on 30/04/2023.
//

#include "TuringTape.h"

using namespace std;

TuringTape::TuringTape(const TuringTape &turing_ref) {
    tape = turing_ref.tape;
    current_position = tape.begin();
}

TuringTape::TuringTape(int n) {
    tape.resize(n, 0);
}

bool TuringTape::moveRight() {
    if (current_position != tape.end()) {
        current_position++;
        return true;
    }
    return false;
}

bool TuringTape::moveLeft() {
    if (current_position > tape.begin() + 1) {
        current_position--;
        return true;
    }
    return false;
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

ostream& operator<<(ostream& out,const TuringTape& T) {
    for (auto i = T.tape.begin(); i != T.tape.end(); i++) {
        out << *i << " ";
    }
    out << endl;
    return out;
}



