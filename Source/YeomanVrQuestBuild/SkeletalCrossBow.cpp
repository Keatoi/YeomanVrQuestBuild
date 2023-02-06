// By OwenAtkinson

#include "Components/BoxComponent.h"
#include "SkeletalCrossBow.h"

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
