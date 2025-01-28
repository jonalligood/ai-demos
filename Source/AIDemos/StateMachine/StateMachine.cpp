#include "StateMachine.h"

#include "LumberjackController.h"
#include "State.h"

StateMachine::StateMachine(ALumberjackController* MachineOwner)
    : Owner(MachineOwner)
    , CurrentState(nullptr)
{
    /*ChopWoodState = MakeShared<ChopWood>();
    SellWoodState = MakeShared<SellWood>();
    EatFoodState = MakeShared<EatFood>();
    SleepState = MakeShared<Sleep>();*/
}

void StateMachine::Update() const
{
    if (CurrentState)
    {
        CurrentState->Execute(Owner);
    }
}

// void StateMachine::ChangeState(State* NewState)
void StateMachine::ChangeState(TSharedPtr<State> NewState)
{
    if (!NewState)
    {
        return;
    }

    if (CurrentState)
    {
        CurrentState->Exit(Owner);
    }

    CurrentState = NewState;

    CurrentState->Enter(Owner);
}
