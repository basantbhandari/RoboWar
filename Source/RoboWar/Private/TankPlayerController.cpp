// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if(!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("tank is not controlled by player controller class"));
	}else
	{
		UE_LOG(LogTemp, Error, TEXT("tank is  controlled by player controller class= %s"), *(ControlledTank->GetName()));
	}
	
}




ATank* ATankPlayerController::GetControlledTank() const
{
	 return Cast<ATank>(GetPawn());
}