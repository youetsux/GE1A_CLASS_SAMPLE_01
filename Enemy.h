#pragma once

#include <string>
#include "Vector2D.h"

//宣言
using std::string;

//カプセル化済み
class Enemy
{
public:
	Enemy(string name, Vector2D pos, Vector2D speed, float rudius);//コンストラクタ
	void Update();//アップデート
	void SpeeedUp();
	void SpeedDown();
	void Draw();
	//void ShootBeam();
public:
	//セッターゲッター
	void SetName(string name);
	void SetPosition(Vector2D pos);
	string GetName() const;
	Vector2D GetPosition() const;
	void SetSpeed(Vector2D speed);
	Vector2D GetSpeed() const;
	void SetRadius(double radius);
	double GetRadius() const;
	void SetEnemy(string n, Vector2D p, Vector2D v, double r);

private:
	string name_; //なまえ
	Vector2D pos_; //位置
	Vector2D speed_;//速さ v(vx, vy)
	float radius_;//当たり判定距離
	//bool isShootingBeam_; //今ビームを撃っているかどうか
};