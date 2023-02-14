// Copyright Epic Games, Inc. All Rights Reserved.


#include "YeomanVrQuestBuildGameModeBase.h"

void AYeomanVrQuestBuildGameModeBase::AddScore()
{
	
	switch (scoreVariable)
	{
	case(Hit_X):
		scoreTotal += 10;
		break;
	case(Hit_10):
		scoreTotal += 10;
		break;
	case(Hit_9):
		scoreTotal += 9;
		break;
	case(Hit_8):
		scoreTotal += 8;
		break;
	case(Hit_7):
		scoreTotal += 7;
		break;
	case(Hit_6):
		scoreTotal += 6;
		break;
	case(Hit_5):
		scoreTotal += 5;
		break;
	case(Hit_4):
		scoreTotal += 4;
		break;
	case(Hit_3):
		scoreTotal += 3;
		break;
	case(Hit_2):
		scoreTotal += 2;
		break;
	case(Hit_1):
		scoreTotal += 1;
		break;
	case(Hit_Miss):
		
		break;
	}
	//Increase arrow count by one and then calculate an average to display on the Wrist UI
	ArrowCount++;
	ArrowAvg = scoreTotal / ArrowCount;
}

void AYeomanVrQuestBuildGameModeBase::UpdateEnds()
{

}

void AYeomanVrQuestBuildGameModeBase::Reset()
{
	scoreTotal = 0;
	ArrowAvg = 0;
	ArrowCount = 0;
}
