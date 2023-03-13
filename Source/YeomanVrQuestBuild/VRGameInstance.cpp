// By OwenAtkinson
#include "VRGameInstance.h"
#include "Kismet/GameplayStatics.h"


void UVRGameInstance::Init()
{
	//This method checks if there is a save in the save slot or not.
	//If there is load it, if not make it.
	Data = Cast<UVRSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveName, 0));
	if (!Data)
	{
		//if no data make a new one.
		Data = Cast<UVRSaveGame>(UGameplayStatics::CreateSaveGameObject(UVRSaveGame::StaticClass()));
		Data->PBScore = 0;
		
		UGameplayStatics::SaveGameToSlot(Data, SaveName, 0);//Save score into the save slot
		
	}
}

void UVRGameInstance::SaveData(int Score)
{
	if (Data)
	{
		if (Data->PBScore < Score)
		{
			Data->PBScore = Score;
		}
		UGameplayStatics::SaveGameToSlot(Data, SaveName, 0);
	}
}

UVRSaveGame* UVRGameInstance::LoadData()
{
	if (Data)return Data;
	else return nullptr;
}
