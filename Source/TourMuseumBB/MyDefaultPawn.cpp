// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDefaultPawn.h"

// Sets default values
AMyDefaultPawn::AMyDefaultPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize default components
	//SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
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
void AMyDefaultPawn::BeginPlay()
{
	Super::BeginPlay();

	SetupNewItem();
}

// Called every frame
void AMyDefaultPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyDefaultPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (PlayerInputComponent)
	{
		PlayerInputComponent->BindAxis("Zoom", this, &AMyDefaultPawn::Zoom);
		PlayerInputComponent->BindAxis("MouseRotatorX", this, &AMyDefaultPawn::SceneRotator);
		PlayerInputComponent->BindAction("MouseHoldToRotate", IE_Pressed, this, &AMyDefaultPawn::LeftMouseButtonPressed);
		PlayerInputComponent->BindAction("MouseHoldToRotate", IE_Released, this, &AMyDefaultPawn::LeftMouseButtonReleased);
	}
		
}

void AMyDefaultPawn::Zoom(float Value)
{

	SpringArm->TargetArmLength += 10.f * Value;
	
}

void AMyDefaultPawn::LeftMouseButtonPressed()
{
	bHoldLeftMouseButton = true;
}

void AMyDefaultPawn::LeftMouseButtonReleased()
{
	bHoldLeftMouseButton = false;
}

void AMyDefaultPawn::SceneRotator(float Value)
{

	if (bHoldLeftMouseButton) {
		AddControllerYawInput(Value);
	}

	
}

void AMyDefaultPawn::NextItem()
{

	if (ItemList.IsValidIndex(CurrentItem + 1))
	{
		CurrentItem++;
	}
	else
	{
		CurrentItem = 0;
	}

	SetupNewItem();
}

void AMyDefaultPawn::PreviousItem()
{
	if (ItemList.IsValidIndex(CurrentItem - 1))
	{
		CurrentItem--;
	}
	else
	{
		CurrentItem = ItemList.Max() - 1;
	}

	SetupNewItem();
}

void AMyDefaultPawn::SetupNewItem()
{
	ItemMesh->SetStaticMesh(ItemList[CurrentItem]);
	ItemMesh->SetWorldScale3D(FVector(ItemScale[CurrentItem]));
	OnItemChangeDelegate.Broadcast(ItemDescription[CurrentItem]);
}
