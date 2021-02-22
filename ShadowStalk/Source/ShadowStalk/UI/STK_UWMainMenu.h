// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "STK_UserWidget.h"
#include "STK_UWMainMenu.generated.h"

/**
 * 
 */
UCLASS()
class SHADOWSTALK_API USTK_UWMainMenu : public USTK_UserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	class UButton* PlayButton = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	class UButton* OptionsButton = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	class UButton* CreditsButton = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	class UButton* QuitButton = nullptr;

protected:

	virtual bool Initialize() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:

	UFUNCTION()
	void PlayPressed();

	UFUNCTION()
	void OpenOptionsMenu();

	UFUNCTION()
	void OpenCreditsPanel();

	UFUNCTION()
	void QuitPressed();
};
