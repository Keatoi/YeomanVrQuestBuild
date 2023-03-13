// By OwenAtkinson


#include "SimpleDestructibleTarget.h"

// Sets default values
ASimpleDestructibleTarget::ASimpleDestructibleTarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>("TargetMesh");
	WoundMaterial = CreateDefaultSubobject<UMaterial>(TEXT("IdleMaterial"));
	DeathMaterial = CreateDefaultSubobject<UMaterial>(TEXT("HitMaterial"));
	
	this->Tags.Add(FName("Target"));
	this->Tags.Add(FName("Impulse"));
}

// Called when the game starts or when spawned
void ASimpleDestructibleTarget::BeginPlay()
{
	Super::BeginPlay();
	OnActorHit.AddDynamic(this, &ASimpleDestructibleTarget::OnTargetHit);
	if (bGhost)
	{
		FTimerHandle TargetTimer;
		GetWorldTimerManager().SetTimer(TargetTimer, this, &ASimpleDestructibleTarget::Hide, GhostDelay, true, 1.0f);
	}
	
}

// Called every frame
void ASimpleDestructibleTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASimpleDestructibleTarget::OnTargetHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	if (bMultiHit)
	{
		HitsRemaining--;
		TargetMesh->SetMaterial(0,WoundMaterial);
		if (HitsRemaining <= 0)
		{
			TargetMesh->SetMaterial(0, DeathMaterial);
			FTimerHandle TargetTimer;
			GetWorldTimerManager().SetTimer(TargetTimer, this, &ASimpleDestructibleTarget::Kill, TimerDelay, false, 0.0f);
			
		}
	}
	else
	{
		FTimerHandle TargetTimer;
		GetWorldTimerManager().SetTimer(TargetTimer, this, &ASimpleDestructibleTarget::Kill, TimerDelay, false, 0.0f);
	}
}

void ASimpleDestructibleTarget::Kill()
{
	GetWorldTimerManager().ClearAllTimersForObject(this);
	Destroy();
}

void ASimpleDestructibleTarget::Hide()
{
	if (TargetMesh->IsVisible())
	{
		TargetMesh->SetVisibility(false);
		
	}
	else
	{
		TargetMesh->SetVisibility(true);
	}
}

