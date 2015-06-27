// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "WorldState/WorldState.h"
#include "AntAttackParse.generated.h"

/**
 * 
 */



UCLASS()
class GOLEMSTONE_ANTATTACK_API UAntAttackParse : public UObject
{
	GENERATED_BODY()
public:

	static void GetParameterStrToWorldStateStruct(FString InputString, UWorldState* WorldStateClass);
	static FString WorldStateStructToParameterStr(FString CommandText, UWorldState* WorldStateClass);

};
