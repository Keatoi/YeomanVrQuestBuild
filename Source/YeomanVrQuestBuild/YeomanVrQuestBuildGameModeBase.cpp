// Copyright Epic Games, Inc. All Rights Reserved.


#include "YeomanVrQuestBuildGameModeBase.h"

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
		
		break;
	}
	//Increase arrow count by one and then calculate an average to display on the Wrist UI
	ArrowCount++;
	ArrowAvg = scoreTotal / ArrowCount;
}

void AYeomanVrQuestBuildGameModeBase::UpdateEnds()
{
	//not yet implemented
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
