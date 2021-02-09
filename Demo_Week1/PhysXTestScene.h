#pragma once
#include "GameScene.h"
class PhysXTestScene :
    public GameScene
{
public:
    PhysXTestScene();
protected:
    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Draw() const override;
    virtual void SceneActivated() override;

private:
    void ResetScene();

    enum class InputActionEnum
    {
        reset // ID 0
    };
    GameObject* m_pCube = nullptr;
};

