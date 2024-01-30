#include "Novice.h"
#include "Bullet.h"

Bullet::Bullet(Transform transform, int s, int r2, bool i) {
	transform_ = transform;
	speed_ = s;
	r_ = r2;
	isShot_ = i;
}

void Bullet::SetisShot(bool i) {
	isShot_ = i;
}

void Bullet::Update() {
	if (isShot_ == true) {
		transform_.y -= speed_;
		if (transform_.y <= 0) {
			isShot_ = false;
		}
	}
}

void Bullet::Draw() {
	if (isShot_ == true) {
		Novice::DrawEllipse(transform_.x, transform_.y, r_, r_, 0.0f, WHITE, kFillModeSolid);
	}
}