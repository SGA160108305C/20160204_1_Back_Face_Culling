#pragma once
#include "GameState.h"
#include "Cube.h"
class GameState_Test :
	public GameState
{
public:
	GameState_Test();
	virtual ~GameState_Test();

	virtual void Update(double tickTime) override;
	virtual void Draw(HDC targetDC) override;

	virtual void OnEnterState() override;
	virtual void OnLeaveState() override;

private:
	Cube* myCube = nullptr;
};

