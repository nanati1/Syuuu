#include "Enemy.h"
#include "DxLib.h"
#include <string>
#include "Effect.h"
#include "EnemyBeam.h"

namespace
{
	const int ENEMY_IMAGE_WIDTH = 48; // 敵の画像の幅;
	const int ENEMY_IMAGE_HEIGHT = 48; // 敵の画像の高さ;

	const float ENEMY_INIT_X = 100; // 敵の初期X座標;
	const float ENEMY_INIT_Y = 100; // 敵の初期Y座標;
	const float ENEMY_INIT_SPEED = 100.0f; // 敵の初期移動速度;
}


Enemy::Enemy()
	:GameObject(),
	hImage_(-1),
	x_(0), y_(0),
	speed_(0),
	imageSize_({ ENEMY_IMAGE_WIDTH, ENEMY_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph("Assets\\tiny_ship10.png"); // 敵の画像を読み込む
	if (hImage_ == -1) {
		// 画像の読み込みに失敗した場合のエラーハンドリング
		// エラーを返してゲーム終了
	}
	x_ = ENEMY_INIT_X; // 初期座標
	y_ = ENEMY_INIT_Y; // 初期座標
	speed_ = ENEMY_INIT_SPEED; // 移動速度
	//idとtypeをしていされなかったときのしょりをここに書かねば
}

Enemy::Enemy(int id, ETYPE type)
	:GameObject(),
	hImage_(-1),
	x_(0), y_(0),
	speed_(0),
	ID_(id), type_(type), imageSize_({ ENEMY_IMAGE_WIDTH, ENEMY_IMAGE_HEIGHT })

{
	//ETYPE::ZAKO =>  "Assets/tiny_ship10.png"
	//ETYPE::MID = > "Assets/tiny_ship18.png"
	//ETYPE::KNIGHT = > "Assets/tiny_ship16.png"
	//ETYPE::BOSS = > "Assets/tiny_ship9.png"
	// 画像の読み込み
	std::string imagePath[MAX_ETYPE] = {
		"Assets\\tiny_ship10.png", // ZAKO
		"Assets\\tiny_ship18.png", // MID
		"Assets\\tiny_ship16.png", // KNIGHT
		"Assets\\tiny_ship9.png"   // BOSS
	};

	moveTime_ = 0.0f;
	hImage_ = LoadGraph(imagePath[type_].c_str()); // 敵の画像を読み込む
	if (hImage_ == -1) {
		// 画像の読み込みに失敗した場合のエラーハンドリング
		// エラーを返してゲーム終了
	}
	x_ = ENEMY_INIT_X; // 初期座標
	y_ = ENEMY_INIT_Y; // 初期座標
	speed_ = ENEMY_INIT_SPEED; // 移動速度
	AddGameObject(this); // 敵オブジェクトをゲームオブジェクトのベクターに追加
}

Enemy::~Enemy()
{
	new Effect({ x_, y_ });
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_); // 画像のハンドルを解放
	}
}

void Enemy::Update()
{
	static float beamTimer = 3.0f;

	float period = 10.0f; // 1往復にかける時間（秒）
	float omega = 2.0f * 3.14159265f / period; // 角速度 ω = 2π / T
	moveTime_ = moveTime_ + GetDeltaTime();
	x_ = xorigin_ + xMoveMax_ / 2.0 * sinf(omega * moveTime_);
	y_ = y_;

	if (beamTimer < 0)
	{
		new EnemyBeam(x_ + ENEMY_IMAGE_WIDTH / 2, y_ + ENEMY_IMAGE_HEIGHT);
		beamTimer = 3.0f;
	}

	beamTimer -= GetDeltaTime();
}

void Enemy::Draw()
{
	//画面の左上に敵画像を表示
	DrawExtendGraphF(x_, y_, x_ + ENEMY_IMAGE_WIDTH, y_ + ENEMY_IMAGE_HEIGHT,
		hImage_, TRUE);
}