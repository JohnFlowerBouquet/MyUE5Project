// Fill out your copyright notice in the Description page of Project Settings.

#include "RollaBallPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ARollaBallPlayer::ARollaBallPlayer()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create components
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	// Components configuration
	RootComponent = Mesh;
	SpringArm->SetupAttachment(Mesh);
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void ARollaBallPlayer::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
// void ARollaBallPlayer::Tick(float DeltaTime)
// {
// 	Super::Tick(DeltaTime);

// }

// Called to bind functionality to input
void ARollaBallPlayer::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Axis Bindings
	InputComponent->BindAxis("MoveForward", this, &ARollaBallPlayer::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ARollaBallPlayer::MoveRight);
	// Action Bindings
	InputComponent->BindAction("Jump", IE_Pressed, this, &ARollaBallPlayer::Jump);
}

void ARollaBallPlayer::MoveForward(float Value)
{
	// Get the forward vector of the camera as it doesn't rotate and move the player in this direction based on
	// value and MoveForce
	const FVector Forward = Camera->GetForwardVector() * MoveForce * Value;
	Mesh->AddForce(Forward);
}

void ARollaBallPlayer::MoveRight(float Value)
{
	// Get the right vector of the camera as it doesn't rotate and move the player in this direction based on
	// value and MoveForce
	const FVector Right = Camera->GetRightVector() * MoveForce * Value;
	Mesh->AddForce(Right);
}

void ARollaBallPlayer::Jump()
{
	// Add impulse to the Mesh in x vector
	Mesh->AddImpulse(FVector(0, 0, JumpImpulse));
}
