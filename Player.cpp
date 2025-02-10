#include "Player.h"
#include"Novice.h"

Player::Player() {
	posX_ = 600.0f;
	posY_ = 300.0f;
	radius_ = 20.0f;
	speed_ = 10.0f;
	bullet = new Bullet();
}

Player::~Player() {
	delete bullet;
};

void Player::Update(char* keys, char* preKeys) {
	if (keys[DIK_W]) {
		posY_ -= speed_;
	}

	if (keys[DIK_S]) {
		posY_ += speed_;
	}

	if (keys[DIK_D]) {
		posX_ += speed_;
	}

	if (keys[DIK_A]) {
		posX_ -= speed_;
	}

	if (keys[DIK_SPACE] && preKeys[DIK_SPACE]) {
		if (bullet->isShoot_ == false) {
			bullet->isShoot_ = true;
			bullet->posX_ = posX_;
			bullet->posY_ = posY_;
		}
	}

	if (posX_ + radius_ >= 1280) {
		posX_  = 1280 - radius_;
	}

	if (posX_ - radius_ < 0) {
		posX_ = radius_;
	}

	if (posY_ <= radius_) {
		posY_ = radius_;
	}

	if (posY_ + radius_ >= 720) {
		posY_ = 720 - radius_;
	}


	bullet->Update();

}

void Player::Draw() {

	bullet->Draw();

	Novice::DrawEllipse(static_cast<int>(posX_), static_cast<int>(posY_), static_cast<int>(radius_),
		static_cast<int>(radius_), 0.0f, WHITE, kFillModeSolid);
}

void Player::initialize(){
	posX_ = 600.0f;
	posY_ = 300.0f;
	radius_ = 20.0f;
	speed_ = 10.0f;
	bullet = new Bullet();
}
