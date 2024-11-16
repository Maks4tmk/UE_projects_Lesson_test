// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBase.h"

// Sets default values
ACppBase::ACppBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ACppBase::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = GetActorLocation();
}

// Called every frame
void ACppBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ACppBase::ShowInformation() {
	UE_LOG(LogTemp, Display, TEXT("Instance name: %s"), *actorName);
	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("isAlive: %i"), isAlive);
}

void ACppBase::SinMovement() {
	float FrequencyTimeProduct = Frequency * GetWorld()->GetTimeSeconds();
	float SineAmplitudeProduct = FMath::Sin(FrequencyTimeProduct) * Amplitude;
	InitialLocation.Z += SineAmplitudeProduct;
	SetActorLocation(InitialLocation);
}

