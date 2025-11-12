#include "CharaBase.h"
#include "globals.h"
#include "Input.h"
#include "DxLib.h"

//ŠÖ”’è‹`
CharaBase::CharaBase(string name, Vector2D pos, Vector2D speed, float rudius)
{
    name_ = name;
    pos_ = pos;
    speed_ = speed;
    radius_ = rudius;
}

void CharaBase::Update()
{
    float dt = GetDeltaTime();//Œ»İ‚ÌƒtƒŒ[ƒ€ŠÔŠÔ
    pos_.x = pos_.x + speed_.x * dt;
    pos_.y = pos_.y + speed_.y * dt;
}

void CharaBase::Draw()
{
    DrawCircle((int)pos_.x, (int)pos_.y,
        10, GetColor(0, 0, 255), TRUE);
    DrawCircle((int)pos_.x, (int)pos_.y,
        11, GetColor(0, 0, 0), FALSE, 1);
}

void CharaBase::SetName(string name)
{
    name_ = name;
}

void CharaBase::SetPosition(Vector2D pos)
{
	pos_ = pos;
}

string CharaBase::GetName() const
{
	return name_;
}

Vector2D CharaBase::GetPosition() const
{
    return Vector2D();
}

void CharaBase::SetSpeed(Vector2D speed)
{
    speed_ = speed;
}

Vector2D CharaBase::GetSpeed() const
{
	return speed_;
}

void CharaBase::SetRadius(float radius)
{
	radius_ = radius;
}

double CharaBase::GetRadius() const
{
	return radius_;
}

void CharaBase::SetChara(string n, Vector2D p, Vector2D v, double r)
{
	name_ = n;
	pos_ = p;
	speed_ = v;
	radius_ = r;
}
