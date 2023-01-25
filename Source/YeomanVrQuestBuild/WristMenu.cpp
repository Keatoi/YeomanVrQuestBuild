// By OwenAtkinson


#include "WristMenu.h"

// Sets default values
AWristMenu::AWristMenu()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	WidgetComp = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("Widget Component"));
}

// Called when the game starts or when spawned
void AWristMenu::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWristMenu::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

