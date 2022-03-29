// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GEExecMelee.generated.h"

/**
 * 
 */
UCLASS()
class GASTUTORIAL_API UGEExecMelee : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
	
public:
	UGEExecMelee();
	
	void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecParams, FGameplayEffectCustomExecutionOutput& ExecOutputs) const;
};
