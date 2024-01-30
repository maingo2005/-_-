#pragma once
#include "Struct.h"

class Bullet {
public:
	Transform transform_;
	int speed_;
	int r_;
	bool isShot_;

public:
	Bullet(Transform transform, int s, int r, bool i);

	int GetPosX() { return transform_.x; };
	int GetPosY() { return transform_.y; };
	int GetRadius() { return r_; };
	int GetSpeedX() { return speed_; };
	int GetisShot() { return isShot_; };

	void SetisShot(bool isShot);

	void Update();
	void Draw();
};