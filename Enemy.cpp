#include "Enemy.h"
#include "Novice.h"

Enemy::Enemy(int posX, int posY, int speedX, int speedY,int isAlive){
	posX_ = posX;
	posY_ = posY;
	speedX_ = speedX;
	speedY_ = speedY;
	radius_ = 15;
	timer_ = 60;
	isAlive_ = isAlive;
}

void Enemy::Update() {
	posX_ += speedX_;
	

	if (posX_ - radius_ <= 0 || posX_ + radius_ >= 1280) {
		speedX_ = -speedX_;
	}
	
}

void Enemy::Draw() {
	if (isAlive_) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, BLUE, kFillModeSolid);
	} else {
		timer_--;
		if (timer_ < 0) {
			timer_ = 60;
			isAlive_ = true;
		}
	}
}

void Enemy::Initialize(){
	posX_ = 100;
	posY_ = 100;
	speedX_ = 5;
	speedY_ = 0;
	isAlive_ = true;
}

void Enemy::SetSpeed(int x, int y) {

	speedX_ = x;
	speedY_ = y;

}

void Enemy::SetisAlive(int isAlive) {
	isAlive_ = isAlive;
}
