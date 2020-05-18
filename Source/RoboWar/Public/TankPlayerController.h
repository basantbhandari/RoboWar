// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ROBOWAR_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()


public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
private:
	ATank* GetControlledTank() const;
	void AimTowardsCrossHair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitDirection(FVector LookDirection, FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
	float crossHairXLocation = 0.5;


	UPROPERTY(EditAnywhere)
	float crossHairYLocation = 0.3333;
	
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.0f;
};




