// Fill out your copyright notice in the Description page of Project Settings.


#include "RollaBallItemBase.h"
#include "MyProject/Game/RollaBallPlayer.h"
#include "MyProject/Game/RollaBallGameModeBase.h"

// Sets default values
ARollaBallItemBase::ARollaBallItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create components
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	// Components configuration
	RootComponent = Mesh;

}

// Called when the game starts or when spawned
void ARollaBallItemBase::BeginPlay()
{
	Super::BeginPlay();

	// Event binding
	Mesh->OnComponentBeginOverlap.AddDynamic(this, &ARollaBallItemBase::OverlapBegin);
	
}

void ARollaBallItemBase::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (Cast<ARollaBallPlayer>(OtherActor) != nullptr)
	{
		Collected();
	}
}

void ARollaBallItemBase::Collected_Implementation()
{
	ARollaBallGameModeBase* GameMode = Cast<ARollaBallGameModeBase>(GetWorld()->GetAuthGameMode());

	if(GameMode)
	{
		GameMode->ItemCollected();
	}
}