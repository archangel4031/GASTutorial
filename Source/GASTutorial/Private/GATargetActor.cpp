// Fill out your copyright notice in the Description page of Project Settings.


#include "GATargetActor.h"
#include "Abilities/GameplayAbility.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"

AGATargetActor::AGATargetActor()
{
	PrimaryActorTick.bCanEverTick = true;
	TraceRange = 1500.0f;
	bDestroyOnConfirmation = true;
}

bool AGATargetActor::LineTraceFN(FHitResult& TraceHitResult)
{
	FVector ViewPoint;
	FRotator ViewRotation;
	MasterPC->GetPlayerViewPoint(ViewPoint, ViewRotation);
	FCollisionQueryParams QueryParams;
	QueryParams.bTraceComplex = true;
	APawn* MasterPawn = MasterPC->GetPawn();
	if (MasterPawn)
	{
		QueryParams.AddIgnoredActor(MasterPawn->GetUniqueID());
	}

	bool TryTrace = GetWorld()->LineTraceSingleByChannel(TraceHitResult, ViewPoint, ViewPoint + ViewRotation.Vector() * TraceRange, ECC_Visibility, QueryParams);

	return TryTrace;
}

void AGATargetActor::StartTargeting(UGameplayAbility* Ability)
{
	OwningAbility = Ability;
	MasterPC = Cast<APlayerController>(Ability->GetOwningActorFromActorInfo()->GetInstigatorController());
}

void AGATargetActor::ConfirmTargetingAndContinue()
{
	FHitResult HitResult;
	bool TryTrace = LineTraceFN(HitResult);
	FGameplayAbilityTargetDataHandle TargetData;
	TargetData = StartLocation.MakeTargetDataHandleFromHitResult(OwningAbility, HitResult);
	if (TargetData != nullptr)
	{
		TargetDataReadyDelegate.Broadcast(TargetData);
	}
	else
	{
		TargetDataReadyDelegate.Broadcast(FGameplayAbilityTargetDataHandle());
	}
}
