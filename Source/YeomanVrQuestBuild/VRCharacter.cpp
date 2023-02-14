// By OwenAtkinson


#include "VRCharacter.h"

// Sets default values
AVRCharacter::AVRCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	VRCam = CreateDefaultSubobject<UCameraComponent>(TEXT("VRCam"));
	

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
	PlayerInputComponent->BindAxis("Strafe", this, &AVRCharacter::Strafe);
	PlayerInputComponent->BindAxis("Forward", this, &AVRCharacter::MoveForwards);
	PlayerInputComponent->BindAxis("Turn", this, &AVRCharacter::Turn);
	PlayerInputComponent->BindAction("SwapLocomotion", IE_Pressed, this, &AVRCharacter::SnapToggle);
	
}

void AVRCharacter::Strafe(float Value)
{
	float MovementScale = Value * MovementSpeed;
	FVector VRDirection = VRCam->GetRightVector();
	if (abs(Value) > MovementDeadzone)
	{
		//if the absolute value of the axis input is greater than the deadzone then move. This means the pawn should not move unless the joystick is at least a 1/4 of the way pressed in a direction. This
		
		AddMovementInput(VRDirection, MovementScale, false);
	}
}

void AVRCharacter::MoveForwards(float Value)
{
	float MovementScale = Value * MovementSpeed;
	FVector VRDirection = VRCam->GetForwardVector();
	if (abs(Value) > MovementDeadzone)
	{
		

		AddMovementInput(VRDirection, MovementScale, false);
	}
}

void AVRCharacter::Turn(float Value)
{
	if (!bIsUsingSnapTurn)
	{
		if (Value > MovementDeadzone)
		{
			AddControllerYawInput(Value * RotationSpeed);
		}
		else if (Value < (MovementDeadzone * -1.0f))//if moving the stick left
		{
			AddControllerYawInput(Value * RotationSpeed);
		}
	}
	else
	{
		//Snap turning

	}
}

void AVRCharacter::SnapToggle()
{
	if (bIsUsingSnapTurn)
	{
		bIsUsingSnapTurn = false;
	}
	else
	{
		bIsUsingSnapTurn = true;
	}
}

