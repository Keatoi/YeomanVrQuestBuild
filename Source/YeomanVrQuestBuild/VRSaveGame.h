// By OwenAtkinson

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "VRSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class YEOMANVRQUESTBUILD_API UVRSaveGame : public USaveGame
{
	GENERATED_BODY()
public:
		UPROPERTY()
		int ScorePB;//Highest score player has attained to date
		
		
};
