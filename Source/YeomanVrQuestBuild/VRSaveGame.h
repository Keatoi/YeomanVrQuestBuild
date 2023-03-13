// By OwenAtkinson

#pragma once
#include "StructsFile.h"
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
	UPROPERTY(EditAnywhere)
		TArray<FSaveStruct> SaveArray;
	UPROPERTY(EditAnywhere)
		int PBScore;
		
		
};
