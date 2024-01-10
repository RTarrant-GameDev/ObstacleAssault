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

	ObjName = GetName();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime) //Unity equivalent: void Update()
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	if (ShouldPlatformReturn()) {
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;	
	} else {
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation += (PlatformVelocity * DeltaTime);
		SetActorLocation(CurrentLocation);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
		UE_LOG(LogTemp, Display, TEXT("%s should be rotating"), *ObjName);
}

bool AMovingPlatform::ShouldPlatformReturn()
{
    return (GetDistanceMoved() > MoveDistance);
}

float AMovingPlatform::GetDistanceMoved()
{
    return FVector::Dist(StartLocation, GetActorLocation());
}
