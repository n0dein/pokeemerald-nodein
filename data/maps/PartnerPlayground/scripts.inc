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

//PP_Pokemon Section//

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



//PP_Give//

PP_GiveBulbasaur::
	givemon SPECIES_BULBASAUR, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyBulbasaur
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCBulbasaur
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveCharmander::
	givemon SPECIES_CHARMANDER, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyCharmander
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCCharmander
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveSquirtle::
	givemon SPECIES_SQUIRTLE, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartySquirtle
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCSquirtle
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveChikorita::
	givemon SPECIES_CHIKORITA, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyChikorita
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCChikorita
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveCyndaquil::
	givemon SPECIES_CYNDAQUIL, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyCyndaquil
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCCyndaquil
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveTotodile::
	givemon SPECIES_TOTODILE, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyTotodile
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCTotodile
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveTreecko::
	givemon SPECIES_TREECKO, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyTreecko
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCTreecko
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveTorchic::
	givemon SPECIES_TORCHIC, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyTorchic
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCTorchic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveMudkip::
	givemon SPECIES_MUDKIP, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyMudkip
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCMudkip
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveTurtwig::
	givemon SPECIES_TURTWIG, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyTurtwig
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCTurtwig
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveChimchar::
	givemon SPECIES_CHIMCHAR, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyChimchar
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCChimchar
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GivePiplup::
	givemon SPECIES_PIPLUP, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyPiplup
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCPiplup
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveSnivy::
	givemon SPECIES_SNIVY, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartySnivy
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCSnivy
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveTepig::
	givemon SPECIES_TEPIG, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyTepig
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCTepig
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveOshawott::
	givemon SPECIES_OSHAWOTT, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyOshawott
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCOshawott
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveChespin::
	givemon SPECIES_CHESPIN, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyChespin
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCChespin
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveFennekin::
	givemon SPECIES_FENNEKIN, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyFennekin
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCFennekin
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveFroakie::
	givemon SPECIES_FROAKIE, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyFroakie
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCFroakie
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveRowlet::
	givemon SPECIES_ROWLET, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyRowlet
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCRowlet
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveLitten::
	givemon SPECIES_LITTEN, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyLitten
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCLitten
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GivePopplio::
	givemon SPECIES_POPPLIO, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyPopplio
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCPopplio
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveGrookey::
	givemon SPECIES_GROOKEY, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyGrookey
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCGrookey
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveScorbunny::
	givemon SPECIES_SCORBUNNY, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyScorbunny
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCScorbunny
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveSobble::
	givemon SPECIES_SOBBLE, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartySobble
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCSobble
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveSprigatito::
	givemon SPECIES_SPRIGATITO, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartySprigatito
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCSprigatito
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveFuecoco::
	givemon SPECIES_FUECOCO, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyFuecoco
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCFuecoco
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveQuaxly::
	givemon SPECIES_QUAXLY, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyQuaxly
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCQuaxly
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GivePikachu::
	givemon SPECIES_PIKACHU, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyPikachu
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCPikachu
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PP_GiveEevee::
	givemon SPECIES_EEVEE, 5,
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PP_PartyEevee
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PP_PCEevee
	goto Common_EventScript_NoMoreRoomForPokemon
	end


//PP_Party Section//

PP_PartyBulbasaur::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingBulbasaur
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyCharmander::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingCharmander
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartySquirtle::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingSquirtle
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyChikorita::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingChikorita
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyCyndaquil::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingCyndaquil
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyTotodile::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingTotodile
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyTreecko::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingTreecko
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyTorchic::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingTorchic
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyMudkip::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingMudkip
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyTurtwig::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingTurtwig
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyChimchar::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingChimchar
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyPiplup::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingPiplup
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartySnivy::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingSnivy
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyTepig::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingTepig
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyOshawott::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingOshawott
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyChespin::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingChespin
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyFennekin::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingFennekin
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyFroakie::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingFroakie
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyRowlet::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingRowlet
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyLitten::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingLitten
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyPopplio::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingPopplio
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyGrookey::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingGrookey
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyScorbunny::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingScorbunny
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartySobble::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingSobble
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartySprigatito::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingSprigatito
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyFuecoco::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingFuecoco
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyQuaxly::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingQuaxly
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyPikachu::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingPikachu
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon

PP_PartyEevee::
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipNamingEevee
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon


//PP_SkipNaming Section//
	
PP_SkipNamingBulbasaur::
	goto PP_ReceivedBulbasaur
	end

PP_SkipNamingCharmander::
	goto PP_ReceivedCharmander
	end

PP_SkipNamingSquirtle::
	goto PP_ReceivedSquirtle
	end

PP_SkipNamingChikorita::
	goto PP_ReceivedChikorita
	end

PP_SkipNamingCyndaquil::
	goto PP_ReceivedCyndaquil
	end

PP_SkipNamingTotodile::
	goto PP_ReceivedTotodile
	end

PP_SkipNamingTreecko::
	goto PP_ReceivedTreecko
	end

PP_SkipNamingTorchic::
	goto PP_ReceivedTorchic
	end

PP_SkipNamingMudkip::
	goto PP_ReceivedMudkip
	end

PP_SkipNamingTurtwig::
	goto PP_ReceivedTurtwig
	end

PP_SkipNamingChimchar::
	goto PP_ReceivedChimchar
	end

PP_SkipNamingPiplup::
	goto PP_ReceivedPiplup
	end

PP_SkipNamingSnivy::
	goto PP_ReceivedSnivy
	end

PP_SkipNamingTepig::
	goto PP_ReceivedTepig
	end

PP_SkipNamingOshawott::
	goto PP_ReceivedOshawott
	end

PP_SkipNamingChespin::
	goto PP_ReceivedChespin
	end

PP_SkipNamingFennekin::
	goto PP_ReceivedFennekin
	end

PP_SkipNamingFroakie::
	goto PP_ReceivedFroakie
	end

PP_SkipNamingRowlet::
	goto PP_ReceivedRowlet
	end

PP_SkipNamingLitten::
	goto PP_ReceivedLitten
	end

PP_SkipNamingPopplio::
	goto PP_ReceivedPopplio
	end

PP_SkipNamingGrookey::
	goto PP_ReceivedGrookey
	end

PP_SkipNamingScorbunny::
	goto PP_ReceivedScorbunny
	end

PP_SkipNamingSobble::
	goto PP_ReceivedSobble
	end

PP_SkipNamingSprigatito::
	goto PP_ReceivedSprigatito
	end

PP_SkipNamingFuecoco::
	goto PP_ReceivedFuecoco
	end

PP_SkipNamingQuaxly::
	goto PP_ReceivedQuaxly
	end

PP_SkipNamingPikachu::
	goto PP_ReceivedPikachu
	end

PP_SkipNamingEevee::
	goto PP_ReceivedEevee
	end


//PP_PC Section//

PP_PCBulbasaur::
	call PP_CelebrateBulbasaur
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Bulbasaur
	call Common_EventScript_NameReceivedBoxMon

PP_PCCharmander::
	call PP_CelebrateCharmander
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Charmander
	call Common_EventScript_NameReceivedBoxMon

PP_PCSquirtle::
	call PP_CelebrateSquirtle
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Squirtle
	call Common_EventScript_NameReceivedBoxMon

PP_PCChikorita::
	call PP_CelebrateChikorita
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Chikorita
	call Common_EventScript_NameReceivedBoxMon

PP_PCCyndaquil::
	call PP_CelebrateCyndaquil
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Cyndaquil
	call Common_EventScript_NameReceivedBoxMon

PP_PCTotodile::
	call PP_CelebrateTotodile
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Totodile
	call Common_EventScript_NameReceivedBoxMon

PP_PCTreecko::
	call PP_CelebrateTreecko
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Treecko
	call Common_EventScript_NameReceivedBoxMon

PP_PCTorchic::
	call PP_CelebrateTorchic
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Torchic
	call Common_EventScript_NameReceivedBoxMon

PP_PCMudkip::
	call PP_CelebrateMudkip
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Mudkip
	call Common_EventScript_NameReceivedBoxMon

PP_PCTurtwig::
	call PP_CelebrateTurtwig
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Turtwig
	call Common_EventScript_NameReceivedBoxMon

PP_PCChimchar::
	call PP_CelebrateChimchar
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Chimchar
	call Common_EventScript_NameReceivedBoxMon

PP_PCPiplup::
	call PP_CelebratePiplup
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Piplup
	call Common_EventScript_NameReceivedBoxMon

PP_PCSnivy::
	call PP_CelebrateSnivy
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Snivy
	call Common_EventScript_NameReceivedBoxMon

PP_PCTepig::
	call PP_CelebrateTepig
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Tepig
	call Common_EventScript_NameReceivedBoxMon

PP_PCOshawott::
	call PP_CelebrateOshawott
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Oshawott
	call Common_EventScript_NameReceivedBoxMon

PP_PCChespin::
	call PP_CelebrateChespin
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Chespin
	call Common_EventScript_NameReceivedBoxMon

PP_PCFennekin::
	call PP_CelebrateFennekin
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Fennekin
	call Common_EventScript_NameReceivedBoxMon

PP_PCFroakie::
	call PP_CelebrateFroakie
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Froakie
	call Common_EventScript_NameReceivedBoxMon

PP_PCRowlet::
	call PP_CelebrateRowlet
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Rowlet
	call Common_EventScript_NameReceivedBoxMon

PP_PCLitten::
	call PP_CelebrateLitten
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Litten
	call Common_EventScript_NameReceivedBoxMon

PP_PCPopplio::
	call PP_CelebratePopplio
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Popplio
	call Common_EventScript_NameReceivedBoxMon

PP_PCGrookey::
	call PP_CelebrateGrookey
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Grookey
	call Common_EventScript_NameReceivedBoxMon

PP_PCScorbunny::
	call PP_CelebrateScorbunny
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Scorbunny
	call Common_EventScript_NameReceivedBoxMon

PP_PCSobble::
	call PP_CelebrateSobble
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Sobble
	call Common_EventScript_NameReceivedBoxMon

PP_PCSprigatito::
	call PP_CelebrateSprigatito
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Sprigatito
	call Common_EventScript_NameReceivedBoxMon

PP_PCFuecoco::
	call PP_CelebrateFuecoco
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Fuecoco
	call Common_EventScript_NameReceivedBoxMon

PP_PCQuaxly::
	call PP_CelebrateQuaxly
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Quaxly
	call Common_EventScript_NameReceivedBoxMon

PP_PCPikachu::
	call PP_CelebratePikachu
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Pikachu
	call Common_EventScript_NameReceivedBoxMon

PP_PCEevee::
	call PP_CelebrateEevee
	msgbox PP_NicknameChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO PP_SkipPCNaming_Eevee
	call Common_EventScript_NameReceivedBoxMon


//PP_SkipPCName Section//

PP_SkipPCNaming_Bulbasaur::
	goto PP_BulbasaurToPC
	end

PP_SkipPCNaming_Charmander::
	goto PP_CharmanderToPC
	end

PP_SkipPCNaming_Squirtle::
	goto PP_SquirtleToPC
	end

PP_SkipPCNaming_Chikorita::
	goto PP_ChikoritaToPC
	end

PP_SkipPCNaming_Cyndaquil::
	goto PP_CyndaquilToPC
	end

PP_SkipPCNaming_Totodile::
	goto PP_TotodileToPC
	end

PP_SkipPCNaming_Treecko::
	goto PP_TreeckoToPC
	end

PP_SkipPCNaming_Torchic::
	goto PP_TorchicToPC
	end

PP_SkipPCNaming_Mudkip::
	goto PP_MudkipToPC
	end

PP_SkipPCNaming_Turtwig::
	goto PP_TurtwigToPC
	end

PP_SkipPCNaming_Chimchar::
	goto PP_ChimcharToPC
	end

PP_SkipPCNaming_Piplup::
	goto PP_PiplupToPC
	end

PP_SkipPCNaming_Snivy::
	goto PP_SnivyToPC
	end

PP_SkipPCNaming_Tepig::
	goto PP_TepigToPC
	end

PP_SkipPCNaming_Oshawott::
	goto PP_OshawottToPC
	end

PP_SkipPCNaming_Chespin::
	goto PP_ChespinToPC
	end

PP_SkipPCNaming_Fennekin::
	goto PP_FennekinToPC
	end

PP_SkipPCNaming_Froakie::
	goto PP_FroakieToPC
	end

PP_SkipPCNaming_Rowlet::
	goto PP_RowletToPC
	end

PP_SkipPCNaming_Litten::
	goto PP_LittenToPC
	end

PP_SkipPCNaming_Popplio::
	goto PP_PopplioToPC
	end

PP_SkipPCNaming_Grookey::
	goto PP_GrookeyToPC
	end

PP_SkipPCNaming_Scorbunny::
	goto PP_ScorbunnyToPC
	end

PP_SkipPCNaming_Sobble::
	goto PP_SobbleToPC
	end

PP_SkipPCNaming_Sprigatito::
	goto PP_SprigatitoToPC
	end

PP_SkipPCNaming_Fuecoco::
	goto PP_FuecocoToPC
	end

PP_SkipPCNaming_Quaxly::
	goto PP_QuaxlyToPC
	end

PP_SkipPCNaming_Pikachu::
	goto PP_PikachuToPC
	end

PP_SkipPCNaming_Eevee::
	goto PP_EeveeToPC
	end


//PP_TO_PC Section//

PP_BulbasaurToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedBulbasaur
	end

PP_CharmanderToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedCharmander
	end

PP_SquirtleToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedSquirtle
	end

PP_ChikoritaToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedChikorita
	end

PP_CyndaquilToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedCyndaquil
	end

PP_TotodileToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedTotodile
	end

PP_TreeckoToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedTreecko
	end

PP_TorchicToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedTorchic
	end

PP_MudkipToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedMudkip
	end

PP_TurtwigToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedTurtwig
	end

PP_ChimcharToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedChimchar
	end

PP_PiplupToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedPiplup
	end

PP_SnivyToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedSnivy
	end

PP_TepigToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedTepig
	end

PP_OshawottToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedOshawott
	end

PP_ChespinToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedChespin
	end

PP_FennekinToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedFennekin
	end

PP_FroakieToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedFroakie
	end

PP_RowletToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedRowlet
	end

PP_LittenToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedLitten
	end

PP_PopplioToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedPopplio
	end

PP_GrookeyToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedGrookey
	end

PP_ScorbunnyToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedScorbunny
	end

PP_SobbleToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedSobble
	end

PP_SprigatitoToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedSprigatito
	end

PP_FuecocoToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedFuecoco
	end

PP_QuaxlyToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedQuaxly
	end

PP_PikachuToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedPikachu
	end

PP_EeveeToPC::
	call Common_EventScript_TransferredToPC
	goto PP_ReceivedEevee
	end


//PP_Received Section//

PP_ReceivedBulbasaur::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_BULBASAUR
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateBulbasaur
	delay 20
	releaseall
	end

PP_ReceivedCharmander::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_CHARMANDER
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateCharmander
	delay 20
	releaseall
	end

PP_ReceivedSquirtle::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_SQUIRTLE
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateSquirtle
	delay 20
	releaseall
	end

PP_ReceivedChikorita::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_CHIKORITA
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateChikorita
	delay 20
	releaseall
	end

PP_ReceivedCyndaquil::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_CYNDAQUIL
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateCyndaquil
	delay 20
	releaseall
	end

PP_ReceivedTotodile::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_TOTODILE
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateTotodile
	delay 20
	releaseall
	end

PP_ReceivedTreecko::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_TREECKO
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateTreecko
	delay 20
	releaseall
	end

PP_ReceivedTorchic::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_TORCHIC
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateTorchic
	delay 20
	releaseall
	end

PP_ReceivedMudkip::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_MUDKIP
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateMudkip
	delay 20
	releaseall
	end

PP_ReceivedTurtwig::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_TURTWIG
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateTurtwig
	delay 20
	releaseall
	end

PP_ReceivedChimchar::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_CHIMCHAR
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateChimchar
	delay 20
	releaseall
	end

PP_ReceivedPiplup::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_PIPLUP
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebratePiplup
	delay 20
	releaseall
	end

PP_ReceivedSnivy::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_SNIVY
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateSnivy
	delay 20
	releaseall
	end

PP_ReceivedTepig::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_TEPIG
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateTepig
	delay 20
	releaseall
	end

PP_ReceivedOshawott::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_OSHAWOTT
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateOshawott
	delay 20
	releaseall
	end

PP_ReceivedChespin::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_CHESPIN
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateChespin
	delay 20
	releaseall
	end

PP_ReceivedFennekin::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_FENNEKIN
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateFennekin
	delay 20
	releaseall
	end

PP_ReceivedFroakie::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_FROAKIE
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateFroakie
	delay 20
	releaseall
	end

PP_ReceivedRowlet::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_ROWLET
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateRowlet
	delay 20
	releaseall
	end

PP_ReceivedLitten::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_LITTEN
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateLitten
	delay 20
	releaseall
	end

PP_ReceivedPopplio::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_POPPLIO
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebratePopplio
	delay 20
	releaseall
	end

PP_ReceivedGrookey::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_GROOKEY
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateGrookey
	delay 20
	releaseall
	end

PP_ReceivedScorbunny::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_SCORBUNNY
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateScorbunny
	delay 20
	releaseall
	end

PP_ReceivedSobble::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_SOBBLE
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateSobble
	delay 20
	releaseall
	end

PP_ReceivedSprigatito::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_SPRIGATITO
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateSprigatito
	delay 20
	releaseall
	end

PP_ReceivedFuecoco::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_FUECOCO
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateFuecoco
	delay 20
	releaseall
	end

PP_ReceivedQuaxly::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_QUAXLY
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateQuaxly
	delay 20
	releaseall
	end

PP_ReceivedPikachu::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_PIKACHU
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebratePikachu
	delay 20
	releaseall
	end

PP_ReceivedEevee::
	hidemonpic
	delay 60
	playse SE_BALL_OPEN
	delay 30
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	delay 20
	playse SE_BALL
	delay 30
	playse SE_BALL
	delay 40
	playse SE_BALL
	delay 50
	playse SE_RG_BALL_CLICK
	delay 20
	setflag FLAG_PP_EEVEE
	applymovement 0x1E, Movement_PPByeMon
	waitmovement 0x1E
	call PP_CelebrateEevee
	delay 20
	releaseall
	end


//PP_Celebrate Section//

PP_CelebrateBulbasaur::
	playfanfare MUS_OBTAIN_ITEM
	message PP_BulbasaurText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateCharmander::
	playfanfare MUS_OBTAIN_ITEM
	message PP_CharmanderText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateSquirtle::
	playfanfare MUS_OBTAIN_ITEM
	message PP_SquirtleText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateChikorita::
	playfanfare MUS_OBTAIN_ITEM
	message PP_ChikoritaText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateCyndaquil::
	playfanfare MUS_OBTAIN_ITEM
	message PP_CyndaquilText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateTotodile::
	playfanfare MUS_OBTAIN_ITEM
	message PP_TotodileText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateTreecko::
	playfanfare MUS_OBTAIN_ITEM
	message PP_TreeckoText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateTorchic::
	playfanfare MUS_OBTAIN_ITEM
	message PP_TorchicText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateMudkip::
	playfanfare MUS_OBTAIN_ITEM
	message PP_MudkipText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateTurtwig::
	playfanfare MUS_OBTAIN_ITEM
	message PP_TurtwigText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateChimchar::
	playfanfare MUS_OBTAIN_ITEM
	message PP_ChimcharText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebratePiplup::
	playfanfare MUS_OBTAIN_ITEM
	message PP_PiplupText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateSnivy::
	playfanfare MUS_OBTAIN_ITEM
	message PP_SnivyText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateTepig::
	playfanfare MUS_OBTAIN_ITEM
	message PP_TepigText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateOshawott::
	playfanfare MUS_OBTAIN_ITEM
	message PP_OshawottText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateChespin::
	playfanfare MUS_OBTAIN_ITEM
	message PP_ChespinText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateFennekin::
	playfanfare MUS_OBTAIN_ITEM
	message PP_FennekinText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateFroakie::
	playfanfare MUS_OBTAIN_ITEM
	message PP_FroakieText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateRowlet::
	playfanfare MUS_OBTAIN_ITEM
	message PP_RowletText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateLitten::
	playfanfare MUS_OBTAIN_ITEM
	message PP_LittenText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebratePopplio::
	playfanfare MUS_OBTAIN_ITEM
	message PP_PopplioText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateGrookey::
	playfanfare MUS_OBTAIN_ITEM
	message PP_GrookeyText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateScorbunny::
	playfanfare MUS_OBTAIN_ITEM
	message PP_ScorbunnyText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateSobble::
	playfanfare MUS_OBTAIN_ITEM
	message PP_SobbleText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateSprigatito::
	playfanfare MUS_OBTAIN_ITEM
	message PP_SprigatitoText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateFuecoco::
	playfanfare MUS_OBTAIN_ITEM
	message PP_FuecocoText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateQuaxly::
	playfanfare MUS_OBTAIN_ITEM
	message PP_QuaxlyText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebratePikachu::
	playfanfare MUS_OBTAIN_ITEM
	message PP_PikachuText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return

PP_CelebrateEevee::
	playfanfare MUS_OBTAIN_ITEM
	message PP_EeveeText1
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	return


//PP_Choice Section//

PP_BulbasaurChoice::
    .string "Do you want to take Bulbasaur with\n"
    .string "you to be your first partner POKéMON?$"

PP_CharmanderChoice::
    .string "Do you want to take Charmander with\n"
    .string "you to be your first partner POKéMON?$"

PP_SquirtleChoice::
    .string "Do you want to take Squirtle with\n"
    .string "you to be your first partner POKéMON?$"

PP_ChikoritaChoice::
    .string "Do you want to take Chikorita with\n"
    .string "you to be your first partner POKéMON?$"

PP_CyndaquilChoice::
    .string "Do you want to take Cyndaquil with\n"
    .string "you to be your first partner POKéMON?$"

PP_TotodileChoice::
    .string "Do you want to take Totodile with\n"
    .string "you to be your first partner POKéMON?$"

PP_TreeckoChoice::
    .string "Do you want to take Treecko with\n"
    .string "you to be your first partner POKéMON?$"

PP_TorchicChoice::
    .string "Do you want to take Torchic with\n"
    .string "you to be your first partner POKéMON?$"

PP_MudkipChoice::
    .string "Do you want to take Mudkip with\n"
    .string "you to be your first partner POKéMON?$"

PP_TurtwigChoice::
    .string "Do you want to take Turtwig with\n"
    .string "you to be your first partner POKéMON?$"

PP_ChimcharChoice::
    .string "Do you want to take Chimchar with\n"
    .string "you to be your first partner POKéMON?$"

PP_PiplupChoice::
    .string "Do you want to take Piplup with\n"
    .string "you to be your first partner POKéMON?$"

PP_SnivyChoice::
    .string "Do you want to take Snivy with\n"
    .string "you to be your first partner POKéMON?$"

PP_TepigChoice::
    .string "Do you want to take Tepig with\n"
    .string "you to be your first partner POKéMON?$"

PP_OshawottChoice::
    .string "Do you want to take Oshawott with\n"
    .string "you to be your first partner POKéMON?$"

PP_ChespinChoice::
    .string "Do you want to take Chespin with\n"
    .string "you to be your first partner POKéMON?$"

PP_FennekinChoice::
    .string "Do you want to take Fennekin with\n"
    .string "you to be your first partner POKéMON?$"

PP_FroakieChoice::
    .string "Do you want to take Froakie with\n"
    .string "you to be your first partner POKéMON?$"

PP_RowletChoice::
    .string "Do you want to take Rowlet with\n"
    .string "you to be your first partner POKéMON?$"

PP_LittenChoice::
    .string "Do you want to take Litten with\n"
    .string "you to be your first partner POKéMON?$"

PP_PopplioChoice::
    .string "Do you want to take Popplio with\n"
    .string "you to be your first partner POKéMON?$"

PP_GrookeyChoice::
    .string "Do you want to take Grookey with\n"
    .string "you to be your first partner POKéMON?$"

PP_ScorbunnyChoice::
    .string "Do you want to take Scorbunny with\n"
    .string "you to be your first partner POKéMON?$"

PP_SobbleChoice::
    .string "Do you want to take Sobble with\n"
    .string "you to be your first partner POKéMON?$"

PP_SprigatitoChoice::
    .string "Do you want to take Sprigatito with\n"
    .string "you to be your first partner POKéMON?$"

PP_FuecocoChoice::
    .string "Do you want to take Fuecoco with\n"
    .string "you to be your first partner POKéMON?$"

PP_QuaxlyChoice::
    .string "Do you want to take Quaxly with\n"
    .string "you to be your first partner POKéMON?$"

PP_PikachuChoice::
    .string "Do you want to take Pikachu with\n"
    .string "you to be your first partner POKéMON?$"

PP_EeveeChoice::
    .string "Do you want to take Eevee with\n"
    .string "you to be your first partner POKéMON?$"

//PP_Text1 Section//

PP_BulbasaurText1::
    .string "You received Bulbasaur!\n"
    .string "The Grass and Poison Type \"Seed\" POKéMON.$"

PP_CharmanderText1::
    .string "You received Charmander!\n"
    .string "The Fire-Type \"Lizard\" POKéMON.$"

PP_SquirtleText1::
    .string "You received Squirtle!\n"
    .string "The Water-Type \"Tiny Turtle\" POKéMON.$"

PP_ChikoritaText1::
    .string "You received Chikorita!\n"
    .string "The Grass-Type \"Leaf\" POKéMON.$"

PP_CyndaquilText1::
    .string "You received Cyndaquil!\n"
    .string "The Fire-Type \"Fire Mouse\" POKéMON.$"

PP_TotodileText1::
    .string "You received Totodile!\n"
    .string "The Water-Type \"Big Jaw\" POKéMON.$"

PP_TreeckoText1::
    .string "You received Treecko!\n"
    .string "The Grass-Type \"Wood Gecko\" POKéMON.$"

PP_TorchicText1::
    .string "You received Torchic!\n"
    .string "The Fire-Type \"Chick\" POKéMON.$"

PP_MudkipText1::
    .string "You received Mudkip!\n"
    .string "The Water-Type \"Mud Fish\" POKéMON.$"

PP_TurtwigText1::
    .string "You received Turtwig!\n"
    .string "The Grass-Type \"Tiny Leaf\" POKéMON.$"

PP_ChimcharText1::
    .string "You received Chimchar!\n"
    .string "The Fire-Type \"Chimp\" POKéMON.$"

PP_PiplupText1::
    .string "You received Piplup!\n"
    .string "The Water-Type \"Penguin\" POKéMON.$"

PP_SnivyText1::
    .string "You received Snivy!\n"
    .string "The Grass-Type \"Grass Snake\" POKéMON.$"

PP_TepigText1::
    .string "You received Tepig!\n"
    .string "The Fire-Type \"Fire Pig\" POKéMON.$"

PP_OshawottText1::
    .string "You received Oshawott!\n"
    .string "The Water-Type \"Sea Otter\" POKéMON.$"

PP_ChespinText1::
    .string "You received Chespin!\n"
    .string "The Grass-Type \"Spiny Nut\" POKéMON.$"

PP_FennekinText1::
    .string "You received Fennekin!\n"
    .string "The Fire-Type \"Fox\" POKéMON.$"

PP_FroakieText1::
    .string "You received Froakie!\n"
    .string "The Water-Type \"Bubble Frog\" POKéMON.$"

PP_RowletText1::
    .string "You received Rowlet!\n"
    .string "The Grass and Flying Type \"Grass Quill\" POKéMON.$"

PP_LittenText1::
    .string "You received Litten!\n"
    .string "The Fire-Type \"Fire Cat\" POKéMON.$"

PP_PopplioText1::
    .string "You received Popplio!\n"
    .string "The Water-Type \"Sea Lion\" POKéMON.$"

PP_GrookeyText1::
    .string "You received Grookey!\n"
    .string "The Grass-Type \"Chimp\" POKéMON.$"

PP_ScorbunnyText1::
    .string "You received Scorbunny!\n"
    .string "The Fire-Type \"Rabbit\" POKéMON.$"

PP_SobbleText1::
    .string "You received Sobble!\n"
    .string "The Water-Type \"Water Lizard\" POKéMON.$"

PP_SprigatitoText1::
    .string "You received Sprigatito!\n"
    .string "The Grass-Type \"Grass Cat\" POKéMON.$"

PP_FuecocoText1::
    .string "You received Fuecoco!\n"
    .string "The Fire-Type \"Fire Croc\" POKéMON.$"

PP_QuaxlyText1::
    .string "You received Quaxly!\n"
    .string "The Water-Type \"Duckling\" POKéMON.$"

PP_PikachuText1::
    .string "You received Pikachu!\n"
    .string "The Electric-Type \"Mouse\" POKéMON.$"

PP_EeveeText1::
    .string "You received Eevee!\n"
    .string "The Normal-Type \"Evolution\" POKéMON.$"

Movement_PPByeMon::
	set_invisible
	step_end


