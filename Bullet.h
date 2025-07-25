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
	void SetFired(bool fired) { isFired_ = fired; } // 弾の発射状態を設定
	bool IsFired() const { return isFired_; } // 弾が発射されているかどうか
	Rect GetRect() const { return { x_, y_,imageSize_.x,imageSize_.y }; } // 弾の矩形を取得
protected:
private:  
   int hImage_;  
   float x_;  
   float y_;  
   float speed_;  
   Point imageSize_; // 弾の画像サイズ
 /*  int isize_x;  
   int isize_y;  */
   bool isFired_; // 弾が発射されたかどうか

};
