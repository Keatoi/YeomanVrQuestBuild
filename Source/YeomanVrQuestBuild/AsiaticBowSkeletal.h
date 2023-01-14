// By OwenAtkinson

#pragma once
#include "Components/BoxComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AsiaticBowSkeletal.generated.h"

UCLASS()
class YEOMANVRQUESTBUILD_API AAsiaticBowSkeletal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAsiaticBowSkeletal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "Bow")
		USkeletalMeshComponent* BowMesh;//Traditional Bows are in one piece so only need one mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision")
		UBoxComponent* ArrowSlot; //will check if arrow is being put near bow
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Bow")
		UBoxComponent* BowQuiver;// will allow user to spawn arrows from bow
};
