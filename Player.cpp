#include "Player.h"
#include "globals.h"
#include "Input.h"
#include "DxLib.h"

//関数定義
Player::Player(string name, Vector2D pos, Vector2D speed, float rudius)
{
	name_ = name;
	pos_ = pos;
	speed_ = speed;
	radius_ = rudius;
	isSayHello_ = false;//はじめは挨拶していない
}

//スコープ解決演算子 ::   クラス名::関数名
void Player::Update()
{
	float dt = GetDeltaTime();//現在のフレーム間時間
	pos_.x = pos_.x + speed_.x * dt;
	pos_.y = pos_.y + speed_.y * dt;

	if (Input::IsKeyDown(KEY_INPUT_SPACE) == true)
	{
		SayHello();
	}

}
void Player::Draw()
{
	DrawCircle((int)pos_.x, (int)pos_.y, 
		            10, GetColor(0, 0, 255), TRUE);
	DrawCircle((int)pos_.x, (int)pos_.y,
					11, GetColor(0, 0, 0), FALSE, 1);
}

void Player::SetName(string name)
{
	name_ = name;
}

void Player::SetPosition(Vector2D pos)
{
	pos_ = pos;
}

string Player::GetName() const
{
	return name_;
}

Vector2D Player::GetPosition() const
{
	return pos_;
}

void Player::SetSpeed(Vector2D speed)
{
	speed_ = speed;
}

Vector2D Player::GetSpeed() const
{
	return speed_;
}

void Player::SetRadius(double radius)
{
	radius_ = radius;
}

double Player::GetRadius() const
{
	return radius_;
}

void Player::SetEnemy(string n, Vector2D p, Vector2D v, double r)
{
	name_ = n;
	pos_ = p;
	speed_ = v;
	radius_ = r;
}

void Player::SayHello()
{
	if (isSayHello_ == true)
	{
		isSayHello_ = false;//挨拶をやめる
		return;//ここで関数終了
	}
	isSayHello_ = true;//挨拶している状態にする
}
