#pragma once
class Player
{
protected:
public:

	int posX_;
	int posY_;
	int rad_;

	int bulletX_;
	int bulletY_;
	int bulletSpeed_;
	int isBulletShot_;

	int isShot;

	Player();

	void Update(char* keys);

	void Draw();
};

