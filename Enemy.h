#pragma once
#include "Struct.h"

class Enemy {
public:

	Enemy(Transform t, int r, int sX, bool a);

	int GetPosX() { return transform_.x; };
	int GetPosY() { return transform_.y; };
	int GetRadius() { return radius_; };
	int GetSpeedX() { return speedX_; };
	int GetAlive() { return Alive_; };

	void SetAlive(bool Alive);
	void SetSpeedX(bool SpeedX);

	void Update(char* keys, char* preKeys);

	void Draw();

private:
	Transform transform_;
	int speedX_;
	int radius_;
	bool Alive_;
};