// By OwenAtkinson

#pragma once
#include "Kismet/KismetMathLibrary.h"
#include "MotionControllerComponent.h"
#include "CoreMinimal.h"
#include "SkeletalBow.h"
#include "SkeletalCompoundBow.generated.h"

/**
 * 
 */
UCLASS()
class YEOMANVRQUESTBUILD_API ASkeletalCompoundBow : public ASkeletalBow
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure,meta = (DisplayName = "Calculate DrawLength",CompactNodeTitle = "GetDrawLength", Keywords = "Draw Length"),Category = "Archery Maths")
		float GetDrawLength(UMotionControllerComponent* DrawHand);
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Calculate DrawValue", CompactNodeTitle = "GetDrawValue", Keywords = "Draw Value"), Category = "Archery Maths")
		float GetDrawValue(float DrawLen);
	UPROPERTY(BlueprintReadWrite, category = "Draw Values")
		float MinDrawValue = 50.0f;
	UPROPERTY(BlueprintReadWrite, category = "Draw Values")
		float MaxDrawValue = 100000.0f;

	
};
