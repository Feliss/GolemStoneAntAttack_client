// Fill out your copyright notice in the Description page of Project Settings.

#include "GolemStone_AntAttack.h"
#include "StoneCharacterByPawn.h"


// Sets default values
AStoneCharacterByPawn::AStoneCharacterByPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Capsule
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(ACharacter::CapsuleComponentName);
	CapsuleComponent->InitCapsuleSize(34.0f, 88.0f);
	static FName CollisionProfileName(TEXT("Pawn"));
	CapsuleComponent->SetCollisionProfileName(CollisionProfileName);
	CapsuleComponent->CanCharacterStepUpOn = ECB_No;
	CapsuleComponent->bShouldUpdatePhysicsVolume = true;
	CapsuleComponent->bCheckAsyncSceneOnMove = false;
	CapsuleComponent->bCanEverAffectNavigation = false;
	CapsuleComponent->bDynamicObstacle = true;
	RootComponent = CapsuleComponent;

	// Arrow
	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	if (ArrowComponent)
	{
		ArrowComponent->ArrowColor = FColor(150, 200, 255);
		ArrowComponent->bTreatAsASprite = true;
		//ArrowComponent->SpriteInfo.Category = ID_Characters;
		//ArrowComponent->SpriteInfo.DisplayName = NAME_Characters;
		ArrowComponent->AttachParent = CapsuleComponent;
		ArrowComponent->bIsScreenSizeScaled = true;
	}
	
	// Character Movement
	CharacterMovementCustom = CreateDefaultSubobject<UCharacterMovementComponent>(FName("CharacterMovementCustom"));//ACharacter::CharacterMovementComponentName
	if (CharacterMovementCustom)
	{
		CharacterMovementCustom->UpdatedComponent = CapsuleComponent;
		CrouchedEyeHeight = CharacterMovementCustom->CrouchedHalfHeight * 0.80f;
	}

	Mesh = CreateOptionalDefaultSubobject<USkeletalMeshComponent>(ACharacter::MeshComponentName);
	if (Mesh)
	{
		Mesh->AlwaysLoadOnClient = true;
		Mesh->AlwaysLoadOnServer = true;
		Mesh->bOwnerNoSee = false;
		Mesh->MeshComponentUpdateFlag = EMeshComponentUpdateFlag::AlwaysTickPose;
		Mesh->bCastDynamicShadow = true;
		Mesh->bAffectDynamicIndirectLighting = true;
		Mesh->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		Mesh->bChartDistanceFactor = true;
		Mesh->AttachParent = CapsuleComponent;
		static FName CollisionProfileName(TEXT("CharacterMesh"));
		Mesh->SetCollisionProfileName(CollisionProfileName);
		Mesh->bGenerateOverlapEvents = false;
		Mesh->bCanEverAffectNavigation = false;
	}
}


void AStoneCharacterByPawn::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (CharacterMovementCustom)
	{
		CharacterMovementCustom->SetDefaultMovementMode();
	}
}



// Called when the game starts or when spawned
void AStoneCharacterByPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStoneCharacterByPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, );

}

// Called to bind functionality to input
void AStoneCharacterByPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

/** Returns Mesh subobject **/
USkeletalMeshComponent* AStoneCharacterByPawn::GetMesh() const { return Mesh; }
/** Returns ArrowComponent subobject **/
UArrowComponent* AStoneCharacterByPawn::GetArrowComponent() const { return ArrowComponent; }
/** Returns CharacterMovement subobject **/
UCharacterMovementComponent* AStoneCharacterByPawn::GetCharacterMovement() const { return CharacterMovementCustom; }
/** Returns CapsuleComponent subobject **/
UCapsuleComponent* AStoneCharacterByPawn::GetCapsuleComponent() const { return CapsuleComponent; }