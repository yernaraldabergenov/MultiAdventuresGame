// Copyright (C) 2019 Yernar Aldabergenov. All Rights Reserved.


#include "PlatformsGameInstance.h"
#include "PlatformTrigger.h"
#include "MainMenu.h"
#include "GameMenu.h"

#include "Blueprint/UserWidget.h"

UPlatformsGameInstance::UPlatformsGameInstance(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> WBP_MainMenuClass(TEXT("/Game/MenuSystem/Widgets/WBP_MainMenu"));
	MainMenuClass = (WBP_MainMenuClass.Class ? WBP_MainMenuClass.Class : nullptr);

	ConstructorHelpers::FClassFinder<UUserWidget> WBP_GameMenuClass(TEXT("/Game/MenuSystem/Widgets/WBP_GameMenu"));
	GameMenuClass = (WBP_GameMenuClass.Class ? WBP_GameMenuClass.Class : nullptr);
}

void UPlatformsGameInstance::Init()
{

}

void UPlatformsGameInstance::HostGame()
{
	if (!GetEngine())
		return;

	if (MainMenuWidget)
		MainMenuWidget->TeardownMainMenu();

	GetEngine()->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("Hosting"));
	if (GetWorld()->ServerTravel("/Game/Maps/MainLevel?listen"))
		GetEngine()->AddOnScreenDebugMessage(-1, 1.5f, FColor::Green, FString::Printf(TEXT("Hosted the session")));
}

void UPlatformsGameInstance::JoinGame(const FString& Address)
{
	if (!GetEngine())
		return;

	if (MainMenuWidget)
		MainMenuWidget->TeardownMainMenu();

	GetPrimaryPlayerController()->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
	GetEngine()->AddOnScreenDebugMessage(-1, 1.5f, FColor::Green, FString::Printf(TEXT("Joining the %s"), *Address));
}

void UPlatformsGameInstance::QuitToMainMenu()
{
	LoadMainMenu();
}

void UPlatformsGameInstance::LoadMainMenu()
{
	MainMenuWidget = (MainMenuClass ? CreateWidget<UMainMenu>(this, MainMenuClass) : nullptr);

	if (MainMenuWidget)
	{
		MainMenuWidget->SetMenuInterface(this);
		MainMenuWidget->SetupMainMenu();
	}
}

void UPlatformsGameInstance::LoadGameMenu()
{
	GameMenuWidget = (GameMenuClass ? CreateWidget<UGameMenu>(this, GameMenuClass) : nullptr);

	if (GameMenuWidget)
	{
		GameMenuWidget->SetMenuInterface(this);
		GameMenuWidget->SetupGameMenu();
	}
}
