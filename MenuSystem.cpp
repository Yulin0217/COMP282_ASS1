//
// Created by Yulin on 01/05/2023.
//
#include <iostream>
#include "TuringMachineState.h"
#include <vector>
#include "DenseTuringMachine.h"
#include <algorithm>
#include "TuringTape.h"
#include "MenuSystem.h"
#include <string>

using namespace std;

void MenuSystem::menu() {
    std::cout << "How long should the tape be?" << std::endl;
    std::cin >> tape_size;
    
    //Creat initial turing machine
    TuringTape tape(tape_size);
    DenseTuringMachine dense(0, 0);
    DenseTuringMachine *dense_ptr = &dense;
    TuringMachineState s(0, 0, 0, 0, "->");
    current_state = 0;
    string move_direction;
    
    while (true) {
        cout << "1. Create dense Turing machine" << endl;
        cout << "2. Create sparse Turing machine" << endl;
        cout << "3. Add state to Turing machine" << endl;
        cout << "4. Compact Turing machine" << endl;
        cout << "5. Execute Turing machine" << endl;
        cout << "6. Output current information" << endl;
        cout << "Write q or Q to quit" << endl;
        cout << "Enter Option " << endl;
        
        char choice;
        cin >> choice;
        
        if (choice == 'q' || choice == 'Q') {
            exit(0);
        }
        
        switch (choice) {
            case '1':
                cout << "What is the maximum state and what is the maximum content?" << endl;
                std::cin >> max_x >> max_y;
                dense = DenseTuringMachine(max_x,max_y);
                break;
            case '2':
                break;
            case '3':
                cout << "What state do you wish to add?" << endl;
                int current_state_add, current_content_add, next_state_add, next_content_add;
                cin >> current_state_add >> current_content_add >> next_state_add >> next_content_add >> move_direction;
                s = TuringMachineState(current_state_add, current_content_add, next_state_add, next_content_add,move_direction);
                dense.add(s);
                dense_ptr = &dense;
                break;
            case '4':
                break;
            case '5':
                break;
            case '6':
                //Out put current state
                cout << "The current state is " << current_state << "." << endl;
                //Out put position of TuringTape
                cout << "The current position is " << tape.getPosition() << "." << endl;
                //Out put content
                cout << "The content of the tape is ";
                cout << tape;
                cout << "." << endl;
                cout << "The Turing machine has states: ";
                show(dense_ptr);
                cout << endl;
                break;
        }
    }
    
}

void MenuSystem::show(TuringMachine *t) {
    vector<TuringMachineState> vec = *t->getAll();
    for (auto s: *t->getAll()) cout << "<" << s << ">";
}

