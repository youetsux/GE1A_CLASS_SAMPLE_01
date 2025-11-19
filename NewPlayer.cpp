#include "NewPlayer.h"
#include "globals.h"
#include "Input.h"
#include <Dxlib.h>

NewPlayer::NewPlayer(string name, Vector2D pos, Vector2D speed, float radius)
	:CharaBase(name, pos, speed, radius), isSayHello_(false)
{
}

void NewPlayer::SayHello()
{
	isSayHello_ = true;
}

void NewPlayer::Update()
{
	float dt = GetDeltaTime();//現在のフレーム間時間
	Vector2D pos = GetPosition();
	Vector2D speed = GetSpeed();
	pos.x = pos.x + speed.x * dt;
	pos.y = pos.y + speed.y * dt;

	SetPosition(pos);

	if (Input::IsKeyDown(KEY_INPUT_SPACE) == true)
	{
		SayHello();
	}
}

void NewPlayer::Draw()
{
	DrawCircle((int)GetPosition().x, (int)GetPosition().y,
		10, GetColor(65, 105, 225), TRUE);
	DrawCircle((int)GetPosition().x, (int)GetPosition().y,
		11, GetColor(0, 0, 0), FALSE, 1);
}
