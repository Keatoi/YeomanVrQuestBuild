// By OwenAtkinson

#include "Kismet/GameplayStatics.h"
#include "VRGameInstance.h"

void UVRGameInstance::Init()
{
	//This method checks if there is a save in the save slot or not.
	//If there is load it, if not make it.
	Data = Cast<UVRSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveName, 0));
	if (!Data)
	{
		//if no data make a new one.
		Data = Cast<UVRSaveGame>(UGameplayStatics::CreateSaveGameObject(UVRSaveGame::StaticClass()));
		Data->ScorePB = 0;//equal to 0 until scoring is actually implemented.
		UGameplayStatics::SaveGameToSlot(Data, SaveName, 0);//Save score into the save slot
		
	}
}

void UVRGameInstance::SaveData(int Score)
{
	if (Data)
	{
		Data->ScorePB = Score;
		UGameplayStatics::SaveGameToSlot(Data, SaveName, 0);
	}
}

UVRSaveGame* UVRGameInstance::LoadData()
{
	if (Data)return Data;
	else return nullptr;
}
