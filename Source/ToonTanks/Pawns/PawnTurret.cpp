// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "PawnTank.h"
#include "Kismet/GameplayStatics.h"

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!PlayerPawn || GetDistanceToPlayer() > FireRange) return;

	RotateTurret(PlayerPawn->GetActorLocation());
}

void APawnTurret::CheckFireCondition()
{
	bool bPlayerAlive = PlayerPawn->GetIsPlayerAlive();
	bool bPlayerInRange = GetDistanceToPlayer() <= FireRange;

	if (!PlayerPawn || !bPlayerAlive) return;

	if (bPlayerInRange)
		Fire();
}

float APawnTurret::GetDistanceToPlayer() const
{
	if (!PlayerPawn) return 0.0f;

	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}

void APawnTurret::OnDestruction()
{
	Super::OnDestruction();

	Destroy();
}

