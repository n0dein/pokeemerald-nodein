PartnerPlayground_MapScripts::
	.byte 0

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
	lockall
	playmoncry SPECIES_MUDKIP
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
	lockall
	playmoncry SPECIES_TREECKO
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
	lockall
	playmoncry SPECIES_Torchic
	showmonpic SPECIES_Torchic, 10, 3
	msgbox PP_TorchicChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_NotChosen
	goto PP_GiveTorchic
	end

PP_GiveTorchic::
	givemon SPECIES_Torchic, 5, 
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
	hidemonpic
	releaseall
	end

PP_ReceivedTreecko::
	hidemonpic
	releaseall
	end

PP_ReceivedTorchic::
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