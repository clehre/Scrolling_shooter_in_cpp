//
// Created by Christoffer Lehre on 15/04/2022.
//

#ifndef CPP_EKSAMEN3_UI_ELEMENT_H
#define CPP_EKSAMEN3_UI_ELEMENT_H


#include "GameObject.h"

class UI_Element : public GameObject{
public:
    UI_Element(const ObjectParamLoader &pParams);

public:
    void draw() override;

    void update() override;

    void clean() override;

    void shoot() override;

    void nextFrame() override;

    bool isMIsDead() const override;

    void setMVelocity(Vector2D velocity) override;

    void checkCollision() override;

    void checkOOB() override;

    void setMText(const char *mText) override;

    const Vector2D &getMPosition() const override;

    Vector2D getMSize() const override;
};


#endif //CPP_EKSAMEN3_UI_ELEMENT_H