#pragma once
#include "Bullet.h"
class Player{
public:
	float GetposX() { return posX_; };
	float GetposY() { return posY_; };
	float Getradius() { return radius_; };
	float Getspeed() { return speed_; };
	
	Bullet* bullet = new Bullet();


public:

	Player();
	~Player();
	void Update(char* keys, char* preKeys);
	void Draw();
	void initialize();

private:

	
	float posX_;
	float posY_;
	float radius_;
	float speed_;


};


