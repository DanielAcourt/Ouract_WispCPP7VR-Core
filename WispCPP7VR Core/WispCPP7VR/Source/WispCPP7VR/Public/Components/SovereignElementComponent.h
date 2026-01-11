// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/SovereignBaseComponent.h"
#include "SovereignElementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WISPCPP7VR_API USovereignElementComponent : public USovereignBaseComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USovereignElementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//virtual TMap<FString, FString> GetSaveData() override;
	//virtual void RestoreSaveData(const TMap<FString, FString>& Data) override;

	void ProcessQiFlow(float DeltaTime, int32 WisdomStat);
		
};
