// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"
//using namespace UP;

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// ".h" files acts like the "MyBlueprint" panel, where you can create functions, variables, etc.
	// ".cpp" files acts more like the "Event Graph" itself, where you can use / modify variable values, implement functionallity to your methods, etc.
	// In other words...
	// The "header" file is for configuring and declaring what things are in the class
	// while "C++" file is where the actual code lives.
	// UPROPERTY() is like C# attributes ("[SerializeField]", "[HideInInspector]", etc)
	UPROPERTY(EditAnywhere, Category="Moving Platform Settings") FVector PlatformVelocity = FVector(100, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Moving Platform Settings") float DistanceToMove = 100;
	FVector StartLocation;

	void MovePlatform();
};
