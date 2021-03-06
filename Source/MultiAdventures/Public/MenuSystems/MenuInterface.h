// Copyright (C) 2019 Yernar Aldabergenov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MenuInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMenuInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MULTIADVENTURES_API IMenuInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void HostGame(const FString& HostName = UnspecifiedHostName) = 0;
	virtual void JoinGame(uint32 ServerIndex) = 0;
	virtual void QuitToMainMenu() = 0;
	virtual void QuitFromMainMenu() = 0;
	virtual void RefreshServers() = 0;

	const static FString UnspecifiedHostName;
};
