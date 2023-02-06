// By OwenAtkinson


#include "SevenSpotTarget.h"
//Although not technically used in record status competitions it is used in less common formats so is a nice addition if I can get the main one to work, and If I can I'll just add more rings 
// 
// Sets default values
ASevenSpotTarget::ASevenSpotTarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BullMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bull"));
	RootComponent = BullMesh;
	InnerGoldMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Inner Gold"));
	InnerGoldMesh->SetupAttachment(BullMesh);
	OuterGoldMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Outer Gold"));
	OuterGoldMesh->SetupAttachment(BullMesh);
	InnerRedMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Inner Red"));
	InnerRedMesh->SetupAttachment(BullMesh);
	OuterRedMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Outer Red"));
	OuterRedMesh->SetupAttachment(BullMesh);
	InnerBlueMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Inner Blue"));
	InnerBlueMesh->SetupAttachment(BullMesh);
	OuterBlueMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Outer Blue"));
	OuterBlueMesh->SetupAttachment(BullMesh);


}

// Called when the game starts or when spawned
void ASevenSpotTarget::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASevenSpotTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

