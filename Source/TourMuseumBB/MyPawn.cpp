// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"



// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize default components
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	SuportMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Suport"));
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Item"));

	//Defauts settings for ibheriting controller rotation
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationYaw = false;
	
    // Setup SpringAmr
	SpringArm->SetupAttachment(RootComponent);

	PlayerCamera->SetupAttachment(SpringArm);
	SuportMesh->SetupAttachment(RootComponent);
	ItemMesh->SetupAttachment(RootComponent);
	
	
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

