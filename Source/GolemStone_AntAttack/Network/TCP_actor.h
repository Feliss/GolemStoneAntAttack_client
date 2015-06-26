// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Networking.h"
#include "TCP_actor.generated.h"


UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class ETCP_Type : uint8
{
	TCP_Server UMETA(DisplayName = "TCP_Server"),
	TCP_Client UMETA(DisplayName = "TCP_Client"),
};



UCLASS()
class GOLEMSTONE_ANTATTACK_API ATCP_actor : public AActor
{
	GENERATED_BODY()
	
public:	
	FSocket* Socket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TCP_Type)
		ETCP_Type TCP_Type;

	UFUNCTION(BlueprintCallable, Category = TCP_connection)
		bool ConnectToTCP(FString IPAdress, int32 Port);

	UFUNCTION(BlueprintCallable, Category = TCP_message)
		bool SendTCPMessage(FString TCPMessage);
	UFUNCTION(BlueprintCallable, Category = TCP_message)
		FString GetTCPMessage();


	FString BinaryArrayToString(const TArray<uint8>& BinaryArray);

	
	ATCP_actor(); // Sets default values for this actor's properties
	virtual void BeginPlay() override; // Called when the game starts or when spawned
	virtual void Tick( float DeltaSeconds ) override; // Called every frame
};
