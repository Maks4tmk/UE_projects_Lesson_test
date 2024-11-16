// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CppBase.h"
#include "TimerManager.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppHubActor.generated.h"


UCLASS()
class LESSON_TEST_API ACppHubActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppHubActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float SpawnTimerRate = 2.0f;

	UPROPERTY(EditAnywhere)
	float DestroyTimerRate = 1.0f;

	UPROPERTY()
	TArray<ACppBase*> SpawnedObjects;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ACppBase> CppClass;

private:
	FTimerHandle SpawnTimerHandle;
	FTimerHandle DestroyTimerHandle;

	const int32 TotalTimerCount = 10;
	int32 CurrentTimerCount = 0;

	void OnTimeToSpawn();
	void OnTimeToDestroy();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
