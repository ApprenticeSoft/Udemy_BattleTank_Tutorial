// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"))
	else
		UE_LOG(LogTemp, Warning, TEXT("AIController found player %s"), *(PlayerTank->GetName()))

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("Player Controller is ticking"));

	if (GetPlayerTank()) {
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank* ATankAIController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank)
		return nullptr;
	else
		return Cast<ATank>(PlayerTank);
}
