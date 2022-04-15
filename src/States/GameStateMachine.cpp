//
// Created by Christoffer Lehre on 14/04/2022.
//

#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState *pState) {
    m_gameStates.push_back(pState);
    m_gameStates.back()->onEnter();
}

void GameStateMachine::changeState(GameState *pState) {
    if(!m_gameStates.empty()){
        if(m_gameStates.back()->getStateID() == pState->getStateID()){
            return;
        }
        if(m_gameStates.back()->onExit()){
            delete m_gameStates.back();
            m_gameStates.pop_back();
        }
    }
    m_gameStates.push_back(pState);
    m_gameStates.back()->onEnter();
}

void GameStateMachine::popState(GameState *pState) {
    if(!m_gameStates.empty()){
        if(m_gameStates.back()->onExit()){
            delete m_gameStates.back();
            m_gameStates.pop_back();
        }
    }}