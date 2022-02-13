// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "InventoryAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class GASTUTORIAL_API UInventoryAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	UInventoryAttributeSet();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")
	FGameplayAttributeData Apple;
	ATTRIBUTE_ACCESSORS(UInventoryAttributeSet, Apple);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")
	FGameplayAttributeData Orange;
	ATTRIBUTE_ACCESSORS(UInventoryAttributeSet, Orange);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")
	FGameplayAttributeData Pineapple;
	ATTRIBUTE_ACCESSORS(UInventoryAttributeSet, Pineapple);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")
	FGameplayAttributeData AppleShake;
	ATTRIBUTE_ACCESSORS(UInventoryAttributeSet, AppleShake);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")
	FGameplayAttributeData FruitCocktail;
	ATTRIBUTE_ACCESSORS(UInventoryAttributeSet, FruitCocktail);

	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
	
};
