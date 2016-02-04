#include "stdafx.h"
#include "GameState_Test.h"


GameState_Test::GameState_Test()
{
}


GameState_Test::~GameState_Test()
{
}

void GameState_Test::Update(double tickTime)
{
}

void GameState_Test::Draw(HDC targetDC)
{
	if (myCube != nullptr)
	{
		myCube->Render(
			targetDC,
			g_GameManager.GetViewMatrix(),
			g_GameManager.GetProjectionMatrix(),
			g_GameManager.GetViewPortMatrix()
			);
	}
}

void GameState_Test::OnEnterState()
{
	if (myCube != nullptr)
	{
		delete myCube;
		myCube = nullptr;
	}
	myCube = new Cube();
	myCube->Initialize();
}

void GameState_Test::OnLeaveState()
{
	if (myCube != nullptr)
	{
		delete myCube;
		myCube = nullptr;
	}
}