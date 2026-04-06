// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroDinamico.h"
#include "TimerManager.h"

AMuroDinamico::AMuroDinamico()
{
	PrimaryActorTick.bCanEverTick = false;
	ExtensionesActuales = 0;
	MaxExtensiones = 5; // Crecerá 5 veces
}

void AMuroDinamico::BeginPlay()
{
	Super::BeginPlay();

	// Color Amarillo para identificarlo
	SetColorMuro(FLinearColor::Yellow);

	// Iniciamos el temporizador: Cada 3 segundos llama a ExtenderMuro
	GetWorldTimerManager().SetTimer(TemporizadorExtension, this, &AMuroDinamico::ExtenderMuro, 3.0f, true);
}

void AMuroDinamico::ExtenderMuro()
{
	if (ExtensionesActuales < MaxExtensiones)
	{
		// Obtenemos la escala actual
		FVector EscalaActual = GetActorScale3D();

		// Aumentamos el largo (Y) en 1.0 cada vez que se llama
		EscalaActual.Y += 1.0f;

		SetActorScale3D(EscalaActual);

		ExtensionesActuales++;

		// Log para que el profe vea que el código corre
		UE_LOG(LogTemp, Warning, TEXT("Muro Divisor generando nueva sección. Extensión: %d"), ExtensionesActuales);
	}
	else
	{
		// Si ya creció lo suficiente, detenemos el timer
		GetWorldTimerManager().ClearTimer(TemporizadorExtension);
	}
}
