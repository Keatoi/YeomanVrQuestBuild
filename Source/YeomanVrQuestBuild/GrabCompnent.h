// By OwenAtkinson

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GrabCompnent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class YEOMANVRQUESTBUILD_API UGrabCompnent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabCompnent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
