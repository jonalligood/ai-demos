// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "LumberjackController.generated.h"

class ALumberjack;
// TODO
// class State;
class StateMachine;
class ChopWood;
class EatFood;
class SellWood;
class Sleep;

/**
 * 
 */
UCLASS()
class AIDEMOS_API ALumberjackController : public AAIController
{
	GENERATED_BODY()
	
public:
	void Tick(float DeltaTime) override;
	
	void Update();

	TSharedPtr<StateMachine> GetStateMachine() { return LumberjackStateMachine; }

	FORCEINLINE int GetWood() { return Wood; }
	void AddWood(int Amount);
	void RemoveWood(int Amount);
	bool IsInventoryFull() const { return Wood > InventoryLimit; }

	FORCEINLINE int GetMoney() { return Money; }
	void AddMoney(int Amount);
	void RemoveMoney(int Amount);
	bool HasEnoughMoney() const { return Money > MoneyLimit; }

	FORCEINLINE int GetHunger() { return Hunger; }
	void AddHunger(int Amount);
	void RemoveHunger(int Amount);
	bool IsHungry() const { return Hunger > HungerLimit; }

	FORCEINLINE int GetFatigue() { return Fatigue; }
	void AddFatigue(int Amount);
	void RemoveFatigue(int Amount);
	bool IsTired() const { return Fatigue > FatigueLimit; }

	/** Travel */
	void MoveToWoods();
	bool IsCloseToWoods();

	void MoveToStore();
	bool IsCloseToStore();

	void MoveToTavern();
	bool IsCloseToTavern();

	void MoveToHome();
	bool IsCloseToHome();

	TSharedPtr<ChopWood> GetChopWoodState() { return ChopWoodState; }
	TSharedPtr<SellWood> GetSellWoodState() { return SellWoodState; }
	TSharedPtr<EatFood> GetEatFoodState() { return EatFoodState; }
	TSharedPtr<Sleep> GetSleepState() { return SleepState; }

protected:
	void BeginPlay() override;

private:
	TObjectPtr<ALumberjack> Lumberjack;
	TSharedPtr<StateMachine> LumberjackStateMachine;

	// Since all the states are Lumberjack specific
	TSharedPtr<ChopWood> ChopWoodState;
	TSharedPtr<SellWood> SellWoodState;
	TSharedPtr<EatFood> EatFoodState;
	TSharedPtr<Sleep> SleepState;

	float UpdateRate = 3.f;
	float TimeSinceLastUpdate = 0.f;

	int Wood = 0;
	int Money = 0;
	int Hunger = 0;
	int Fatigue = 0;
	int InventoryLimit = 3;
	int HungerLimit = 5;
	int FatigueLimit = 5;
	int MoneyLimit = 5;

	float CloseToTarget = 200.f;
};
