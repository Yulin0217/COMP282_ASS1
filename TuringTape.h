#ifndef TURINGTAPE_H_
#define TURINGTAPE_H_

#include <iostream>
#include <vector>

using namespace std;

class TuringTape {
public:
    TuringTape(int n);
    
    TuringTape(const TuringTape &turing_ref);
    
    bool moveRight();
    
    bool moveLeft();
    
    int getContent();
    
    void setContent(int c);
    
    int getPosition();
    
    friend ostream &operator<<(ostream &out, const TuringTape &s);


private:
    vector<int> tape;
    vector<int>::iterator current_position;
};

#endif
