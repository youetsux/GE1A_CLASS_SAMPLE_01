#pragma once
#include "CharaBase.h"
class NewEnemy :
    public CharaBase
{
public:
	NewEnemy(string name, Vector2D pos, Vector2D speed, float radius);
	~NewEnemy() {}
	void SpeedUp();
	void SpeedDown();
	void Update() override;
	void Draw() override;
};

