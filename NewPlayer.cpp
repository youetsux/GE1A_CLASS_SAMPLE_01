#include "NewPlayer.h"

NewPlayer::NewPlayer(string name, Vector2D pos, Vector2D speed, float radius)
	:CharaBase(name, pos, speed, radius), isSayHello_(false)
{
}

void NewPlayer::SayHello()
{
	isSayHello_ = true;
}
