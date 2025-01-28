#pragma once

class ALumberjackController;
class State;
// TODO
class ChopWood;
class EatFood;
class SellWood;
class Sleep;

class StateMachine
{
public:
    StateMachine(ALumberjackController* MachineOwner);

    void SetCurrentState(TSharedPtr<State> S) { CurrentState = S; }

    void Update() const;

    // Change to a new state, calling exit and enter functionality along the way
    void ChangeState(TSharedPtr<State> NewState);

 // TODO
    /*TSharedPtr<ChopWood> GetChopWoodState() { return ChopWoodState; }
    TSharedPtr<SellWood> GetSellWoodState() { return SellWoodState; }
    TSharedPtr<EatFood> GetEatFoodState() { return EatFoodState; }
    TSharedPtr<Sleep> GetSleepState() { return SleepState; }*/

private:
    TSharedPtr<State> CurrentState;

    // Not exactly a reusable state machine, which is fine for a demo
    // 
    TObjectPtr<ALumberjackController> Owner;

    // TODO
    /*TSharedPtr<ChopWood> ChopWoodState;
    TSharedPtr<SellWood> SellWoodState;
    TSharedPtr<EatFood> EatFoodState;
    TSharedPtr<Sleep> SleepState;*/
};

