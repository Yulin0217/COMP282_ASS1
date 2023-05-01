#ifndef MENUSYSTEM_H_
#define MENUSYSTEM_H_
class MenuSystem {
public:
	void menu();
    void show(TuringMachine* t);
    TuringMachineState&
    build(int current_state_add, int current_content_add, int next_state_add, int next_content_add, std::string move_direction);
private:
    int tape_size;
    int current_state;
    int max_x;
    int max_y;
};

#endif /* MENUSYSTEM_H_ */
