// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("tank is not controlled by AI controller class"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("tank is  controlled by AI controller class= %s"), *(ControlledTank->GetName()));
	}

}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
