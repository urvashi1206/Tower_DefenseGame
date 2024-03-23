// Fill out your copyright notice in the Description page of Project Settings.


#include "GridManager.h"
#include "GridCell.h"
#include "DrawDebugHelpers.h"

// Sets default values
AGridManager::AGridManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GridMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GridMesh"));
}

void AGridManager::ConstructGrid()
{
	FVector GridStart = FVector(GetActorLocation().X - (NumberOfCells * CellSize)/2, GetActorLocation().Y - (NumberOfCells * CellSize)/2, 0);
	for(int32 i = 0; i < NumberOfCells; i++)
	{
		GridCells.Add(TArray<FGridCell*>());
		for(int32 j = 0; j < NumberOfCells; j++)
		{
			FGridCell* GridCell = new FGridCell(GridStart + FVector( i * CellSize + CellSize/2, j * CellSize + CellSize/2, 0));
			GridCells[i].Add(GridCell);
		}
	}
	
	//GridMesh->SetWorldScale3D(FVector(NumberOfCells * CellSize/100, NumberOfCells * CellSize/100, 0));
}

FGridCell* AGridManager::ConvertWorldPosToCell(FVector WorldPos)
{
	FVector GridStart = FVector(GetActorLocation().X - (NumberOfCells * CellSize)/2, GetActorLocation().Y - (NumberOfCells * CellSize)/2, 0);
	FVector LocalPos = WorldPos - GridStart;

	int32 ColIndex = FMath::Clamp((LocalPos.X/CellSize), 0, NumberOfCells - 1);
	int32 RowIndex = FMath::Clamp((LocalPos.Y/CellSize), 0, NumberOfCells - 1);

	return GridCells[ColIndex][RowIndex];
}

// Called when the game starts or when spawned
void AGridManager::BeginPlay()
{
	Super::BeginPlay();

	ConstructGrid();
}


// Called every frame
void AGridManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(bDrawDebugCenters)
		DebugDrawCellCenters();
}


/*
 * Blueprint callable functions
 */

FVector AGridManager::GetCellPosFromWorldPos(FVector WorldPos)
{
	return ConvertWorldPosToCell(WorldPos)->centerPos;
}

bool AGridManager::IsCellEmpty(FVector WorldPos)
{
	return ConvertWorldPosToCell(WorldPos)->bIsEmpty;
}

void AGridManager::SetIsCellEmpty(FVector WorldPos, bool bIsEmpty)
{
	ConvertWorldPosToCell(WorldPos)->bIsEmpty = bIsEmpty;
}


void AGridManager::DebugDrawCellCenters()
{
	for(int32 i = 0; i < NumberOfCells; i++)
	{
		for(int32 j = 0; j < NumberOfCells; j++)
		{
			UWorld* World = GetWorld();
			if(!World) return;
			
			DrawDebugSphere(World, GridCells[i][j]->centerPos, 100, 16, FColor::Red);
		}
	}
}

