// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "YeomanVrQuestBuildGameModeBase.generated.h"

UENUM()
enum EScore
{
	Hit_X,//For spiders i.e the very center of the bull. counts as a ten but is displayed as an X on official score sheets
	Hit_10,
	Hit_9,
	Hit_8,
	Hit_7,
	Hit_6,
	Hit_5,
	Hit_4,
	Hit_3,
	Hit_2,
	Hit_1,
	Hit_Miss,
};

	
UCLASS()
class YEOMANVRQUESTBUILD_API AYeomanVrQuestBuildGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		TEnumAsByte<EScore> scoreVariable;
	UPROPERTY(BlueprintReadWrite)
		int EndCount;
	UPROPERTY(BlueprintReadWrite)
		int ArrowCount;
	UPROPERTY(BlueprintReadWrite)
		int scoreTotal;
	UPROPERTY(BlueprintReadWrite)
		int RoundTotal;
	UPROPERTY(BlueprintReadWrite)
		int RunningTotal;
	UPROPERTY(BlueprintReadWrite)
		int ArrowAvg;
	UPROPERTY(BlueprintReadWrite)
		int EndScore;
	UFUNCTION(BlueprintCallable)
		void AddScore();
	UFUNCTION(BlueprintCallable)
		void UpdateEnds();
	UFUNCTION(BlueprintCallable)
		void Reset();//Resets score arrow count etc. to zero
};
