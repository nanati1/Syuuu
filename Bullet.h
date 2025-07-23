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
	void SetFired(bool fired) { isFired_ = fired; } // ’e‚Ì”­Ëó‘Ô‚ğİ’è
	bool IsFired() const { return isFired_; } // ’e‚ª”­Ë‚³‚ê‚Ä‚¢‚é‚©‚Ç‚¤‚©
	Rect GetRect() const { return { x_, y_,imageSize_.x,imageSize_.y }; } // ’e‚Ì‹éŒ`‚ğæ“¾
protected:
private:  
   int hImage_;  
   float x_;  
   float y_;  
   float speed_;  
   Point imageSize_; // ’e‚Ì‰æ‘œƒTƒCƒY
 /*  int isize_x;  
   int isize_y;  */
   bool isFired_; // ’e‚ª”­Ë‚³‚ê‚½‚©‚Ç‚¤‚©

};
