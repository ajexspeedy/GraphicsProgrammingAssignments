#pragma once
#include "GameScene.h"
class FrictionTestScene :
    public GameScene
{
public:
    FrictionTestScene();
protected:
    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Draw() const override;

private:
    GameObject* m_pCube1 = nullptr;
    GameObject* m_pCube2 = nullptr;
    GameObject* m_pCube3 = nullptr;

    GameObject* m_pRamp1 = nullptr;
    GameObject* m_pRamp2 = nullptr;
    GameObject* m_pRamp3 = nullptr;
};

