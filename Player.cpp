#include "Novice.h"
#include "Player.h"
#include "Bullet.h"

Player::Player(Transform transform, int r1, int s, bool a) {
	transform_ = transform;
	r_ = r1;
	speedX_ = s;
	speedY_ = s;
	Alive_ = a;
	bullet_ = new Bullet({ 0,0 }, 10, 10, false);
}
Player::~Player() {
	delete bullet_;
}

void Player::SetAlive(bool Alive) {
	Alive_ = Alive;
}

void Player::Update(char* keys, char* preKeys) {
	speedX_ = 0;
	speedY_ = 0;

	if (transform_.x < r_) {
		transform_.x = r_;
	}
	if (transform_.x > 1280 - r_) {
		transform_.x = 1280 - r_;
	}
	if (transform_.y < r_) {
		transform_.y = r_;
	}
	if (transform_.y > 720 - r_) {
		transform_.y = 720 - r_;
	}

	if (keys[DIK_W] && preKeys[DIK_W]) {
		speedY_ = -1;
	}
	if (keys[DIK_S] && preKeys[DIK_S]) {
		speedY_ = 1;
	}
	if (keys[DIK_A] && preKeys[DIK_A]) {
		speedX_ = -1;
	}
	if (keys[DIK_D] && preKeys[DIK_D]) {
		speedX_ = 1;
	}
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && bullet_->isShot_ == false) {
		bullet_->transform_ = transform_;
		bullet_->isShot_ = true;
	}
	bullet_->Update();

	transform_.x += speedX_;
	transform_.y += speedY_;

	if (keys[DIK_R] && preKeys[DIK_R]) {
		Alive_ = false;
	}
}

void Player::Draw() {
	if (Alive_ == false) {
		Novice::DrawEllipse(transform_.x, transform_.y, r_, r_, 0.0f, WHITE, kFillModeSolid);
	}
	bullet_->Draw();
}