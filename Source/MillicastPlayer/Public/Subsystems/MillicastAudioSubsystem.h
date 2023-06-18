// Copyright Millicast 2023. All Rights Reserved.

#pragma once

#include "Subsystems/GameInstanceSubsystem.h"
#include "MillicastAudioSubsystem.generated.h"

class UAudioComponent;
class UMillicastAudioInstance;

/*
 * Manages all registered audio instances. This is the glue between UAudioComponent and streamed audio from Millicast
 */

UCLASS()
class MILLICASTPLAYER_API UMillicastAudioSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "MillicastPlayer")
    void Register(UAudioComponent* Component);

    UFUNCTION(BlueprintCallable, Category = "MillicastPlayer")
    void Unregister(UAudioComponent* Component);

    UMillicastAudioInstance* GetInstance(UAudioComponent* Component);

    UFUNCTION(BlueprintCallable, Category = "MillicastPlayer")
    void ForceFadeInFadeOut();
    
private:
    UPROPERTY()
    TArray<UMillicastAudioInstance*> AudioInstances;
};
