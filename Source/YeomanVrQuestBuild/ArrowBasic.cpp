// By OwenAtkinson
#include "Kismet/GameplayStatics.h"
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
	Mesh->SetRelativeLocation(FVector{ 32,0,0 });
	Mesh->SetRelativeRotation(FRotator{180,0,0});
	ArrowSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Arrow Sphere"));
	ArrowSphere->SetupAttachment(Root);
	ArrowSphere->SetSphereRadius(SphereRad);
	ArrowSphere->SetRelativeLocation(FVector{ 68,0,0 });
	ArrowSphere->OnComponentHit.AddDynamic(this, &AArrowBasic::OnHit);
	if (!ProjMovement)
	{
		ProjMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComponent"));
		ProjMovement->SetUpdatedComponent(Mesh);
		
		ProjMovement->bRotationFollowsVelocity = true;
		ProjMovement->bAutoActivate = true;
		ProjMovement->Velocity = { 0,0,0 };
		bEnableMovement = false;
	}

}
void AArrowBasic::OnDestroy()
{
}
void AArrowBasic::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//when it hits another actor, add some impulse force and attach to the hit component
}
void AArrowBasic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Used for testing
	//ArrowMovement(Mesh->GetForwardVector());
	
}


void AArrowBasic::ReleaseArrow_Implementation(float ForceToApply)
{
	//Detach Actor from any thing it is attached to, then set it's location.
	//DetachFromActor(FDetachmentTransformRules(EDetachmentRule::KeepRelative, false));
	UE_LOG(LogTemp, Warning, TEXT("Called Arrow Imp"));
	
	//ProjMovement->Activate();
	UE_LOG(LogTemp, Warning, TEXT("Draw Val is : %f"), ForceToApply);
	NewVelo = (this->GetActorForwardVector() * ForceToApply);
	ProjMovement->Velocity = NewVelo /** UGameplayStatics::GetWorldDeltaSeconds(this)*/;
}



void AArrowBasic::ArrowMovement(const FVector& ProjDirection)
{
	// A line trace but in an arc, used to determine where the arrow goes
	ProjMovement->Velocity = ProjDirection * ProjMovement->InitialSpeed;
}





