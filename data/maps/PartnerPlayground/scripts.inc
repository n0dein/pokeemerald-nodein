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
	msgbox PP_MudkipText2
	return

PP_CelebrateMudkip::
	playfanfare MUS_OBTAIN_ITEM
	msgbox PP_MudkipText1
	removeobject 1
	setflag FLAG_SYS_POKEMON_GET
	call Common_EventScript_NameReceivedPartyMon
	return

PP_PCMudkip::
	playfanfare MUS_OBTAIN_ITEM
	msgbox PP_MudkipText1
	removeobject 1
	setflag FLAG_SYS_POKEMON_GET
	call Common_EventScript_NameReceivedBoxMon
	return

PP_MudkipChoice::
	.string "Do you want to take this\p"
	.string "Mudkip with you to be your\n"
	.string "partner?$"

PP_MudkipText1::
	.string "You received a Mudkip!$"

PP_MudkipText2::
	.string "You decided not to take the Mudkip.$" 

PP_NotChosen::
	.string "You decided not to take this POKéMON.$"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      

