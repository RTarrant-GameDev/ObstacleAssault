// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay() //Unity equivalent: void Start()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime) //Unity equivalent: void Update()
{
	Super::Tick(DeltaTime);

	// Move platform forwards
		//Get current location
	FVector CurrentLocation = GetActorLocation();
		//Add vector to location with local variable
	CurrentLocation += (PlatformVelocity * DeltaTime);
		//Set new location
	SetActorLocation(CurrentLocation);
	//Move platform backwards if gone too far
		//Check how far we moved
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
		//Reverse direction of motion if gone too far
	if(DistanceMoved > MoveDistance){
		PlatformVelocity = -PlatformVelocity;
		StartLocation = CurrentLocation;
	}
}
