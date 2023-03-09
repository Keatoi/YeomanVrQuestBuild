// By OwenAtkinson

#pragma once
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WindActor.generated.h"

UCLASS()
class YEOMANVRQUESTBUILD_API AWindActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWindActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
		UBoxComponent* WindBox;
	UPROPERTY(EditAnywhere)
		UArrowComponent* WindIndicator;
	UPROPERTY(EditAnywhere, Category = "Wind Settings")
		FVector WindVector;
	UPROPERTY(EditAnywhere, Category = "Wind Settings")
		float WindSpeed = 500;
	
	UPROPERTY(EditAnywhere, Category = "Wind Settings")
		class AArrowBasic* Arrow;
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/** called when something leaves the sphere component */
	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	

};
