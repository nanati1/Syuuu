#pragma once
#include "GameObject.h"
#include "globals.h"

enum ETYPE
{
	ZAKO, MID, KNIGHT, BOSS, MAX_ETYPE
};


class Enemy :
	public GameObject
{
public:
	Enemy(int id, ETYPE type);
	Enemy();
	~Enemy();
	void Update() override;
	void Draw() override;
	void SetPos(float x, float y) { x_ = x; y_ = y; } //敵の座標を設定
	Rect GetRect() const { return { x_, y_, imageSize_.x, imageSize_.y }; } // 敵の矩形を取得	
	//void SetID(int id) { ID_ = id; } //敵のIDを設定
	void SetMaxMoveX(float xmax) { xMoveMax_ = xmax; }
	void SetXorigin(float x) { xorigin_ = x; }
protected:
private:
	int hImage_;  //敵の画像ハンドル
	float x_, y_; //敵の座標
	float speed_; //敵の移動速度
	float xMoveMax_;//横方向の移動最大値
	float xorigin_;
	float moveTime_;
	Point imageSize_;

	int ID_; //敵のID
	ETYPE type_; //敵の種類
};