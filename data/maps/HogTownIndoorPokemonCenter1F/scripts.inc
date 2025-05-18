HogTownIndoorPokemonCenter1F_MapScripts::
	.byte 0

HogTownIndoorPokemonCenter1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end