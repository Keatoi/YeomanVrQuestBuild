// By OwenAtkinson


#include "MyTimelineComponent.h"

// Sets default values
AMyTimelineComponent::AMyTimelineComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyTimelineComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTimelineComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

