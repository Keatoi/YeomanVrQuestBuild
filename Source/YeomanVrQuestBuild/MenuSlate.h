// By OwenAtkinson

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MenuSlate.generated.h"

UCLASS()
class YEOMANVRQUESTBUILD_API AMenuSlate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMenuSlate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
