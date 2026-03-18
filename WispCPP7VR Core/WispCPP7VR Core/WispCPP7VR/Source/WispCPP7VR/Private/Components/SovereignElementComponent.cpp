// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/SovereignElementComponent.h"

// Sets default values for this component's properties
USovereignElementComponent::USovereignElementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void USovereignElementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USovereignElementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}



TMap<FString, FString> USovereignElementComponent::GetSaveData()
{
    // 1. Get base metadata (Symmetry/Trust)
    TMap<FString, FString> Data = Super::GetSaveData();

    // 2. Pack the Affinities
    Data.Add(TEXT("Elem.Fire"), FString::SanitizeFloat(FireAffinity));
    Data.Add(TEXT("Elem.Earth"), FString::SanitizeFloat(EarthAffinity));
    Data.Add(TEXT("Elem.Wind"), FString::SanitizeFloat(WindAffinity));
    Data.Add(TEXT("Elem.Water"), FString::SanitizeFloat(WaterAffinity));
    Data.Add(TEXT("Elem.SlowRes"), FString::SanitizeFloat(SlowResistance));

    return Data;
}

void USovereignElementComponent::RestoreSaveData(const TMap<FString, FString>& Data)
{
    Super::RestoreSaveData(Data);

    // Defensive lookup to prevent crashes on old 2017 save files
    if (const FString* Val = Data.Find(TEXT("Elem.Fire")))    FireAffinity = FCString::Atof(**Val);
    if (const FString* Val = Data.Find(TEXT("Elem.Earth")))   EarthAffinity = FCString::Atof(**Val);
    if (const FString* Val = Data.Find(TEXT("Elem.Wind")))    WindAffinity = FCString::Atof(**Val);
    if (const FString* Val = Data.Find(TEXT("Elem.Water")))   WaterAffinity = FCString::Atof(**Val);
    if (const FString* Val = Data.Find(TEXT("Elem.SlowRes"))) SlowResistance = FCString::Atof(**Val);
}