// By OwenAtkinson

#pragma once
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CompetitionTarget.generated.h"

UCLASS()
class YEOMANVRQUESTBUILD_API ACompetitionTarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACompetitionTarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* TargetFace;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Vectors")
		FVector TargetCenter = { 0.0,0.0,0.0 };
	void OnTargetHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse,
		const FHitResult& Hit);
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USphereComponent* ScoreDetection10;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USphereComponent* ScoreDetection9;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USphereComponent* ScoreDetection8;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USphereComponent* ScoreDetection7;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USphereComponent* ScoreDetection6;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USphereComponent* ScoreDetection5;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USphereComponent* ScoreDetection4;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USphereComponent* ScoreDetection3;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USphereComponent* ScoreDetection2;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USphereComponent* ScoreDetection1;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UBoxComponent* ScoreDetectionMiss;
};
