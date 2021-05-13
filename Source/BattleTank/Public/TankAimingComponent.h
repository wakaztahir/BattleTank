// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "TankAimingComponent.generated.h"



UENUM()
enum class EFiringState:uint8
{
	Locked,
	Aiming,
	Reloading
};

class AProjectile;
class UTankTurret;
class UTankBarrel;
// Holds barrel's properties and Elevate method
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Fire")
	void Fire();

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
protected:
	UPROPERTY(BlueprintReadOnly)
	EFiringState FiringStatus = EFiringState::Reloading;

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

	FVector CurrentAimDirection;

	bool IsBarrelMoving();
	
	double LastFireTime = 0;
	float ReloadTimeInSeconds = 3;

	void MoveBarrelTowards(FVector AimDirection);
};
