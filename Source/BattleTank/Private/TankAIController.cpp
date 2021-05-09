// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank()
{
	auto pawn = GetPawn();
	if (pawn)
	{
		return Cast<ATank>(pawn);
	}
	else
	{
		return nullptr;
	}
}

ATank* ATankAIController::GetPlayerTank()
{
	auto pawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (pawn)
	{
		return Cast<ATank>(pawn);
	}
	else
	{
		return nullptr;
	}
}
