// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneradorMuros.h"
#include "MuroMovil.h"
#include "MuroTrampa.h"
#include "MuroDinamico.h"
#include "Engine/World.h"

// Sets default values
AGeneradorMuros::AGeneradorMuros()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CantidadMuros = 20; // Valor por defecto

}

// Called when the game starts or when spawned
void AGeneradorMuros::BeginPlay()
{
	Super::BeginPlay();

	for (int32 i = 0; i < CantidadMuros; i++)
	{
		SpawnMuroAleatorio();
	}
	
}

// Called every frame
void AGeneradorMuros::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGeneradorMuros::SpawnMuroAleatorio()
{
    // 1. Ubicación (Lo que ya tenías en tu foto)
    FVector UbicacionAleatoria = FVector(FMath::RandRange(-1800.f, 1800.f), FMath::RandRange(-1800.f, 1800.f), 100.f);
    FRotator Rotacion = FRotator::ZeroRotator;

    AMuroBase* NuevoMuro = nullptr;

    // 2. DECISIÓN: Ahora elegimos entre 3 números (0, 1 o 2)
    int32 TipoAleatorio = FMath::RandRange(0, 2);

    if (TipoAleatorio == 0)
    {
        // Caso 0: Creamos el Móvil (Azul)
        NuevoMuro = GetWorld()->SpawnActor<AMuroMovil>(AMuroMovil::StaticClass(), UbicacionAleatoria, Rotacion);
    }
    else if (TipoAleatorio == 1)
    {
        // Caso 1: Creamos la Trampa (Rojo)
        NuevoMuro = GetWorld()->SpawnActor<AMuroTrampa>(AMuroTrampa::StaticClass(), UbicacionAleatoria, Rotacion);
    }
    else
    {
        // Caso 2: Creamos tu nuevo MuroDinamico (Amarillo/Extensible)
        NuevoMuro = GetWorld()->SpawnActor<AMuroDinamico>(AMuroDinamico::StaticClass(), UbicacionAleatoria, Rotacion);
    }

    // 3. Configuración final (Escalas y lista)
    if (NuevoMuro)
    {
        float AnchoAleatorio = FMath::RandRange(1.0f, 2.5f);
        float LargoAleatorio = FMath::RandRange(2.0f, 6.0f);
        float AltoAleatorio = FMath::RandRange(2.0f, 4.0f);

        NuevoMuro->SetActorScale3D(FVector(AnchoAleatorio, LargoAleatorio, AltoAleatorio));

        // IMPORTANTE: Esto cumple con el requisito del contenedor del examen
        ListaDeMuros.Add(NuevoMuro);
    }
}