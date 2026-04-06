// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroMovil.h"

AMuroMovil::AMuroMovil()
{
    Velocidad = 200.0f;
    Direccion = FVector(0.f, 1.f, 0.f); // Se mueve en el eje Y por defecto
    LimiteDistancia = 500.0f;
    DistanciaRecorrida = 0.0f;
}

void AMuroMovil::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime); // Ejecuta lo del padre si tuviera algo

    // Calculamos el desplazamiento de este frame
    FVector Desplazamiento = Direccion * Velocidad * DeltaTime;

    // Movemos el actor
    AddActorWorldOffset(Desplazamiento);

    // Lógica para que rebote
    DistanciaRecorrida += Desplazamiento.Size();

    if (DistanciaRecorrida >= LimiteDistancia)
    {
        Direccion *= -1; // Invierte el sentido
        DistanciaRecorrida = 0.0f;
    }
}

//asignamos color al hijo
void AMuroMovil::BeginPlay()
{
    Super::BeginPlay();
    SetColorMuro(FLinearColor::Blue); // Los móviles serán azules
}

