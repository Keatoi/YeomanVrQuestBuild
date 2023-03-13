// By OwenAtkinson

#pragma once

#include "CoreMinimal.h"
#include "StructsFile.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct YEOMANVRQUESTBUILD_API FSaveStruct
{
public:
	GENERATED_BODY();
	UPROPERTY(EditAnywhere)
	int Score;
	UPROPERTY(EditAnywhere)
	FName PlayerName;

	FSaveStruct();
	~FSaveStruct();
};
