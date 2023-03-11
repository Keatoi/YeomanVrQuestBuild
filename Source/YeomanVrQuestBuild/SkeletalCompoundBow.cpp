// By OwenAtkinson


#include "SkeletalCompoundBow.h"

float ASkeletalCompoundBow::GetDrawLength(FVector HandLoc)
{
	
		//Get the Tranform of the string idle socket and the location of the mc component, and then inverse transform its location.
		
		FTransform IdleTransform = BowSkeleton->GetSocketTransform("stringSocket_Idle", RTS_World);

		FVector TransformedLoc = UKismetMathLibrary::InverseTransformLocation(IdleTransform, HandLoc);
		float value = TransformedLoc.Z;
		float DrawLen = UKismetMathLibrary::MapRangeClamped(value, 0, -2, 0, 1);
		return DrawLen;
	

	
	
}

float ASkeletalCompoundBow::GetDrawValue(float DrawLen)
{
	float DrawValue = UKismetMathLibrary::MapRangeClamped(DrawLen,0, 1, MinDrawValue, MaxDrawValue);
	return DrawValue;
		
}
