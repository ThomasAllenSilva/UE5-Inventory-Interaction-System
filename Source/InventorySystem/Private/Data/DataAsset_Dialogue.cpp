// Fill out your copyright notice in the Description page of Project Settings.

#include "Data/DataAsset_Dialogue.h"

FText UDataAsset_Dialogue::GetDialogueAtIndex(const int Index) const
{
    checkf(Dialogues.IsValidIndex(Index), TEXT("The index '%d' is not a valid index inside the Dialogues array"));
    
    return Dialogues[Index];
}

bool UDataAsset_Dialogue::IsFinalDialogue(const int Index) const
{
    return Index >= Dialogues.Num() - 1;
}
