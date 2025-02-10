#pragma once
class Bullet{
public:
	float posX_;
	float posY_;
	float speed_;
	float radius_;
	int isShoot_;

public:
	Bullet();
	void Update();
	void Draw();
};


