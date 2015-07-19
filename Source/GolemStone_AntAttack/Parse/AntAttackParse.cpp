// Fill out your copyright notice in the Description page of Project Settings.

#include "GolemStone_AntAttack.h"
#include "AntAttackParse.h"



//Parse text to WorldStateStruct (pointer) (input)
void UAntAttackParse::GetParameterStrToWorldStateStruct(FString InputString, UWorldState* WorldStateClass)
{
	if (InputString == "") return;
	if (WorldStateClass == NULL) return;

	
	//const TCHAR* Delims[] = {TEXT("|")};
	//WorldStateClass->WorldStateInputStruct.InputCommandMessage = InputString;


	TArray<FString> ParsedStrings;
	InputString.ParseIntoArray(ParsedStrings, TEXT("|"), false);

	if (!ParsedStrings.IsValidIndex(0)) return;

	//save command name
	WorldStateClass->WorldStateInputStruct.InputCommandMessage = ParsedStrings[0];

	if (ParsedStrings[0] == "ERROR")
	{
		if (!ParsedStrings.IsValidIndex(1)) return;
		WorldStateClass->WorldStateInputStruct.ErrorText = ParsedStrings[1];//ERROR_TEXT
	}

	if (ParsedStrings[0] == "CONNECTED")
	{
		GEngine->AddOnScreenDebugMessage(-1, 4, FColor::Yellow, FString("fhfgh"));
		if (!ParsedStrings.IsValidIndex(1)) return;
		WorldStateClass->WorldStateInputStruct.MyPlayerID = ParsedStrings[1]; //(my) PLAYER_ID
	}

	if (ParsedStrings[0] != "CONNECTED" && ParsedStrings[0] != "ERROR")
	{
		WorldStateClass->WorldStateInputStruct.MessagePlayerID = ParsedStrings[0]; //(message) PLAYER_ID
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

//Parameter to text
FString UAntAttackParse::WorldStateStructToParameterStr(FString CommandText, UWorldState* WorldStateClass)
{
	if (CommandText == "") return "ERROR|noCommandText#1";
	if (WorldStateClass == NULL) return "ERROR|NoWorldStateClass";

	if (CommandText == "ERROR")
		return CommandText + "|" + WorldStateClass->WorldStateOutputStruct.ErrorText;

	if (CommandText == "CONNECT")
		return CommandText + "|" + WorldStateClass->WorldStateOutputStruct.NickName;

	if (CommandText == "LOCATION")
		return CommandText + "|" + FString::SanitizeFloat(WorldStateClass->WorldStateOutputStruct.Location.X) + "|" + 
		FString::SanitizeFloat(WorldStateClass->WorldStateOutputStruct.Location.Y) + "|" +
		FString::SanitizeFloat(WorldStateClass->WorldStateOutputStruct.Location.Z);

	if (CommandText == "MOVE")
		return CommandText + "|" + FString::SanitizeFloat(WorldStateClass->WorldStateOutputStruct.Move.Direction.X) + "|" +
		FString::SanitizeFloat(WorldStateClass->WorldStateOutputStruct.Move.Direction.Y) + "|" +
		FString::SanitizeFloat(WorldStateClass->WorldStateOutputStruct.Move.Direction.Z) + "|" + 
		FString::SanitizeFloat(WorldStateClass->WorldStateOutputStruct.Move.Speed) + "|" +
		FString::SanitizeFloat(WorldStateClass->WorldStateOutputStruct.Move.Acceleration);

	if (CommandText == "STOP")
		return CommandText + "|" + FString::SanitizeFloat(WorldStateClass->WorldStateOutputStruct.Stop.X) + "|" +
		FString::SanitizeFloat(WorldStateClass->WorldStateOutputStruct.Stop.Y) + "|" +
		FString::SanitizeFloat(WorldStateClass->WorldStateOutputStruct.Stop.Z);

	if (CommandText == "PICK")
		return CommandText;

	if (CommandText == "THROW")
		return CommandText + "|" + FString::SanitizeFloat(WorldStateClass->WorldStateOutputStruct.Throw.Direction.X) + "|" +
		FString::SanitizeFloat(WorldStateClass->WorldStateOutputStruct.Throw.Direction.Y) + "|" +
		FString::SanitizeFloat(WorldStateClass->WorldStateOutputStruct.Throw.Direction.Z) + "|" +
		FString::SanitizeFloat(WorldStateClass->WorldStateOutputStruct.Throw.Speed) + "|" +
		FString::SanitizeFloat(WorldStateClass->WorldStateOutputStruct.Throw.Acceleration);

	if (CommandText == "HIT")
		return CommandText + "|" + FString::FromInt(WorldStateClass->WorldStateOutputStruct.HitID);

	if (CommandText == "DEATH")
		return CommandText;

	if (CommandText == "DISCONNECT")
		return CommandText;

	return "ERROR|noCommandText#2";
}
