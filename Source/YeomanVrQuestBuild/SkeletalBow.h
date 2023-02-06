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
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USceneComponent* ArrowHelper;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrow Settings")
		int DrawWeight = 45;//Weight of the bow at max draw length in lbs; e.g when measured at 29" my bow has 45lbs of force applied to fingers
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrow Settings")
		float AdditionalWeight = 0; //Some Bows have attachments that can affect the string, such as silencers. Doubtfull if they'll make it into the project but nice to put in just in case.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrow Settings")
		float DrawLength;
	UFUNCTION(BlueprintCallable)
		void ReleaseArrow(USceneComponent* HandComp, float DrawVal);
};
