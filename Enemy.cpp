#include "Enemy.h"
#include "globals.h"
#include "Input.h"
#include "DxLib.h"

Enemy::Enemy(string name, Vector2D pos, Vector2D speed, float rudius)
{
	name_ = name;
	pos_ = pos;
	speed_ = speed;
	radius_ = rudius;
}

void Enemy::Update()
{
	float dt = GetDeltaTime();//Œ»Ý‚ÌƒtƒŒ[ƒ€ŠÔŽžŠÔ
	pos_.x = pos_.x + speed_.x * dt;
	pos_.y = pos_.y + speed_.y * dt;
	if (Input::IsKeyDown(KEY_INPUT_ADD))
	{
		SpeeedUp();
	}
	if (Input::IsKeyDown(KEY_INPUT_SUBTRACT))
	{
		SpeedDown();
	}
}

void Enemy::SetName(string name)
{
	name_ = name;
}

void Enemy::SetPosition(Vector2D pos)
{
	pos_ = pos;
}

string Enemy::GetName() const
{
	return name_;
}

Vector2D Enemy::GetPosition() const
{
	return pos_;
}

void Enemy::SetSpeed(Vector2D speed)
{
	speed_ = speed;
}

Vector2D Enemy::GetSpeed() const
{
	return speed_;
}

void Enemy::SetRadius(double radius)
{
	radius_ = radius;
}

double Enemy::GetRadius() const
{
	return radius_;
}

void Enemy::SetEnemy(string n, Vector2D p, Vector2D v, double r)
{
	name_ = n;
	pos_ = p;
	speed_ = v;
	radius_ = r;
}

void Enemy::SpeeedUp()
{
	if(speed_.x >= 0)
		speed_.x = speed_.x + 1.0f;
	else
		speed_.x = speed_.x - 1.0f;
	speed_.y = speed_.y + 0.0f;//•Ï‚í‚ç‚È‚¢
}

void Enemy::SpeedDown()
{
	if (speed_.x >= 0)
		speed_.x = speed_.x - 1.0f;
	else
		speed_.x = speed_.x + 1.0f;
	speed_.y = speed_.y - 0.0f;//•Ï‚í‚ç‚È‚¢
}

void Enemy::Draw()
{
	DrawCircle(pos_.x, pos_.y, 10, GetColor(200, 40, 40), TRUE);
	DrawCircle(pos_.x, pos_.y, 11, GetColor(0, 0, 0), FALSE, 1);
}

