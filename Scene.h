#pragma once
class Scene
{
public:
    virtual ~Scene() {}
    virtual void Update() = 0;
    virtual void Draw() = 0;
    // 次のシーンがあれば返す（なければnullptr）
    virtual Scene* GetNextScene() { return nullptr; }
};
enum class SceneType {
    Title,
    Game,
    GameOver  
};

