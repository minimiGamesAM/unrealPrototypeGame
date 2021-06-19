// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCharacterMovementComponent.h"

UMainCharacterMovementComponent::UMainCharacterMovementComponent()
{
	MaxAcceleration = 1000.0f;
	Acceleration = FVector::ZeroVector;
}

void UMainCharacterMovementComponent::MoveForward(float AxisValue)
{
	if (PawnOwner && UpdatedComponent == PawnOwner->GetRootComponent())
	{
		AddInputVector(PawnOwner->GetActorForwardVector() * AxisValue);
	}
}

void UMainCharacterMovementComponent::MoveRight(float AxisValue)
{
	if (PawnOwner && UpdatedComponent == PawnOwner->GetRootComponent())
	{
		AddInputVector(PawnOwner->GetActorRightVector() * AxisValue);
	}
}

void UMainCharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
	{
		return;
	}

	const FVector InputVector = ConsumeInputVector().GetClampedToMaxSize(1.0f);
	Acceleration += InputVector * MaxAcceleration;

	Velocity += Acceleration * DeltaTime;

	FVector DesiredMovementThisFrame = Velocity * DeltaTime;

	if (!DesiredMovementThisFrame.IsNearlyZero())
	{
		FRotator CurrentRotation;
		MoveUpdatedComponent(DesiredMovementThisFrame, CurrentRotation, true);
	}
		
	//Damping
	Acceleration *= 0.65f;
	Velocity *= 0.95f;

}