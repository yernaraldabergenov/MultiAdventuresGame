// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TP_VehicleGameMode.h"
#include "TP_VehicleHud.h"
#include "TP_VehiclePawn.h"

#include "UObject/ConstructorHelpers.h"

ATP_VehicleGameMode::ATP_VehicleGameMode()
{	
	DefaultPawnClass = ATP_VehiclePawn::StaticClass();
	HUDClass = ATP_VehicleHud::StaticClass();
}
