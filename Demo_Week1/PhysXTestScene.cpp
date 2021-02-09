#include "stdafx.h"
#include "PhysXTestScene.h"

#include "PhysxManager.h"
#include "CubePosColorNorm.h"
#include "Logger.h"

PhysXTestScene::PhysXTestScene() :
	GameScene(L"PhysXTestScene")
{
}

void PhysXTestScene::Initialize()
{
	EnablePhysxDebugRendering(true);

	using namespace physx;
	PxPhysics* const pxPhysX = PhysxManager::GetInstance()->GetPhysics();
	PxRigidBody* const pBoxActor = pxPhysX->createRigidDynamic(PxTransform::createIdentity());
	XMFLOAT3 dimensions = XMFLOAT3(2.f, 1.f, 0.5f);
	PxBoxGeometry const boxGeometry = PxBoxGeometry(dimensions.x / 2.f, dimensions.y / 2.f, dimensions.z / 2.f);
	PxMaterial* const pBoxMaterial = pxPhysX->createMaterial(0.2f, 0.1f, 0.5f);
	pBoxActor->createShape(boxGeometry, *pBoxMaterial);

	m_pCube = new CubePosColorNorm(dimensions.x, dimensions.y, dimensions.z);
	m_pCube->AttachRigidActor(pBoxActor);
	m_pCube->Translate(0.f, 0.5f, 0.f);
	m_pCube->Rotate(0.1f, 0.2f, 0.3f);
	AddGameObject(m_pCube);

	//Plane
	PxTransform const planeTransform = PxTransform(PxQuat{ PxPiDivTwo, PxVec3{0,0,1} }); // Fixes plane orientation
	PxRigidStatic* const pPlaneActor = pxPhysX->createRigidStatic(planeTransform);
	PxMaterial* const pPlaneMaterial = pxPhysX->createMaterial(0.5f, 0.5f, 0.5f);
	pPlaneActor->createShape(PxPlaneGeometry(), *pPlaneMaterial);
	m_pPhysxScene->addActor(*pPlaneActor);


	//Input
	m_pSceneContext->GetInput()->AddInputAction(
		InputAction(int(InputActionEnum::reset), InputTriggerState::pressed, 'R'));
}

void PhysXTestScene::Update()
{
	if (m_pSceneContext->GetInput()->IsActionTriggered(int(InputActionEnum::reset)))
		ResetScene();
}



void PhysXTestScene::Draw() const
{
}

void PhysXTestScene::SceneActivated()
{
	Logger::GetInstance()->LogInfo(L"Reset my scene....weee...\a"); // #include "Logger.h"
	ResetScene();
}

void PhysXTestScene::ResetScene()
{
	m_pCube->Translate(0.f, 0.5f, 0.f);
	m_pCube->Rotate(0.1f, 0.2f, 0.3f);

	//Reset velocities with dirty casts
	static_cast<PxRigidDynamic*>(m_pCube->GetRigidActor())->setLinearVelocity({ 0.f,0.f,0.f });
	static_cast<PxRigidDynamic*>(m_pCube->GetRigidActor())->setAngularVelocity({ 0.f,0.f,0.f });

}
