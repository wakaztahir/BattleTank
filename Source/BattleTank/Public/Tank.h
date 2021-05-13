// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Projectile.h"

#include "Tank.generated.h"

class UTankTurret;
class UTankBarrel;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void Initialize(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = "Fire")
	void Fire();

protected:
	virtual void BeginPlay() override;
	
private:
	// Sets default values for this pawn's properties
	ATank();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr; //Local Barrel Reference For Spawning Projectile

	double LastFireTime = 0;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;
};
