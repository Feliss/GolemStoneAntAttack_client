// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "WorldState.generated.h"

/**
 * 
 */


USTRUCT(BlueprintType)
struct FDirectMoveStruct
{
	GENERATED_USTRUCT_BODY()

	//|X|Y|Z|SPEED|ACCELERATION

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		FVector Direction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		float Acceleration;

	//defaults
	FDirectMoveStruct()
	{
		Direction = FVector(0.f,0.f,0.f);
		Speed = 0.f;
		Acceleration = 0.f;
	}
};



USTRUCT(BlueprintType)
struct FWorldStateOutputStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		bool Connected;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		FString NickName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		FVector Location;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		FDirectMoveStruct Move;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		FVector Stop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		bool Pick;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		FDirectMoveStruct Throw;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		int32 HitID; //PlayerID is hit

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		bool Death; //PlayerID is Death

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		bool Disconnect; //PlayerID is Revive

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		FString ErrorText; //PlayerID is Revive

	//defaults
	FWorldStateOutputStruct()
	{
		Connected = false;
		NickName = FString("DefaultPlayerName");
		Location = FVector(0.f, 0.f, 0.f);
		Stop = FVector(0.f, 0.f, 0.f);
		Pick = false;
		HitID = 0;
		Death = false;
		Disconnect = false;
		ErrorText = FString("");
	}
};



USTRUCT(BlueprintType)
struct FWorldStateInputStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		bool Connected;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		int32 MessagePlayerID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		int32 MyPlayerID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		FString NickName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		FVector Location;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		FDirectMoveStruct Move;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		FVector Stop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		bool Pick;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		FDirectMoveStruct Throw;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		bool Hit; //PlayerID is hit

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		bool Death; //PlayerID is Death

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		bool Revive; //PlayerID is Revive

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		bool Disconnect; //PlayerID is Revive

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WorldStateStruct)
	FWorldStateInputStruct WorldStateInputStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WorldStateStruct)
	FWorldStateOutputStruct WorldStateOutputStruct;
	
};
