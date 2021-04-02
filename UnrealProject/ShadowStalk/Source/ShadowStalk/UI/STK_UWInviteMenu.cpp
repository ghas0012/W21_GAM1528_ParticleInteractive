// Copyright (C) Particle Interactive Ltd. 2021. All Rights Reserved.

#include "STK_UWInviteMenu.h"


#include "STK_UWFriendRow.h"
#include "Components/Button.h"
#include "STK_UWFriendsList.h"

USTK_UWInviteMenu::USTK_UWInviteMenu(const FObjectInitializer& ObjectInitializer) :
    Super(ObjectInitializer)
{
    //Search for Friend Row Widget Blueprint
    {
        /*ConstructorHelpers::FClassFinder<UUserWidget> FriendsListBPClass(TEXT("/Game/UI/WBP_FriendsList"));
        if (!ensure(FriendsListBPClass.Class != nullptr)) return;

        FriendsListClass = FriendsListBPClass.Class;*/
    }
}

bool USTK_UWInviteMenu::Initialize()
{
    bool Success = Super::Initialize();
    if (!Success) return false;

    //Create the Friends List Custom Widget
    //UWFriendsList = CreateWidget<USTK_UWFriendsList>(this, FriendsListClass);
    //if (!ensure(UWFriendsList != nullptr)) return false;
    //
    //if (UWFriendsList) GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, TEXT("Friends List Found!"));

    //Setup Input for Exit Button
    if (!ensure(ExitButton != nullptr)) return false;
    ExitButton->OnClicked.AddDynamic(this, &USTK_UWInviteMenu::ExitPressed);
    ExitButton->OnHovered.AddDynamic(this, &USTK_UserWidget::PlayHoverSoundFX);

    return true;
}

///<summary>
///Removes the Invite menu widget from the viewport.
///</summary>
void USTK_UWInviteMenu::ExitPressed()
{
    this->RemoveFromViewport();
}