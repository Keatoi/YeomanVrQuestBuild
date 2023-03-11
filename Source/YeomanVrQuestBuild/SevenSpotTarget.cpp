// By OwenAtkinson


#include "SevenSpotTarget.h"
//Although not technically used in record status competitions it is used in less common formats so is a nice addition if I can get the main one to work, and If I can I'll just add more rings 
// 
// Sets default values
ASevenSpotTarget::ASevenSpotTarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BullMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bull"));
	RootComponent = BullMesh;
	InnerGoldMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Inner Gold"));
	InnerGoldMesh->SetupAttachment(BullMesh);
	OuterGoldMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Outer Gold"));
	OuterGoldMesh->SetupAttachment(BullMesh);
	InnerRedMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Inner Red"));
	InnerRedMesh->SetupAttachment(BullMesh);
	OuterRedMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Outer Red"));
	OuterRedMesh->SetupAttachment(BullMesh);
	InnerBlueMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Inner Blue"));
	InnerBlueMesh->SetupAttachment(BullMesh);
	OuterBlueMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Outer Blue"));
	OuterBlueMesh->SetupAttachment(BullMesh);
	InnerBlackMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Inner Black"));
	InnerBlackMesh->SetupAttachment(BullMesh);
	OuterBlackMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Outer Black"));
	OuterBlackMesh->SetupAttachment(BullMesh);
	InnerWhiteMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Inner White"));
	InnerWhiteMesh->SetupAttachment(BullMesh);
	OuterWhiteMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Outer White"));
	OuterWhiteMesh->SetupAttachment(BullMesh);
	this->Tags.Add(FName("Target"));

	//Text setup
	TXTMapName = CreateDefaultSubobject<UTextRenderComponent>(TEXT("MapName"));
	TXTMapName->ToggleVisibility(false);
	TXTMapName->SetRelativeLocation(FVector(0,10,0));
	TXTMapName->SetText(FText::FromName(MapToLoad));
    
}

// Called when the game starts or when spawned
void ASevenSpotTarget::BeginPlay()
{
	Super::BeginPlay();
	FString MapName = GetWorld()->GetMapName();
	if (MapName == "Lvl_MainMenu")
	{
		OnActorHit.AddDynamic(this, &ASevenSpotTarget::OpenLevel);
	}
	else
	{
		OnActorHit.AddDynamic(this, &ASevenSpotTarget::OnTargetHit);
		
	}
	GameModeRef = Cast<AYeomanVrQuestBuildGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	
	
	
}

// Called every frame
void ASevenSpotTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASevenSpotTarget::OnTargetHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse,
	const FHitResult& Hit)
{
	UObject* HitComponent = Hit.GetComponent();
	if (GameModeRef != nullptr)
	{
		//Determine what static mesh was hit, change the score Enum in the gamemode to the corresponding score and then call the method that updates the score
		if (HitComponent == BullMesh)
		{
			//Originally wanted this to be a switch statement but couldn't get it to work so it'll be a series of elifs until I can figure out a more efficient way
			UE_LOG(LogTemp, Warning, TEXT("Bull Hit"));
			GameModeRef->scoreVariable = EScore::Hit_X;
		}
		else if (HitComponent == InnerGoldMesh)
		{
			//Originally wanted this to be a switch statement but couldn't get it to work so it'll be a series of elifs until I can figure out a more efficient way
			UE_LOG(LogTemp, Warning, TEXT("IGold Hit"));
			GameModeRef->scoreVariable = EScore::Hit_10;

		}
		else if (HitComponent == OuterGoldMesh)
		{
			//Originally wanted this to be a switch statement but couldn't get it to work so it'll be a series of elifs until I can figure out a more efficient way
			UE_LOG(LogTemp, Warning, TEXT("OGold Hit"));
			GameModeRef->scoreVariable = EScore::Hit_9;

		}
		else if (HitComponent == InnerRedMesh)
		{
			//Originally wanted this to be a switch statement but couldn't get it to work so it'll be a series of elifs until I can figure out a more efficient way
			UE_LOG(LogTemp, Warning, TEXT("Ired Hit"));
			GameModeRef->scoreVariable = EScore::Hit_8;

		}
		else if (HitComponent == OuterRedMesh)
		{
			//Originally wanted this to be a switch statement but couldn't get it to work so it'll be a series of elifs until I can figure out a more efficient way
			UE_LOG(LogTemp, Warning, TEXT("ORedl Hit"));
			GameModeRef->scoreVariable = EScore::Hit_7;

		}
		else if (HitComponent == InnerBlueMesh)
		{
			//Originally wanted this to be a switch statement but couldn't get it to work so it'll be a series of elifs until I can figure out a more efficient way
			UE_LOG(LogTemp, Warning, TEXT("IBlue Hit"));
			GameModeRef->scoreVariable = EScore::Hit_6;

		}
		else if (HitComponent == OuterBlueMesh)
		{
			//Originally wanted this to be a switch statement but couldn't get it to work so it'll be a series of elifs until I can figure out a more efficient way
			UE_LOG(LogTemp, Warning, TEXT("OBlue Hit"));
			GameModeRef->scoreVariable = EScore::Hit_5;

		}
		else if (HitComponent == InnerBlackMesh)
		{
			//Originally wanted this to be a switch statement but couldn't get it to work so it'll be a series of elifs until I can figure out a more efficient way
			UE_LOG(LogTemp, Warning, TEXT("Iblack Hit"));
			GameModeRef->scoreVariable = EScore::Hit_4;

		}
		else if (HitComponent == OuterBlackMesh)
		{
			//Originally wanted this to be a switch statement but couldn't get it to work so it'll be a series of elifs until I can figure out a more efficient way
			UE_LOG(LogTemp, Warning, TEXT("Oblack Hit"));
			GameModeRef->scoreVariable = EScore::Hit_3;

		}
		else if (HitComponent == InnerWhiteMesh)
		{
			//Originally wanted this to be a switch statement but couldn't get it to work so it'll be a series of elifs until I can figure out a more efficient way
			UE_LOG(LogTemp, Warning, TEXT("IWhite Hit"));
			GameModeRef->scoreVariable = EScore::Hit_2;

		}
		else if (HitComponent == OuterWhiteMesh)
		{
			//Originally wanted this to be a switch statement but couldn't get it to work so it'll be a series of elifs until I can figure out a more efficient way
			UE_LOG(LogTemp, Warning, TEXT("OWhite Hit"));
			GameModeRef->scoreVariable = EScore::Hit_1;

		}
		GameModeRef->AddScore();
	}
	
	
}

void ASevenSpotTarget::OpenLevel(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	UGameplayStatics::OpenLevel(GetWorld(), MapToLoad);
}

