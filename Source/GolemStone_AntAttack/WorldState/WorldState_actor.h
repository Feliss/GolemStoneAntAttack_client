// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Parse/AntAttackParse.h"
#include "Network/TCP_actor.h"
#include "WorldState_actor.generated.h"

UCLASS()
class GOLEMSTONE_ANTATTACK_API AWorldState_actor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WorldState)
		bool isShowTCPLog = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WorldState)
		bool isShowInputLog = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WorldState)
		bool ShowSendMessage = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WorldState)
		class UWorldState* WorldStateClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TCP_actor)
		ATCP_actor* TCP_actor;

	UFUNCTION(BlueprintCallable, Category = TCP_gameOperations)
		bool ConnectToTCP(FString IPAdress, int32 Port);
	UFUNCTION(BlueprintCallable, Category = TCP_gameOperations)
		void GetTCPValues();
	UFUNCTION(BlueprintCallable, Category = TCP_gameOperations)
		bool SendTCPValues(FString CommandSend);

	void ShowTCPLog();


	AWorldState_actor();// Sets default values for this actor's properties
	virtual void BeginPlay() override;// Called when the game starts or when spawned
	virtual void Tick( float DeltaSeconds ) override;// Called every frame

};
