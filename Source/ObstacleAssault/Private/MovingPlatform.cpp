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
	start_location = actor_position_on_play;
	SetActorLocation(actor_position_on_play);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetActorLocation().Y >= start_location.Y + 200) direction = -1;
	else if (GetActorLocation().Y <= start_location.Y - 200) direction = 1;

	SetActorLocation(GetActorLocation() + (FVector(0, 1, 0) * DeltaTime * direction * 100));
}

