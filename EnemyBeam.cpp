#include "EnemyBeam.h"
#include "DxLib.h"

namespace 
{
	const int ENEMY_BEAM_IMAGE_WIDTH = 11;
	const int ENEMY_BEAM_IMAGE_HEIGHT = 21;
	const float ENEMY_BEAM_INIT_SPEED = 200.0f;
}
EnemyBeam::EnemyBeam()
	:GameObject(), hImage_(-1),pos_({-10,-10}),
	speed_(0),isFired_(false), imageSize_({ENEMY_BEAM_IMAGE_WIDTH, ENEMY_BEAM_IMAGE_HEIGHT})
{
	hImage_ = LoadGraph("Assets\\ebeams.png");

	AddGameObject(this);
}

EnemyBeam::EnemyBeam(float x, float y)
	:GameObject(), hImage_(-1), pos_({ x, y }),
	speed_(ENEMY_BEAM_INIT_SPEED), isFired_(true),//Œã‚Å‘‚«Š·‚¦‚é
	imageSize_({ ENEMY_BEAM_IMAGE_WIDTH, ENEMY_BEAM_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph("Assets\\ebeams.png");

	AddGameObject(this);
}

EnemyBeam::EnemyBeam(Point pos_)
	:GameObject(), hImage_(-1), pos_({pos_.x, pos_.y }),
	speed_(ENEMY_BEAM_INIT_SPEED), isFired_(true),
	imageSize_({ ENEMY_BEAM_IMAGE_WIDTH, ENEMY_BEAM_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph("Assets\\ebeams.png");

	AddGameObject(this);
}

EnemyBeam::~EnemyBeam()
{
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_);
	}
	hImage_ = -1;
}

void EnemyBeam::Update()
{
	if (!isFired_) return;
	pos_.y += speed_ * gDeltaTime; // gDeltaTime‚ÅƒtƒŒ[ƒ€ˆË‘¶‚ð–h‚®
	if (pos_.y > WIN_HEIGHT) {
		isFired_ = false;
	}
}

void EnemyBeam::Draw()
{
	if (isFired_)
	{
		DrawExtendGraphF(pos_.x, pos_.y,
			pos_.x + imageSize_.x, pos_.y + imageSize_.y,
			hImage_, TRUE);
	}
}
