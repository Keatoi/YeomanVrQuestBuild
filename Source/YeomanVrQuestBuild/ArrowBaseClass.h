// By OwenAtkinson

#pragma once
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArrowBaseClass.generated.h"

UCLASS()
class YEOMANVRQUESTBUILD_API AArrowBaseClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArrowBaseClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* ArrowMesh;
	UPROPERTY(VisibleAnywhere)
		USphereComponent* CollisionComp;// This will be used to detect collision
	UPROPERTY(VisibleAnywhere)
		UProjectileMovementComponent* ProjComp;

	//Variables
	float ArrowSphereRadius = 2.0f;
	FVector ArrowHeadLocation = { -37.0f,0.0f,0.0f };


};
