// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	
	

	
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AIController can't find Player controller class"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AIController find Player controller class = %s"), *(PlayerTank->GetName()));
	}
	
	
	
}



 void ATankAIController::Tick(float DeltaSeconds)
{
	 Super::Tick(DeltaSeconds);

	 if (GetPlayerTank())
	 {
	 	//TODO move towards the player
	 	//Aim towards the player
		 GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	 	//fire if ready
		 
	 }
}



ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


ATank* ATankAIController::GetPlayerTank() const
{

	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if(!PlayerPawn)
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
	
}




