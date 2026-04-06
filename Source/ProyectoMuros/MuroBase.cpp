// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroBase.h"

// Sets default values
AMuroBase::AMuroBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Creamos el componente de malla
    MallaMuro = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaMuro"));
    RootComponent = MallaMuro;

    // Buscamos un cubo básico de Unreal para no tener que asignarlo a mano siempre
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CuboMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
    if (CuboMesh.Succeeded())
    {
        MallaMuro->SetStaticMesh(CuboMesh.Object);
    }

}

// Called when the game starts or when spawned
void AMuroBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMuroBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMuroBase::ComportamientoMuro()
{
    // Aquí irá la lógica base si es necesario
}

//funcion para implementar color
void AMuroBase::SetColorMuro(FLinearColor NuevoColor)
{
    if (MallaMuro)
    {
        // Creamos un material dinámico basado en el que ya tiene el cubo
        UMaterialInstanceDynamic* DynMaterial = MallaMuro->CreateDynamicMaterialInstance(0);
        if (DynMaterial)
        {
            // "Color" es el nombre del parámetro en los materiales básicos de Unreal
            DynMaterial->SetVectorParameterValue(TEXT("Color"), NuevoColor);
        }
    }
}