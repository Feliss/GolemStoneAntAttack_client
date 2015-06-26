// Fill out your copyright notice in the Description page of Project Settings.

#include "GolemStone_AntAttack.h"
#include "WorldState_actor.h"


// Sets default values
AWorldState_actor::AWorldState_actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AWorldState_actor::BeginPlay()
{
	Super::BeginPlay();

	//create object of WorldStateClass
	WorldStateClass = NewObject<UWorldState>(UWorldState::StaticClass(), FName(TEXT("WorldState_Class")));
}

// Called every frame
void AWorldState_actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ShowTCPLog();//Show World State Log
	GetTCPValues();//Get values from TCP to WorldStateClass
}

// Get TCP Values
void AWorldState_actor::GetTCPValues()
{
	if (TCP_actor == NULL) return;
	if (WorldStateClass == NULL) return;

	FString TCP_Message = TCP_actor->GetTCPMessage();  //TCP_Message = FString("2564|THROW|2.6|-6.2|4.7|250.7|2.f"); //For Test!!! THROW    TCP_Message = FString("2564|DEATH");

	UAntAttackParse::GetParameterStrToWorldStateStruct(TCP_Message, WorldStateClass);//Get values from parsing and live change
}

//Show World State Log
void AWorldState_actor::ShowTCPLog()
{
	if (isShowTCPLog == false) return;
	if (WorldStateClass == NULL) return;

	float DeltaTime = GetWorld()->GetDeltaSeconds();

	GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Yellow, FString::Printf(TEXT("DISCONNECT= %s"), WorldStateClass->WorldStateInputStruct.Disconnect ? TEXT("true") : TEXT("false")));
	GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Yellow, FString::Printf(TEXT("REVIVE= %s"), WorldStateClass->WorldStateInputStruct.Revive ? TEXT("true") : TEXT("false")));
	GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Yellow, FString::Printf(TEXT("DEATH= %s"), WorldStateClass->WorldStateInputStruct.Death ? TEXT("true") : TEXT("false")));
	GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Yellow, FString::Printf(TEXT("HIT= %s"), WorldStateClass->WorldStateInputStruct.Hit ? TEXT("true") : TEXT("false")));
	GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Yellow, TEXT("THROW DIRECTION=") + WorldStateClass->WorldStateInputStruct.Throw.Direction.ToString() + TEXT(" SPEED=") + FString::SanitizeFloat(WorldStateClass->WorldStateInputStruct.Throw.Speed) + TEXT(" ACCELERATION=") + FString::SanitizeFloat(WorldStateClass->WorldStateInputStruct.Throw.Acceleration));
	GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Yellow, FString::Printf(TEXT("PICK= %s"), WorldStateClass->WorldStateInputStruct.Pick ? TEXT("true") : TEXT("false")));
	GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Yellow, TEXT("STOP=") + WorldStateClass->WorldStateInputStruct.Stop.ToString());
	GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Yellow, TEXT("MOVE DIRECTION=") + WorldStateClass->WorldStateInputStruct.Move.Direction.ToString() + TEXT(" SPEED=") + FString::SanitizeFloat(WorldStateClass->WorldStateInputStruct.Move.Speed) + TEXT(" ACCELERATION=") + FString::SanitizeFloat(WorldStateClass->WorldStateInputStruct.Move.Acceleration));
	GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Yellow, TEXT("LOCATION=") + WorldStateClass->WorldStateInputStruct.Location.ToString());
	GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Yellow, TEXT("NickName=") + WorldStateClass->WorldStateInputStruct.NickName);
	GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Yellow, TEXT("MessageID=") + FString::FromInt(WorldStateClass->WorldStateInputStruct.MessagePlayerID));
	GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Yellow, TEXT("MyID=") + FString::FromInt(WorldStateClass->WorldStateInputStruct.MyPlayerID));
	GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Yellow, FString::Printf(TEXT("CONNECTED= %s"), WorldStateClass->WorldStateInputStruct.Connected ? TEXT("true") : TEXT("false")));
}