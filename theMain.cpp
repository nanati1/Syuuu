#include "DxLib.h"
#include "globals.h"
#include "input.h"
#include <vector>
#include "Stage.h"
#include "Scene.h"
#include "Player.h"
#include "EnemyBeam.h"

bool CheckHit(const Rect& a, const Rect& b) {
    return !(a.x > b.x + b.width || a.x + a.width < b.x ||
        a.y > b.y + b.height || a.y + a.height < b.y);
}


namespace
{
	const int BGCOLOR[3] = { 0, 0, 0 }; // �w�i�F{ 255, 250, 205 }; // �w�i�F
	int crrTime;
	int prevTime;
}

std::vector<GameObject*> gameObjects; // �Q�[���I�u�W�F�N�g�̃x�N�^�[
std::vector<GameObject*> newObjects; // �Q�[���I�u�W�F�N�g�̃x�N�^�[


float gDeltaTime = 0.0f; // �t���[���Ԃ̎��ԍ�

void DxInit()
{
	ChangeWindowMode(true);
	SetWindowSizeChangeEnableFlag(false, false);
	SetMainWindowText("TITLE");
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);
	SetWindowSizeExtendRate(1.0);
	SetBackgroundColor(BGCOLOR[0], BGCOLOR[1], BGCOLOR[2]);

	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		DxLib_End();
	}

	SetDrawScreen(DX_SCREEN_BACK);
}

void MyGame()
{

	DrawFormatString(100, 100, GetColor(0, 0, 0), "�E�B���h�E�̃e�X�g");
	static int timer = 0;
	timer++;
	DrawFormatString(100, 150, GetColor(0, 0, 0), "%010d", timer);
}



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
 
	DxInit();
	crrTime = GetNowCount();
	prevTime = GetNowCount();

	Stage* stage = new Stage(); // �X�e�[�W�I�u�W�F�N�g�̐���

	//SceneManager manager(new TitleScene());

	while (true)
	{
       
        ClearDrawScreen();
        Input::KeyStateUpdate();

        crrTime = GetNowCount();
        float deltaTime = (crrTime - prevTime) / 1000.0f;
        gDeltaTime = deltaTime;

        // --- �V�[�����Ƃɕ��� ---
        if (g_Scene == SceneType::Title)
        {
            DrawFormatString(100, 100, GetColor(255, 255, 255), "P�L�[�ŃX�^�[�g");
            if (CheckHitKey(KEY_INPUT_P))
            {
                g_Scene = SceneType::Game;
            }
        }
        else if (g_Scene == SceneType::Game) 
        {
            // �Q�[���{�҂̏���
            if (newObjects.size() > 0) 
            {
                for (auto& obj : newObjects)
                {
                    gameObjects.push_back(obj);
                }
                newObjects.clear();
            }
            for (auto& obj : gameObjects) 
            {
                obj->Update();
            }
            for (auto& obj : gameObjects) 
            {
                obj->Draw();
            }
            for (auto it = gameObjects.begin(); it != gameObjects.end();) {
                if (!(*it)->IsAlive())
                {
                    delete* it;
                    it = gameObjects.erase(it);
                }
                else
                {
                    ++it;
                }
            }

           
            Player* player = nullptr;
            for (auto& obj : gameObjects) 
            {
                player = dynamic_cast<Player*>(obj);
                if (player) break;
            }
            if (player) 
            {
                for (auto& obj : gameObjects) 
                {
                    EnemyBeam* beam = dynamic_cast<EnemyBeam*>(obj);
                    if (beam && beam->IsFired()) 
                    {
                        if (CheckHit(player->GetRect(), beam->GetRect())) 
                        {
                            g_Scene = SceneType::GameOver;
                        }
                    }
                }
            }
            
        }
        else if (g_Scene == SceneType::GameOver) 
        {
            DrawFormatString(100, 100, GetColor(255, 0, 0), "�Q�[���I�[�o�[");
            DrawFormatString(100, 150, GetColor(255, 255, 255), "R�L�[�Ń��g���C");
            if (CheckHitKey(KEY_INPUT_R)) 
            {
                g_Scene = SceneType::Title;
            }
        }


        ScreenFlip();
        WaitTimer(16);

        prevTime = crrTime;

        if (ProcessMessage() == -1)
            break;
        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
            break;
	}

	DxLib_End();
	return 0;
}