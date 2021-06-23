// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBasico.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APawnBasico::APawnBasico()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionCapsule"));
	RootComponent = Capsule;
	Capsule->SetCollisionProfileName(TEXT("Pawn"));

	MovementComponent = CreateDefaultSubobject<UMainCharacterMovementComponent>(TEXT("MovementComponent"));

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void APawnBasico::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APawnBasico::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UMainCharacterMovementComponent* APawnBasico::GetMovementComponent() const
{
	return MovementComponent;
}

// Called to bind functionality to input
void APawnBasico::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", MovementComponent, &UMainCharacterMovementComponent::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", MovementComponent, &UMainCharacterMovementComponent::MoveRight);
}

