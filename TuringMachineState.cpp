//
// Created by Yulin on 20/04/2023.
//
#include "TuringMachineState.h"
#include <iostream>

using namespace std;

TuringMachineState::TuringMachineState(int currentState, int currentContent, int nextState, int nextContent,
                                       string moveDirection) :
        currentState_mvar(currentState),
        currentContent_mvar(currentContent),
        nextState_mvar(nextState),
        nextContent_mvar(nextContent),
        moveDirection_mvar(moveDirection) {
}

int TuringMachineState::getCurrentState() const {
    return currentState_mvar;
}

int TuringMachineState::getCurrentContent() const {
    return currentContent_mvar;
}

int TuringMachineState::getNextState() const {
    return nextState_mvar;
}

int TuringMachineState::getNextContent() const {
    return nextContent_mvar;
}

string TuringMachineState::getMoveDirection() const {
    return moveDirection_mvar;
}

ostream &operator<<(ostream &os, const TuringMachineState &state) {
    os << state.currentState_mvar << " "
       << state.currentContent_mvar << " "
       << state.nextState_mvar << " "
       << state.nextContent_mvar << " "
       << state.moveDirection_mvar;
    return os;
}

istream &operator>>(istream &is, TuringMachineState &state) {
    int currentState, currentContent, nextState, nextContent;
    string moveDirection;
    is >> currentState >> currentContent >> nextState >> nextContent >> moveDirection;
    state = TuringMachineState(currentState, currentContent, nextState, nextContent, moveDirection);
    return is;
}

bool TuringMachineState::operator>(const TuringMachineState &state) const {
    if (currentState_mvar != state.currentState_mvar) {
        return currentState_mvar > state.currentState_mvar;
    } else {
        return currentContent_mvar > state.currentContent_mvar;
    }
}

bool TuringMachineState::operator<(const TuringMachineState &state) const {
    if (currentState_mvar != state.currentState_mvar) {
        return currentState_mvar < state.currentState_mvar;
    } else {
        return currentContent_mvar < state.currentContent_mvar;
    }
}


bool TuringMachineState::operator==(const TuringMachineState &state) const {
    return currentState_mvar == state.currentState_mvar && currentContent_mvar == state.currentContent_mvar;
}

