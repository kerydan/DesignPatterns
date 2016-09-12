//
#include <stdio.h>
#include <iostream>




class PowerState 
{
public:
	static PowerState* GetInstance();
	void GoSuspendPower(PowerManager* man) {};
	void GoFullPower(PowerManager* man) {};
	void GoLowPower(PowerManager* man) {};

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
	};
	void GoSuspendPower() { ChangeState }
};



class FullPowerState : public PowerState
{
public:
	static PowerState* GetInstance()
	{
		static FullPowerState state;
		return &state;
	};
};

class SuspendPowerState : public PowerState
{
public:
	static PowerState* GetInstance()
	{
		static SuspendPowerState state;
		return &state;
	};
};



class PowerManager 
{
public:
	PowerManager();
	void GoSuspendPower(PowerManager *man) 
	{ 
		// do whatever needed prior going to the suspend mode
		state->GoSuspendPower(this); 
	};
	void GoFullPower()
	{
		// do whatever needed prior going to the suspend mode
		state->GoFullPower(this);
	};

	void GoLowPower()
	{
		// do whatever needed prior going to the suspend mode
		state->GoLowPower(this);
	};

private:
	friend class PowerState;
	void ChangeState(PowerState* _state) { state = _state; };
	PowerState* state;
};

PowerManager::PowerManager() 
{
	state = LowPowerState::GetInstance();

}



int main()
{
	

	return 0;
}