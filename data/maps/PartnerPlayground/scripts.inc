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

PP_MudkipChoice::
	.string "Do you want to take Mudkip with\n"
	.string "you to be your first partner POKéMON?$"

PP_MudkipText1::
	.string "You received Mudkip!\n"
	.string "The Mud Fish POKéMON.$"

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

PP_MudkipToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedMudkip
	end