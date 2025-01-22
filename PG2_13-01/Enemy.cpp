#include "Enemy.h"
#include <Novice.h>
#include "Player.h"

Enemy::Enemy()
{
    posX_ = 360;
    posY_ = 40;
    speed_ = 32;
    rad_ = 20;

    dx_ = 0;
    dy_ = 0;
    distance_ = 0;
    radiusSum_ = rad_ + 5;
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
    if (isAlive_) {
        posX_ += speed_;
        if (posX_ > 1280 || posX_ < 0) {
            speed_ = -speed_;
        }
    }
}

void Enemy::Draw()
{
    if (isAlive_) {
        Novice::DrawEllipse(posX_, posY_, rad_, rad_, 0.0f, BLUE, kFillModeSolid);
    }
}

void Enemy::CheckCollisionWithBullet()
{
    if (isAlive_ && player_->isBulletShot_) {
        dx_ = posX_ - player_->bulletX_;
        dy_ = posY_ - player_->bulletY_;
        distance_ = dx_ * dx_ + dy_ * dy_;

    
        if (distance_ <= radiusSum_ * radiusSum_) {
            isAlive_ = 0;
            player_->isBulletShot_ = 0; 
        }
    }
}