// By OwenAtkinson

#pragma once
#include "VRSaveGame.h"
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "VRGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class YEOMANVRQUESTBUILD_API UVRGameInstance : public UGameInstance
{
	GENERATED_BODY()
		void Init() override;
	FString SaveName = "SaveName";
	UVRSaveGame* Data;
public:
	void SaveData(int Score);
	UVRSaveGame* LoadData();
};
