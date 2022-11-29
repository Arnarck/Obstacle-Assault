// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();

	FString Name = GetName();

	UE_LOG(LogTemp, Display, TEXT("BeginPlay: %s"), *Name);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	FString Name = GetName();
	CurrentLocation += DeltaTime * PlatformVelocity;
	SetActorLocation(CurrentLocation);

	// Scope Resolution Operator (::) -> Looks inside a class. Allow to get functions that don't run on a particular INSTANCE of that class.
	// Dot Operator (.) Looks inside an INSTANCE of a class.
	float DistanceMoved = FVector::Distance(StartLocation, CurrentLocation);

	if (DistanceMoved >= DistanceToMove)
	{
		float OverShoot = DistanceMoved - DistanceToMove;
		UE_LOG(LogTemp, Error, TEXT("Actor %s overshoot by %f"), *Name, OverShoot);
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation += MoveDirection * DistanceToMove;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
}

void AMovingPlatform::MovePlatform()
{

}