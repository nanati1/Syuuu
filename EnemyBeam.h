#pragma once
#include "GameObject.h"
#include "globals.h"

class EnemyBeam :
	public GameObject
{
public:
EnemyBeam();
EnemyBeam(float x, float y);
EnemyBeam(Point pos_);
~EnemyBeam();
void Update() override;
void Draw() override;

void SetPos(float x, float y) { pos_.x = x; pos_.y = y; }
void SetPos(const Point& pos) { pos_ = pos; }
void SetFired(bool fired) { isFired_ = fired; } // ’e‚Ì”­Ëó‘Ô‚ğİ’è
bool IsFired() const { return isFired_; } // ’e‚ª”­Ë‚³‚ê‚Ä‚¢‚é‚©‚Ç‚¤‚©
Rect GetRect() const { return { pos_.x, pos_.y, imageSize_.x, imageSize_.y }; }

protected:
Point pos_; // ˆÊ’u‚ğ•\‚·PointŒ^‚Ìƒƒ“ƒo•Ï”‚ğ’Ç‰Á

private:
int hImage_;
float x_;
float y_;
float speed_;
Point imageSize_; // ’e‚Ì‰æ‘œƒTƒCƒY
bool isFired_; // ’e‚ª”­Ë‚³‚ê‚½‚©‚Ç‚¤‚©
};
