// By OwenAtkinson


#include "VRSlider.h"

// Sets default values
AVRSlider::AVRSlider()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SliderSpline = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	SliderMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VR Slider Mesh"));
}

// Called when the game starts or when spawned
void AVRSlider::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVRSlider::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

