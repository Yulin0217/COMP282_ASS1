//
// Created by Yulin on 20/04/2023.
//

#ifndef TURINGMACHINESTATE_H_
#define TURINGMACHINESTATE_H_
#include <iostream>
#include <string>


class TuringMachineState {
public:
    TuringMachineState(int currentState, int currentContent, int nextState, int nextContent, std::string moveDirection);
    
    int getCurrentState() const;
    
    int getCurrentContent() const;
    
    int getNextState() const;
    
    int getNextContent() const;
    
    std::string getMoveDirection() const;
    
    friend std::ostream &operator<<(std::ostream &os, const TuringMachineState &state);
    
    friend std::istream &operator>>(std::istream &is, TuringMachineState &state);
    bool operator<(const TuringMachineState& state) const;
    bool operator>(const TuringMachineState& state) const;
    bool operator==(const TuringMachineState& state) const;

private:
    int currentState_mvar;
    int currentContent_mvar;
    int nextState_mvar;
    int nextContent_mvar;
    std::string moveDirection_mvar;
};


#endif
