// By OwenAtkinson


#pragma once
#include "Components/SphereComponent.h"
#include "ArrowBasic.h"
#include "CableComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BowBase.generated.h"

UCLASS()
class YEOMANVRQUESTBUILD_API ABowBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABowBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USceneComponent* BowRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* RiserMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* UpperLimbMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* LowerLimbMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "String");
	USphereComponent* ArrowDetector;
	

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "String");
	class UCableComponent* UpperString;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "String");
	class UCableComponent* LowerString;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "String");
	USceneComponent* DrawLocation;// This will be in the middle of the two cables and it is what we will pull on

	///ARROW DECLARATIONS//
	
	AArrowBasic* SpawnedArrow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrow Settings")
		TSubclassOf<AArrowBasic> ArrowClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,Category = "Arrow Settings")
		float ArrowStartPos;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrow Settings")
		float ArrowEndPos;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrow Settings")
		float LastPos;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrow Settings")
		float MinRelease = 20.0f;//how small the smallest draw we will allow is. Only using the x axis so only one value is required.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrow Settings")
		float Force = 15000.0f;//Bows have an incredibly large force output comparable to a .22cal rifle but bigger in size so not as fast. Dodging arrows is doable, can confirm from experience.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrow Settings")
	bool bUpdatePos;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrow Settings")
	bool bSpawnable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrow Settings")
	FVector InitialStringLoc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrow Settings")
		bool bRightHandedRelease;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrow Settings")
		FRotator ArrowOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrow Settings")
		FVector OffsetReadjust;//Some Bows may need a slight location readjustment after the offset to prevent clipping
	UFUNCTION(BlueprintCallable)
	void ReleaseArrow(float SliderPosition);
	UFUNCTION(BlueprintCallable)
		void SpawnArrow();
	UFUNCTION(BlueprintCallable)
		void ArrowTrigger(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


};
