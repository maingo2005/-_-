#include "Enemy.h"
#include "Novice.h"

Enemy::Enemy(Transform t, int r, int sX, bool a) {
	transform_ = t;
	speedX_ = sX;
	radius_ = r;
	Alive_ = a;
}

void Enemy::SetAlive(bool Alive) {
	Alive_ = Alive;
}

void Enemy::SetSpeedX(bool SpeedX) {
	speedX_ = SpeedX;
}

void Enemy::Update(char* keys, char* preKeys) {
	transform_.x += speedX_;

	if (keys[DIK_R] && preKeys[DIK_R] && Alive_ == true) {
		Alive_ = false;
		speedX_ = 10;
	}

	if (transform_.x - radius_ <= 0 || transform_.x + radius_ >= 1280) {
		speedX_ *= -1;
	}
}

void Enemy::Draw() {
	if (Alive_ == false) {
		Novice::DrawEllipse(transform_.x, transform_.y, radius_, radius_, 0.0f, RED, kFillModeSolid);
	}
}
