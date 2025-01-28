#pragma once

class ALumberjackController;

class State
{
public:
	virtual ~State() {}

	virtual void Enter(ALumberjackController* Lumberjack) = 0;
	virtual void Execute(ALumberjackController* Lumberjack) = 0;
	virtual void Exit(ALumberjackController* Lumberjack) = 0;
};

class ChopWood : public State
{
public:
	void Enter(ALumberjackController* Lumberjack) override;
	void Execute(ALumberjackController* Lumberjack) override;
	void Exit(ALumberjackController* Lumberjack) override;

private:
};

class SellWood : public State
{
public:
	void Enter(ALumberjackController* Lumberjack) override;
	void Execute(ALumberjackController* Lumberjack) override;
	void Exit(ALumberjackController* Lumberjack) override;
};

class EatFood : public State
{
public:
	void Enter(ALumberjackController* Lumberjack) override;
	void Execute(ALumberjackController* Lumberjack) override;
	void Exit(ALumberjackController* Lumberjack) override;
};

class Sleep : public State
{
public:
	void Enter(ALumberjackController* Lumberjack) override;
	void Execute(ALumberjackController* Lumberjack) override;
	void Exit(ALumberjackController* Lumberjack) override;
};
