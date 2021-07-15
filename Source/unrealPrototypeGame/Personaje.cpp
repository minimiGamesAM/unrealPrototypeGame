// Fill out your copyright notice in the Description page of Project Settings.


#include "Personaje.h"

// Sets default values
APersonaje::APersonaje()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APersonaje::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APersonaje::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float APersonaje::MoveForward(float AxisValue)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, AxisValue);

	//UE_LOG(LogTemp, Warning, TEXT("MoveForward %f"), AxisValue);

	return 0.0f;
}

float APersonaje::MoveRight(float AxisValue)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, AxisValue);
	return 0.0f;
}

// Called to bind functionality to input
void APersonaje::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	//PlayerInputComponent->BindAxis("MoveForward", this, &APersonaje::MoveForward);
	//PlayerInputComponent->BindAxis("MoveRight", this, &APersonaje::MoveRight);
}

