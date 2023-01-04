// By OwenAtkinson


#include "BowBase.h"

// Sets default values
ABowBase::ABowBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RiserMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RiserMesh"));
	UpperLimbMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UpperLimbMesh"));
	UpperLimbMesh->SetupAttachment(RiserMesh);
	LowerLimbMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LowerLimbMesh"));
	LowerLimbMesh->SetupAttachment(RiserMesh);
	UpperNock = CreateDefaultSubobject<USceneComponent>(TEXT("UpperNock"));
	UpperNock->SetupAttachment(RiserMesh);
	LowerNock = CreateDefaultSubobject<USceneComponent>(TEXT("LowerNock"));
	LowerNock->SetupAttachment(RiserMesh);
}

// Called when the game starts or when spawned
void ABowBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABowBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

