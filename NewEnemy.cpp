#include "NewEnemy.h"

NewEnemy::NewEnemy(string name, Vector2D pos, Vector2D speed, float radius)
	:CharaBase(name, pos, speed, radius)
{
}

void NewEnemy::SpeedUp()
{
	Vector2D speed = GetSpeed();
	if (speed.x >= 0) {
		speed.x = speed.x + 1.0f;
		this->SetSpeed(speed);
	}
	else {
		speed.x = speed.x - 1.0f;
		this->SetSpeed(speed);
	}
	//speed_.y = speed_.y + 0.0f;//•Ï‚í‚ç‚È‚¢
}

void NewEnemy::SpeedDown()
{
	Vector2D speed = GetSpeed();
	if (speed.x >= 0) {
		speed.x = speed.x - 1.0f;
		this->SetSpeed(speed);
	}
	else {
		speed.x = speed.x + 1.0f;
		this->SetSpeed(speed);
	}
}
