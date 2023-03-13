// By OwenAtkinson

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SimpleDestructibleTarget.generated.h"

UCLASS()
class YEOMANVRQUESTBUILD_API ASimpleDestructibleTarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASimpleDestructibleTarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* TargetMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bGhost = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMaterial* WoundMaterial;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMaterial* DeathMaterial;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bMultiHit = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int HitsRemaining = 2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TimerDelay = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float GhostDelay = 3.0f;
	UFUNCTION()
		void OnTargetHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse,
			const FHitResult& Hit);
	UFUNCTION()
		void Kill();
	UFUNCTION()
		void Hide();
};
