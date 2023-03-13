// By OwenAtkinson
#include "Scope.h"
#include "Components/SceneCaptureComponent2D.h"


// Sets default values
AScope::AScope()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ScopeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Scope"));
	ScopeCylinder = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Scope Cylinder"));
	ScopeCylinder->SetupAttachment(ScopeMesh);
	SceneCapture = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("SceneCapture"));
	SceneCapture->SetupAttachment(ScopeMesh);
	SceneCapture->SetRelativeLocation(ScopeZoom);
}

// Called when the game starts or when spawned
void AScope::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AScope::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AScope::Grab_Implementation(UMotionControllerComponent* GrabbingHand)
{
	if (ScopeMesh->IsSimulatingPhysics())
	{
		ScopeMesh->SetSimulatePhysics(false);
	}
	AttachToComponent(GrabbingHand, FAttachmentTransformRules(EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, true));
}

void AScope::Drop_Implementation(UMotionControllerComponent* GrabbingHand)
{
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	if (!ScopeMesh->IsSimulatingPhysics())
	{
		ScopeMesh->SetSimulatePhysics(true);
	}
}

