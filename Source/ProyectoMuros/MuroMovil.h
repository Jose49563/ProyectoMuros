// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MuroBase.h"
#include "MuroMovil.generated.h"

/**
 * 
 */
UCLASS()
class PROYECTOMUROS_API AMuroMovil : public AMuroBase
{
	GENERATED_BODY()

public:
    AMuroMovil();

    // Sobrescribimos la función del padre (Polimorfismo)
    virtual void Tick(float DeltaTime) override;
     //para color
    virtual void BeginPlay() override;

protected:
    // Variables para el movimiento
    UPROPERTY(EditAnywhere, Category = "Movimiento")
    float Velocidad;

    UPROPERTY(EditAnywhere, Category = "Movimiento")
    FVector Direccion;

    float DistanciaRecorrida;

    UPROPERTY(EditAnywhere, Category = "Movimiento")
    float LimiteDistancia;
};