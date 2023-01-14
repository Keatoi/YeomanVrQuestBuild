// By OwenAtkinson

#pragma once
#include "Components/SplineComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VRSlider.generated.h"

UCLASS()
class YEOMANVRQUESTBUILD_API AVRSlider : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVRSlider();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* SliderMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USplineComponent* SliderSpline;
};
