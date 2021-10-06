// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "MyDefaultPawn.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemChangeDelegate, FString, ItemDescription);

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class TOURMUSEUMBB_API AMyDefaultPawn : public ADefaultPawn
{
	GENERATED_BODY()
	
public:
	// Sets default values for this pawn's properties
	AMyDefaultPawn();
	
	/** Camera Boom */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class USpringArmComponent* SpringArm;

	/** Camera */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UCameraComponent* PlayerCamera;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UStaticMeshComponent* SuportMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UStaticMeshComponent* ItemMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Itens")
	TArray<UStaticMesh*> ItemList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Itens")
	TArray<FString> ItemDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Itens")
	TArray<float> ItemScale;

	int32 CurrentItem = 0;
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zoom")
	float MinZoom = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zoom")
	float MaxZoom = 1000;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zoom")
	float SpeedZoom = 100;
	// Zoom
	void Zoom(float Value);

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	bool bHoldLeftMouseButton = false;
	
	void LeftMouseButtonPressed();
	void LeftMouseButtonReleased();

	
	void SceneRotator(float Value);

	
	UFUNCTION(BlueprintCallable)
	void NextItem();

	UFUNCTION(BlueprintCallable)
	void PreviousItem();

	void SetupNewItem();

	UPROPERTY(BlueprintAssignable)
	FOnItemChangeDelegate OnItemChangeDelegate;
};
