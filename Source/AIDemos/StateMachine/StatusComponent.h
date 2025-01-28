// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "StatusComponent.generated.h"

class UStatusWidget;

/**
 * 
 */
UCLASS()
class AIDEMOS_API UStatusComponent : public UWidgetComponent
{
	GENERATED_BODY()
	
public:
	void SetStatusText(FString Status);

private:
	UPROPERTY()
	TObjectPtr<UStatusWidget> StatusWidget;
};
