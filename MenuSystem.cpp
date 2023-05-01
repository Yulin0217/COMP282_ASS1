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
    TuringMachineState s(0, 0, 0, 0, "->");
    //Initialize variable
    int step_sum = 0;
    current_turing_ptr = nullptr;
    current_state = 0;
    string move_direction;
    int i = 1;
    
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
                turing_ptr = new DenseTuringMachine(max_x, max_y);;
                break;
            case '2':
                break;
            case '3':
                cout << "What state do you wish to add?" << endl;
                int current_state_add, current_content_add, next_state_add, next_content_add;
                cin >> current_state_add >> current_content_add >> next_state_add >> next_content_add >> move_direction;
                s = TuringMachineState(current_state_add, current_content_add, next_state_add, next_content_add,
                                       move_direction);
                turing_ptr->add(s);
                break;
            case '4':
                break;
            case '5':
                cout << "How many steps do you wish to execute?" << endl;
                int step;
                step = 0;
                cin >> step;
                step_sum = step + step_sum;
                for (i = 1; i <= step; i++) {
                    if (tape.getPosition() < 0 || tape.getPosition() >= tape_size) {
                        cout << "In step " << step_sum << ", the position is " << "-1"
                             << ", but that is outside the tape." << endl;
                        break;
                    } else {
                        current_turing_ptr = turing_ptr->find(current_state, tape.getContent());
                        if (current_turing_ptr != nullptr) {
                            tape.setContent(current_turing_ptr->getNextContent());
                            if (current_turing_ptr->getMoveDirection() == "->") {
                                tape.moveRight();
                            } else if (current_turing_ptr->getMoveDirection() == "<-") {
                                tape.moveLeft();
                            }
                            current_state = current_turing_ptr->getNextState();
                            step_sum++;
                        } else {
                            cout << "In step " << step_sum << " there is no Turing machine state with state "
                                 << current_state << " and content " << tape.getContent()
                                 << endl;
                            break;
                            
                        }
                    }
                }
                break;
            case '6':
                //Out put current state
                cout << "The current state is " << current_state << "." << endl;
                //Out put position of TuringTape
                cout << "The current position is " << tape.getPosition() << "." << endl;
                //Out put content
                cout << "The content of the tape is " << tape << '.' << endl;
                cout << "The Turing machine has states: ";
                show(turing_ptr);
                cout << endl;
                break;
            default:
                break;
        }
    }
    
}

void MenuSystem::show(TuringMachine *t) {
    vector<TuringMachineState> vec = *t->getAll();
    for (auto s: *t->getAll()) cout << "<" << s << ">";
}

