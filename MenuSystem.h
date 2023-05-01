#ifndef MENUSYSTEM_H_
#define MENUSYSTEM_H_
#include "TuringMachineState.h"
#include "TuringMachine.h"
class MenuSystem {
public:
	void menu();
    void show(TuringMachine* t);
private:
    int tape_size;
    TuringMachineState* current_turing_ptr;
    int current_state;
    int max_x;
    int max_y;
    TuringMachine *turing_ptr;
};

#endif /* MENUSYSTEM_H_ */

