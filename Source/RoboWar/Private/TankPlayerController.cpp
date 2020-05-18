// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
# define OUT

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
	//UE_LOG(LogTemp, Warning, TEXT("ticked from player controller"));

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

	FVector HitLocation; //out parameter
    if(GetSightRayHitLocation(HitLocation))
    {
		UE_LOG(LogTemp, Warning, TEXT("Hit location = %s"), *(HitLocation.ToString()));
		   // TODO tell controlled tank to hit the aim
    }
	
}


//get world location if line trace through cross hair
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{

	//find the cross hair position

	int32 viewPortSizeX, viewPortSizeY;
	GetViewportSize(OUT viewPortSizeX, OUT viewPortSizeY);

	auto ScreenLocation = FVector2D( viewPortSizeX*crossHairXLocation, viewPortSizeY*crossHairYLocation);
	//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation = %s"), *(ScreenLocation.ToString()));
	//"De-projects" the screen position to the cross hair to the world location

	
	FVector LookDirection;

	if(GetLookDirection(ScreenLocation, OUT LookDirection))
	{
		//line trace along that look direction and see what we hit(up to max range)
		GetLookVectorHitDirection(LookDirection, OUT HitLocation);
	}
	
	

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	bool result = DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, OUT CameraWorldLocation, OUT LookDirection);
	return result;
}



bool ATankPlayerController::GetLookVectorHitDirection(FVector LookDirection, FVector& HitLocation) const
{

	FHitResult HitResults;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	//if hit location successed
	if(GetWorld()->LineTraceSingleByChannel(HitResults,StartLocation,EndLocation,ECollisionChannel::ECC_Visibility)){
		// set hit location
		HitLocation = HitResults.Location;
		return true;
     }
	return false;
	
}





