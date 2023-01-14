// By OwenAtkinson

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "VRInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UVRInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class YEOMANVRQUESTBUILD_API IVRInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "VR Interface")
		void Grab(class UMotionControllerComponent* MotionController);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "VR Interface")
		void Drop(class UMotionControllerComponent* MotionController);
};
