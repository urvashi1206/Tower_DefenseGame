// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OnboardingManager.generated.h"

UCLASS()
class SURVIVALBUILDER_API AOnboardingManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOnboardingManager();
	virtual void Tick(float DeltaTime) override;
	void ProgressOnboarding(int32 curState);
	
	UPROPERTY(VisibleAnywhere)
	int32 CurrentState = 0;
	UPROPERTY(EditAnywhere)
	UUserWidget* OnboardingWidget;
	UPROPERTY(EditAnywhere)
	UUserWidget* PlayerUI;

	UPROPERTY(EditAnywhere)
	class UButton* WallBtn;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

};
