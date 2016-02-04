#pragma once
#include <Windows.h>

class GameState
{
public:
	virtual void Update(double tickTime) = 0;	
	virtual void Draw(HDC targetDC) = 0;	

	virtual void OnEnterState() = 0;	
	virtual void OnLeaveState() = 0;	
};

