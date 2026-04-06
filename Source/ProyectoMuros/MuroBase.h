// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MuroBase.generated.h"

UCLASS()
class PROYECTOMUROS_API AMuroBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMuroBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// La malla del muro (el cubo que veremos)
	UPROPERTY(VisibleAnywhere, Category = "Componentes")
	UStaticMeshComponent* MallaMuro;

	// Función para cambiar el color del muro
	void SetColorMuro(FLinearColor NuevoColor);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Función virtual para que los hijos puedan tener comportamientos diferentes (Polimorfismo)
	virtual void ComportamientoMuro();
};