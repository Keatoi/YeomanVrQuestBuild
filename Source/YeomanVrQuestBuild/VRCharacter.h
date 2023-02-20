// By OwenAtkinson

#pragma once
/* VR Includes */
#include "HeadMountedDisplay.h"
#include "MotionControllerComponent.h"
#include "XRMotionControllerBase.h"
////////////
#include "Camera/CameraComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VRCharacter.generated.h"

UCLASS()
class YEOMANVRQUESTBUILD_API AVRCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVRCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    UPROPERTY(EditAnywhere, Category = "Components")
        UCameraComponent* HMDCamera;

    /* Component to specify origin for the HMD */
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
        USceneComponent* VROrigin;

    UPROPERTY(EditDefaultsOnly, Category = "VR")
        bool bPositionalHeadTracking;

    /* Motion Controllers */
   /* UPROPERTY(EditDefaultsOnly, Category = "Components")
        class UMotionControllerComponent* LeftHandController;

    UPROPERTY(EditDefaultsOnly, Category = "Components")
        class UMotionControllerComponent* RightHandController;
    UPROPERTY(EditDefaultsOnly, Category = "Components")
        UStaticMeshComponent* LeftHandMesh;
    UPROPERTY(EditDefaultsOnly, Category = "Components")
        UStaticMeshComponent* RightHandMesh;*/
    UFUNCTION()
        void Strafe(float Value);
    UFUNCTION()
        void MoveForwards(float Value);
    UFUNCTION()
        void Turn(float Value);
    UFUNCTION()
        void SnapToggle();
    UPROPERTY(EditDefaultsOnly, Category = "Movement")
        float MovementDeadzone = 0.25f;
    UPROPERTY(EditDefaultsOnly, Category = "Movement")
        float MovementSpeed = 0.5f;
    UPROPERTY(EditDefaultsOnly, Category = "Movement")
        float RotationSpeed = 0.5f;
    UPROPERTY(EditDefaultsOnly, Category = "Movement")
        bool bIsUsingSnapTurn = false;
    UPROPERTY(EditDefaultsOnly, Category = "Movement")
        float RotationAngle = 45.0f;



};
