#include "stdafx.h"
#include "FrictionTestScene.h"

#include "CubePosColorNorm.h"

FrictionTestScene::FrictionTestScene() :
	GameScene(L"FrictionTestScene")
{
}

void FrictionTestScene::Initialize()
{
	EnablePhysxDebugRendering(true);

	using namespace physx;
	PxPhysics* const pxPhysX = PhysxManager::GetInstance()->GetPhysics();

	//Create a plane
	PxTransform const planeTransform = PxTransform(PxQuat{ PxPiDivTwo, PxVec3{0,0,1} }); // Fixes plane orientation
	PxRigidStatic* const pPlaneActor = pxPhysX->createRigidStatic(planeTransform);
	PxMaterial* const pPlaneMaterial = pxPhysX->createMaterial(0.f, 0.f, 0.f);
	pPlaneActor->createShape(PxPlaneGeometry(), *pPlaneMaterial);
	m_pPhysxScene->addActor(*pPlaneActor); // Add plane to scene

	//Create boxes
	PxRigidBody* const pBoxActor1 = pxPhysX->createRigidDynamic(PxTransform::createIdentity());
	PxRigidBody* const pBoxActor2 = pxPhysX->createRigidDynamic(PxTransform::createIdentity());
	PxRigidBody* const pBoxActor3 = pxPhysX->createRigidDynamic(PxTransform::createIdentity());

	XMFLOAT3 dimensions = XMFLOAT3(1.f, 1.f, 1.f);
	PxBoxGeometry const boxGeometry = PxBoxGeometry(dimensions.x / 2.f, dimensions.y / 2.f, dimensions.z / 2.f);
	PxMaterial* const pBoxMaterial1 = pxPhysX->createMaterial(0.f, 0.f, 0.f);
	PxMaterial* const pBoxMaterial2 = pxPhysX->createMaterial(0.f, 0.5f, 0.f);
	PxMaterial* const pBoxMaterial3 = pxPhysX->createMaterial(0.f, 1.f, 0.f);

	pBoxActor1->createShape(boxGeometry, *pBoxMaterial1);
	pBoxActor2->createShape(boxGeometry, *pBoxMaterial2);
	pBoxActor3->createShape(boxGeometry, *pBoxMaterial3);

	m_pCube1 = new CubePosColorNorm(dimensions.x, dimensions.y, dimensions.z);
	m_pCube2 = new CubePosColorNorm(dimensions.x, dimensions.y, dimensions.z);
	m_pCube3 = new CubePosColorNorm(dimensions.x, dimensions.y, dimensions.z);


	m_pCube1->AttachRigidActor(pBoxActor1);
	m_pCube2->AttachRigidActor(pBoxActor2);
	m_pCube3->AttachRigidActor(pBoxActor3);


	m_pCube1->Translate(-10.f, 5.f, 0.f);
	m_pCube2->Translate(0.f, 5.f, 0.f);
	m_pCube3->Translate(10.f, 5.f, 0.f);
	AddGameObject(m_pCube1);
	AddGameObject(m_pCube2);
	AddGameObject(m_pCube3);



	//Create ramps
	PxRigidStatic* const pRampActor1 = pxPhysX->createRigidStatic(PxTransform::createIdentity());
	PxRigidStatic* const pRampActor2 = pxPhysX->createRigidStatic(PxTransform::createIdentity());
	PxRigidStatic* const pRampActor3 = pxPhysX->createRigidStatic(PxTransform::createIdentity());

	XMFLOAT3 rampDimensions = XMFLOAT3(4.f, 1.f, 2.f);
	PxBoxGeometry const rampGeometry = PxBoxGeometry(rampDimensions.x / 2.f, rampDimensions.y / 2.f, rampDimensions.z / 2.f);
	PxMaterial* const pRampMaterial = pxPhysX->createMaterial(0.f,0.f,0.f);

	pRampActor1->createShape(rampGeometry,*pRampMaterial);
	pRampActor2->createShape(rampGeometry,*pRampMaterial);
	pRampActor3->createShape(rampGeometry,*pRampMaterial);

	m_pRamp1 = new CubePosColorNorm(rampDimensions.x,rampDimensions.y,rampDimensions.z);
	m_pRamp2 = new CubePosColorNorm(rampDimensions.x,rampDimensions.y,rampDimensions.z);
	m_pRamp3 = new CubePosColorNorm(rampDimensions.x,rampDimensions.y,rampDimensions.z);

	m_pRamp1->AttachRigidActor(pRampActor1);
	m_pRamp2->AttachRigidActor(pRampActor2);
	m_pRamp3->AttachRigidActor(pRampActor3);

	m_pRamp1->Translate(0.f, 4.f, 0.f);
	m_pRamp1->Rotate(0.f,0.f,-0.3f);

	m_pRamp2->Translate(-10.f, 4.f, 0.f);
	m_pRamp2->Rotate(0.f, 0.f, -0.3f);

	m_pRamp3->Translate(10.f, 4.f, 0.f);
	m_pRamp3->Rotate(0.f, 0.f, -0.3f);

	AddGameObject(m_pRamp1);
	AddGameObject(m_pRamp2);
	AddGameObject(m_pRamp3);

}



void FrictionTestScene::Update()
{
}

void FrictionTestScene::Draw() const
{
}
