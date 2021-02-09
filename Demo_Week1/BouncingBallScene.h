#pragma once
#include "GameScene.h"
class BouncingBallScene :
    public GameScene
{
public:
    BouncingBallScene();

protected:
    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Draw() const override;
private:
    GameObject* m_pSphere1 = nullptr;
    GameObject* m_pSphere2 = nullptr;
    GameObject* m_pSphere3 = nullptr;


};

