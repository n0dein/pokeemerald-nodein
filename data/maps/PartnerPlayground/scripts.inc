PartnerPlayground_MapScripts::
	.byte 0	
	

PP_TriggerUnlock::
	getpartysize
	compare VAR_RESULT, 1
	goto_if_ge VAR_RESULT, 1, PP_UnlockPath
	releaseall
	end

PP_UnlockText::
	.string "Now that I have my very\n"
	.string "own partner POKéMON,\p"
	.string "I can start my adventure!\p"
	.string "I should show MOM my partner\n"
	.string "POKéMON first though,\p"
	.string "she is so excited to see.$"

PP_UnlockPath::
	msgbox PP_UnlockText, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STARTER_GOT, 2
	return

PP_PreventExitEast::
	lockall
	msgbox PP_CantLeave, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PP_Movement_PreventExitEast
	waitmovement 0
	releaseall
	end

PP_Movement_PreventExitEast::
	walk_left
	walk_left
	step_end

PP_CantLeave::
	.string "I can't leave until I pick\n"
	.string "my first partner POKéMON!$"

PP_EnterPP::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, PP_Movement_PreventExitEast
	waitmovement 0
	msgbox PP_GET_STARTER_TEXT, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STARTER_GOT, 1
	releaseall
	end

PP_GET_STARTER_TEXT::
	.string "This looks like the park\n"
	.string "Prfessor Birch was talking about.\p"
	.string "I should go and select my\n"
	.string "first partner POKéMON!$"

PartnerPlayground_EventScript_Sign::
	msgbox PartnerPlayground_Text_Sign, MSGBOX_SIGN
	end

PartnerPlayground_EventScript_Machamp::
	msgbox PartnerPlayground_Text_Machamp, MSGBOX_NPC
	end
	
PartnerPlayground_Text_Sign:
	.string "{LEFT_ARROW} PARTNER PLAYGROUND\p"
	.string "“Where new trainers make\n"
	.string "lifetime bonds with POKéMON.”$"

PartnerPlayground_Text_Machamp:
	.string "The Machamp motions toward your\n"
	.string "trainer card.\p"
	.string "It puts eight fingers up and\n"
	.string "gestures for you to go away.$"

PP_Mudkip::
	faceplayer
	lockall
	playmoncry SPECIES_MUDKIP, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_MUDKIP, 10, 3
	msgbox PP_MudkipChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveMudkip
	end

PP_GiveMudkip::
	givemon SPECIES_MUDKIP, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyMudkip
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCMudkip
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyMudkip::
	call PP_CelebrateMudkip
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedMudkip
	end 

PP_CelebrateMudkip::
	playfanfare MUS_OBTAIN_ITEM
	message PP_MudkipText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCMudkip::
	call PP_CelebrateMudkip
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_MudkipToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_MudkipToPC
	end 

PP_Treecko::
	faceplayer
	lockall
	playmoncry SPECIES_TREECKO, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_TREECKO, 10, 3
	msgbox PP_TreeckoChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveTreecko
	end

PP_GiveTreecko::
	givemon SPECIES_TREECKO, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyTreecko
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCTreecko
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyTreecko::
	call PP_CelebrateTreecko
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedTreecko
	end 

PP_CelebrateTreecko::
	playfanfare MUS_OBTAIN_ITEM
	message PP_TreeckoText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCTreecko::
	call PP_CelebrateTreecko
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_TreeckoToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_TreeckoToPC
	end

PP_Torchic::
	faceplayer
	lockall
	playmoncry SPECIES_TORCHIC, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_TORCHIC, 10, 3
	msgbox PP_TorchicChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveTorchic
	end

PP_GiveTorchic::
	givemon SPECIES_TORCHIC, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyTorchic
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCTorchic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyTorchic::
	call PP_CelebrateTorchic
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedTorchic
	end 

PP_CelebrateTorchic::
	playfanfare MUS_OBTAIN_ITEM
	message PP_TorchicText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCTorchic::
	call PP_CelebrateTorchic
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_TorchicToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_TorchicToPC
	end


PP_MudkipChoice::
	.string "Do you want to take Mudkip with\n"
	.string "you to be your first partner POKéMON?$"

PP_TreeckoChoice::
	.string "Do you want to take Treecko with\n"
	.string "you to be your first partner POKéMON?$"

PP_TorchicChoice::
	.string "Do you want to take Torchic with\n"
	.string "you to be your first partner POKéMON?$"

PP_MudkipText1::
	.string "You received Mudkip!\n"
	.string "The Mud Fish POKéMON.$"

PP_TreeckoText1::
	.string "You received Treecko!\n"
	.string "The Wood Gecko POKéMON.$"

PP_TorchicText1::
	.string "You received Torchic!\n"
	.string "The Chick POKéMON.$"

PP_NotChosenText::
	.string "You decided not to take this POKéMON.$"

PP_NicknameChoice::
 	.string "Do you want to give a nickname\n"
	.string "to the POKéMON you received?$"

PP_NotNamedText::
	.string "You can always pick a name later\n"
	.string "on the summary screen.$"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    

PP_NotChosen::
	msgbox PP_NotChosenText, MSGBOX_DEFAULT
	hidemonpic
	releaseall
	end

PP_NotNamed::
	msgbox PP_NotNamedText, MSGBOX_DEFAULT
	hidemonpic
	releaseall
	end

PP_ReceivedMudkip::
	setflag FLAG_PP_MUDKIP
	hidemonpic
	releaseall
	end

PP_ReceivedTreecko::
	setflag FLAG_PP_TREECKO
	hidemonpic
	releaseall
	end

PP_ReceivedTorchic::
	setflag FLAG_PP_TORCHIC
	hidemonpic
	releaseall
	end

PP_MudkipToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedMudkip
	end

PP_TreeckoToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedTreecko
	end

PP_TorchicToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedTorchic
	end

PP_Turtwig::
	faceplayer
	lockall
	playmoncry SPECIES_TURTWIG, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_TURTWIG, 10, 3
	msgbox PP_TurtwigChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveTurtwig
	end

PP_GiveTurtwig::
	givemon SPECIES_TURTWIG, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyTurtwig
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCTurtwig
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyTurtwig::
	call PP_CelebrateTurtwig
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedTurtwig
	end 

PP_CelebrateTurtwig::
	playfanfare MUS_OBTAIN_ITEM
	message PP_TurtwigText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCTurtwig::
	call PP_CelebrateTurtwig
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_TurtwigToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_TurtwigToPC
	end 

PP_TurtwigChoice::
	.string "Do you want to take Turtwig with\n"
	.string "you to be your first partner POKéMON?$"

PP_TurtwigText1::
	.string "You received Turtwig!\n"
	.string "The Tiny Leaf POKéMON.$"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

PP_ReceivedTurtwig::
	setflag FLAG_PP_TURTWIG
	hidemonpic
	releaseall
	end

PP_TurtwigToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedTurtwig
	end

PP_Chimchar::
	faceplayer
	lockall
	playmoncry SPECIES_CHIMCHAR, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_CHIMCHAR, 10, 3
	msgbox PP_ChimcharChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveChimchar
	end

PP_GiveChimchar::
	givemon SPECIES_CHIMCHAR, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyChimchar
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCChimchar
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyChimchar::
	call PP_CelebrateChimchar
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedChimchar
	end 

PP_CelebrateChimchar::
	playfanfare MUS_OBTAIN_ITEM
	message PP_ChimcharText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCChimchar::
	call PP_CelebrateChimchar
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_ChimcharToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_ChimcharToPC
	end 

PP_ChimcharChoice::
	.string "Do you want to take Chimchar with\n"
	.string "you to be your first partner POKéMON?$"

PP_ChimcharText1::
	.string "You received Chimchar!\n"
	.string "The Chimp POKéMON.$"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

PP_ReceivedChimchar::
	setflag FLAG_PP_CHIMCHAR
	hidemonpic
	releaseall
	end

PP_ChimcharToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedChimchar
	end
	
	PP_Piplup::
	faceplayer
	lockall
	playmoncry SPECIES_PIPLUP, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_PIPLUP, 10, 3
	msgbox PP_PiplupChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GivePiplup
	end

PP_GivePiplup::
	givemon SPECIES_PIPLUP, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyPiplup
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCPiplup
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyPiplup::
	call PP_CelebratePiplup
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedPiplup
	end 

PP_CelebratePiplup::
	playfanfare MUS_OBTAIN_ITEM
	message PP_PiplupText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCPiplup::
	call PP_CelebratePiplup
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_PiplupToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_PiplupToPC
	end 

PP_PiplupChoice::
	.string "Do you want to take Piplup with\n"
	.string "you to be your first partner POKéMON?$"

PP_PiplupText1::
	.string "You received Piplup!\n"
	.string "The Penguin POKéMON.$"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

PP_ReceivedPiplup::
	setflag FLAG_PP_PIPLUP
	hidemonpic
	releaseall
	end

PP_PiplupToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedPiplup
	end

PP_Pikachu::
	faceplayer
	lockall
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_PIKACHU, 10, 3
	msgbox PP_PikachuChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GivePikachu
	end

PP_GivePikachu::
	givemon SPECIES_PIKACHU, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyPikachu
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCPikachu
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyPikachu::
	call PP_CelebratePikachu
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedPikachu
	end 

PP_CelebratePikachu::
	playfanfare MUS_OBTAIN_ITEM
	message PP_PikachuText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCPikachu::
	call PP_CelebratePikachu
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_PikachuToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_PikachuToPC
	end 

PP_PikachuChoice::
	.string "Do you want to take Pikachu with\n"
	.string "you to be your first partner POKéMON?$"

PP_PikachuText1::
	.string "You received Pikachu!\n"
	.string "The Electric Mouse POKéMON.$"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

PP_ReceivedPikachu::
	setflag FLAG_PP_PIKACHU
	hidemonpic
	releaseall
	end

PP_PikachuToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedPikachu
	end

PP_Bulbasaur::
	faceplayer
	lockall
	playmoncry SPECIES_BULBASAUR, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_BULBASAUR, 10, 3
	msgbox PP_BulbasaurChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveBulbasaur
	end

PP_GiveBulbasaur::
	givemon SPECIES_BULBASAUR, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyBulbasaur
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCBulbasaur
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyBulbasaur::
	call PP_CelebrateBulbasaur
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedBulbasaur
	end 

PP_CelebrateBulbasaur::
	playfanfare MUS_OBTAIN_ITEM
	message PP_BulbasaurText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCBulbasaur::
	call PP_CelebrateBulbasaur
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_BulbasaurToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_BulbasaurToPC
	end 

PP_BulbasaurChoice::
	.string "Do you want to take Bulbasaur with\n"
	.string "you to be your first partner POKéMON?$"

PP_BulbasaurText1::
	.string "You received Bulbasaur!\n"
	.string "The Seed POKéMON.$"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

PP_ReceivedBulbasaur::
	setflag FLAG_PP_BULBASAUR
	hidemonpic
	releaseall
	end

PP_BulbasaurToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedBulbasaur
	end
PP_Charmander::
	faceplayer
	lockall
	playmoncry SPECIES_CHARMANDER, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_CHARMANDER, 10, 3
	msgbox PP_CharmanderChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveCharmander
	end

PP_GiveCharmander::
	givemon SPECIES_CHARMANDER, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyCharmander
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCCharmander
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyCharmander::
	call PP_CelebrateCharmander
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedCharmander
	end 

PP_CelebrateCharmander::
	playfanfare MUS_OBTAIN_ITEM
	message PP_CharmanderText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCCharmander::
	call PP_CelebrateCharmander
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_CharmanderToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_CharmanderToPC
	end 

PP_CharmanderChoice::
	.string "Do you want to take Charmander with\n"
	.string "you to be your first partner POKéMON?$"

PP_CharmanderText1::
	.string "You received Charmander!\n"
	.string "The Lizard POKéMON.$"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

PP_ReceivedCharmander::
	setflag FLAG_PP_CHARMANDER
	hidemonpic
	releaseall
	end

PP_CharmanderToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedCharmander
	end
PP_Squirtle::
	faceplayer
	lockall
	playmoncry SPECIES_SQUIRTLE, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_SQUIRTLE, 10, 3
	msgbox PP_SquirtleChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveSquirtle
	end

PP_GiveSquirtle::
	givemon SPECIES_SQUIRTLE, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartySquirtle
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCSquirtle
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartySquirtle::
	call PP_CelebrateSquirtle
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedSquirtle
	end 

PP_CelebrateSquirtle::
	playfanfare MUS_OBTAIN_ITEM
	message PP_SquirtleText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCSquirtle::
	call PP_CelebrateSquirtle
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SquirtleToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_SquirtleToPC
	end 

PP_SquirtleChoice::
	.string "Do you want to take Squirtle with\n"
	.string "you to be your first partner POKéMON?$"

PP_SquirtleText1::
	.string "You received Squirtle!\n"
	.string "The Tiny Turtle POKéMON.$"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

PP_ReceivedSquirtle::
	setflag FLAG_PP_SQUIRTLE
	hidemonpic
	releaseall
	end

PP_SquirtleToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedSquirtle
	end
PP_Chikorita::
	faceplayer
	lockall
	playmoncry SPECIES_CHIKORITA, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_CHIKORITA, 10, 3
	msgbox PP_ChikoritaChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveChikorita
	end

PP_GiveChikorita::
	givemon SPECIES_CHIKORITA, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyChikorita
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCChikorita
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyChikorita::
	call PP_CelebrateChikorita
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedChikorita
	end 

PP_CelebrateChikorita::
	playfanfare MUS_OBTAIN_ITEM
	message PP_ChikoritaText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCChikorita::
	call PP_CelebrateChikorita
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_ChikoritaToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_ChikoritaToPC
	end 

PP_ChikoritaChoice::
	.string "Do you want to take Chikorita with\n"
	.string "you to be your first partner POKéMON?$"

PP_ChikoritaText1::
	.string "You received Chikorita!\n"
	.string "The Leaf POKéMON.$"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

PP_ReceivedChikorita::
	setflag FLAG_PP_CHIKORITA
	hidemonpic
	releaseall
	end

PP_ChikoritaToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedChikorita
	end
PP_Cyndaquil::
	faceplayer
	lockall
	playmoncry SPECIES_CYNDAQUIL, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_CYNDAQUIL, 10, 3
	msgbox PP_CyndaquilChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveCyndaquil
	end

PP_GiveCyndaquil::
	givemon SPECIES_CYNDAQUIL, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyCyndaquil
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCCyndaquil
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyCyndaquil::
	call PP_CelebrateCyndaquil
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedCyndaquil
	end 

PP_CelebrateCyndaquil::
	playfanfare MUS_OBTAIN_ITEM
	message PP_CyndaquilText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCCyndaquil::
	call PP_CelebrateCyndaquil
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_CyndaquilToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_CyndaquilToPC
	end 

PP_CyndaquilChoice::
	.string "Do you want to take Cyndaquil with\n"
	.string "you to be your first partner POKéMON?$"

PP_CyndaquilText1::
	.string "You received Cyndaquil!\n"
	.string "The Fire Mouse POKéMON.$"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

PP_ReceivedCyndaquil::
	setflag FLAG_PP_CYNDAQUIL
	hidemonpic
	releaseall
	end

PP_CyndaquilToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedCyndaquil
	end
PP_Totodile::
	faceplayer
	lockall
	playmoncry SPECIES_TOTODILE, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_TOTODILE, 10, 3
	msgbox PP_TotodileChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveTotodile
	end

PP_GiveTotodile::
	givemon SPECIES_TOTODILE, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyTotodile
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCTotodile
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyTotodile::
	call PP_CelebrateTotodile
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedTotodile
	end 

PP_CelebrateTotodile::
	playfanfare MUS_OBTAIN_ITEM
	message PP_TotodileText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCTotodile::
	call PP_CelebrateTotodile
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_TotodileToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_TotodileToPC
	end 

PP_TotodileChoice::
	.string "Do you want to take Totodile with\n"
	.string "you to be your first partner POKéMON?$"

PP_TotodileText1::
	.string "You received Totodile!\n"
	.string "The Big Jaw POKéMON.$"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

PP_ReceivedTotodile::
	setflag FLAG_PP_TOTODILE
	hidemonpic
	releaseall
	end

PP_TotodileToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedTotodile
	end
PP_Snivy::
	faceplayer
	lockall
	playmoncry SPECIES_SNIVY, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_SNIVY, 10, 3
	msgbox PP_SnivyChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveSnivy
	end

PP_GiveSnivy::
	givemon SPECIES_SNIVY, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartySnivy
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCSnivy
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartySnivy::
	call PP_CelebrateSnivy
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedSnivy
	end 

PP_CelebrateSnivy::
	playfanfare MUS_OBTAIN_ITEM
	message PP_SnivyText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCSnivy::
	call PP_CelebrateSnivy
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SnivyToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_SnivyToPC
	end 

PP_SnivyChoice::
	.string "Do you want to take Snivy with\n"
	.string "you to be your first partner POKéMON?$"

PP_SnivyText1::
	.string "You received Snivy!\n"
	.string "The Grass Snake POKéMON.$"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

PP_ReceivedSnivy::
	setflag FLAG_PP_SNIVY
	hidemonpic
	releaseall
	end

PP_SnivyToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedSnivy
	end
PP_Tepig::
	faceplayer
	lockall
	playmoncry SPECIES_TEPIG, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_TEPIG, 10, 3
	msgbox PP_TepigChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveTepig
	end

PP_GiveTepig::
	givemon SPECIES_TEPIG, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyTepig
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCTepig
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyTepig::
	call PP_CelebrateTepig
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedTepig
	end 

PP_CelebrateTepig::
	playfanfare MUS_OBTAIN_ITEM
	message PP_TepigText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCTepig::
	call PP_CelebrateTepig
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_TepigToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_TepigToPC
	end 

PP_TepigChoice::
	.string "Do you want to take Tepig with\n"
	.string "you to be your first partner POKéMON?$"

PP_TepigText1::
	.string "You received Tepig!\n"
	.string "The Fire Pig POKéMON.$"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

PP_ReceivedTepig::
	setflag FLAG_PP_TEPIG
	hidemonpic
	releaseall
	end

PP_TepigToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedTepig
	end

PP_Oshawott::
	faceplayer
	lockall
	playmoncry SPECIES_OSHAWOTT, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_OSHAWOTT, 10, 3
	msgbox PP_OshawottChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveOshawott
	end

PP_GiveOshawott::
	givemon SPECIES_OSHAWOTT, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyOshawott
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCOshawott
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyOshawott::
	call PP_CelebrateOshawott
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedOshawott
	end 

PP_CelebrateOshawott::
	playfanfare MUS_OBTAIN_ITEM
	message PP_OshawottText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCOshawott::
	call PP_CelebrateOshawott
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_OshawottToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_OshawottToPC
	end 

PP_OshawottChoice::
	.string "Do you want to take Oshawott with\n"
	.string "you to be your first partner POKéMON?$"

PP_OshawottText1::
	.string "You received Oshawott!\n"
	.string "The Sea Otter POKéMON.$"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

PP_ReceivedOshawott::
	setflag FLAG_PP_OSHAWOTT
	hidemonpic
	releaseall
	end

PP_OshawottToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedOshawott
	end

PP_Chespin::
	faceplayer
	lockall
	playmoncry SPECIES_CHESPIN, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_CHESPIN, 10, 3
	msgbox PP_ChespinChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveChespin
	end

PP_GiveChespin::
	givemon SPECIES_CHESPIN, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyChespin
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCChespin
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyChespin::
	call PP_CelebrateChespin
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedChespin
	end 

PP_CelebrateChespin::
	playfanfare MUS_OBTAIN_ITEM
	message PP_ChespinText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCChespin::
	call PP_CelebrateChespin
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_ChespinToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_ChespinToPC
	end 

PP_ChespinChoice::
	.string "Do you want to take Chespin with\n"
	.string "you to be your first partner POKéMON?$"

PP_ChespinText1::
	.string "You received Chespin!\n"
	.string "The Spiny Nut POKéMON.$"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

PP_ReceivedChespin::
	setflag FLAG_PP_CHESPIN
	hidemonpic
	releaseall
	end

PP_ChespinToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedChespin
	end

PP_Fennekin::
	faceplayer
	lockall
	playmoncry SPECIES_FENNEKIN, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_FENNEKIN, 10, 3
	msgbox PP_FennekinChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveFennekin
	end

PP_GiveFennekin::
	givemon SPECIES_FENNEKIN, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyFennekin
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCFennekin
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyFennekin::
	call PP_CelebrateFennekin
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedFennekin
	end 

PP_CelebrateFennekin::
	playfanfare MUS_OBTAIN_ITEM
	message PP_FennekinText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCFennekin::
	call PP_CelebrateFennekin
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_FennekinToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_FennekinToPC
	end 

PP_FennekinChoice::
	.string "Do you want to take Fennekin with\n"
	.string "you to be your first partner POKéMON?$"

PP_FennekinText1::
	.string "You received Fennekin!\n"
	.string "The Fox POKéMON.$"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

PP_ReceivedFennekin::
	setflag FLAG_PP_FENNEKIN
	hidemonpic
	releaseall
	end

PP_FennekinToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedFennekin
	end

PP_Froakie::
	faceplayer
	lockall
	playmoncry SPECIES_FROAKIE, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_FROAKIE, 10, 3
	msgbox PP_FroakieChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveFroakie
	end

PP_GiveFroakie::
	givemon SPECIES_FROAKIE, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyFroakie
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCFroakie
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyFroakie::
	call PP_CelebrateFroakie
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedFroakie
	end 

PP_CelebrateFroakie::
	playfanfare MUS_OBTAIN_ITEM
	message PP_FroakieText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCFroakie::
	call PP_CelebrateFroakie
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_FroakieToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_FroakieToPC
	end 

PP_FroakieChoice::
	.string "Do you want to take Froakie with\n"
	.string "you to be your first partner POKéMON?$"

PP_FroakieText1::
	.string "You received Froakie!\n"
	.string "The Bubble Frog POKéMON.$"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

PP_ReceivedFroakie::
	setflag FLAG_PP_FROAKIE
	hidemonpic
	releaseall
	end

PP_FroakieToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedFroakie
	end

PP_Rowlet::
	faceplayer
	lockall
	playmoncry SPECIES_ROWLET, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_ROWLET, 10, 3
	msgbox PP_RowletChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveRowlet
	end

PP_GiveRowlet::
	givemon SPECIES_ROWLET, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyRowlet
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCRowlet
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyRowlet::
	call PP_CelebrateRowlet
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedRowlet
	end 

PP_CelebrateRowlet::
	playfanfare MUS_OBTAIN_ITEM
	message PP_RowletText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCRowlet::
	call PP_CelebrateRowlet
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_RowletToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_RowletToPC
	end 

PP_RowletChoice::
	.string "Do you want to take Rowlet with\n"
	.string "you to be your first partner POKéMON?$"

PP_RowletText1::
	.string "You received Rowlet!\n"
	.string "The Grass Quill POKéMON.$"

PP_ReceivedRowlet::
	setflag FLAG_PP_ROWLET
	hidemonpic
	releaseall
	end

PP_RowletToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedRowlet
	end

PP_Litten::
	faceplayer
	lockall
	playmoncry SPECIES_LITTEN, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_LITTEN, 10, 3
	msgbox PP_LittenChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveLitten
	end

PP_GiveLitten::
	givemon SPECIES_LITTEN, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyLitten
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCLitten
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyLitten::
	call PP_CelebrateLitten
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedLitten
	end 

PP_CelebrateLitten::
	playfanfare MUS_OBTAIN_ITEM
	message PP_LittenText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCLitten::
	call PP_CelebrateLitten
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_LittenToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_LittenToPC
	end 

PP_LittenChoice::
	.string "Do you want to take Litten with\n"
	.string "you to be your first partner POKéMON?$"

PP_LittenText1::
	.string "You received Litten!\n"
	.string "The Fire Cat POKéMON.$"

PP_ReceivedLitten::
	setflag FLAG_PP_LITTEN
	hidemonpic
	releaseall
	end

PP_LittenToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedLitten
	end

PP_Popplio::
	faceplayer
	lockall
	playmoncry SPECIES_POPPLIO, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_POPPLIO, 10, 3
	msgbox PP_PopplioChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GivePopplio
	end

PP_GivePopplio::
	givemon SPECIES_POPPLIO, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyPopplio
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCPopplio
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyPopplio::
	call PP_CelebratePopplio
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedPopplio
	end 

PP_CelebratePopplio::
	playfanfare MUS_OBTAIN_ITEM
	message PP_PopplioText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCPopplio::
	call PP_CelebratePopplio
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_PopplioToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_PopplioToPC
	end 

PP_PopplioChoice::
	.string "Do you want to take Popplio with\n"
	.string "you to be your first partner POKéMON?$"

PP_PopplioText1::
	.string "You received Popplio!\n"
	.string "The Sea Lion POKéMON.$"

PP_ReceivedPopplio::
	setflag FLAG_PP_POPPLIO
	hidemonpic
	releaseall
	end

PP_PopplioToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedPopplio
	end

PP_Grookey::
	faceplayer
	lockall
	playmoncry SPECIES_GROOKEY, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_GROOKEY, 10, 3
	msgbox PP_GrookeyChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveGrookey
	end

PP_GiveGrookey::
	givemon SPECIES_GROOKEY, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyGrookey
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCGrookey
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyGrookey::
	call PP_CelebrateGrookey
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedGrookey
	end 

PP_CelebrateGrookey::
	playfanfare MUS_OBTAIN_ITEM
	message PP_GrookeyText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCGrookey::
	call PP_CelebrateGrookey
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_GrookeyToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_GrookeyToPC
	end 

PP_GrookeyChoice::
	.string "Do you want to take Grookey with\n"
	.string "you to be your first partner POKéMON?$"

PP_GrookeyText1::
	.string "You received Grookey!\n"
	.string "The Chimp POKéMON.$"

PP_ReceivedGrookey::
	setflag FLAG_PP_GROOKEY
	hidemonpic
	releaseall
	end

PP_GrookeyToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedGrookey
	end

PP_Scorbunny::
	faceplayer
	lockall
	playmoncry SPECIES_SCORBUNNY, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_SCORBUNNY, 10, 3
	msgbox PP_ScorbunnyChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveScorbunny
	end

PP_GiveScorbunny::
	givemon SPECIES_SCORBUNNY, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyScorbunny
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCScorbunny
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyScorbunny::
	call PP_CelebrateScorbunny
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedScorbunny
	end 

PP_CelebrateScorbunny::
	playfanfare MUS_OBTAIN_ITEM
	message PP_ScorbunnyText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCScorbunny::
	call PP_CelebrateScorbunny
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_ScorbunnyToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_ScorbunnyToPC
	end 

PP_ScorbunnyChoice::
	.string "Do you want to take Scorbunny with\n"
	.string "you to be your first partner POKéMON?$"

PP_ScorbunnyText1::
	.string "You received Scorbunny!\n"
	.string "The Rabbit POKéMON.$"

PP_ReceivedScorbunny::
	setflag FLAG_PP_SCORBUNNY
	hidemonpic
	releaseall
	end

PP_ScorbunnyToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedScorbunny
	end

PP_Sobble::
	faceplayer
	lockall
	playmoncry SPECIES_SOBBLE, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_SOBBLE, 10, 3
	msgbox PP_SobbleChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveSobble
	end

PP_GiveSobble::
	givemon SPECIES_SOBBLE, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartySobble
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCSobble
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartySobble::
	call PP_CelebrateSobble
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedSobble
	end 

PP_CelebrateSobble::
	playfanfare MUS_OBTAIN_ITEM
	message PP_SobbleText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCSobble::
	call PP_CelebrateSobble
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SobbleToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_SobbleToPC
	end 

PP_SobbleChoice::
	.string "Do you want to take Sobble with\n"
	.string "you to be your first partner POKéMON?$"

PP_SobbleText1::
	.string "You received Sobble!\n"
	.string "The Water Lizard POKéMON.$"

PP_ReceivedSobble::
	setflag FLAG_PP_SOBBLE
	hidemonpic
	releaseall
	end

PP_SobbleToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedSobble
	end

PP_Sprigatito::
	faceplayer
	lockall
	playmoncry SPECIES_SPRIGATITO, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_SPRIGATITO, 10, 3
	msgbox PP_SprigatitoChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveSprigatito
	end

PP_GiveSprigatito::
	givemon SPECIES_SPRIGATITO, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartySprigatito
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCSprigatito
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartySprigatito::
	call PP_CelebrateSprigatito
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedSprigatito
	end 

PP_CelebrateSprigatito::
	playfanfare MUS_OBTAIN_ITEM
	message PP_SprigatitoText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCSprigatito::
	call PP_CelebrateSprigatito
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SprigatitoToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_SprigatitoToPC
	end 

PP_SprigatitoChoice::
	.string "Do you want to take Sprigatito with\n"
	.string "you to be your first partner POKéMON?$"

PP_SprigatitoText1::
	.string "You received Sprigatito!\n"
	.string "The Grass Cat POKéMON.$"

PP_ReceivedSprigatito::
	setflag FLAG_PP_SPRIGATITO
	hidemonpic
	releaseall
	end

PP_SprigatitoToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedSprigatito
	end

PP_Fuecoco::
	faceplayer
	lockall
	playmoncry SPECIES_FUECOCO, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_FUECOCO, 10, 3
	msgbox PP_FuecocoChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveFuecoco
	end

PP_GiveFuecoco::
	givemon SPECIES_FUECOCO, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyFuecoco
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCFuecoco
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyFuecoco::
	call PP_CelebrateFuecoco
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedFuecoco
	end 

PP_CelebrateFuecoco::
	playfanfare MUS_OBTAIN_ITEM
	message PP_FuecocoText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCFuecoco::
	call PP_CelebrateFuecoco
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_FuecocoToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_FuecocoToPC
	end 

PP_FuecocoChoice::
	.string "Do you want to take Fuecoco with\n"
	.string "you to be your first partner POKéMON?$"

PP_FuecocoText1::
	.string "You received Fuecoco!\n"
	.string "The Fire Croc POKéMON.$"

PP_ReceivedFuecoco::
	setflag FLAG_PP_FUECOCO
	hidemonpic
	releaseall
	end

PP_FuecocoToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedFuecoco
	end

PP_Quaxly::
	faceplayer
	lockall
	playmoncry SPECIES_QUAXLY, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_QUAXLY, 10, 3
	msgbox PP_QuaxlyChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveQuaxly
	end

PP_GiveQuaxly::
	givemon SPECIES_QUAXLY, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyQuaxly
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCQuaxly
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyQuaxly::
	call PP_CelebrateQuaxly
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedQuaxly
	end 

PP_CelebrateQuaxly::
	playfanfare MUS_OBTAIN_ITEM
	message PP_QuaxlyText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCQuaxly::
	call PP_CelebrateQuaxly
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_QuaxlyToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_QuaxlyToPC
	end 

PP_QuaxlyChoice::
	.string "Do you want to take Quaxly with\n"
	.string "you to be your first partner POKéMON?$"

PP_QuaxlyText1::
	.string "You received Quaxly!\n"
	.string "The Duckling POKéMON.$"

PP_ReceivedQuaxly::
	setflag FLAG_PP_QUAXLY
	hidemonpic
	releaseall
	end

PP_QuaxlyToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedQuaxly
	end

PP_Eevee::
	faceplayer
	lockall
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	waitmoncry
	showmonpic SPECIES_EEVEE, 10, 3
	msgbox PP_EeveeChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveEevee
	end

PP_GiveEevee::
	givemon SPECIES_EEVEE, 5, 
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyEevee
	goto_if_eq  VAR_RESULT, MON_GIVEN_TO_PC, PP_PCEevee
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_PartyEevee::
	call PP_CelebrateEevee
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotNamed
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PP_ReceivedEevee
	end 

PP_CelebrateEevee::
	playfanfare MUS_OBTAIN_ITEM
	message PP_EeveeText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_PCEevee::
	call PP_CelebrateEevee
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_EeveeToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PP_EeveeToPC
	end 

PP_EeveeChoice::
	.string "Do you want to take Eevee with\n"
	.string "you to be your first partner POKéMON?$"

PP_EeveeText1::
	.string "You received Eevee!\n"
	.string "The Evolution POKéMON.$"

PP_ReceivedEevee::
	lock
	faceplayer
	fadescreen FADE_TO_BLACK
	setflag FLAG_PP_EEVEE
	hidemonpic
	waitbuttonpress
	fadescreen FADE_FROM_BLACK
	releaseall
	end

PP_EeveeToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedEevee
	end

