#pragma once
class Enemy{
public:

	int GetposX() { return posX_; };
	int GetposY() { return posY_; };
	int GetspeedX() { return speedX_; };
	int GetspeedY() { return speedY_; };
	int Getradius() { return radius_; };
	int GetisAlive() { return isAlive_; };

	void SetSpeed(int x, int y);

	void SetisAlive(int isAlive);

	Enemy(int posX, int posY, int speedX, int speedY ,int isAlive);


	void Update();


	void Draw();

	void Initialize();

private:
	int posX_;
	int posY_;
	int speedX_;
	int speedY_;
	int radius_;
	int isAlive_;
	int timer_;
};


