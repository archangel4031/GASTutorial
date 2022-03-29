// Fill out your copyright notice in the Description page of Project Settings.


#include "GEExecMelee.h"
#include "BaseAttributeSet.h"

struct DamageCapture
{
  DECLARE_ATTRIBUTE_CAPTUREDEF(Shield)
  DECLARE_ATTRIBUTE_CAPTUREDEF(Health)
    
  DamageCapture()
  {
    DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet, Shield, Target, true)
    DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet, Health, Target, true)
  }
}

static DamageCapture& GetDamageCapture()
{
  static DamageCapture DamageCaptureVar;
  return DamageCaptureVar;
}

UGEExecMelee::UGEExecMelee()
{
  RelevantAttributesToCapture.Add(GetDamageCapture().ShieldDef);
  RelevantAttributesToCapture.Add(GetDamageCapture().HealthDef);
  //Remember to add this tag to your project
  ValidTransientAggregatorIdentifiers.AddTag(FGameplayTag::RequestGameplayTag("char.calc.damage.melee"));
}

void UGEExecMelee::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecParams, FGameplayEffectCustomExecutionOutput& ExecOutputs) const
{
  //Calc Variables
  float OutHealth = 0.0f;
  float OutShield = 0.0f;
  
  //Capture Variables
  float ShieldMagnitude = 0.0f;
  float HealthMagnitude = 0.0f;
  float AttackDamage = 0.0f;
  
  ExecParams.AttemptCalculateCapturedAttributeMagnitude(GetDamageCapture().ShieldDef, FAggregatorEvaluateParameters(), ShieldMagnitude);
  ExecParams.AttemptCalculateCapturedAttributeMagnitude(GetDamageCapture().HealthDef, FAggregatorEvaluateParameters(), HealthMagnitude);
  ExecParams.AttemptCalculateTransientAggregatorMagnitude(FGameplayTag::RequestGameplayTag("char.calc.damage.melee"), FAggregatorEvaluateParameters(), AttackDamage);
  
  //Start the Calculation
  OutShield = ShieldMagnitude - AttackDamage;
  if (OutShield <0)
  {
    OutHealth = HealthMagnitude - fabs(OutShield);
    OutShield = 0;
    
    ExecOutputs.AddOutputModifier(FGameplayModifierEvaluatedData(GetDamageCapture().ShieldProperty, EGameplayModOp::Override, OutShield));
    ExecOutputs.AddOutputModifier(FGameplayModifierEvaluatedData(GetDamageCapture().HealthProperty, EGameplayModOp::Override, OutHealth));
  }
  else
  {
    ExecOutputs.AddOutputModifier(FGameplayModifierEvaluatedData(GetDamageCapture().ShieldProperty, EGameplayModOp::Override, OutShield));
  }
}
