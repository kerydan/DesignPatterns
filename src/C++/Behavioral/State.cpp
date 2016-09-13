#include <stdio.h>
#include <iostream>

class PowerManager
{
public:
	PowerManager();
	void GoSuspendPower();
	void GoFullPower();
	void GoLowPower();

private:
	friend class PowerState;
	void ChangeState(PowerState* _state) { state = _state; };
	PowerState* state;
};

class PowerState
{
public:
	static PowerState* GetInstance();
	virtual void GoSuspendPower(PowerManager* man) {};
	virtual void GoFullPower(PowerManager* man) {};
	virtual void GoLowPower(PowerManager* man) {};

protected:
	PowerState() {}
	void ChangeState(PowerManager* man, PowerState* state) { man->ChangeState(state); };
};

class LowPowerState : public PowerState
{
public:
	static PowerState* GetInstance()
	{
		static LowPowerState state;
		return &state;
	}
	virtual void GoSuspendPower(PowerManager *man);
	virtual void GoFullPower(PowerManager *man);
};

class FullPowerState : public PowerState
{
public:
	static PowerState* GetInstance()
	{
		static FullPowerState state;
		return &state;
	}
};

class SuspendPowerState : public PowerState
{
public:
	static PowerState* GetInstance()
	{
		static SuspendPowerState state;
		return &state;
	}
	virtual void GoFullPower(PowerManager *man);
};

PowerManager::PowerManager()
{
	state = LowPowerState::GetInstance();
}

void PowerManager::GoSuspendPower()
{
	// do whatever needed prior going to the suspend mode
	state->GoSuspendPower(this);
}

void PowerManager::GoFullPower()
{
	// do whatever needed prior going to the suspend mode
	state->GoFullPower(this);
}

void PowerManager::GoLowPower()
{
	// do whatever needed prior going to the suspend mode
	state->GoLowPower(this);
}

void LowPowerState::GoSuspendPower(PowerManager *man)
{
	// save configuration to RAM
	ChangeState(man, SuspendPowerState::GetInstance());
}

void LowPowerState::GoFullPower(PowerManager *man)
{
	// start modules
	ChangeState(man, FullPowerState::GetInstance());
}

void SuspendPowerState::GoFullPower(PowerManager *man)
{
	// load configuration from RAM
	// start modules
	ChangeState(man, FullPowerState::GetInstance());
}

int main()
{
	PowerManager power_man;
	power_man.GoSuspendPower();
	power_man.GoFullPower();
	return 0;
}