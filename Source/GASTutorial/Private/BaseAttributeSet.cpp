// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAttributeSet.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "BaseCharacter.h"

UBaseAttributeSet::UBaseAttributeSet()
{

}

void UBaseAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	
	//This is the CPP implementation of how to add and remove Gameplay Tags on Full Health Event. Just uncomment below code lines
	//Just make sure the Tag is present in the Editor in Project Settings
	//ABaseCharacter* OwnerCharacter = Cast<ABaseCharacter>(GetOwningActor());
	//FGameplayTag FullHealthTag = FGameplayTag::RequestGameplayTag(FName("char.ability.healthRegen.fullHealth"));
	
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
		
		//This is the CPP implementation of how to add and remove Gameplay Tags on Full Health Event. Just uncomment below code lines
		//if (GetHealth() >= GetMaxHealth())
		//{
		//	OwnerCharacter->AddLooseGameplayTag(FullHealthTag);
		//}
		//else
		//{
		//	OwnerCharacter->RemoveLooseGameplayTags(FullHealthTag);
		//}
	}
	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(), 0.0f, GetMaxMana()));
	}
	if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	{
		SetStamina(FMath::Clamp(GetStamina(), 0.0f, GetMaxStamina()));
	}
}
