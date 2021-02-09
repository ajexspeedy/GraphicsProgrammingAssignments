#include "stdafx.h"
#include "BouncingBallScene.h"


#include "SpherePosColorNorm.h"


BouncingBallScene::BouncingBallScene():
	GameScene(L"BouncingBallScene")
{
}

void BouncingBallScene::Initialize()
{
	EnablePhysxDebugRendering(true);

	using namespace physx;
	PxPhysics* const pxPhysX = PhysxManager::GetInstance()->GetPhysics();

	//Spheres

	PxRigidBody* const pSphereActor1 = pxPhysX->createRigidDynamic(PxTransform::createIdentity());
	PxRigidBody* const pSphereActor2 = pxPhysX->createRigidDynamic(PxTransform::createIdentity());
	PxRigidBody* const pSphereActor3 = pxPhysX->createRigidDynamic(PxTransform::createIdentity());

	PxSphereGeometry const sphereGeometry = PxSphereGeometry(XM_PIDIV2);
	PxMaterial* const pSphereBouncingMaterial = pxPhysX->createMaterial(1.f, 1.f, 1.f);
	PxMaterial* const pSphereHalfBouncingMaterial = pxPhysX->createMaterial(1.f, 1.f, 0.5f);
	PxMaterial* const pSphereNoBouncingMaterial = pxPhysX->createMaterial(1.f, 1.f, 0.f);
	pSphereActor1->createShape(sphereGeometry, *pSphereBouncingMaterial);
	pSphereActor2->createShape(sphereGeometry, *pSphereHalfBouncingMaterial);
	pSphereActor3->createShape(sphereGeometry, *pSphereNoBouncingMaterial);


	m_pSphere1 = new SpherePosColorNorm(XM_PIDIV2, 10, 10, {1,0,0,1});
	m_pSphere2 = new SpherePosColorNorm(XM_PIDIV2, 10, 10, {0,1,0,1});
	m_pSphere3 = new SpherePosColorNorm(XM_PIDIV2, 10, 10, {0,0,1,1});

	m_pSphere1->AttachRigidActor(pSphereActor1);
	m_pSphere2->AttachRigidActor(pSphereActor2);
	m_pSphere3->AttachRigidActor(pSphereActor3);

	m_pSphere1->Translate(-10.f, 10.f, 0.f);
	m_pSphere2->Translate(0.f, 20.f, 0.f);
	m_pSphere3->Translate(10.f, 30.f, 0.f);

	AddGameObject(m_pSphere1);
	AddGameObject(m_pSphere2);
	AddGameObject(m_pSphere3);
	

	//Create a plane
	PxTransform const planeTransform = PxTransform(PxQuat{ PxPiDivTwo, PxVec3{0,0,1} }); // Fixes plane orientation
	PxRigidStatic* const pPlaneActor = pxPhysX->createRigidStatic(planeTransform);
	PxMaterial* const pPlaneMaterial = pxPhysX->createMaterial(0.5f, 0.5f, 0.5f);
	pPlaneActor->createShape(PxPlaneGeometry(), *pPlaneMaterial);
	m_pPhysxScene->addActor(*pPlaneActor); // Add plane to scene

	
}

void BouncingBallScene::Update()
{

}

void BouncingBallScene::Draw() const
{
}
