// By OwenAtkinson

#pragma once
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



};
