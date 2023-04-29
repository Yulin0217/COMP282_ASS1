//
// Created by Yulin on 20/04/2023.
//
#include "DenseTuringMachine.h"
#include <iostream>

using namespace std;

DenseTuringMachine::DenseTuringMachine(int x, int y) : max_x_mvrb(x), max_y_mvrb(y) {
    //Resize the vector to (x+1)*(y+1),
    // which can store every possible state and content (as pointers) of the turing machine(In the state/content range max_x and max_y),
    // contents are all NULL at first.
    state_matrix.resize(x + 1);
    for (int i = 0; i <= x; i++) {
        state_matrix[i].resize(y + 1, nullptr);
    }
}

TuringMachineState *DenseTuringMachine::find(int x, int y) {
    //Check for out of range, if so, return NULL
    if (x > max_x_mvrb || y > max_y_mvrb) {
        return nullptr;
    }
    //Get a TuringMachineState pointer from state_matrix based on parameters x and y
    TuringMachineState *state_pointer = state_matrix[x][y];
    if (state_pointer == nullptr) {
        return nullptr;
    }
    //Check for a match with the search target
    if (state_pointer->getCurrentState() == x && state_pointer->getCurrentContent() == y) {
        return state_pointer;
    }
    return nullptr;
}

void DenseTuringMachine::add(TuringMachineState &s) {
    int current_state = s.getCurrentState();
    int current_content = s.getCurrentContent();
    //Check for out of range, if so terminate
    if (current_state > max_x_mvrb || current_content > max_y_mvrb) {
        return;
    }
    //Check whether already exist or not
    TuringMachineState *exist_state_pointer = find(current_state, current_content);
    if (exist_state_pointer != nullptr) {
        *exist_state_pointer = s;
    } else {
        TuringMachineState *new_state_pointer = new TuringMachineState(s);
        state_matrix[current_state][current_content] = new_state_pointer;
        states_repository.push_back(s);
    }
}

vector<TuringMachineState> *DenseTuringMachine::getAll() {
    //Return the pointer to "states_repository" but not the whole vector
    return &states_repository;
}
