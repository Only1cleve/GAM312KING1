// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerChar.h"

// Sets default values
APlayerChar::APlayerChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Initial camera component set up
	PlayerCamComp = CreateDefaultSubobject<UCameraComponent>(TEXT("First Person Cam"));

	//Attaching camera to player head
	PlayerCamComp->SetupAttachment(GetMesh(), "head");

	//Setting camera to rotate with player's head
	PlayerCamComp->bUsePawnControlRotation = true;


}

// Called when the game starts or when spawned
void APlayerChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//Initial binding of axis controls, key mappings, and mouse x and y, as well as left
	// click to interact.
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerChar::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerChar::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerChar::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &APlayerChar::AddControllerYawInput);
	PlayerInputComponent->BindAction("JumpEvent", IE_Pressed, this, &APlayerChar::StartJump);
	PlayerInputComponent->BindAction("JumpEvent", IE_Released, this, &APlayerChar::StopJump);
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &APlayerChar::FindObject);


}

void APlayerChar::MoveForward(float axisValue)
{
	//Pressing w? Moving forward. Pressing s? Moving backwards.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, axisValue);

}

void APlayerChar::MoveRight(float axisValue)
{
	//Pressing a? Going left. Pressing d? Going right.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, axisValue);

}

void APlayerChar::StartJump()
{
	//Is spacebar pressed? Youre jumping.
	bPressedJump = true;
}

void APlayerChar::StopJump()
{
	//You stopped pressing it? No more jumping. 
	bPressedJump = false;
}

void APlayerChar::FindObject()
{
}

