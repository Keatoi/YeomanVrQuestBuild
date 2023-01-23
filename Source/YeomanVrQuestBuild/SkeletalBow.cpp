// By OwenAtkinson

#include"Runtime/Engine/Classes/Engine/World.h."
#include "SkeletalBow.h"

// Sets default values
ASkeletalBow::ASkeletalBow()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	root->SetMobility(EComponentMobility::Movable);
	RootComponent = root;
	BowSkeleton = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeleton"));
	BowSkeleton->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void ASkeletalBow::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASkeletalBow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UObject* ASkeletalBow::SpawnArrow()
{
	if (ArrowClass)
	{
		FTransform SkeleTransform = BowSkeleton->GetComponentTransform();
		FActorSpawnParameters SpawnParams = FActorSpawnParameters();
		SpawnParams.Owner = this;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		SpawnedArrow = GetWorld()->SpawnActor<AArrowBasic>(ArrowClass, SkeleTransform);
		UE_LOG(LogTemp, Warning, TEXT("Arrow is Spawning"));
		return SpawnedArrow;
	}
	else return nullptr;
	
	
	
	
}

bool ASkeletalBow::ShouldSpawnArrow(FVector MCWorldLoc)
{
	//if the other motion controller is close enough to the skeleton string socket location return true
	if (BowSkeleton)
	{
		FVector SkeleLoc = BowSkeleton->GetSocketLocation(FName("StringIdle"));
		FVector SubVect = MCWorldLoc - SkeleLoc;
		float VectLen = SubVect.Size();
		if (VectLen < 20.0f)
		{
			return true;
		}
		else return false;
	}
	else return false;
	
}

void ASkeletalBow::AttachArrow()
{
	if (SpawnedArrow != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Arrow is Attaching to string"));
		SpawnedArrow->AttachToComponent(BowSkeleton, FAttachmentTransformRules(EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, true), FName("bowStringSocket"));
		SpawnedArrow->AddActorLocalOffset(ArrowOffset);
		SpawnedArrow->SetActorRelativeRotation(ArrowRot);
	}
	else UE_LOG(LogTemp, Warning, TEXT("Arrow is null"));
}

void ASkeletalBow::ReleaseArrow(USceneComponent* HandComp,float DrawVal)
{
	//this->AttachToComponent(HandComp, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, true), FName("Bow_Grip_Socket"));
	if (SpawnedArrow != nullptr)
	{
		SpawnedArrow->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		SpawnedArrow->SetActorRotation(HandComp->GetComponentRotation());
		SpawnedArrow->ReleaseArrow_Implementation(DrawVal);
		SpawnedArrow = nullptr;
	}
	
}

