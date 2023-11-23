// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"//incluimos el core de unreal
#include "GameFramework/Actor.h"//incluimos la clase AActor
#include "MovingPlatform.generated.h"//generamos el cuerpo de la clase

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor//heredamos de la clase AActor
{
	GENERATED_BODY()//generamos el cuerpo de la clase
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();//llamamos al constructor de la clase padre

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;//llamamos a la funcion tick cada frame

private:	

	UPROPERTY(EditAnywhere, Category="Moving") //velocidad de la plataforma
	FVector PlatformVelocity = FVector(100, 0, 0);//velocidad de la plataforma
	UPROPERTY(EditAnywhere, Category="Moving")//distancia que se mueve la plataforma 
	float PlatformDistance = 100;//distancia que se mueve la plataforma
	UPROPERTY(EditAnywhere, Category="Rotation")//velocidad de rotacion de la plataforma
	FRotator RotationVelocity;//velocidad de rotacion de la plataforma
	
	FVector StartLocation;//localizacion inicial de la plataforma

	void MovePlatform(float DeltaTime);//movemos la plataforma							
	void RotatePlatform(float DeltaTime);//rotamos la plataforma

	bool ShouldPlatformReturn() const;//comprobamos si la plataforma se ha movido mas de la distancia que le hemos indicado
	float GetDistanceMoved() const;//calculamos la distancia que se ha movido la plataforma
};
