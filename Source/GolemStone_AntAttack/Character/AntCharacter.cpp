// Fill out your copyright notice in the Description page of Project Settings.

#include "GolemStone_AntAttack.h"
#include "AntCharacter.h"



/*
AAntCharacter::AAntCharacter(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	UCapsuleComponent* MyCapsule = CreateDefaultSubobject<UCapsuleComponent>(ACharacter::CapsuleComponentName);
}
*/


// Sets default values
AAntCharacter::AAntCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UCapsuleComponent* MyCapsule = CreateDefaultSubobject<UCapsuleComponent>(ACharacter::CapsuleComponentName);
	MyCapsule->InitCapsuleSize(34.0f, 50.0f);
	APhysicsVolume* CapsulePhysicsVolume;
	CapsulePhysicsVolume = MyCapsule->GetPhysicsVolume();
	//CapsulePhysicsVolume->SetPrePivot(FVector(0.0,0.0,0.0));
	MyCapsule->SetPhysicsVolume(CapsulePhysicsVolume, true);
	RootComponent = MyCapsule;
}

// Called when the game starts or when spawned
void AAntCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAntCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AAntCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

