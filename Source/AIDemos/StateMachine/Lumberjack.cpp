// Fill out your copyright notice in the Description page of Project Settings.


#include "Lumberjack.h"
#include "StatusComponent.h"

// Sets default values
ALumberjack::ALumberjack()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PositiveStatus = CreateDefaultSubobject<UStatusComponent>(TEXT("PositiveStatus"));
	PositiveStatus->SetupAttachment(GetRootComponent());
	PositiveStatus->SetWidgetSpace(EWidgetSpace::Screen);
	NegativeStatus = CreateDefaultSubobject<UStatusComponent>(TEXT("NegativeStatus"));
	NegativeStatus->SetupAttachment(GetRootComponent());
    NegativeStatus->SetWidgetSpace(EWidgetSpace::Screen);
}

void ALumberjack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALumberjack::ShowPositiveStatus(FString Status)
{
	if (PositiveStatus)
	{
		PositiveStatus->SetStatusText(Status);
	}
}

void ALumberjack::ShowNegativeStatus(FString Status)
{
	if (NegativeStatus)
	{
		NegativeStatus->SetStatusText(Status);
	}
}

void ALumberjack::BeginPlay()
{
	Super::BeginPlay();
}

