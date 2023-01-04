// By OwenAtkinson

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BowTest.generated.h"

UCLASS()
class YEOMANVRQUESTBUILD_API ABowTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABowTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	/*UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
		UStaticMeshComponent* Riser;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
		UStaticMeshComponent* UpperLimb;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
		UStaticMeshComponent* LowerLimb;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "String")
		USceneComponent* UpperNock;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "String")
		USceneComponent* LowerNock;*/
};
