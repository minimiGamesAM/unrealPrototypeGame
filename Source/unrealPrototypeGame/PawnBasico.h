// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MainCharacterMovementComponent.h"
#include "PawnBasico.generated.h"

UCLASS()
class UNREALPROTOTYPEGAME_API APawnBasico : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnBasico();

	virtual UMainCharacterMovementComponent* GetMovementComponent() const override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
		
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Collision", meta = (DisplayName = "Pawn Collision AM"))
	class UCapsuleComponent* Capsule;

	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Movement", meta = (BluePrintProtected))
	UMainCharacterMovementComponent* MovementComponent;
};
