// By OwenAtkinson

#include "BowBase.h"

// Sets default values
ABowBase::ABowBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BowRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Bow Root"));
	SetRootComponent(BowRoot);
	//Bow parts
	//(We are using 3 meshes for the bow by default as most modern bows are infact in three parts. For single part bows we won't need them. For compound and Xbows we will probably make a seperate class
	RiserMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RiserMesh"));
	RiserMesh->SetupAttachment(BowRoot);
	RiserMesh->SetRelativeLocation(FVector(0,0,0));
	UpperLimbMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UpperLimbMesh"));
	UpperLimbMesh->SetupAttachment(RiserMesh);
	LowerLimbMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LowerLimbMesh"));
	LowerLimbMesh->SetupAttachment(RiserMesh);
	/*UpperNock = CreateDefaultSubobject<USceneComponent>(TEXT("UpperNock"));
	UpperNock->SetupAttachment(RiserMesh);
	LowerNock = CreateDefaultSubobject<USceneComponent>(TEXT("LowerNock"));
	LowerNock->SetupAttachment(RiserMesh);*/
	DrawLocation = CreateDefaultSubobject<USceneComponent>(TEXT("Draw Location"));
	UpperString = CreateDefaultSubobject<UCableComponent>(TEXT("UpperString"));
	UpperString->SetupAttachment(RiserMesh);
	
	LowerString = CreateDefaultSubobject<UCableComponent>(TEXT("LowerString"));
	LowerString->SetupAttachment(RiserMesh);
}

// Called when the game starts or when spawned
void ABowBase::BeginPlay()
{
	Super::BeginPlay();
	//Setting the intial nock loaction so it knows when to stop on release
}

// Called every frame
void ABowBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

