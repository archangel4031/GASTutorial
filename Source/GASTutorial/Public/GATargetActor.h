// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetActor.h"
#include "GATargetActor.generated.h"

/**
 * 
 */
UCLASS()
class GASTUTORIAL_API AGATargetActor : public AGameplayAbilityTargetActor
{
	GENERATED_BODY()

public:

	AGATargetActor();

	virtual void StartTargeting(UGameplayAbility* Ability) override;
	virtual void ConfirmTargetingAndContinue() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = true), Category = "TargetActor")
	float TraceRange;

	bool LineTraceFN(FHitResult& TraceHitResult);

};
