// By OwenAtkinson

#include "ArrowBasic.h"
#include "CompetitionTarget.h"

// Sets default values
ACompetitionTarget::ACompetitionTarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TargetFace = CreateDefaultSubobject<UStaticMeshComponent>("Target Face");
	/*Score Detection Initialisation - Idea is to have multiple overlapping collision primitives to determine score, not very efficient will improve on this if I think of a better way later on*/
	ScoreDetection10 = CreateDefaultSubobject<USphereComponent>("10");
	ScoreDetection9 = CreateDefaultSubobject<USphereComponent>("9");
	ScoreDetection8 = CreateDefaultSubobject<USphereComponent>("8");
	ScoreDetection7 = CreateDefaultSubobject<USphereComponent>("7");
	ScoreDetection6 = CreateDefaultSubobject<USphereComponent>("6");
	ScoreDetection5 = CreateDefaultSubobject<USphereComponent>("5");
	ScoreDetection4 = CreateDefaultSubobject<USphereComponent>("4");
	ScoreDetection3 = CreateDefaultSubobject<USphereComponent>("3");
	ScoreDetection2 = CreateDefaultSubobject<USphereComponent>("2");
	ScoreDetection1 = CreateDefaultSubobject<USphereComponent>("1");
	ScoreDetectionMiss = CreateDefaultSubobject<UBoxComponent>("Miss");
}

// Called when the game starts or when spawned
void ACompetitionTarget::BeginPlay()
{
	Super::BeginPlay();
	OnActorHit.AddDynamic(this, &ACompetitionTarget::OnTargetHit);
}

// Called every frame
void ACompetitionTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACompetitionTarget::OnTargetHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor->IsA<AArrowBasic>())
	{
		//If the other actor is an arrow.Calculate
		FVector ArrowLocation = OtherActor->GetActorLocation();
		
	}
}

