#include "Bullet.h"
#include"Novice.h"

Bullet::Bullet() {
	posX_ = 100.0f;
	posY_ = 100.0f;
	speed_ = 10.0f;
	radius_ = 10.0f;
	isShoot_ = false;
}

void Bullet::Update() {
	if (isShoot_) {
		posY_ -= speed_;
	}

	if (posY_ + radius_ <= 0) {
		isShoot_ = false;
	}
}

void Bullet::Draw() {
	if (isShoot_) {

		Novice::DrawEllipse(static_cast<int>(posX_), static_cast<int>(posY_), static_cast<int>(radius_),
			static_cast<int>(radius_), 0.0f, RED, kFillModeSolid);
	}
}
