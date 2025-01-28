// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Lumberjack.generated.h"

class UStatusComponent;

UCLASS()
class AIDEMOS_API ALumberjack : public ACharacter
{
	GENERATED_BODY()

public:
	ALumberjack();

	virtual void Tick(float DeltaTime) override;

	AActor* GetWoodsTarget() { return WoodsTarget; }
	AActor* GetStoreTarget() { return StoreTarget; }
	AActor* GetTavernTarget() { return TavernTarget; }
	AActor* GetHomeTarget() { return HomeTarget; }

	void ShowPositiveStatus(FString Status);
	void ShowNegativeStatus(FString Status);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
	TObjectPtr<AActor> WoodsTarget;
	
	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
	TObjectPtr<AActor> StoreTarget;

	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
	TObjectPtr<AActor> TavernTarget;

	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
	TObjectPtr<AActor> HomeTarget;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStatusComponent> PositiveStatus;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStatusComponent> NegativeStatus;
};
