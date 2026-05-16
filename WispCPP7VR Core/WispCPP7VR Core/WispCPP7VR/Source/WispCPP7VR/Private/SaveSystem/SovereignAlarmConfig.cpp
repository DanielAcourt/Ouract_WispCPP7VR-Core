// Copyright (c) 2013-2025 Daniel Acourt. All Rights Reserved. Confidential & Proprietary.

#include "SaveSystem/SovereignAlarmConfig.h"

const FSovereignAlarmRule* USovereignAlarmConfig::GetRule(const FString& AlarmID) const
{
    for (const FSovereignAlarmRule& Rule : AlarmRules)
    {
        if (Rule.AlarmID == AlarmID)
        {
            return &Rule;
        }
    }
    return nullptr;
}
