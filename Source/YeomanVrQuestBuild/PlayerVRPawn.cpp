// By OwenAtkinson


#include "PlayerVRPawn.h"

// Sets default values
APlayerVRPawn::APlayerVRPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerVRPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerVRPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerVRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

