#include "GameMode1.h"
#include "PlayerChar.h" // Your custom player character
#include "Kismet/GameplayStatics.h"

AGameMode1::AGameMode1()
{
    // Set default player character
    DefaultPawnClass = APlayerChar::StaticClass();
}

void AGameMode1::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("Survival Game Mode Initialized"));
}

void AGameMode1::PlayerDied(AController* PlayerController)
{
    if (PlayerController)
    {
        UE_LOG(LogTemp, Warning, TEXT("Player has died!"));

        // Optionally respawn the player after a delay (if survival allows it)
        FTimerHandle RespawnTimer;
        GetWorldTimerManager().SetTimer(RespawnTimer, FTimerDelegate::CreateUObject(this, &AGameMode1::RespawnPlayer, PlayerController), 5.0f, false);
    }
}

void AGameMode1::RespawnPlayer(AController* PlayerController)
{
    if (PlayerController)
    {
        UE_LOG(LogTemp, Warning, TEXT("Respawning Player..."));

        // Get a random spawn point
        TArray<AActor*> SpawnPoints;
        UGameplayStatics::GetAllActorsWithTag(GetWorld(), "PlayerSpawn", SpawnPoints);

        if (SpawnPoints.Num() > 0)
        {
            AActor* SpawnLocation = SpawnPoints[FMath::RandRange(0, SpawnPoints.Num() - 1)];
            APlayerChar* NewPlayer = GetWorld()->SpawnActor<APlayerChar>(DefaultPawnClass, SpawnLocation->GetActorLocation(), SpawnLocation->GetActorRotation());

            if (NewPlayer)
            {
                PlayerController->Possess(NewPlayer);
            }
        }
    }
}
