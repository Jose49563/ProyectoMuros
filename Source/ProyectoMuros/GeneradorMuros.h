// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MuroBase.h" // Importante incluir la base
#include "GeneradorMuros.generated.h"

UCLASS()
class PROYECTOMUROS_API AGeneradorMuros : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGeneradorMuros();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// El contenedor que pidió el profesor
	UPROPERTY(VisibleAnywhere, Category = "Datos")
	TArray<AMuroBase*> ListaDeMuros;

	// Función para crear un muro aleatorio
	void SpawnMuroAleatorio();

	UPROPERTY(EditAnywhere, Category = "Configuracion")
	int32 CantidadMuros;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
