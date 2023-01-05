// By OwenAtkinson


#include "VRCharacter.h"

// Sets default values
AVRCharacter::AVRCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	/*VROrigin  = CreateDefaultSubobject<USceneComponent>(TEXT("VROrigin"));
	VROrigin->AttachParent = RootComponent;
	VRCam = CreateDefaultSubobject<UCameraComponent>(TEXT("VRCam"));
	VRCam->AttachParent = VROrigin;*/

	//MotionControllers
	/*LeftHandController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("Left Hand"));
	LeftHandController->AttachParent = VROrigin;
	LeftHandController->Hand = EControllerHand::Left;
	LeftHandMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left Hand Mesh"));
	LeftHandMesh->AttachParent = LeftHandController;
	RightHandController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("Right Hand"));
	RightHandController->AttachParent = VROrigin;
	RightHandController->Hand = EControllerHand::Right;
	RightHandMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right Hand Mesh"));
	RightHandMesh->AttachParent = RightHandController;*/
}

// Called when the game starts or when spawned
void AVRCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVRCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVRCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

