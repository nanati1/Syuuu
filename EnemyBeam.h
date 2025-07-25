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
void SetFired(bool fired) { isFired_ = fired; } // 弾の発射状態を設定
bool IsFired() const { return isFired_; } // 弾が発射されているかどうか
Rect GetRect() const { return { pos_.x, pos_.y, imageSize_.x, imageSize_.y }; }

protected:
Point pos_; // 位置を表すPoint型のメンバ変数を追加

private:
int hImage_;
float x_;
float y_;
float speed_;
Point imageSize_; // 弾の画像サイズ
bool isFired_; // 弾が発射されたかどうか
};
