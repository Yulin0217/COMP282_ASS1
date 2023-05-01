//
// Created by Yulin on 20/04/2023.
//
#ifndef DENSETURINGMACHINE_H_
#define DENSETURINGMACHINE_H_

#include "TuringMachine.h"
#include <vector>


class DenseTuringMachine : public TuringMachine {
public:
    DenseTuringMachine(int x, int y);
    
    TuringMachineState *find(int x, int y);
    
    void add(TuringMachineState &s);
    
    std::vector<TuringMachineState>* getAll();
    

private:
    //Store the max value x and y
    int max_x_mvrb, max_y_mvrb;
    //Status Repository
    std::vector<TuringMachineState> states_repository;
    //Store the "currentState" and "currentContent"
    std::vector<std::vector<TuringMachineState *>> state_matrix;
};

#endif
