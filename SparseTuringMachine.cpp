//
// Created by Yulin on 25/04/2023.
//
#include "SparseTuringMachine.h"
#include <algorithm>
#include <vector>

using namespace std;

TuringMachineState* SparseTuringMachine::find(int x, int y) {
    //Binary search, and time complexity of binary search is O(log n)
    int left = 0, right = states_binary.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (states_binary[mid].getCurrentState() == x && states_binary[mid].getCurrentContent() == y) {
            return &states_binary[mid];
        } else if (states_binary[mid].getCurrentState() < x || (states_binary[mid].getCurrentState() == x && states_binary[mid].getCurrentContent() < y)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return nullptr;
}

void SparseTuringMachine::add(TuringMachineState &s)  {
    //Insert the new TuringMachineState into the ordered vector to prepare for binary search
    //lower_bound function has a time complexity of O(log n)
    //The < operator is already overload (in Class TuringMachineState), which could help sorts based on the current state and current content of each state.
    states_binary.insert(lower_bound(states_binary.begin(), states_binary.end(), s), s);
    //Keep the original states for getAll
    states.push_back(s);
}

vector<TuringMachineState>* SparseTuringMachine::getAll() {
    return &states;
}