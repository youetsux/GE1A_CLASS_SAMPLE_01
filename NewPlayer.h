#pragma once
#include "CharaBase.h"


class NewPlayer :
    public CharaBase
{
public:
    NewPlayer(string name, Vector2D pos, Vector2D speed, float radius);
    ~NewPlayer() {}
    void SayHello();
    bool GetIsSayHello() { return isSayHello_; }
private:
    bool isSayHello_; //今挨拶をしているかどうか
};