#include "DenseTuringMachine.h"
#include <iostream>

DenseTuringMachine::DenseTuringMachine(int x, int y) : xMax(x), yMax(y) {
    stateMatrix.resize(x + 1);
    for (int i = 0; i <= x; i++) {
        stateMatrix[i].resize(y + 1, nullptr);
    }
}

TuringMachineState* DenseTuringMachine::find(int x, int y) {
    if (x > xMax || y > yMax) {
        return nullptr;
    }
    TuringMachineState* statePtr = stateMatrix[x][y];
    if (statePtr == nullptr) {
        return nullptr;
    }
    if (statePtr->getCurrentState() == x && statePtr->getCurrentContent() == y) {
        return statePtr;
    }
    return nullptr;
}

void DenseTuringMachine::add(TuringMachineState& s) {
    int currentState = s.getCurrentState();
    int currentContent = s.getCurrentContent();
    if (currentState > xMax || currentContent > yMax) {
        return;
    }
    TuringMachineState* existingStatePtr = find(currentState, currentContent);
    if (existingStatePtr != nullptr) {
        *existingStatePtr = s;
    } else {
        TuringMachineState* newStatePtr = new TuringMachineState(s);
        stateMatrix[currentState][currentContent] = newStatePtr;
        allStates.push_back(s);
    }
}

std::vector<TuringMachineState>* DenseTuringMachine::getAll(){
    return new std::vector<TuringMachineState>(allStates);
}
