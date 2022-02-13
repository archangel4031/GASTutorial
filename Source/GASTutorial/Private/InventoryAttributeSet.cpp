// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryAttributeSet.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"

UInventoryAttributeSet::UInventoryAttributeSet()
{

}


void UInventoryAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetAppleAttribute())
	{
		SetApple(FMath::Clamp(GetApple(), 0.0f, 99.0f));
	}
	if (Data.EvaluatedData.Attribute == GetOrangeAttribute())
	{
		SetOrange(FMath::Clamp(GetOrange(), 0.0f, 99.0f));
	}
	if (Data.EvaluatedData.Attribute == GetPineappleAttribute())
	{
		SetPineapple(FMath::Clamp(GetPineapple(), 0.0f, 99.0f));
	}
	if (Data.EvaluatedData.Attribute == GetAppleShakeAttribute())
	{
		SetAppleShake(FMath::Clamp(GetAppleShake(), 0.0f, 99.0f));
	}
	if (Data.EvaluatedData.Attribute == GetFruitCocktailAttribute())
	{
		SetFruitCocktail(FMath::Clamp(GetFruitCocktail(), 0.0f, 99.0f));
	}
}