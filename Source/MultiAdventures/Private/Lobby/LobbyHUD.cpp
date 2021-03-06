// Copyright (C) 2019 Yernar Aldabergenov. All Rights Reserved.


#include "LobbyHUD.h"
#include "MultiPlayerState.h"

#include "Engine/Font.h"

ALobbyHUD::ALobbyHUD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UFont> FredokaFontObject(TEXT("/Game/MenuSystem/Fonts/FredokaOne-Regular_Font"));
	FredokaFont = (FredokaFontObject.Object ? FredokaFontObject.Object : nullptr);
}

void ALobbyHUD::DrawHUD()
{
	if (GetOwningPlayerController() && Cast<AMultiPlayerState>(GetOwningPlayerController()->PlayerState))
	{
		APlayerController* APC = GetOwningPlayerController();
		AMultiPlayerState* AMPS = Cast<AMultiPlayerState>(APC->PlayerState);
		EPlayerReadinessStatus PlayerStatus = AMPS->PlayerReadinessStatus;

		FString StatusText;
		FLinearColor TextColor;

		switch (PlayerStatus)
		{
			case EPlayerReadinessStatus::NOT_ENOUGH_PLAYERS:
				StatusText = "Not Enough Players";
				TextColor = FLinearColor::Gray;
				break;

			case EPlayerReadinessStatus::NOT_READY:
				StatusText = "Not Ready";
				TextColor = FLinearColor::Red;
				break;

			case EPlayerReadinessStatus::READY:
				StatusText = "Ready";
				TextColor = FLinearColor::Green;
				break;
		}

		DrawText("Press R to Toggle Your Status: ", FLinearColor::Blue, 10.f, 10.f, FredokaFont, 2.f);
		DrawText(StatusText, TextColor, 375.f, 10.f, FredokaFont, 2.f);
	}
}