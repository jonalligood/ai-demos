#include "State.h"

#include "LumberjackController.h"
#include "Kismet/GameplayStatics.h"
#include "StateMachine.h"

void ChopWood::Enter(ALumberjackController* Lumberjack)
{
    if (Lumberjack)
    {
        Lumberjack->MoveToWoods();
    }
}

void ChopWood::Execute(ALumberjackController* Lumberjack)
{
    if (!Lumberjack)
    {
        return;
    }

    if (!Lumberjack->IsCloseToWoods())
    {
        // Not at the woods, too far away
        return;
    }

    UE_LOG(LogTemp, Display, TEXT("Chop!"));
    Lumberjack->AddWood(1);
    Lumberjack->AddFatigue(1);

    if (Lumberjack->IsInventoryFull())
    {
        // TODO
        // Lumberjack->GetStateMachine()->ChangeState(Lumberjack->GetStateMachine()->GetSellWoodState());
        Lumberjack->GetStateMachine()->ChangeState(Lumberjack->GetSellWoodState());
    }

    if (Lumberjack->IsHungry())
    {
        // TODO
        // Lumberjack->GetStateMachine()->ChangeState(Lumberjack->GetStateMachine()->GetEatFoodState());
        Lumberjack->GetStateMachine()->ChangeState(Lumberjack->GetEatFoodState());
    }
}

void ChopWood::Exit(ALumberjackController* Lumberjack)
{
}

void SellWood::Enter(ALumberjackController* Lumberjack)
{
    if (Lumberjack)
    {
        Lumberjack->MoveToStore();
    }
}

void SellWood::Execute(ALumberjackController* Lumberjack)
{
    if (!Lumberjack)
    {
        return;
    }


    if (!Lumberjack->IsCloseToStore())
    {
        return;
    }

    Lumberjack->AddMoney(Lumberjack->GetWood());
    Lumberjack->RemoveWood(Lumberjack->GetWood());

    UE_LOG(LogTemp, Display, TEXT("Sold wood!"));

    if (Lumberjack->HasEnoughMoney())
    {
        // TODO
        // Lumberjack->GetStateMachine()->ChangeState(Lumberjack->GetStateMachine()->GetSleepState());
        Lumberjack->GetStateMachine()->ChangeState(Lumberjack->GetSleepState());
    }
    else
    {
        // TODO
        // Lumberjack->GetStateMachine()->ChangeState(Lumberjack->GetStateMachine()->GetChopWoodState());
        Lumberjack->GetStateMachine()->ChangeState(Lumberjack->GetChopWoodState());
    }
}

void SellWood::Exit(ALumberjackController* Lumberjack)
{
}

void EatFood::Enter(ALumberjackController* Lumberjack)
{
    if (Lumberjack)
    {
        Lumberjack->MoveToTavern();
    }
}

void EatFood::Execute(ALumberjackController* Lumberjack)
{
    if (!Lumberjack)
    {
        return;
    }


    if (!Lumberjack->IsCloseToTavern())
    {
        return;
    }

    Lumberjack->RemoveHunger(Lumberjack->GetHunger());
    Lumberjack->RemoveMoney(2);

    UE_LOG(LogTemp, Display, TEXT("Ate food!"));

    // TODO
    // Lumberjack->GetStateMachine()->ChangeState(Lumberjack->GetStateMachine()->GetChopWoodState());
    Lumberjack->GetStateMachine()->ChangeState(Lumberjack->GetChopWoodState());
}

void EatFood::Exit(ALumberjackController* Lumberjack)
{
}

void Sleep::Enter(ALumberjackController* Lumberjack)
{
    if (Lumberjack)
    {
        Lumberjack->MoveToHome();
    }
}

void Sleep::Execute(ALumberjackController* Lumberjack)
{
    if (!Lumberjack)
    {
        return;
    }

    if (!Lumberjack->IsCloseToHome())
    {
        return;
    }

    if (Lumberjack->GetFatigue() > 0)
    {
        UE_LOG(LogTemp, Display, TEXT("Zzz!"));
        Lumberjack->RemoveFatigue(1);
    }
    else
    {
        UE_LOG(LogTemp, Display, TEXT("I'm awake! Time to get back to work!"));

        // TODO
        // Lumberjack->GetStateMachine()->ChangeState(Lumberjack->GetStateMachine()->GetChopWoodState());
        Lumberjack->GetStateMachine()->ChangeState(Lumberjack->GetChopWoodState());
    }
}

void Sleep::Exit(ALumberjackController* Lumberjack)
{
}
