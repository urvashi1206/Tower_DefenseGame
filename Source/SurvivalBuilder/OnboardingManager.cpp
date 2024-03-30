// Fill out your copyright notice in the Description page of Project Settings.


#include "OnboardingManager.h"

#include "Blueprint/UserWidget.h"

// Sets default values
AOnboardingManager::AOnboardingManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOnboardingManager::BeginPlay()
{
	Super::BeginPlay();

	if(!OnboardingWidget) return;

	OnboardingWidget->AddToViewport();
	OnboardingWidget->SetVisibility(ESlateVisibility::Hidden);
	
}

// Called every frame
void AOnboardingManager::Tick(float DeltaTime)
{
	switch (CurrentState)
	{
		case(0):
			break;
	}
}

void AOnboardingManager::ProgressOnboarding(int32 CurState)
{
	if(CurState == CurrentState)
	{
		CurrentState++;
	}
}

