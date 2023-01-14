// By OwenAtkinson


#include "AsiaticBowSkeletal.h"

// Sets default values
AAsiaticBowSkeletal::AAsiaticBowSkeletal()
{
	//Despite the name this class could be used for every traditional bow style.Unlike other bow type which uses spines this uses an animated skeletal mesh
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BowMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Trad Bow Mesh"));
	ArrowSlot = CreateDefaultSubobject<UBoxComponent>(TEXT("Arrow Slot"));
	ArrowSlot->SetupAttachment(BowMesh);
	BowQuiver = CreateDefaultSubobject<UBoxComponent>(TEXT("Bow Quiver"));
	BowQuiver->SetupAttachment(BowMesh);
}

// Called when the game starts or when spawned
void AAsiaticBowSkeletal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAsiaticBowSkeletal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

