// By OwenAtkinson


#include "SkeletalCompoundBow.h"

float ASkeletalCompoundBow::GetDrawLength(UMotionControllerComponent* DrawHand)
{
	if (DrawHand)//If something is inputted into the UMotionController Node
	{
		//Get the Tranform of the string idle socket and the location of the mc component, and then inverse transform its location.
		FVector HandLoc = DrawHand->GetComponentLocation();
		FTransform IdleTransform = BowSkeleton->GetSocketTransform("stringSocket_Idle", RTS_World);

		FVector TransformedLoc = UKismetMathLibrary::InverseTransformLocation(IdleTransform, HandLoc);
		float value = TransformedLoc.X;
		float DrawLen = UKismetMathLibrary::MapRangeClamped(value, NULL, 38, NULL, 1);
		return DrawLen;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("BowHand invalid"));
		return 0.0f;
	}
	
	
}

float ASkeletalCompoundBow::GetDrawValue(float DrawLen)
{
	float DrawValue = UKismetMathLibrary::MapRangeClamped(DrawLen, NULL, 1, MinDrawValue, MaxDrawValue);
	return DrawValue
		;
}
