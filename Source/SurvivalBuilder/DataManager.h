// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DataManager.generated.h"

class FJsonObject;

USTRUCT(BlueprintType)
struct FSaveData
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int DaysSurvived;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int WallsPlaced;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int MillsPlaced;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int OutpostsPlaced;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int TotalSugarBought;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int TotalMoneySpent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int TotalRepairs;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int TotalUpgrades;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int TotalDestroyed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int GummiesKilled;
};


/**
 * 
 */
UCLASS()
class SURVIVALBUILDER_API UDataManager : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
		UFUNCTION(BlueprintCallable)
		static FString GenerateUUID();

		UFUNCTION(BlueprintCallable)
		static void WriteSaveDataToJsonFile(FString JsonFilePath, FSaveData Data, bool& bOutSuccess, FString& OutInfoMessage);
public:
		static void WriteStringToFile(FString FilePath, FString String, bool& bOutSuccess, FString& OutInfoMessage);
		static void WriteJson(FString JsonFilePath, TSharedPtr<FJsonObject> JsonObject, bool& bOutSuccess, FString& OutInfoMessage);
};
