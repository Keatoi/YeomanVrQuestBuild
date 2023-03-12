// By OwenAtkinson
#include "ArrowBasic.h"
#include "SkeletalBow.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"


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
	IdleMaterial = CreateDefaultSubobject<UMaterial>(TEXT("IdleMaterial"));
	MovementMaterial = CreateDefaultSubobject<UMaterial>(TEXT("MovementMaterial"));
	
	if (!ProjMovement)
	{
		ProjMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComponent"));
		ProjMovement->SetUpdatedComponent(Mesh);
		
		ProjMovement->bRotationFollowsVelocity = true;
		ProjMovement->bAutoActivate = true;
		ProjMovement->Velocity = Velo;
		
	}

}
void AArrowBasic::BeginPlay()
{
	Super::BeginPlay();
	OnActorHit.AddDynamic(this, &AArrowBasic::OnHit);
	Mesh->SetMaterial(0, IdleMaterial);
}

void AArrowBasic::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse,
	const FHitResult& Hit)
{
	
	//when it hits another actor, add some impulse force and attach to the hit component
	if (OtherActor->ActorHasTag("Target"))//if a target attach and dig into the actor, scoring is handled in the target actor
	{
		
		ProjMovement->Velocity = FVector::ZeroVector;//Stop the projectile.
		SelfActor->AttachToActor(OtherActor, FAttachmentTransformRules(EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, true));//Attach it to the hit actor
		SelfActor->AddActorLocalOffset(FVector(FMath::FRandRange(1.0f, 8.0f), 0.0, 0.0));//Sinks the arrow into the target by a random amount to simulate the target being used before.
		Mesh->SetMaterial(0, IdleMaterial);
		
	}
	else if (!OtherActor->ActorHasTag("Bow"))//If its not a target or a bow, collide and count as a miss
	{
		ProjMovement->Velocity = FVector::ZeroVector;//Stop the projectile.
		Mesh->SetMaterial(0, IdleMaterial);
		if (GameModeRef)
		{
			GameModeRef->scoreVariable = EScore::Hit_Miss;
		}
	}
	
}
void AArrowBasic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!ProjMovement->Velocity.IsZero())//If the velocity of the arrow is not zero, i.e it is moving, then we rotate the mesh
	{
		FRotator ArrowRotation((Rotation * DeltaTime));
		Mesh->AddLocalRotation(ArrowRotation);
		float DragVal = GetDrag();
		ApplyDrag(DeltaTime, DragVal);
		ProjMovement->Velocity = (WindToApply * DeltaTime) + ProjMovement->Velocity;
	}
	FVector FinalPos = GetActorLocation();
	Distance = (FinalPos - SpawnPos).Size();
	

	

	
}


void AArrowBasic::ReleaseArrow_Implementation(float DrawLength, int DrawWeight, float AdditionalWeight)
{
	
	UE_LOG(LogTemp, Warning, TEXT("Called Arrow Imp"));
	
	//ProjMovement->Activate();
	UE_LOG(LogTemp, Warning, TEXT("Draw Val is : %f"), DrawLength);
	//Calculating the velocity of the arrow. This uses the equation v = IBO + (L-30) * 10 - W/3 + min(0,-(A-5D/3).
	
	//IBO + (DrawLength - 30) * 10 - AdditionalWeight / 3 + std::min(0, -(AW - (5 * DrawWeight) / 3));
	SpawnPos = GetActorLocation();
	Velo = (this->GetActorForwardVector() * DrawLength);
	UE_LOG(LogTemp, Warning, TEXT("Velo is : %s"), *Velo.ToString());
	//adding a small amount of randomness to the y and Z axis of the velocity vector should simulate the arrow flexing in flight which causes slight deviation. This is why its rare for an arrow to hit another arrow, even with modern equipment
	Velo.Y = Velo.Y + FMath::FRandRange(MinimumDeviation, MaximumDeviation);
	Velo.Z = Velo.Z + FMath::FRandRange(MinimumDeviation, MaximumDeviation);
	ProjMovement->Velocity = Velo;
	ProjMovement->ProjectileGravityScale = GravScale;
	Mesh->SetMaterial(0, MovementMaterial);
	this->SetLifeSpan(Delay);//Destroy the actor after a delat to stop arrow buildup causing performance issues.
}





float AArrowBasic::GetDrag()
{
	if (DragCoefficientCurve)
	{
		float VeloLen = ProjMovement->Velocity.Length() * 0.01;
		float ArrowArea = PI * pow(0.00873, 2);//Calculation to get the cross surface area of an arrow, 0.00873 is 11/32" converted to metres
		float DragCoeffValue = DragCoefficientCurve->GetFloatValue(VeloLen);//Get the position at the float curve along the X axis using the length of the velocity vector.
		float Drag = (-0.5 * DragCoeffValue * AirDensity * ArrowArea * pow(VeloLen, 2)) / 0.028;
		return Drag;
	}
	else
	{
		return 0;
	}
}

void AArrowBasic::ApplyDrag(float DeltaTime, float Drag)
{
	float VeloChange = Drag * DeltaTime * -100.0;//Change in velocity caused by drag. -100 changes it from metres to centimetres
	float RemainingVelo = 1.0 - (VeloChange / ProjMovement->Velocity.Length());//what percentage of the original velocity is left after drag is applied
	FVector NewVelo = ProjMovement->Velocity * RemainingVelo;
	ProjMovement->Velocity = NewVelo;
}

void AArrowBasic::ApplyWind(FVector Wind)
{
	WindToApply = WindToApply + Wind;
}





