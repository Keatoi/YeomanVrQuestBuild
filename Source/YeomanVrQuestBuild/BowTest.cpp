// By OwenAtkinson


#include "BowTest.h"

// Sets default values
ABowTest::ABowTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	/*Riser = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Riser"));*/
}

// Called when the game starts or when spawned
void ABowTest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABowTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

