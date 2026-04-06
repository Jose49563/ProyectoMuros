// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MuroBase.h"
#include "MuroTrampa.generated.h"

/**
 * 
 */
UCLASS()
class PROYECTOMUROS_API AMuroTrampa : public AMuroBase
{
	GENERATED_BODY()

public:
    AMuroTrampa();

protected:
    virtual void BeginPlay() override;

    // Función para cambiar el estado del muro
    void AlternarEstado();

    FTimerHandle TimerHandle_Trampa;

    UPROPERTY(EditAnywhere, Category = "Trampa")
    float TiempoIntervalo;

    bool bEsVisible;
	
};
