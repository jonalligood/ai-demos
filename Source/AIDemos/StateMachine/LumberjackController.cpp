#include "LumberjackController.h"

#include "Kismet/GameplayStatics.h"
#include "Lumberjack.h"
#include "State.h"
#include "StateMachine.h"

void ALumberjackController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    TimeSinceLastUpdate += DeltaTime;

    if (TimeSinceLastUpdate > UpdateRate)
    {
        TimeSinceLastUpdate = 0.f;
        Update();
    }
}

void ALumberjackController::Update()
{
    Hunger += 1;

    if (LumberjackStateMachine)
    {
        LumberjackStateMachine->Update();
    }
}

void ALumberjackController::AddWood(int Amount)
{
    Wood += Amount;
    if (Lumberjack)
    {
        Lumberjack->ShowPositiveStatus(FString::Printf(TEXT("+%d Wood"), Amount));
    }
}

void ALumberjackController::RemoveWood(int Amount)
{
    Wood -= Amount;
    if (Lumberjack)
    {
        Lumberjack->ShowNegativeStatus(FString::Printf(TEXT("-%d Wood"), Amount));
    }
}

void ALumberjackController::AddMoney(int Amount)
{
    Money += Amount;
    if (Lumberjack)
    {
        Lumberjack->ShowPositiveStatus(FString::Printf(TEXT("+%d Money"), Amount));
    }
}

void ALumberjackController::RemoveMoney(int Amount)
{
    Money -= Amount;
    if (Lumberjack)
    {
        Lumberjack->ShowNegativeStatus(FString::Printf(TEXT("-%d Money"), Amount));
    }
}

void ALumberjackController::AddHunger(int Amount)
{
    Hunger += Amount;
    if (Lumberjack)
    {
        Lumberjack->ShowNegativeStatus(FString::Printf(TEXT("+%d Hunger"), Amount));
    }
}

void ALumberjackController::RemoveHunger(int Amount)
{
    Hunger -= Amount;
    if (Lumberjack)
    {
        Lumberjack->ShowPositiveStatus(FString::Printf(TEXT("-%d Hunger"), Amount));
    }
}

void ALumberjackController::AddFatigue(int Amount)
{
    Fatigue += Amount;
    if (Lumberjack)
    {
        Lumberjack->ShowNegativeStatus(FString::Printf(TEXT("+%d Fatigue"), Amount));
    }
}

void ALumberjackController::RemoveFatigue(int Amount)
{
    Fatigue -= Amount;
    if (Lumberjack)
    {
        Lumberjack->ShowNegativeStatus(FString::Printf(TEXT("-%d Fatigue"), Amount));
    }
}

void ALumberjackController::MoveToWoods()
{
    if (Lumberjack)
    {
        AActor* Woods = Lumberjack->GetWoodsTarget();
        if (Woods)
        {
            MoveToActor(Woods);
        }
    }
}

bool ALumberjackController::IsCloseToWoods()
{
    if (Lumberjack)
    {
        AActor* Woods = Lumberjack->GetWoodsTarget();

        if (Woods)
        {
            return (Woods->GetActorLocation() - Lumberjack->GetActorLocation()).Size() < CloseToTarget;
        }
    }

    return false;
}

void ALumberjackController::MoveToStore()
{
    if (Lumberjack)
    {
        AActor* Store = Lumberjack->GetStoreTarget();
        if (Store)
        {
            MoveToActor(Store);
        }
    }
}

bool ALumberjackController::IsCloseToStore()
{
    if (Lumberjack)
    {
        AActor* Store = Lumberjack->GetStoreTarget();

        if (Store)
        {
            return (Store->GetActorLocation() - Lumberjack->GetActorLocation()).Size() < CloseToTarget;
        }
    }

    return false;
}

void ALumberjackController::MoveToTavern()
{
    if (Lumberjack)
    {
        AActor* Tavern = Lumberjack->GetTavernTarget();
        if (Tavern)
        {
            MoveToActor(Tavern);
        }
    }

}

bool ALumberjackController::IsCloseToTavern()
{
    if (Lumberjack)
    {
        AActor* Tavern = Lumberjack->GetTavernTarget();

        if (Tavern)
        {
            return (Tavern->GetActorLocation() - Lumberjack->GetActorLocation()).Size() < CloseToTarget;
        }
    }

    return false;
}

void ALumberjackController::MoveToHome()
{
    if (Lumberjack)
    {
        AActor* Home = Lumberjack->GetHomeTarget();
        if (Home)
        {
            MoveToActor(Home);
        }
    }
}

bool ALumberjackController::IsCloseToHome()
{
    if (Lumberjack)
    {
        AActor* Home = Lumberjack->GetHomeTarget();

        if (Home)
        {
            return (Home->GetActorLocation() - Lumberjack->GetActorLocation()).Size() < CloseToTarget;
        }
    }

    return false;
}

void ALumberjackController::BeginPlay()
{
    Super::BeginPlay();

    if (GetPawn())
    {
        Lumberjack = Cast<ALumberjack>(GetPawn());
    }

    ChopWoodState = MakeShared<ChopWood>();
    SellWoodState = MakeShared<SellWood>();
    EatFoodState = MakeShared<EatFood>();
    SleepState = MakeShared<Sleep>();

    LumberjackStateMachine = MakeShared<StateMachine>(this);
    // TODO
    // LumberjackStateMachine->ChangeState(LumberjackStateMachine->GetChopWoodState());
    LumberjackStateMachine->ChangeState(ChopWoodState);
}
