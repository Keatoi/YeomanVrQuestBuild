// By OwenAtkinson

#pragma once
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArrowBasic.generated.h"

UCLASS()
class YEOMANVRQUESTBUILD_API AArrowBasic : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArrowBasic();

protected:
	//// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

public:	
	//// Called every frame
	//virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USceneComponent* Root;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USphereComponent* ArrowSphere;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UBoxComponent* ArrowBowTrigger;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		float Delay = 10.0f;//arrow kills itself after being released, perhaps due to not wanting to allow the player to pick them up, perhaps due to loneliness, perhaps due to performance reasons who knows.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool bEnableGrab; // a toggle to allow times when we want the player to grab the arrow or not
	float SphereRad = 4.0f;
	FTimerHandle ArrowTH;
	UFUNCTION()
		void OnDestroy();
	void OnHit();//called when collision occurs
	void ReleaseArrow_Implementation(float ForceToApply);
};
