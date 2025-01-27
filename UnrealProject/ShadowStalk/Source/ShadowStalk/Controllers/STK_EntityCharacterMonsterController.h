// Copyright (C) Particle Interactive Ltd. 2021. All Rights Reserved.

 /*
  Author: Christian Young, Arianne Fennell
  Date Modified: 3/23/2021
  Comment/Description:: A controller for the Monster pawn. Doesn't allow crawling.
  ChangeLog:
  C 3/12/2021: Initialized class and populated input.
  H 3/16/2021: Added a class description and summaries to pertinent functions.
  A 3/23/2021: Added function and Input that sets up the Pause Menu.
  H 4/12/2021: Swapped to character. includes changes to lookat, moveto, execution, animation blueprint, attack, controllers, gamemode, gamestate.
  */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "STK_EntityCharacterMonsterController.generated.h"

UCLASS()
class SHADOWSTALK_API ASTK_EntityCharacterMonsterController : public APlayerController
{
    GENERATED_BODY()

public:

    virtual void OnPossess(APawn* aPawn) override;
    virtual void OnUnPossess() override;

    virtual void AcknowledgePossession(APawn* Pawn) override;

protected:

    virtual void SetupInputComponent() override;

    void Forward(float value);
    void Strafe(float value);

    void Jump();
    void SetSprint();
    void StopSprint();
    void Interact();
    void MouseLook_Vertical(float value);
    void MouseLook_Horizontal(float value);
    void Attack();

    void PauseMenu();  
    void DropTrap();


	UPROPERTY(Replicated)
	class ASTK_EntityCharacterMonster* m_MonsterEntityCharacter;

};
