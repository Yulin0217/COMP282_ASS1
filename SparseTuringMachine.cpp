//
// Created by Yulin on 25/04/2023.
//
#include "SparseTuringMachine.h"
#include <algorithm>
#include <vector>

using namespace std;

TuringMachineState* SparseTuringMachine::find(int x, int y) {
    //Binary search, and time complexity of binary search is O(log n)
    int left = 0, right = states.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (states[mid].getCurrentState() == x && states[mid].getCurrentContent() == y) {
            return &states[mid];
        } else if (states[mid].getCurrentState() <= x && states[mid].getCurrentContent() < y)) {
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
    states.insert(lower_bound(states.begin(), states.end(), s), s);
}

vector<TuringMachineState>* SparseTuringMachine::getAll() {
    return &states;
}