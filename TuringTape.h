#ifndef TURINGTAPE_H_
#define TURINGTAPE_H_

#include <iostream>
#include <vector>


class TuringTape {
public:
    TuringTape(int n);
    
    TuringTape(const TuringTape &turing_ref);
    
    bool moveRight();
    
    bool moveLeft();
    
    int getContent();
    
    void setContent(int c);
    
    int getPosition();
    
    friend std::ostream &operator<<(std::ostream &out, const TuringTape &s);


private:
    std::vector<int> tape;
    std::vector<int>::iterator current_position;
    //Create an iterator to indicate the current rightmost content position
    std::vector<int>:: iterator most_right;
};

#endif
