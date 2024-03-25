// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridManager.generated.h"

class FGridCell;

UCLASS()
class SURVIVALBUILDER_API AGridManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridManager();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* GridMesh;
	UPROPERTY(EditAnywhere)
	float NumberOfCells = 10.f;
	UPROPERTY(EditAnywhere)
	float CellSize = 1000.f;
	UPROPERTY(EditAnywhere)
	bool bDrawDebugCenters = false;

	void ConstructGrid();
	FGridCell* ConvertWorldPosToCell(FVector WorldPos);
	
	UFUNCTION(BlueprintCallable)
	FVector GetCellPosFromWorldPos(FVector WorldPos);
	UFUNCTION(BlueprintCallable)
	bool IsCellEmpty(FVector WorldPos);
	UFUNCTION(BlueprintCallable)
	void SetIsCellEmpty(FVector WorldPos, bool bIsEmpty);

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> TownHall;

	void PlaceTownHall();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void DebugDrawCellCenters();
	TArray<TArray<FGridCell*>> GridCells;

public:	

	

};
