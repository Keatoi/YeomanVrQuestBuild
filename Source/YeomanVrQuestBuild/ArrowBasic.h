// By OwenAtkinson

#pragma once

#include "Kismet/KismetSystemLibrary.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArrowBasic.generated.h"
class UProjectileMovementComponent;

UCLASS()
class YEOMANVRQUESTBUILD_API AArrowBasic : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArrowBasic();

protected:
	//// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	//// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UProjectileMovementComponent* ProjMovement;

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
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool bEnableMovement;
	float SphereRad = 4.0f;
	FTimerHandle ArrowTH;
	float MaxSpeed = 100.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector Velo = { 0.0, 0.0, 0.0 };
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float GravScale = 1.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Arrow Settings")
		int IBO = 150; //Bow arrow speed in ft/s according to manufacturer specification. We'll just use a generic value that can be changed between arrow types based on their closest irl equivalents
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Arrow Settings")
		float AW = 200.0f;//arrow weight in grains. A grain is based upon the ideal weight of a grain of cereal according to a man born in the bronze age. Downfall of basing a project on one of the oldest sports in history. For reference one grain == 6.4799e-5 kg.
	//A Military Longbow arrow has roughly betweeen 500 and 1500 grain weight for a 60 to 200lb bow,(International Longbow Archers Association,n.d)[shorturl.at/aijP3] Most modern archers max out at 40-50 lbs so we'll go with 420 as a guesstimate of a modern day avg arrow weight.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Arrow Settings")
		float p;// Momentum. 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Arrow Settings")
		FVector Impulse;//Impulse energy generated on contact
	UFUNCTION()
		void OnDestroy();
	UFUNCTION()
		void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse,
			const FHitResult& Hit);
	void ReleaseArrow_Implementation(float DrawLength,int DrawWeight, float AdditionalWeight);
	void ArrowMovement(const FVector& ProjDirection);
};
