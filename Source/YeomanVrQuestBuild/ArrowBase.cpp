// By OwenAtkinson


#include "ArrowBase.h"

// Sets default values
AArrowBase::AArrowBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSceneComponent"));
	}
	if (!CollisionComp)
	{
		// Use a sphere as a simple collision representation.
		CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
		// Set the sphere's collision radius.
		CollisionComp->InitSphereRadius(15.0f);
		// Set the root component to be the collision component.
		RootComponent = CollisionComp;
	}
	if (!ProjComp)
	{
		ProjComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
		ProjComp->SetUpdatedComponent(CollisionComp);
		/*ProjectileMovementComponent->InitialSpeed = 3000.0f;
		ProjectileMovementComponent->MaxSpeed = 3000.0f;
		ProjectileMovementComponent->bRotationFollowsVelocity = true;*/
		ProjComp->bShouldBounce = true;
		ProjComp->Bounciness = 0.3f;
		ProjComp->ProjectileGravityScale = 0.0f;
	}
}

// Called when the game starts or when spawned
void AArrowBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AArrowBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

