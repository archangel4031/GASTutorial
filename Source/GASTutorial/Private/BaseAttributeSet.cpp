// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAttributeSet.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"

UBaseAttributeSet::UBaseAttributeSet()
	:Health(200.0f),
	MaxHealth(200.0f),
	Mana(100.0f),
	MaxMana(100.f),
	Stamina(150.0f),
	MaxStamina(150.0f)
{

}

void UBaseAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	{
		if (Data.EvaluatedData.Attribute == GetHealthAttribute())
		{
			SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
		}
		if (Data.EvaluatedData.Attribute == GetManaAttribute())
		{
			SetMana(FMath::Clamp(GetMana(), 0.f, GetMaxMana()));
		}
		if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
		{
			SetStamina(FMath::Clamp(GetStamina(), 0.f, GetMaxStamina()));
		}
	}
}
