// By OwenAtkinson
#include "WindActor.h"
#include "Kismet/KismetMathLibrary.h"
#include "ArrowBasic.h"


// Sets default values
AWindActor::AWindActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	WindBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Wind Box"));
	WindIndicator = CreateDefaultSubobject<UArrowComponent>(TEXT("Wind Dir"));
	
}

// Called when the game starts or when spawned
void AWindActor::BeginPlay()
{
	Super::BeginPlay();
	WindVector = this->GetActorForwardVector() * WindSpeed;
	WindBox->OnComponentBeginOverlap.AddDynamic(this, &AWindActor::OnOverlapBegin);
	WindBox->OnComponentEndOverlap.AddDynamic(this, &AWindActor::OnOverlapEnd);
}

// Called every frame
void AWindActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWindActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Arrow = Cast<AArrowBasic>(OtherActor);
	if (Arrow)
	{
		Arrow->ApplyWind(WindVector);
	}
}

void AWindActor::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Arrow = Cast<AArrowBasic>(OtherActor);
	if (Arrow)
	{
		FVector NegWind = UKismetMathLibrary::NegateVector(WindVector);
		Arrow->ApplyWind(NegWind);//Negates the vector so it stops applying when the arrow leaves the wind box.
	}
	
}



