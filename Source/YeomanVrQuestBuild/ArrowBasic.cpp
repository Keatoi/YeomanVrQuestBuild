// By OwenAtkinson
#include "SkeletalBow.h"
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
	Mesh->SetNotifyRigidBodyCollision(true);
	ArrowSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Arrow Sphere"));
	ArrowSphere->SetupAttachment(Root);
	ArrowSphere->SetSphereRadius(SphereRad);
	ArrowSphere->SetRelativeLocation(FVector{ 68,0,0 });
	
	if (!ProjMovement)
	{
		ProjMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComponent"));
		ProjMovement->SetUpdatedComponent(Mesh);
		
		ProjMovement->bRotationFollowsVelocity = true;
		ProjMovement->bAutoActivate = true;
		ProjMovement->Velocity = Velo;
		bEnableMovement = false;
	}

}
void AArrowBasic::BeginPlay()
{
	Super::BeginPlay();
	OnActorHit.AddDynamic(this, &AArrowBasic::OnHit);
}

void AArrowBasic::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse,
	const FHitResult& Hit)
{
	//when it hits another actor, add some impulse force and attach to the hit component
	if (!OtherActor->IsA(ASkeletalBow::StaticClass()))//if not a bow do stuff.
	{
		
		ProjMovement->Velocity = FVector::ZeroVector;//Stop the projectile.
		SelfActor->AttachToActor(OtherActor, FAttachmentTransformRules(EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, true));//Attach it to the hit actor
		SelfActor->AddActorLocalOffset(FVector(FMath::FRandRange(1.0f, 8.0f), 0.0, 0.0));//Sinks the arrow into the target by a random amount to simulate the target being used before.
	}
	
}
void AArrowBasic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Used for testing
	//ArrowMovement(Mesh->GetForwardVector());
	
}


void AArrowBasic::ReleaseArrow_Implementation(float DrawLength, int DrawWeight, float AdditionalWeight)
{
	
	UE_LOG(LogTemp, Warning, TEXT("Called Arrow Imp"));
	
	//ProjMovement->Activate();
	UE_LOG(LogTemp, Warning, TEXT("Draw Val is : %f"), DrawLength);
	//Calculating the velocity of the arrow. This uses the equation v = IBO + (L-30) * 10 - W/3 + min(0,-(A-5D/3).
	
	//IBO + (DrawLength - 30) * 10 - AdditionalWeight / 3 + std::min(0, -(AW - (5 * DrawWeight) / 3));
	
	Velo = (this->GetActorForwardVector() * DrawLength);
	UE_LOG(LogTemp, Warning, TEXT("Velo is : %s"), *Velo.ToString());
	ProjMovement->Velocity = Velo/* * UGameplayStatics::GetWorldDeltaSeconds(this)*/;
	ProjMovement->ProjectileGravityScale = GravScale;
	this->SetLifeSpan(Delay);//Destroy the actor after a delat to stop arrow buildup causing performance issues.
}



void AArrowBasic::ArrowMovement(const FVector& ProjDirection)
{
	// A line trace but in an arc, used to determine where the arrow goes
	ProjMovement->Velocity = ProjDirection * ProjMovement->InitialSpeed;
}





