// Copyright (c) 2013-2025 Daniel Acourt. All Rights Reserved. Confidential & Proprietary.

#include "SaveSystem/SovereignPSTAConfig.h"

USovereignPSTAConfig::USovereignPSTAConfig()
{
    // Default weights
    DimensionWeights.Add(EPSTADimension::Psychological, 0.25f);
    DimensionWeights.Add(EPSTADimension::Social, 0.25f);
    DimensionWeights.Add(EPSTADimension::Technical, 0.25f);
    DimensionWeights.Add(EPSTADimension::Administrative, 0.25f);
}

float USovereignPSTAConfig::NormalizeValue(const FPSTATagMapping& Mapping, float RawValue) const
{
    float Range = Mapping.RangeMax - Mapping.RangeMin;
    if (FMath::IsNearlyZero(Range))
    {
        return RawValue >= Mapping.RangeMax ? 1.0f : 0.0f;
    }

    float Normalized = (RawValue - Mapping.RangeMin) / Range;
    return FMath::Clamp(Normalized, 0.0f, 1.0f);
}
