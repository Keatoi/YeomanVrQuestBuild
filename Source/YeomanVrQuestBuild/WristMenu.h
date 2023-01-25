// By OwenAtkinson

#pragma once
#include "Components/WidgetInteractionComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WristMenu.generated.h"

UCLASS()
class YEOMANVRQUESTBUILD_API AWristMenu : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWristMenu();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UWidgetInteractionComponent* WidgetComp;
};
