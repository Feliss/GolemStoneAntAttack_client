// Fill out your copyright notice in the Description page of Project Settings.

#include "GolemStone_AntAttack.h"
#include "TCP_actor.h"
#include <string>

#include "AllowWindowsPlatformTypes.h"
#include "winsock.h"
#include "HideWindowsPlatformTypes.h"

#include <windows.h>
#include <iostream>
#include "Windows/WindowsSystemIncludes.h"


// Sets default values
ATCP_actor::ATCP_actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATCP_actor::BeginPlay()
{
	Super::BeginPlay();
	
	system("cmd /c start /min start.bat"); //открывает внешний файл
}

// Called every frame
void ATCP_actor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}





//Client Connection to TCP
bool ATCP_actor::ConnectToTCP(FString IPAdress, int32 Port)
{
	if (Socket == NULL) 
	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), true); 
	Socket->Wait(ESocketWaitConditions::WaitForReadOrWrite, 0.2);
	
	FIPv4Address IPv4Address;
	bool isIPAdressParse = FIPv4Address::Parse(IPAdress, IPv4Address);

	if (!isIPAdressParse) return false;
	
	TSharedRef<FInternetAddr> InternetAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	InternetAddr->SetIp(IPv4Address.GetValue());
	InternetAddr->SetPort(Port);

	bool connected = Socket->Connect(*InternetAddr);//connect
	
	
	if (connected)
		return true;
	else
		return false;
}

//Send message
bool ATCP_actor::SendTCPMessage(FString TCPMessage)
{
	if (!Socket) return false;

	TCHAR *TCPMessageChar = TCPMessage.GetCharArray().GetData();
	int32 size = FCString::Strlen(TCPMessageChar);
	int32 sent = 0;

	bool successful = Socket->Send((uint8*)TCHAR_TO_UTF8(TCPMessageChar), size, sent);//sending message

	if (successful)
		return true;
	else
		return false;
}

//GetMessage
FString ATCP_actor::GetTCPMessage()
{
	if (!Socket) return FString("ERROR|No TCP Connection for get Message!");

	//Binary Array
	TArray<uint8> ReceivedData;

	uint32 Size;

	while (Socket->HasPendingData(Size))
	{
		ReceivedData.SetNumUninitialized(FMath::Min(Size, 65507u));
		int32 Read = 0;
		Socket->Recv(ReceivedData.GetData(), ReceivedData.Num(), Read, ESocketReceiveFlags::WaitAll);
	}

	if (ReceivedData.Num() <= 0)
	{
		return FString("ERROR|No message data!"); //No Data Received
	}

	FString ReceivedTCPString = BinaryArrayToString(ReceivedData);

	return ReceivedTCPString;
}


//Binary Array To String
FString ATCP_actor::BinaryArrayToString(const TArray<uint8>& BinaryArray)
{
	const std::string cstr(reinterpret_cast<const char*>(BinaryArray.GetData()), BinaryArray.Num()); //Create a string from a byte array!
	return FString(cstr.c_str());//FString can take in the c_str() of a std::string

}