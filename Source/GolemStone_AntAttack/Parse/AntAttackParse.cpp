// Fill out your copyright notice in the Description page of Project Settings.

#include "GolemStone_AntAttack.h"
#include "AntAttackParse.h"



//Parse text to WorldStateStruct (pointer)
void UAntAttackParse::GetParameterStrToWorldStateStruct(FString InputString, UWorldState* WorldStateClass)
{
	if (InputString == "") return;

	//const TCHAR* Delims[] = {TEXT("|")};
	TArray<FString> ParsedStrings;
	InputString.ParseIntoArray(ParsedStrings, TEXT("|"), false);

	if (!ParsedStrings.IsValidIndex(0)) return;

	if (ParsedStrings[0] == "ERROR")
	{
		if (!ParsedStrings.IsValidIndex(1)) return;
		WorldStateClass->WorldStateInputStruct.ErrorText = ParsedStrings[1];//ERROR_TEXT
	}

	if (ParsedStrings[0] == "CONNECTED")
	{
		if (!ParsedStrings.IsValidIndex(1)) return;
		WorldStateClass->WorldStateInputStruct.MyPlayerID = FCString::Atoi(*ParsedStrings[1]); //(my) PLAYER_ID
	}

	if (ParsedStrings[0] != "CONNECTED" && ParsedStrings[0] != "ERROR")
	{
		WorldStateClass->WorldStateInputStruct.MessagePlayerID = FCString::Atoi(*ParsedStrings[0]); //(message) PLAYER_ID
		if (!ParsedStrings.IsValidIndex(1)) return;
		if (ParsedStrings[1] == "CONNECTED")
		{
			WorldStateClass->WorldStateInputStruct.Connected = true; //CONNECTED
			if (!ParsedStrings.IsValidIndex(2)) return;
			WorldStateClass->WorldStateInputStruct.NickName = ParsedStrings[2]; //NICKNAME
		}

		if (ParsedStrings[1] == "LOCATION")
		{
			if (!ParsedStrings.IsValidIndex(2) || !ParsedStrings.IsValidIndex(3) || !ParsedStrings.IsValidIndex(4)) return;
			WorldStateClass->WorldStateInputStruct.Location = FVector(FCString::Atof(*ParsedStrings[2]), FCString::Atof(*ParsedStrings[3]), FCString::Atof(*ParsedStrings[4])); //X|Y|Z
		}

		if (ParsedStrings[1] == "MOVE")
		{
			if (!ParsedStrings.IsValidIndex(2) || !ParsedStrings.IsValidIndex(3) || !ParsedStrings.IsValidIndex(4) || !ParsedStrings.IsValidIndex(5) || !ParsedStrings.IsValidIndex(6)) return;
			WorldStateClass->WorldStateInputStruct.Move.Direction = FVector(FCString::Atof(*ParsedStrings[2]), FCString::Atof(*ParsedStrings[3]), FCString::Atof(*ParsedStrings[4])); //X|Y|Z
			WorldStateClass->WorldStateInputStruct.Move.Speed = FCString::Atof(*ParsedStrings[5]); //SPEED
			WorldStateClass->WorldStateInputStruct.Move.Acceleration = FCString::Atof(*ParsedStrings[6]); //ACCELERATION
		}

		if (ParsedStrings[1] == "STOP")
		{
			if (!ParsedStrings.IsValidIndex(2) || !ParsedStrings.IsValidIndex(3) || !ParsedStrings.IsValidIndex(4)) return;
			WorldStateClass->WorldStateInputStruct.Stop = FVector(FCString::Atof(*ParsedStrings[2]), FCString::Atof(*ParsedStrings[3]), FCString::Atof(*ParsedStrings[4])); //X|Y|Z
		}

		if (ParsedStrings[1] == "PICK")
		{
			WorldStateClass->WorldStateInputStruct.Pick = true;
		}

		if (ParsedStrings[1] == "THROW")
		{
			if (!ParsedStrings.IsValidIndex(2) || !ParsedStrings.IsValidIndex(3) || !ParsedStrings.IsValidIndex(4) || !ParsedStrings.IsValidIndex(5) || !ParsedStrings.IsValidIndex(6)) return;
			WorldStateClass->WorldStateInputStruct.Throw.Direction = FVector(FCString::Atof(*ParsedStrings[2]), FCString::Atof(*ParsedStrings[3]), FCString::Atof(*ParsedStrings[4])); //X|Y|Z
			WorldStateClass->WorldStateInputStruct.Throw.Speed = FCString::Atof(*ParsedStrings[5]); //SPEED
			WorldStateClass->WorldStateInputStruct.Throw.Acceleration = FCString::Atof(*ParsedStrings[6]); //ACCELERATION
		}

		if (ParsedStrings[1] == "HIT")
		{
			WorldStateClass->WorldStateInputStruct.Hit = true;
		}

		if (ParsedStrings[1] == "DEATH")
		{
			WorldStateClass->WorldStateInputStruct.Death = true;
		}

		if (ParsedStrings[1] == "REVIVE")
		{
			WorldStateClass->WorldStateInputStruct.Revive = true;
		}

		if (ParsedStrings[1] == "DISCONNECT")
		{
			WorldStateClass->WorldStateInputStruct.Disconnect = true;
		}
	}

	
	//GEngine->AddOnScreenDebugMessage(-1, 0.01, FColor::Yellow, TEXT("InputString=") + InputString);
	//GEngine->AddOnScreenDebugMessage(-1, 0.01, FColor::Yellow, TEXT("InputString=") + InputString);
	//GEngine->AddOnScreenDebugMessage(-1, 0.01, FColor::Yellow, FString::FromInt(ParsedStrings.Num()));
}
