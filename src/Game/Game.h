//
// Created by Christoffer Lehre on 05/04/2022.
//

#ifndef _GAME_H
#define _GAME_H

#include <vector>
#include <memory>
#include "../SupportClasses/Randomizer.h"
#include "../GameObjects/Projectile.h"
#include "../InputHandler/InputHandler.h"
#include "../SupportClasses/TextureManager.h"
#include "../SupportClasses/ObjectParamLoader.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/Enemy.h"
#include "../States/GameStateMachine.h"

class Game {
private:
    Game() {};

    bool m_isRunning;
    Uint32 m_frameStart;
    Uint32 m_frameTime;

    std::vector<std::shared_ptr<Renderable>> m_renderableObjects;
    std::shared_ptr<Renderable> m_player;


    GameStateMachine *m_gameStateMachine;


public:
    Game(const Game &) = delete;

    Game &operator=(const Game &) = delete;

    Game(Game &&) = delete;

    Game &operator=(Game &&) = delete;

    static auto &Instance() {
        static Game game;
        return game;
    }

    void init();

    void loop();

    void quit();

    void addGameObject(const std::shared_ptr<Renderable> &newGO);

    [[nodiscard]] const std::vector<std::shared_ptr<Renderable>> &getGameObjects() const;

    void randomEnemy();


    void renderLoop();

    [[nodiscard]] Uint32 getFrameTime() const;

};


#endif //_GAME_H
