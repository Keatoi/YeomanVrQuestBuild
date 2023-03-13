// By OwenAtkinson
#include "SkeletalCrossBow.h"
#include "Components/BoxComponent.h"


ASkeletalCrossBow::ASkeletalCrossBow()
{
	ScopeDetection = CreateDefaultSubobject<UBoxComponent>("Scope Detector");
	ScopeDetection->SetupAttachment(root);
}

void ASkeletalCrossBow::Grab_Implementation()
{
}

void ASkeletalCrossBow::Drop_Implementation()
{
}
