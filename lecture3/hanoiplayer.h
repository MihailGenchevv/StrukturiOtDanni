#pragma once  
#include <stack>

#include <iostream>

class HanoiPlayer{
    public:
    HanoiPlayer(int n);

    struct gameMove {
        char from, to;
    };
    gameMove nextMove();
    bool moreMoves();

    private:
    struct GameGoal {
        int k;

        char source, dest, temp;
    };
    
    std::stack<GameGoal> s;
};