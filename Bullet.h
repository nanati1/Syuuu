#pragma once  
#include "GameObject.h"  

class Bullet : public GameObject  
{  
public:
	Bullet();
	Bullet(float x, float y);
	~Bullet();
	void Update() override;
	void Draw() override;

	void SetPos(float x, float y);
	void SetFired(bool fired) { isFired_ = fired; } // �e�̔��ˏ�Ԃ�ݒ�
	bool IsFired() const { return isFired_; } // �e�����˂���Ă��邩�ǂ���
	Rect GetRect() const { return { x_, y_,imageSize_.x,imageSize_.y }; } // �e�̋�`���擾
protected:
private:  
   int hImage_;  
   float x_;  
   float y_;  
   float speed_;  
   Point imageSize_; // �e�̉摜�T�C�Y
 /*  int isize_x;  
   int isize_y;  */
   bool isFired_; // �e�����˂��ꂽ���ǂ���

};
