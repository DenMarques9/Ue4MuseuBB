// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "MyPawn.generated.h"

UCLASS()
class TOURMUSEUMBB_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class USceneComponent* SceneComponent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UStaticMeshComponent* SuportMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UStaticMeshComponent* ItemMesh;
	
	/** Camera Boom */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class USpringArmComponent* SpringArm;

	/** Camera */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UCameraComponent* PlayerCamera;
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
