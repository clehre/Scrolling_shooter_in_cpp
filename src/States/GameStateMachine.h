//
// Created by Christoffer Lehre on 14/04/2022.
//

#ifndef CPP_EKSAMEN3_GAMESTATEMACHINE_H
#define CPP_EKSAMEN3_GAMESTATEMACHINE_H


#include <vector>
#include "GameState.h"

class GameStateMachine {

public:
    void changeState(GameState* pState);

    void pushState(GameState* pState);

    void popState(GameState* pState);


private:
    std::vector<GameState*> m_gameStates;

};


#endif //CPP_EKSAMEN3_GAMESTATEMACHINE_H