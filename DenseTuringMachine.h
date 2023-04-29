#ifndef DENSE_TURING_MACHINE_H
#define DENSE_TURING_MACHINE_H

#include "TuringMachine.h"
#include <vector>

class DenseTuringMachine : public TuringMachine {
public:
    DenseTuringMachine(int x, int y);
    TuringMachineState* find(int x, int y);
    void add(TuringMachineState& s);
    std::vector<TuringMachineState>* getAll() ;
private:
    int xMax, yMax;
    std::vector<TuringMachineState> allStates;
    std::vector<std::vector<TuringMachineState*>> stateMatrix;
};

#endif
