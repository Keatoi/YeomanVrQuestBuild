// By OwenAtkinson

#pragma once
#include "ArrowBasic.h"
#include "Components/TextRenderComponent.h"
#include "Kismet/GameplayStatics.h"
#include "YeomanVrQuestBuildGameModeBase.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SevenSpotTarget.generated.h"


UCLASS()
class YEOMANVRQUESTBUILD_API ASevenSpotTarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASevenSpotTarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* BullMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* InnerGoldMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* OuterGoldMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* InnerRedMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* OuterRedMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* InnerBlueMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* OuterBlueMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* InnerBlackMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* OuterBlackMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* InnerWhiteMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* OuterWhiteMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		 FName MapToLoad;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTextRenderComponent* TXTMapName;
	UPROPERTY()
		AYeomanVrQuestBuildGameModeBase* GameModeRef;
	
	UFUNCTION()
		void OnTargetHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse,
			const FHitResult& Hit);
	UFUNCTION()
		void OpenLevel(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse,
			const FHitResult& Hit);
};

