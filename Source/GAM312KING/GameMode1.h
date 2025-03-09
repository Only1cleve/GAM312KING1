#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameMode1.generated.h"

UCLASS()
class GAM312KING_API AGameMode1 : public AGameModeBase
{
    GENERATED_BODY()

public:
    AGameMode1();

protected:
    virtual void BeginPlay() override;

public:
    /** Function to handle player death */
    void PlayerDied(AController* PlayerController);

    /** Function to respawn the player (if applicable) */
    void RespawnPlayer(AController* PlayerController);
};
