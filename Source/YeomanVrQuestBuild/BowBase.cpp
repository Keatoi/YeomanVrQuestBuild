// By OwenAtkinson
#include "ArrowBasic.h"
#include "BowBase.h"

// Sets default values
ABowBase::ABowBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BowRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Bow Root"));
	SetRootComponent(BowRoot);
	//Bow parts
	//(We are using 3 meshes for the bow by default as most modern bows are infact in three parts. For single part bows we won't need them. For compound and Xbows we will probably make a seperate class
	RiserMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RiserMesh"));
	RiserMesh->SetupAttachment(BowRoot);
	RiserMesh->SetRelativeLocation(FVector(0,0,0));
	UpperLimbMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UpperLimbMesh"));
	UpperLimbMesh->SetupAttachment(RiserMesh);
	LowerLimbMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LowerLimbMesh"));
	LowerLimbMesh->SetupAttachment(RiserMesh);
	/*UpperNock = CreateDefaultSubobject<USceneComponent>(TEXT("UpperNock"));
	UpperNock->SetupAttachment(RiserMesh);
	LowerNock = CreateDefaultSubobject<USceneComponent>(TEXT("LowerNock"));
	LowerNock->SetupAttachment(RiserMesh);*/
	DrawLocation = CreateDefaultSubobject<USceneComponent>(TEXT("Draw Location"));
	DrawLocation->SetupAttachment(BowRoot);

	UpperString = CreateDefaultSubobject<UCableComponent>(TEXT("UpperString"));
	UpperString->SetupAttachment(BowRoot);
	
	LowerString = CreateDefaultSubobject<UCableComponent>(TEXT("LowerString"));
	LowerString->SetupAttachment(BowRoot);
	ArrowDetector = CreateDefaultSubobject<USphereComponent>(TEXT("Arrow Detection"));
	ArrowDetector->SetupAttachment(BowRoot);
}

// Called when the game starts or when spawned
void ABowBase::BeginPlay()
{
	Super::BeginPlay();
	//Setting the intial nock loaction so it knows when to stop on release
	InitialStringLoc = DrawLocation->GetRelativeLocation();
	ArrowDetector->OnComponentBeginOverlap.AddDynamic(this, &ABowBase::ArrowTrigger);
	
}

// Called every frame
void ABowBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void ABowBase::ReleaseArrow(float SliderPosition)
{
	float ForcetoApply = 0.0f;
	UE_LOG(LogTemp, Warning, TEXT("SliderPosition is: %f"), SliderPosition);
	if (SpawnedArrow != nullptr)
	{
		SpawnedArrow->DetachFromActor(FDetachmentTransformRules(EDetachmentRule::KeepWorld,false));
		SpawnedArrow->ReleaseArrow_Implementation(Force,Force,Force);
	}
	
}

void ABowBase::SpawnArrow()
{
	if (ArrowClass == nullptr) return;//if there isn't an arrow class assigned abort.
	if (bSpawnable)//Are we allowing arrows to spawn in this bow. Usefule for if we can get the manual arrows working
	{
		//if (DrawLocation->GetComponentLocation().X > MinRelease)
		//{
		//	//Is the absolute location of the string nock larger than the minimum release value? If yes SpawnArrow and Attach to component.
		//	SpawnedArrow->GetWorld()->SpawnActor<AArrowBasic>(ArrowClass, DrawLocation->GetComponentTransform());
		//	SpawnedArrow->AttachToComponent(DrawLocation, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));
		//}
		//Is the absolute location of the string nock larger than the minimum release value? If yes SpawnArrow and Attach to component.
		SpawnedArrow->GetWorld()->SpawnActor<AArrowBasic>(ArrowClass, DrawLocation->GetComponentTransform());
		SpawnedArrow->AttachToComponent(DrawLocation, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));
	}
	
}

void ABowBase::ArrowTrigger(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Function check if arow actor is in trigger box, if so attach to DrawLocation scene component
	if (OtherActor->IsA(AArrowBasic::StaticClass()))
	{
		//stop simulating physics and attach to actor

		
		OtherActor->AttachToComponent(DrawLocation,FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false));
		if (!bRightHandedRelease)
		{
			OtherActor->SetActorRelativeRotation(ArrowOffset * -1);
			
		}
		else
		{
			OtherActor->SetActorRelativeRotation(ArrowOffset);
		}
		
	}
}





