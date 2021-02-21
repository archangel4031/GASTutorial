// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "BaseAttributeSet.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComp = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComp");
	BaseAttributeSetComp = CreateDefaultSubobject<UBaseAttributeSet>("BaseAttributeSetComp");

	AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSetComp->GetHealthAttribute()).AddUObject(this, &ABaseCharacter::OnHealthChangedNative);
	AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSetComp->GetManaAttribute()).AddUObject(this, &ABaseCharacter::OnManaChangedNative);
	AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSetComp->GetStaminaAttribute()).AddUObject(this, &ABaseCharacter::OnStaminaChangedNative);
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::InitializeAbility(TSubclassOf<UGameplayAbility> AbilityToGet, int32 AbilityLevel)
{
	if (AbilitySystemComp)
	{
		if (HasAuthority() && AbilityToGet)
		{
			AbilitySystemComp->GiveAbility(FGameplayAbilitySpec(AbilityToGet, AbilityLevel, 0));
		}
		AbilitySystemComp->InitAbilityActorInfo(this, this);
	}
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}

void ABaseCharacter::GetHealthValues(float& Health, float& MaxHealth)
{
	if (BaseAttributeSetComp)
	{
		Health = BaseAttributeSetComp->GetHealth();
		MaxHealth = BaseAttributeSetComp->GetMaxHealth();
	}
}

void ABaseCharacter::GetManaValues(float& Mana, float& MaxMana)
{
	if (BaseAttributeSetComp)
	{
		Mana = BaseAttributeSetComp->GetMana();
		MaxMana = BaseAttributeSetComp->GetMaxMana();
	}
}

void ABaseCharacter::GetStaminaValues(float& Stamina, float& MaxStamina)
{
	if (BaseAttributeSetComp)
	{
		Stamina = BaseAttributeSetComp->GetStamina();
		MaxStamina = BaseAttributeSetComp->GetMaxStamina();
	}
}

void ABaseCharacter::SetInitialAttributes(float Health, float MaxHealth, float Mana, float MaxMana, float Stamina, float MaxStamina)
{
	BaseAttributeSetComp->InitHealth(Health);
	BaseAttributeSetComp->InitMaxHealth(MaxHealth);
	BaseAttributeSetComp->InitMana(Mana);
	BaseAttributeSetComp->InitMaxMana(MaxMana);
	BaseAttributeSetComp->InitStamina(Stamina);
	BaseAttributeSetComp->InitMaxStamina(MaxStamina);
}

void ABaseCharacter::OnHealthChangedNative(const FOnAttributeChangeData& Data)
{
	OnHealthChanged(Data.OldValue, Data.NewValue);
}

void ABaseCharacter::OnManaChangedNative(const FOnAttributeChangeData& Data)
{
	OnManaChanged(Data.OldValue, Data.NewValue);
}

void ABaseCharacter::OnStaminaChangedNative(const FOnAttributeChangeData& Data)
{
	OnStaminaChanged(Data.OldValue, Data.NewValue);
}

