// By OwenAtkinson
#include "SkeletalBow.h"
#include"Runtime/Engine/Classes/Engine/World.h."


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
	ArrowHelper = CreateDefaultSubobject<USceneComponent>(TEXT("Helper"));
	ArrowHelper->SetRelativeLocation(ArrowOffset);
	this->Tags.Add(FName("Bow"));
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
		if (bUseAlt)
		{
			SpawnedArrow = GetWorld()->SpawnActor<AArrowBasic>(ArrowAlt, SkeleTransform);
		}
		else
		{
			SpawnedArrow = GetWorld()->SpawnActor<AArrowBasic>(ArrowClass, SkeleTransform);
		}
		
		UE_LOG(LogTemp, Warning, TEXT("Arrow is Spawning"));
		AttachArrow();
		return SpawnedArrow;
	}
	else return nullptr;
	
	
	
	
}

bool ASkeletalBow::ShouldSpawnArrow(FVector MCWorldLoc, float MinDist, FName SocketName, bool ReverseCheck)
{
	//if the other motion controller is close enough to the skeleton string socket location return true
	if (BowSkeleton)
	{
		FVector SkeleLoc = BowSkeleton->GetSocketLocation(FName(SocketName));
		FVector SubVect = MCWorldLoc - SkeleLoc;
		float VectLen = SubVect.Size();
		if (!ReverseCheck && VectLen < MinDist)//Some skeletal Meshes tested are set up in a way that the minfist would actually end up being a negative, as a work around the node will have a bool check to determine which if statement to use.
		{
			return true;
		}
		else if(ReverseCheck && VectLen > MinDist)
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
		if (bKeepArrowScale)
		{
			SpawnedArrow->AttachToComponent(BowSkeleton, FAttachmentTransformRules(EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, true), StringSocket);
		}
		else
		{
			SpawnedArrow->AttachToComponent(BowSkeleton, FAttachmentTransformRules(EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, EAttachmentRule::KeepRelative, true), StringSocket);
			
		}
		//SpawnedArrow->AttachToComponent(BowSkeleton, FAttachmentTransformRules(EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, true), StringSocket);
		SpawnedArrow->SetActorScale3D(ArrowScale);
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

		//SpawnedArrow->SetActorRotation(HandComp->GetComponentRotation()); Was used as a temp fix before I got the arrow to travel in the right vector. Not needed anymore, left in for future reference in case the issue happens with another arrow type
		SpawnedArrow->ReleaseArrow_Implementation(DrawVal,DrawWeight,AdditionalWeight);
		SpawnedArrow = nullptr;
	}
	
}

void ASkeletalBow::AttachBow(USkeletalMeshComponent* HandMesh, FName SocketName,FRotator BowRotation)
{
	

	AttachToComponent(HandMesh, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, false),SocketName);
	BowSkeleton->SetRelativeRotation(FRotator(BowRotation));
	BowSkeleton->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ASkeletalBow::DetachBow()
{
	DetachFromActor(FDetachmentTransformRules(EDetachmentRule::KeepWorld,false));
	DrawLength = 0.0f;
	BowSkeleton->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	
}
float ASkeletalBow::GetSkeletalDrawLength(FVector HandLoc)
{

	//Get the Tranform of the string idle socket and the location of the mc component, and then inverse transform its location.

	FTransform IdleTransform = BowSkeleton->GetSocketTransform("StringIdle", RTS_World);

	FVector TransformedLoc = UKismetMathLibrary::InverseTransformLocation(IdleTransform, HandLoc);
	float value = TransformedLoc.X;
	float DrawLen = UKismetMathLibrary::MapRangeClamped(value, MinDrawLength, MaxDrawLength,0,1);
	return DrawLen;
}

float ASkeletalBow::GetDrawValue()
{
	float value = ForceCurve->GetFloatValue(DrawLength);
	float DrawValue = UKismetMathLibrary::MapRangeClamped(value, 0,1,MinDrawValue, MaxDrawValue );
	return DrawValue;

}

