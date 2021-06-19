// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "MainCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPROTOTYPEGAME_API UMainCharacterMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()
	
public:

	UMainCharacterMovementComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//UFUNCTION(BlueprintCallable, Category = "Input")
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);

	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadOnly)
	float MaxAcceleration;

protected:
	FVector Acceleration;
};
