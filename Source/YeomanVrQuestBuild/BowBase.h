// By OwenAtkinson


#pragma once
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
	/*UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "String")
		USceneComponent* UpperNock;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "String")
		USceneComponent* LowerNock; */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "String");
	class UCableComponent* UpperString;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "String");
	class UCableComponent* LowerString;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "String");
	USceneComponent* DrawLocation;// This will be in the middle of the two cables and it is what we will pull on

	///ARROW DECLARATIONS//
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Arrow");
	USceneComponent* ArrowSpawnPoint;// Currently unsure of how to let the player physically place an arrow on the bow so for now it'll spawn when they draw back;
	UPROPERTY(EditDefaultsOnly, Category = "Arrow Settings")
		TSubclassOf<AArrowBasic> BasicArrowClass;
	AArrowBasic* SpawnedArrow;
	UPROPERTY(EditDefaultsOnly, Category = "Arrow Settings")
		float ArrowStartPos;
	UPROPERTY(EditDefaultsOnly, Category = "Arrow Settings")
		float ArrowEndPos;
	UPROPERTY(EditDefaultsOnly, Category = "Arrow Settings")
		float LastPos;
	UPROPERTY(EditDefaultsOnly, Category = "Arrow Settings")
		float MinRelease = 2.0f;//how small the smallest draw we will allow is.
	UPROPERTY(EditDefaultsOnly, Category = "Arrow Settings")
		float Force = 15000.0f;//Bows have an incredibly large force output comparable to a .22cal rifle but bigger in size so not as fast. Dodging arrows is doable, can confirm from experience.
	bool bUpdatePos;
	bool bSpawnable;
	FVector InitialStringLoc;
	void ReleaseArrow();

};
