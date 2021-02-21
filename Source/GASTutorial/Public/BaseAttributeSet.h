// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BaseAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class GASTUTORIAL_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	UBaseAttributeSet();

	//Attribute for Health
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")
	FGameplayAttributeData Health;
	GAMEPLAYATTRIBUTE_VALUE_GETTER(Health);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(Health);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(Health);
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UBaseAttributeSet, Health);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")
	FGameplayAttributeData MaxHealth;
	GAMEPLAYATTRIBUTE_VALUE_GETTER(MaxHealth);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(MaxHealth);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(MaxHealth);
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UBaseAttributeSet, MaxHealth);

	//Attribute for Mana
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")
	FGameplayAttributeData Mana;
	GAMEPLAYATTRIBUTE_VALUE_GETTER(Mana);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(Mana);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(Mana);
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UBaseAttributeSet, Mana);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")
	FGameplayAttributeData MaxMana;
	GAMEPLAYATTRIBUTE_VALUE_GETTER(MaxMana);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(MaxMana);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(MaxMana);
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UBaseAttributeSet, MaxMana);
	
	//Attribute for Stamina
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")
	FGameplayAttributeData Stamina;
	GAMEPLAYATTRIBUTE_VALUE_GETTER(Stamina);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(Stamina);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(Stamina);
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UBaseAttributeSet, Stamina);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")
	FGameplayAttributeData MaxStamina;
	GAMEPLAYATTRIBUTE_VALUE_GETTER(MaxStamina);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(MaxStamina);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(MaxStamina);
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UBaseAttributeSet, MaxStamina);

	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
	
};
