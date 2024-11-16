// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBase.generated.h"

class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	Mobility,
	Static
};

USTRUCT(BlueprintType)
struct FTransformStruct
{

	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CurrentRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);
};

UCLASS()
class LESSON_TEST_API ACppBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACppBase();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ShowInformation();

	UPROPERTY(VisibleAnywhere)
	FString actorName = GetName();

	UPROPERTY(EditAnywhere)
	int EnemyNum = 20;

	UPROPERTY(EditAnywhere)
	bool isAlive = true;

	/*=================================*/

	UPROPERTY(EditAnywhere)
	float Amplitude = 70.0;

	UPROPERTY(EditAnywhere)
	float Frequency = 4.0;

	UPROPERTY(EditAnywhere)
	FVector InitialLocation;

	UFUNCTION(BlueprintCallable)
	void SinMovement();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
