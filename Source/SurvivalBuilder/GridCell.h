// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */


class SURVIVALBUILDER_API FGridCell
{
public:
	FGridCell(FVector centerPos);
	~FGridCell();

	FVector centerPos;
	bool bIsEmpty = true;
};
