// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Personaje.generated.h"

UCLASS()
class UNREALPROTOTYPEGAME_API APersonaje : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APersonaje();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable)
	float MoveForward(float AxisValue);
	
	UFUNCTION(BlueprintCallable)
	float MoveRight(float AxisValue);

protected:

	//UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Float", meta = (BluePrintProtected))
	//float MovimientoRacioAdelante;

	//UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Float", meta = (BluePrintProtected))
	//float MovimientoRacioDerecha;

private:
	
	//Input
	//UFUNCTION()
	//void MoveForward(float AxisValue);
	//void MoveRight(float AxisValue);
};
