// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProyectoMurosGameMode.h"
#include "ProyectoMurosPawn.h"

AProyectoMurosGameMode::AProyectoMurosGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AProyectoMurosPawn::StaticClass();
}

