// By OwenAtkinson


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
}
void AArrowBasic::OnDestroy()
{
}
void AArrowBasic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AArrowBasic::OnHit()
{
	//stop physics simulation, not needed anymore.
}

void AArrowBasic::ReleaseArrow_Implementation(float ForceToApply)
{
	//Detach Actor from any thing it is attached to, then set it's location.
	DetachFromActor(FDetachmentTransformRules(EDetachmentRule::KeepRelative, false));
	ReleaseLocation = this->GetActorLocation();

}

