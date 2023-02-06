// By OwenAtkinson

#pragma once

#include "CoreMinimal.h"
#include "SkeletalBow.h"
#include "SkeletalCrossBow.generated.h"

/**
 * 
 */
UCLASS()
class YEOMANVRQUESTBUILD_API ASkeletalCrossBow : public ASkeletalBow
{
	GENERATED_BODY()
public:
	ASkeletalCrossBow();
	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* ScopeDetection;//Box Component that detects if a scope is in range.If it is attach to skeletal Meshes' scope position if available.
	UFUNCTION(BlueprintCallable)
		void Grab_Implementation();
	UFUNCTION(BlueprintCallable)
		void Drop_Implementation();
};
