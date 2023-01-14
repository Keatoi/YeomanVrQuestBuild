// By OwenAtkinson


#include "ArrowBaseClass.h"

// Sets default values
AArrowBaseClass::AArrowBaseClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Component initialisation
	ArrowMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Arrow Mesh"));
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Component"));
	
	CollisionComp->SetSphereRadius(ArrowSphereRadius);
	CollisionComp->SetRelativeLocation(ArrowHeadLocation);
	
	ProjComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
}

// Called when the game starts or when spawned
void AArrowBaseClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AArrowBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

