// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "WorldState.generated.h"

/**
 * 
 */


USTRUCT()
struct FDirectMoveStruct
{
	GENERATED_USTRUCT_BODY()

	//|X|Y|Z|SPEED|ACCELERATION

	UPROPERTY()
		FVector Direction;

	UPROPERTY()
		float Speed;

	UPROPERTY()
		float Acceleration;

	//defaults
	FDirectMoveStruct()
	{
		Direction = FVector(0.f,0.f,0.f);
		Speed = 0.f;
		Acceleration = 0.f;
	}
};



USTRUCT()
struct FWorldStateOutputStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
		bool Connected;

	UPROPERTY()
		FString NickName;

	UPROPERTY()
		FVector Location;

	UPROPERTY()
		FDirectMoveStruct Move;

	UPROPERTY()
		FVector Stop;

	UPROPERTY()
		bool Pick;

	UPROPERTY()
		FDirectMoveStruct Throw;

	UPROPERTY()
		bool Hit; //PlayerID is hit

	UPROPERTY()
		bool Death; //PlayerID is Death

	UPROPERTY()
		bool Disconnect; //PlayerID is Revive

	UPROPERTY()
		FString ErrorText; //PlayerID is Revive

	//defaults
	FWorldStateOutputStruct()
	{
		Connected = false;
		NickName = FString("DefaultPlayerName");
		Location = FVector(0.f, 0.f, 0.f);
		Stop = FVector(0.f, 0.f, 0.f);
		Pick = false;
		Hit = false;
		Death = false;
		Disconnect = false;
		ErrorText = FString("");
	}
};



USTRUCT()
struct FWorldStateInputStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
		bool Connected;

	UPROPERTY()
		int32 MessagePlayerID;

	UPROPERTY()
		int32 MyPlayerID;

	UPROPERTY()
		FString NickName;

	UPROPERTY()
		FVector Location;

	UPROPERTY()
		FDirectMoveStruct Move;

	UPROPERTY()
		FVector Stop;

	UPROPERTY()
		bool Pick;

	UPROPERTY()
		FDirectMoveStruct Throw;

	UPROPERTY()
		bool Hit; //PlayerID is hit

	UPROPERTY()
		bool Death; //PlayerID is Death

	UPROPERTY()
		bool Revive; //PlayerID is Revive

	UPROPERTY()
		bool Disconnect; //PlayerID is Revive

	UPROPERTY()
		FString ErrorText; //PlayerID is Revive

	//defaults
	FWorldStateInputStruct()
	{
		Connected = false;
		MyPlayerID = FMath::RandRange(1000, 9999);
		MessagePlayerID = 0;
		NickName = FString("DefaultPlayerName");
		Location = FVector(0.f,0.f,0.f);
		Stop = FVector(0.f, 0.f, 0.f);
		Pick = false;
		Hit = false;
		Death = false;
		Revive = false;
		Disconnect = false;
		ErrorText = FString("");
	}
};

UCLASS()
class GOLEMSTONE_ANTATTACK_API UWorldState : public UObject
{
	GENERATED_BODY()

public:

	FWorldStateInputStruct WorldStateInputStruct;
	FWorldStateOutputStruct WorldStateOutputStruct;
	
};
