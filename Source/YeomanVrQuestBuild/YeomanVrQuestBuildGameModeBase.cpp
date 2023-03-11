// Copyright Epic Games, Inc. All Rights Reserved.


#include "YeomanVrQuestBuildGameModeBase.h"

void AYeomanVrQuestBuildGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	//Start a Timer to only start counting scores, 5 seconds after the game mode is loaded allowing players time to orient themselves and grab a bow
	if (bCompetitiveMode)
	{
		GetWorldTimerManager().SetTimer(ScoreTimer, this, &AYeomanVrQuestBuildGameModeBase::StartScoreTimer, 5.0f, false);
	}
}

float AYeomanVrQuestBuildGameModeBase::WindSpeedtoUU()
{
	float UUWindSpeed = (WindSpeed * 0.447) / 100;//converts mph into Metres per Second and then into UU
	return UUWindSpeed;
}

void AYeomanVrQuestBuildGameModeBase::AddScore()
{
	
	switch (scoreVariable)
	{
	case(EScore::Hit_X):
		scoreTotal += 10;
		break;
	case(EScore::Hit_10):
		scoreTotal += 10;
		break;
	case(EScore::Hit_9):
		scoreTotal += 9;
		break;
	case(EScore::Hit_8):
		scoreTotal += 8;
		break;
	case(EScore::Hit_7):
		scoreTotal += 7;
		break;
	case(EScore::Hit_6):
		scoreTotal += 6;
		break;
	case(EScore::Hit_5):
		scoreTotal += 5;
		break;
	case(EScore::Hit_4):
		scoreTotal += 4;
		break;
	case(EScore::Hit_3):
		scoreTotal += 3;
		break;
	case(EScore::Hit_2):
		scoreTotal += 2;
		break;
	case(EScore::Hit_1):
		scoreTotal += 1;
		break;
	case(EScore::Hit_Miss):
		scoreTotal += 0;
		break;
	}
	//Increase arrow count by one and then calculate an average to display on the Wrist UI

	ArrowCount++;
	ArrowAvg = scoreTotal / ArrowCount;
	UpdateEnds();
}

void AYeomanVrQuestBuildGameModeBase::UpdateEnds()
{
	if (ArrowCount % 4 == 0)
	{
		EndCount++;// if Arrow Count is divisible by four update the end counter by 1. This simulates a new end starting every 4th arrow.


		if (bCompetitiveMode == true)// if using the competitive game mode then the game will end after a certain amount of arrows shot
		{
			EndScore += scoreTotal;
			scoreTotal = 0;

			if (ArrowCount >= MaxArrows || EndCount >= MaxEndCount)
			{
				bGameOver = true;
			}
		}
	}
	
}

void AYeomanVrQuestBuildGameModeBase::Reset()
{
	scoreTotal = 0;
	ArrowAvg = 0;
	ArrowCount = 0;
}

void AYeomanVrQuestBuildGameModeBase::WindRotation()
{
	if (bWindEnabled)
	{
		int RandInt = FMath::RandRange(0, 3);
		RandWindDirection = StaticCast<EWind>(RandInt);
		
	}
	else 
	{
		return;
	}
	
}

void AYeomanVrQuestBuildGameModeBase::StartScoreTimer()
{
	GetWorldTimerManager().ClearTimer(ScoreTimer);//Clear the timer so it can be used with the Timeout Function
	GetWorldTimerManager().SetTimer(ScoreTimer,this, &AYeomanVrQuestBuildGameModeBase::Timeout, 120.0f, false, 5.0f);
}

void AYeomanVrQuestBuildGameModeBase::Timeout()
{
	//Still need to figure out how best to do this. For now it will just Add an arrow and add 0 to the score. Effectively costing the player a shot.
	ArrowCount++;
	scoreTotal += 0;
}
