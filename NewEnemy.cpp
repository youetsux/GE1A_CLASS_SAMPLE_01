#include "NewEnemy.h"
#include "globals.h"
#include "Input.h"
#include <Dxlib.h>

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

void NewEnemy::Update()
{
	float dt = GetDeltaTime();//Œ»İ‚ÌƒtƒŒ[ƒ€ŠÔŠÔ
	Vector2D pos = GetPosition();
	Vector2D speed = GetSpeed();
	pos.x = pos.x + speed.x * dt;
	pos.y = pos.y + speed.y * dt;

	SetPosition(pos);

	if (Input::IsKeyDown(KEY_INPUT_ADD))
	{
		SpeedUp();
	}
	if (Input::IsKeyDown(KEY_INPUT_SUBTRACT))
	{
		SpeedDown();
	}
}

void NewEnemy::Draw()
{
	DrawCircle((int)GetPosition().x, (int)GetPosition().y,
		10, GetColor(148, 0, 211), TRUE);
	DrawCircle((int)GetPosition().x, (int)GetPosition().y,
		11, GetColor(0, 0, 0), FALSE, 1);
}


//NewPlayer‚ÌDraw‚àF‚È‚ñ‚©•Ï‚¦‚Ä‚İ‚é
//NewEnemy‚ÌSpeedUp, SpeedDown‚àÀ‘•‚µ‚Ä‚İ‚é