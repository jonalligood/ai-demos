// Fill out your copyright notice in the Description page of Project Settings.


#include "StatusComponent.h"

#include "Components/TextBlock.h"
#include "StatusWidget.h"

void UStatusComponent::SetStatusText(FString Status)
{
    if (StatusWidget == nullptr)
    {
        StatusWidget = Cast<UStatusWidget>(GetUserWidgetObject());
    }

    if (StatusWidget && StatusWidget->StatusText)
    {
        StatusWidget->StatusText->SetText(FText::FromString(Status));
        StatusWidget->PlayAnimation(StatusWidget->ShowStatus);
    }
}
