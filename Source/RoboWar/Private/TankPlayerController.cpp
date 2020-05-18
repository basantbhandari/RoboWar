// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Tank is not controlled by player controller class"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Tank is  controlled by player controller class= %s"), *(ControlledTank->GetName()));
	}

}




void ATankPlayerController::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
  //AimTowardsCrossHair
	AimTowardsCrossHair();
	UE_LOG(LogTemp, Warning, TEXT("ticked from player controller"));

}






ATank* ATankPlayerController::GetControlledTank() const
{
	 return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AimTowardsCrossHair()
{
	if(!GetControlledTank())
	{
		return;
	}
	//get world location if line trace through cross hair
	//if it hits the landscape
	   //tell controlled tank to hit the aim
	
}













