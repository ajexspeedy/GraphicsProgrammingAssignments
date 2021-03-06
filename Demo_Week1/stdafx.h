// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

// TODO: reference additional headers your program requires here

// disable min and max to allow use of algorithm versions (before including windows.h)
//PhysX:you must suppress its definition of the macros min and max, as these are common C++ method names in the SDK
#define NOMINMAX

// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory>
#include <wchar.h>
#include <crtdbg.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <tchar.h>
#include <vector>
#include <algorithm>



#pragma region
//Direct3D Header Files:
#include <dxgi.h>
#pragma comment(lib, "dxgi.lib")

#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")
#include <d3dcompiler.h>
#pragma comment(lib, "d3dcompiler.lib")

//DirectXMath Header Files:
#include <DirectXMath.h>
#include <DirectXColors.h>
#include <DirectXPackedVector.h>
#include <DirectXCollision.h>
using namespace DirectX;

//**EFFECTS11 (Helper for loading Effects (D3DX11))
//https://fx11.codeplex.com/
#include <d3dx11effect.h> //[AdditionalLibraries/DX_Effects11/include/d3dx11effect.h]
#if defined(DEBUG) || defined(_DEBUG)
#pragma comment(lib, "DxEffects11_vc14_Debug.lib")
#else 
#pragma comment(lib, "DxEffects11_vc14_Release.lib")
#endif

//*DXTEX (Helper for loading Textures (D3DX11))
//http://directxtex.codeplex.com/
#include <DirectXTex.h>
#if defined(DEBUG) || defined(_DEBUG)
#pragma comment(lib, "DxTex_vc14_Debug.lib")
#else 
#pragma comment(lib, "DxTex_vc14_Release.lib")
#endif

#pragma endregion DIRECTX INCLUDES


// xbox controller
#include <Xinput.h>
#pragma comment(lib, "XINPUT9_1_0.LIB")

//PhysX
#pragma region
#include <PxPhysicsAPI.h>
using namespace physx;

#if defined(DEBUG) || defined(_DEBUG)
#pragma comment(lib, "PhysX3DEBUG_x86.lib")
#pragma comment(lib, "PhysX3CommonDEBUG_x86.lib")
#pragma comment(lib, "PhysX3ExtensionsDEBUG.lib")
#pragma comment(lib, "PhysXProfileSDKDEBUG.lib")
#pragma comment(lib, "PhysXVisualDebuggerSDKDEBUG.lib")
#else 
#pragma comment(lib, "PhysX3_x86.lib")
#pragma comment(lib, "PhysX3Common_x86.lib")
#pragma comment(lib, "PhysX3Extensions.lib")
#pragma comment(lib, "PhysXProfileSDK.lib")
#pragma comment(lib, "PhysXVisualDebuggerSDK.lib")
#endif
#pragma endregion PHYSX INCLUDES

//FMOD
#pragma region
#include "fmod.hpp" //Precompiled Header
#include "fmod_errors.h"

#if defined(DEBUG) || defined(_DEBUG)
#pragma comment(lib, "fmodL_vc.lib")
#else
#pragma comment(lib, "fmod_vc.lib")
#endif
#pragma endregion FMOD INCLUDES


// the one that holds the D3D11 data
#include "Locator.h"


#pragma region
//*****************************************************************************
//Declare templates for releasing interfaces and deleting objects 
//*****************************************************************************
template<class Interface>
inline void SafeRelease(Interface &pInterfaceToRelease)
{
	if (pInterfaceToRelease != 0)
	{
		pInterfaceToRelease->Release();
		pInterfaceToRelease = 0;
	}
}
template<class T>
inline void SafeDelete(T &pObjectToDelete)
{
	if (pObjectToDelete != nullptr)
	{
		delete(pObjectToDelete);
		pObjectToDelete = nullptr;
	}
}

template<typename T>
inline void Clamp(T& value, T hi, T lo)
{
	if (value > hi)
		value = hi;

	if (value < lo)
		value = lo;
}
#pragma endregion TEMPLATES & MACROS