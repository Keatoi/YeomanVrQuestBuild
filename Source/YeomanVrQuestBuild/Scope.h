// By OwenAtkinson

#pragma once
#include "MotionControllerComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Scope.generated.h"

UCLASS()
class YEOMANVRQUESTBUILD_API AScope : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AScope();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* ScopeMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* ScopeCylinder;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class USceneCaptureComponent2D* SceneCapture;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		FVector ScopeZoom = { 450,0,0 };
	UFUNCTION(BlueprintCallable)
		void Grab_Implementation(UMotionControllerComponent* GrabbingHand);
	UFUNCTION(BlueprintCallable)
		void Drop_Implementation(UMotionControllerComponent* GrabbingHand);

};
