#pragma once
#include <string>
#include "Vector2D.h"

//宣言
using std::string;

class CharaBase
{
public:
	CharaBase(string name, Vector2D pos, Vector2D speed, float rudius);//コンストラクタ
	void Update();//アップデート
	void Draw();
public:
	//セッターゲッター
	void SetName(string name);
	void SetPosition(Vector2D pos);
	string GetName() const;
	Vector2D GetPosition() const;
	void SetSpeed(Vector2D speed);
	Vector2D GetSpeed() const;
	void SetRadius(float radius);
	double GetRadius() const;
	void SetChara(string n, Vector2D p, Vector2D v, double r);//共通のセット関数
private:
	string name_; //なまえ
	Vector2D pos_; //位置
	Vector2D speed_;//速さ v(vx, vy)
	float radius_;//当たり判定距離
};

