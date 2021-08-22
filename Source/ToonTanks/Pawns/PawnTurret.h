// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTurret.generated.h"

UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float FireRate = 2.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float FireRange = 500.f;

	void CheckFireCondition();

	FTimerHandle FireRateTimerHandle;

	class APawnTank* PlayerPawn;

	float GetDistanceToPlayer() const;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void OnDestruction() override;

protected:
	virtual void BeginPlay() override;
};
