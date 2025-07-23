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
void SetFired(bool fired) { isFired_ = fired; } // �e�̔��ˏ�Ԃ�ݒ�
bool IsFired() const { return isFired_; } // �e�����˂���Ă��邩�ǂ���
Rect GetRect() const { return { pos_.x, pos_.y, imageSize_.x, imageSize_.y }; }

protected:
Point pos_; // �ʒu��\��Point�^�̃����o�ϐ���ǉ�

private:
int hImage_;
float x_;
float y_;
float speed_;
Point imageSize_; // �e�̉摜�T�C�Y
bool isFired_; // �e�����˂��ꂽ���ǂ���
};
