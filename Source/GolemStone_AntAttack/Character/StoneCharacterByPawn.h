// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "StoneCharacterByPawn.generated.h"

UCLASS()
class GOLEMSTONE_ANTATTACK_API AStoneCharacterByPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AStoneCharacterByPawn();

	UPROPERTY(Category = CustomCharacter, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* Mesh;
	UPROPERTY()
	class UArrowComponent* ArrowComponent;
	UPROPERTY(Category = CustomCharacter, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCharacterMovementComponent* CharacterMovement;
	UPROPERTY(Category = CustomCharacter, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComponent;

	UPROPERTY(Category = CustomCharacter, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCharacterMovementComponent* CharacterMovementCustom;

	/** Default crouched eye height */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		float CrouchedEyeHeight;

	//returns
	/** Returns Mesh subobject **/
	class USkeletalMeshComponent* GetMesh() const;
	/** Returns ArrowComponent subobject **/
	class UArrowComponent* GetArrowComponent() const;
	/** Returns CharacterMovement subobject **/
	class UCharacterMovementComponent* GetCharacterMovement() const;
	/** Returns CapsuleComponent subobject **/
	class UCapsuleComponent* GetCapsuleComponent() const;

	// Begin APawn Interface.
	virtual void PostInitializeComponents() override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	
};
