// By OwenAtkinson

#pragma once
#include "Components/TimelineComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTimelineComponent.generated.h"

UCLASS()
class YEOMANVRQUESTBUILD_API AMyTimelineComponent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTimelineComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTimelineComponent* ArrowTimeLine;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
