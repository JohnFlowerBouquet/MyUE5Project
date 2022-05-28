// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RollaBallItemBase.generated.h"

UCLASS()
class MYPROJECT_API ARollaBallItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARollaBallItemBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
