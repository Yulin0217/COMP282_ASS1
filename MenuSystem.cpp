//
// Created by Yulin on 20/04/2023.
//
#include <iostream>
#include "TuringMachineState.h"
#include <vector>
#include "DenseTuringMachine.h"
#include <algorithm>
#include "TuringTape.h"
#include "MenuSystem.h"
#include <string>
#include "SparseTuringMachine.h"

using namespace std;

void MenuSystem::menu() {
    std::cout << "How long should the tape be?" << std::endl;
    std::cin >> tape_size;
    
    //Creat initial turing machine
    TuringTape tape(tape_size);
    //Prepare for add in case3
    TuringMachineState s(0, 0, 0, 0, "->");
    //Prepare for add TuringMachineState in case4
    TuringMachineState new_state_for_sparse(0, 0, 0, 0, "->");
    //Initialize variable
    int step_sum = 0;
    current_turing_ptr = nullptr;
    current_state = 0;
    string move_direction;
    int i = 1;
    //Ready to store all pointer of TuringMachineState from sparseturing in case 4
    vector<TuringMachineState> *all_state;
    //To store all states and content in case4
    set<int> turing_state;
    set<int> turing_content;
    
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
                cin >> max_x >> max_y;
                turing_ptr = new DenseTuringMachine(max_x, max_y);;
                break;
            case '2':
                turing_ptr = new SparseTuringMachine;
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
                all_state = turing_ptr->getAll();
                //Put all states(current and next) and all content(current and next) into state and content container.
                for (TuringMachineState &states: *all_state) {
                    turing_state.insert(states.getCurrentState());
                    turing_state.insert(states.getNextState());
                    turing_content.insert(states.getCurrentContent());
                    turing_content.insert(states.getNextContent());
                }
                int state_size;
                state_size = turing_state.size();
                int content_size;
                content_size = turing_content.size();
                //Redirecting the pointer to point to a DenseTuringMachine.
                turing_ptr = new DenseTuringMachine(state_size, content_size);
                //Add all new TuringMachineState to Densetuirngmachine
                for (TuringMachineState &states: *all_state) {
                    int new_current_state = distance(turing_state.begin(), turing_state.find(states.getCurrentState()));
                    int new_next_state = distance(turing_state.begin(), turing_state.find(states.getNextState()));
                    int new_current_content = distance(turing_content.begin(),
                                                       turing_content.find(states.getCurrentContent()));
                    int new_next_content = distance(turing_content.begin(),
                                                    turing_content.find(states.getNextContent()));
                    new_state_for_sparse = TuringMachineState(new_current_state, new_current_content, new_next_state,
                                                              new_next_content, states.getMoveDirection());
                    turing_ptr->add(new_state_for_sparse);
                }
                break;
            case '5':
                cout << "How many steps do you wish to execute?" << endl;
                int step;
                step = 0;
                cin >> step;
                // Add the number of steps to the total number of steps taken so far
                step_sum = step + step_sum;
                for (i = 1; i <= step; i++) {
                    // Check if the tape head is outside the bounds of the tape
                    if (tape.getPosition() < 0 || tape.getPosition() >= tape_size) {
                        cout << "In step " << step_sum << ", the position is " << tape.getPosition()
                             << ", but that is outside the tape." << endl;
                        break;
                    } else {
                        // Find the current Turing machine state based on the current state and content of the tape
                        current_turing_ptr = turing_ptr->find(current_state, tape.getContent());
                        // If a matching state is found, update the tape content, move the tape head, and update the current state
                        if (current_turing_ptr != nullptr) {
                            tape.setContent(current_turing_ptr->getNextContent());
                            if (current_turing_ptr->getMoveDirection() == "->") {
                                tape.moveRight();
                            } else if (current_turing_ptr->getMoveDirection() == "<-") {
                                tape.moveLeft();
                            }
                            current_state = current_turing_ptr->getNextState();
                            // If no matching state is found, print an error message and exit the loop
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

//Function to show all turingmachine
void MenuSystem::show(TuringMachine *t) {
    vector<TuringMachineState> vec = *t->getAll();
    for (auto s: *t->getAll()) cout << "<" << s << ">";
}
