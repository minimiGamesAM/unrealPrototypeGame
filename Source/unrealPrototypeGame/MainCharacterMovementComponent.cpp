// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacterMovementComponent.h"

void UMainCharacterMovementComponent::MoveForward(float AxisValue)
{
	if( AxisValue != 0.0)
	UE_LOG(LogTemp, Warning, TEXT("Move forward activated %f"), AxisValue);
	
	//return 0.0f;
}

void UMainCharacterMovementComponent::MoveRight(float AxisValue)
{
	if (AxisValue != 0.0)
	UE_LOG(LogTemp, Warning, TEXT("Move right activated %f"), AxisValue);
}