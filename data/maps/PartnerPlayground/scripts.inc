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
	faceplayer
	lockall
	showmonpic SPECIES_MUDKIP, 10, 3
	msgbox PP_MudkipChoice, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PP_GiveMudkip
	hidemonpic
	msgbox PP_NotChosen
	releaseall
	end

PP_GiveMudkip::
	givemon SPECIES_MUDKIP, 5, 
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq PP_CelebrateMudkip
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq PP_PCMudkip
	hidemonpic
	return

PP_CelebrateMudkip::
	playfanfare MUS_OBTAIN_ITEM
	msgbox PP_MudkipText1
	removeobject 1
	setflag FLAG_SYS_POKEMON_GET
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PP_NicknameMon
	hidemonpic
	return

PP_PCMudkip::
	playfanfare MUS_OBTAIN_ITEM
	msgbox PP_MudkipText1
	removeobject 1
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_POKEMON_GET
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PP_NicknameMonPC
	call Common_EventScript_TransferredToPC
	return

PP_MudkipChoice::
	.string "Do you want to take Mudkip with\n"
	.string "you to be your first partner POKéMON?$"

PP_MudkipText1::
	.string "You received Mudkip!\n"
	.string "The Mud Fish POKéMON.$"

PP_NotChosen::
	.string "You decided not to take this POKéMON.$"

PP_NicknameChoice::
 	.string "Do you want to give a nickname\n"
	.string "to the POKéMON you received?$"

PP_NicknameMon::
	call Common_EventScript_NameReceivedPartyMon
	end

PP_NicknameMonPC::
	call Common_EventScript_NameReceivedBoxMon
	end                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
