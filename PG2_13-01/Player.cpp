#include "Player.h"
#include <Novice.h>

Player::Player()
{
    posX_ = 640; 
    posY_ = 600;
    rad_ = 20;

    bulletX_ = 0;
    bulletY_ = 0;
    bulletSpeed_ = -10;
    isBulletShot_ = 0;
}

void Player::Update(char* keys)
{
    if (keys[DIK_A]) {
        posX_ -= 5;
    }
    if (keys[DIK_D]) {
        posX_ += 5;
    }
    if (keys[DIK_SPACE] && isBulletShot_ == 0) {
        bulletX_ = posX_;
        bulletY_ = posY_;
        isBulletShot_ = true;
    }

    if (isBulletShot_) {
        bulletY_ += bulletSpeed_;
        if (bulletY_ < 0) {
            isBulletShot_ = false; 
        }
    }
}

void Player::Draw()
{
    Novice::DrawEllipse(posX_, posY_, rad_, rad_, 0.0f, WHITE, kFillModeSolid);
}
