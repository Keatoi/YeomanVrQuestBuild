// By OwenAtkinson

#include "GameFramework/ProjectileMovementComponent.h"
#include "ArrowBasic.h"

// Sets default values
AArrowBasic::AArrowBasic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	RootComponent = Root;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
	
	ArrowSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Arrow Sphere"));
	ArrowSphere->SetupAttachment(Root);
	ArrowSphere->SetSphereRadius(SphereRad);
	if (!ProjMovement)
	{
		ProjMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComponent"));
		ProjMovement->SetUpdatedComponent(Mesh);
		ProjMovement->MaxSpeed = MaxSpeed;
		ProjMovement->InitialSpeed = 40.0f;
		ProjMovement->bRotationFollowsVelocity = true;
		ProjMovement->bAutoActivate = false;
		
		bEnableMovement = false;
	}

}
void AArrowBasic::OnDestroy()
{
}
void AArrowBasic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ArrowMovement(Mesh->GetForwardVector());
}


void AArrowBasic::ReleaseArrow_Implementation(float ForceToApply)
{
	//Detach Actor from any thing it is attached to, then set it's location.
	//DetachFromActor(FDetachmentTransformRules(EDetachmentRule::KeepRelative, false));
	UE_LOG(LogTemp, Warning, TEXT("Called"));
	float Deviation = FMath::RandRange(0.0, 2.0);
	ProjMovement->Activate();
}



void AArrowBasic::ArrowMovement(const FVector& ProjDirection)
{
	// A line trace but in an arc, used to determine where the arrow goes
	ProjMovement->Velocity = ProjDirection * ProjMovement->InitialSpeed;
}

void AArrowBasic::OnHit()
{
	//stop physics simulation, not needed anymore.
}



