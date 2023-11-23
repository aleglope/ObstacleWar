// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"//incluimos el header de la clase

// Sets default values
AMovingPlatform::AMovingPlatform()//llamamos al constructor de la clase padre
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()//llamamos a la funcion beginplay cuando empieza el juego
{
	Super::BeginPlay();//llamamos a la funcion beginplay de la clase padre

	StartLocation = GetActorLocation();//guardamos la localizacion inicial de la plataforma
}
// Called every frame
void AMovingPlatform::Tick(float DeltaTime)//llamamos a la funcion tick cada frame
{
	Super::Tick(DeltaTime);//llamamos a la funcion tick cada frame

	MovePlatform(DeltaTime);//movemos la plataforma
	RotatePlatform(DeltaTime);//rotamos la plataforma	
}
void AMovingPlatform::MovePlatform(float DeltaTime)//movemos la plataforma
{

	if (ShouldPlatformReturn())  //si la plataforma se ha movido mas de la distancia que le hemos indicado, la hacemos volver
	{	
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();    //normalizamos el vector de velocidad para que solo nos de la direccion en la que se mueve
		StartLocation = StartLocation + (MoveDirection * PlatformDistance); //actualizamos la localizacion de la plataforma
		SetActorLocation(StartLocation);//actualizamos la localizacion del actor
		PlatformVelocity = -PlatformVelocity; //cambiamos la direccion de la velocidad para que vuelva
	}
	else
	{
		FVector CurrentLocation = GetActorLocation();       //aqui actualizamos la localizacion del actor
	    CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);//aqui actualizamos la localizacion del actor
		SetActorLocation(CurrentLocation);//aqui actualizamos la localizacion del actor

	}

}
void AMovingPlatform::RotatePlatform(float DeltaTime)//rotamos la plataforma
{
	AddActorLocalRotation(RotationVelocity * DeltaTime);//rotamos la plataforma
}
bool AMovingPlatform::ShouldPlatformReturn() const//comprobamos si la plataforma se ha movido mas de la distancia que le hemos indicado
{	
	return GetDistanceMoved() > PlatformDistance;//comprobamos si la plataforma se ha movido mas de la distancia que le hemos indicado
}
float AMovingPlatform::GetDistanceMoved() const//calculamos la distancia que se ha movido la plataforma
{
	return FVector::Dist(StartLocation, GetActorLocation());//calculamos la distancia que se ha movido la plataforma
}