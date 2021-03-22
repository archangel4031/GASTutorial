// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Abilities/GameplayAbility.h"
#include "BaseCharacter.generated.h"

class UBaseAttributeSet;

UCLASS()
class GASTUTORIAL_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BaseCharacter")
	UAbilitySystemComponent* AbilitySystemComp;

	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
	void InitializeAbility(TSubclassOf<UGameplayAbility> AbilityToGet, int32 AbilityLevel);

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BaseCharacter")
	const class UBaseAttributeSet* BaseAttributeSetComp;

	UFUNCTION(BlueprintPure, Category = "BaseCharacter")
	void GetHealthValues(float& Health, float& MaxHealth);
	UFUNCTION(BlueprintPure, Category = "BaseCharacter")
	void GetManaValues(float& Mana, float& MaxMana);
	UFUNCTION(BlueprintPure, Category = "BaseCharacter")
	void GetStaminaValues(float& Stamina, float& MaxStamina);

	void OnHealthChagedNative(const FOnAttributeChangeData& Data);
	void OnManaChagedNative(const FOnAttributeChangeData& Data);
	void OnStaminaChagedNative(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "BaseCharacter")
	void OnHealthChanged(float OldValue, float NewValue);
	UFUNCTION(BlueprintImplementableEvent, Category = "BaseCharacter")
	void OnManaChanged(float OldValue, float NewValue);
	UFUNCTION(BlueprintImplementableEvent, Category = "BaseCharacter")
	void OnStaminaChanged(float OldValue, float NewValue);

	//Initialize Abilities Multi
	UFUNCTION(BlueprintCallable, Category="BaseCharacter")
	void InitializeAbilityMulti(TArray<TSubclassOf<UGameplayAbility>> AbilitiesToAcquire, int32 AbilityLevel);

	//Remove Abilities with Tag
	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
	void RemoveAbilityWithTags(FGameplayTagContainer TagContainer);

	//Change Ability Level with Tag
	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
	void ChangeAbilityLevelWithTags(FGameplayTagContainer TagContainer, int32 NewLevel);

	//Cancel Ability With Tag
	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
	void CancelAbilityWithTags(FGameplayTagContainer WithTags, FGameplayTagContainer WithoutTags);

	//Add Loose Gameplay Tag
	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
	void AddLooseGameplayTag(FGameplayTag TagToAdd);

	//Remove Loose Gameplay Tag
	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
	void RemoveLooseGameplayTags(FGameplayTag TagsToRemove);

	//Apply GE to Target Data
	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
	void ApplyGEToTargetData(const FGameplayEffectSpecHandle& GESpec, const FGameplayAbilityTargetDataHandle& TargetData);

	//Modify Health Attributes
	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
	void SetHealthValues(float NewHealth, float NewMaxHealth);

	//Modify Mana Attributes
	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
	void SetManaValues(float NewMana, float NewMaxMana);

	//Modify Stamina Attributes
	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
	void SetStaminaValues(float NewStamina, float NewMaxStamina);

};
