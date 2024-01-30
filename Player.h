#pragma once
#include "Bullet.h"

class Player {
private:
	Transform transform_;
	int r_;
	int speedX_;
	int speedY_;
	bool Alive_;

public:
	Bullet* bullet_;
	Player(Transform transform, int r, int s, bool a);
	~Player();

	int GetPosX() { return transform_.x; };
	int GetPosY() { return transform_.y; };
	int GetRadius() { return r_; };
	int GetSpeedX() { return speedX_; };
	int GetSpeedY() { return speedY_; };
	int GetAlive() { return Alive_; };

	void SetAlive(bool Alive);

	void Update(char* keys, char* preKeys);
	void Draw();
};