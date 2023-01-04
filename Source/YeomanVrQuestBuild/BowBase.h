// By OwenAtkinson

#pragma once

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
		UStaticMeshComponent* RiserMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* UpperLimbMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* LowerLimbMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "String")
		USceneComponent* UpperNock;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "String")
		USceneComponent* LowerNock; 

};
