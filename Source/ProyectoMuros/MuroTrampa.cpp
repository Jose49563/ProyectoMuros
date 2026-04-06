// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroTrampa.h"

AMuroTrampa::AMuroTrampa()
{
    TiempoIntervalo = 2.0f; // Cambia cada 2 segundos
    bEsVisible = true;
}

void AMuroTrampa::BeginPlay()
{
    Super::BeginPlay();

    // Iniciamos un temporizador que llama a AlternarEstado repetidamente
    GetWorldTimerManager().SetTimer(TimerHandle_Trampa, this, &AMuroTrampa::AlternarEstado, TiempoIntervalo, true);

    //asignamos color al hijo
    SetColorMuro(FLinearColor::Red); // Las trampas serán rojas
}

void AMuroTrampa::AlternarEstado()
{
    bEsVisible = !bEsVisible;

    // Usamos MallaMuro que heredamos de MuroBase
    if (MallaMuro)
    {
        MallaMuro->SetHiddenInGame(!bEsVisible); // Lo hace invisible
        MallaMuro->SetCollisionEnabled(bEsVisible ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision); // Quita colisión
    }
}


