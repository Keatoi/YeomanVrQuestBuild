// By OwenAtkinson

#pragma once
#include "Curves/CurveFloat.h"
#include "Components/TimelineComponent.h"
#include "ArrowBasic.h"
#include "Components/SkeletalMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SkeletalBow.generated.h"

UCLASS()
class YEOMANVRQUESTBUILD_API ASkeletalBow : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASkeletalBow();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
		USkeletalMeshComponent* BowSkeleton;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USceneComponent* root;
	UFUNCTION(BlueprintCallable)
		UObject* SpawnArrow();
	UFUNCTION(BlueprintCallable)
		bool ShouldSpawnArrow(FVector MCWorldLoc);
	UFUNCTION(BlueprintCallable)
		void AttachArrow();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrow Settings")
		TSubclassOf<AArrowBasic> ArrowClass;
	UPROPERTY()
	AArrowBasic* SpawnedArrow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrow Settings")
		FVector ArrowOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrow Settings")
		FRotator ArrowRot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTimelineComponent* ArrowTimeLine;

	UFUNCTION(BlueprintCallable)
		void ReleaseArrow(USceneComponent* HandComp, float DrawVal);
};
