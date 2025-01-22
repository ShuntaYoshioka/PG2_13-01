#pragma once
#include "Player.h"
class Enemy
{
protected:
public:
    int posX_;
    int posY_;
    int speed_;
    int rad_;

      Player* player_; 

    static int isAlive_; 

    int dx_;
    int dy_;
    int distance_;
    int radiusSum_;

    Enemy();
    ~Enemy();
    void Update();
    void Draw();
    void CheckCollisionWithBullet();
};
