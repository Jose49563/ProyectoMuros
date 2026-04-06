// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MuroBase.h"
#include "MuroDinamico.generated.h"

/**
 * 
 */
UCLASS()
class PROYECTOMUROS_API AMuroDinamico : public AMuroBase
{
	GENERATED_BODY()
	
public:
	AMuroDinamico();

protected:
	virtual void BeginPlay() override;

	// Función para hacer crecer el muro
	void ExtenderMuro();

	FTimerHandle TemporizadorExtension;

	// Cuántas veces ha crecido
	int32 ExtensionesActuales;
	int32 MaxExtensiones;
};
