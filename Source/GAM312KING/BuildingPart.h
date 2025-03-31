#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "BuildingPart.generated.h" 

UCLASS()
class GAM312KING_API ABuildingPart : public AActor
{
	GENERATED_BODY()

public:
	ABuildingPart();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	UArrowComponent* PivotArrow;
};


