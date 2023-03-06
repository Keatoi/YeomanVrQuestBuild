// By OwenAtkinson


#include "SkeletalCompoundBow.h"

float ASkeletalCompoundBow::GetDrawLength(FVector HandLoc)
{
	
		//Get the Tranform of the string idle socket and the location of the mc component, and then inverse transform its location.
		
		FTransform IdleTransform = BowSkeleton->GetSocketTransform("stringSocket_Idle", RTS_World);

		FVector TransformedLoc = UKismetMathLibrary::InverseTransformLocation(IdleTransform, HandLoc);
		float value = TransformedLoc.X;
		float DrawLen = UKismetMathLibrary::MapRangeClamped(value, NULL, 38, NULL, 1);
		return DrawLen;
	

	
	
}

float ASkeletalCompoundBow::GetDrawValue(float DrawLen)
{
	float DrawValue = UKismetMathLibrary::MapRangeClamped(DrawLen, NULL, 1, MinDrawValue, MaxDrawValue);
	return DrawValue
		;
}
