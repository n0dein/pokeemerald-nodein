HogTownIndoorPokemonCenter1F_MapScripts::
	.byte 0

HogTownIndoorPokemonCenter1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

HogTownIndoorPokemonCenter1F_EventScript_NurseBlock::
	msgbox HogTownIndoorPokemonCenter1F_Text_NurseBlock, MSGBOX_NPC
	end
HogTownIndoorPokemonCenter1F_Text_NurseBlock::
	.string "Sorry, but the second floor\n"
	.string "is closed right now.\p"
	.string "Please come back later.$"
