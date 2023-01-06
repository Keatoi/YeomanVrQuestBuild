// By OwenAtkinson

#pragma once
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArrowBase.generated.h"

UCLASS()
class YEOMANVRQUESTBUILD_API AArrowBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArrowBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UProperty(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* ArrowMesh;
	UProperty(VisibleAnywhere, BlueprintReadWrite)
		USphereComponent* CollisionComp;
	UProperty(VisibleAnywhere, BlueprintReadWrite)
		UProjectileMovementComponent* ProjComp;
};
