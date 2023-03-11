// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "YeomanVrQuestBuildGameModeBase.generated.h"

UENUM(BlueprintType)
enum class EScore :uint8
{
	Hit_X = 0 UMETA(DisplayName = "X"),//For spiders i.e the very center of the bull. counts as a ten but is displayed as an X on official score sheets
	Hit_10 UMETA(DisplayName = "10"),
	Hit_9 UMETA(DisplayName = "9"),
	Hit_8 UMETA(DisplayName = "8"),
	Hit_7 UMETA(DisplayName = "7"),
	Hit_6 UMETA(DisplayName = "6"),
	Hit_5 UMETA(DisplayName = "5"),
	Hit_4 UMETA(DisplayName = "4"),
	Hit_3 UMETA(DisplayName = "3"),
	Hit_2 UMETA(DisplayName = "2"),
	Hit_1 UMETA(DisplayName = "1"),
	Hit_Miss UMETA(DisplayName = "M"),
};
UENUM(BlueprintType)
enum class EWind :uint8
{
	W_North = 0 UMETA(DisplayName = "North"),
	W_West UMETA(DisplayName = "West"),
	W_South UMETA(DisplayName = "East"),
	W_East UMETA(DisplayName = "South"),
};

	
UCLASS()
class YEOMANVRQUESTBUILD_API AYeomanVrQuestBuildGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
protected:
	FTimerHandle ScoreTimer;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	UPROPERTY(BlueprintReadWrite)
		EScore scoreVariable;
	UPROPERTY(BlueprintReadWrite)
		int EndCount = 0;
	UPROPERTY(BlueprintReadWrite)
		int ArrowCount = 0;
	UPROPERTY(BlueprintReadWrite)
		int scoreTotal = 0;
	UPROPERTY(BlueprintReadWrite)
		int RoundTotal = 0;
	UPROPERTY(BlueprintReadWrite)
		int RunningTotal = 0;
	UPROPERTY(BlueprintReadWrite)
		int ArrowAvg = 0;
	UPROPERTY(BlueprintReadWrite)
		int EndAvg = 0;
	UPROPERTY(BlueprintReadWrite)
		int EndScore = 0;
	UPROPERTY(BlueprintReadWrite, Category = "Enviroment")
		bool bWindEnabled = false;
	UPROPERTY(BlueprintReadWrite, Category = "Enviroment")
		EWind RandWindDirection;
	UPROPERTY(BlueprintReadWrite, Category = "Enviroment")
		float WindSpeed;
	UPROPERTY(BlueprintReadWrite, Category = "Competition Settings")
		float MaxArrows = 60;
	UPROPERTY(BlueprintReadWrite, Category = "Competition Settings")
		float MaxEndCount = 20;
	UPROPERTY(BlueprintReadWrite, Category = "Competition Settings")
		bool bGameOver = false;
	UPROPERTY(BlueprintReadWrite, Category = "Competition Settings")
		bool bCompetitiveMode = true;
	UFUNCTION(BlueprintCallable)
		float WindSpeedtoUU();
	UFUNCTION(BlueprintCallable)
		void AddScore();
	UFUNCTION(BlueprintCallable)
		void UpdateEnds();
	UFUNCTION(BlueprintCallable)
		void Reset();//Resets score arrow count etc. to zero
	UFUNCTION(BlueprintCallable)
		void WindRotation();//Changes wind direction after timer update
	UFUNCTION(BlueprintCallable)
		void StartScoreTimer();
	UFUNCTION(BlueprintCallable)
		void Timeout();
	
};
