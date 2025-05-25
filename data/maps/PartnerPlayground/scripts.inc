PartnerPlayground_MapScripts::
	.byte 0

PartnerPlayground_EventScript_Sign::
	msgbox PartnerPlayground_Text_Sign, MSGBOX_SIGN
	end

PartnerPlayground_EventScript_Machamp::
	msgbox PartnerPlayground_Text_Machamp, MSGBOX_NPC
	end

PartnerPlayground_EventScript_NotChosen::
	msgbox PartnerPlayground_EventScript_NotChosen, MSGBOX_NPC
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

PartnerPlayground_EventScript_Mudkip::
# 5 "data/maps/PartnerPlayground/scripts.pory"
	showmonpic SPECIES_MUDKIP, 10, 3
# 6 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_0, MSGBOX_YESNO
# 7 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PartnerPlayground_EventScript_Mudkip_1
# 29 "data/maps/PartnerPlayground/scripts.pory"
	hidemonpic
# 30 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_NotChosen
	end

PartnerPlayground_EventScript_Mudkip_1:
# 8 "data/maps/PartnerPlayground/scripts.pory"
	givemon SPECIES_MUDKIP, 5, ITEM_MASTER_BALL
# 9 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq PartnerPlayground_EventScript_Mudkip_4
# 16 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq PartnerPlayground_EventScript_Mudkip_5
# 24 "data/maps/PartnerPlayground/scripts.pory"
	hidemonpic
# 25 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_2
	return

PartnerPlayground_EventScript_Mudkip_4:
# 10 "data/maps/PartnerPlayground/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 11 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_1
# 12 "data/maps/PartnerPlayground/scripts.pory"
	removeobject 1
# 13 "data/maps/PartnerPlayground/scripts.pory"
	setflag FLAG_UNUSED_0x020
# 14 "data/maps/PartnerPlayground/scripts.pory"
	call NicknamePartyMon
	return

PartnerPlayground_EventScript_Mudkip_5:
# 17 "data/maps/PartnerPlayground/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 18 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_1
# 19 "data/maps/PartnerPlayground/scripts.pory"
	removeobject 1
# 20 "data/maps/PartnerPlayground/scripts.pory"
	setflag FLAG_UNUSED_0x020
# 21 "data/maps/PartnerPlayground/scripts.pory"
	call NicknameBoxMon
	return


PartnerPlayground_EventScript_Totodile::
# 36 "data/maps/PartnerPlayground/scripts.pory"
	showmonpic SPECIES_TOTODILE, 10, 3
# 37 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Totodile_Text_0, MSGBOX_YESNO
# 38 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PartnerPlayground_EventScript_Totodile_1
# 60 "data/maps/PartnerPlayground/scripts.pory"
	hidemonpic
# 61 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_NotChosen
	end

PartnerPlayground_EventScript_Totodile_1:
# 39 "data/maps/PartnerPlayground/scripts.pory"
	givemon SPECIES_TOTODILE, 5, ITEM_MASTER_BALL
# 40 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq PartnerPlayground_EventScript_Totodile_4
# 47 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq PartnerPlayground_EventScript_Totodile_5
# 55 "data/maps/PartnerPlayground/scripts.pory"
	hidemonpic
# 56 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_2
	return

PartnerPlayground_EventScript_Totodile_4:
# 41 "data/maps/PartnerPlayground/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 42 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Totodile_Text_1
# 43 "data/maps/PartnerPlayground/scripts.pory"
	removeobject 1
# 44 "data/maps/PartnerPlayground/scripts.pory"
	setflag FLAG_UNUSED_0x020
# 45 "data/maps/PartnerPlayground/scripts.pory"
	call NicknamePartyMon
	return

PartnerPlayground_EventScript_Totodile_5:
# 48 "data/maps/PartnerPlayground/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 49 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Totodile_Text_1
# 50 "data/maps/PartnerPlayground/scripts.pory"
	removeobject 1
# 51 "data/maps/PartnerPlayground/scripts.pory"
	setflag FLAG_UNUSED_0x020
# 52 "data/maps/PartnerPlayground/scripts.pory"
	call NicknameBoxMon
	return


PartnerPlayground_EventScript_Squirtle::
# 67 "data/maps/PartnerPlayground/scripts.pory"
	showmonpic SPECIES_SQUIRTLE, 10, 3
# 68 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Squirtle_Text_0, MSGBOX_YESNO
# 69 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PartnerPlayground_EventScript_Squirtle_1
# 91 "data/maps/PartnerPlayground/scripts.pory"
	hidemonpic
# 92 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_NotChosen
	end

PartnerPlayground_EventScript_Squirtle_1:
# 70 "data/maps/PartnerPlayground/scripts.pory"
	givemon SPECIES_SQUIRTLE, 5, ITEM_MASTER_BALL
# 71 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq PartnerPlayground_EventScript_Squirtle_4
# 78 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq PartnerPlayground_EventScript_Squirtle_5
# 86 "data/maps/PartnerPlayground/scripts.pory"
	hidemonpic
# 87 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_2
	return

PartnerPlayground_EventScript_Squirtle_4:
# 72 "data/maps/PartnerPlayground/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 73 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Squirtle_Text_1
# 74 "data/maps/PartnerPlayground/scripts.pory"
	removeobject 1
# 75 "data/maps/PartnerPlayground/scripts.pory"
	setflag FLAG_UNUSED_0x020
# 76 "data/maps/PartnerPlayground/scripts.pory"
	call NicknamePartyMon
	return

PartnerPlayground_EventScript_Squirtle_5:
# 79 "data/maps/PartnerPlayground/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 80 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Squirtle_Text_1
# 81 "data/maps/PartnerPlayground/scripts.pory"
	removeobject 1
# 82 "data/maps/PartnerPlayground/scripts.pory"
	setflag FLAG_UNUSED_0x020
# 83 "data/maps/PartnerPlayground/scripts.pory"
	call NicknameBoxMon
	return


PartnerPlayground_EventScript_Treecko::
# 98 "data/maps/PartnerPlayground/scripts.pory"
	showmonpic SPECIES_TREECKO, 10, 3
# 99 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Treecko_Text_0, MSGBOX_YESNO
# 100 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PartnerPlayground_EventScript_Treecko_1
# 122 "data/maps/PartnerPlayground/scripts.pory"
	hidemonpic
# 123 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_NotChosen
	end

PartnerPlayground_EventScript_Treecko_1:
# 101 "data/maps/PartnerPlayground/scripts.pory"
	givemon SPECIES_TREECKO, 5, ITEM_MASTER_BALL
# 102 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq PartnerPlayground_EventScript_Treecko_4
# 109 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq PartnerPlayground_EventScript_Treecko_5
# 117 "data/maps/PartnerPlayground/scripts.pory"
	hidemonpic
# 118 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_2
	return

PartnerPlayground_EventScript_Treecko_4:
# 103 "data/maps/PartnerPlayground/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 104 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Treecko_Text_1
# 105 "data/maps/PartnerPlayground/scripts.pory"
	removeobject 2
# 106 "data/maps/PartnerPlayground/scripts.pory"
	setflag FLAG_UNUSED_0x021
# 107 "data/maps/PartnerPlayground/scripts.pory"
	call NicknamePartyMon
	return

PartnerPlayground_EventScript_Treecko_5:
# 110 "data/maps/PartnerPlayground/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 111 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Treecko_Text_1
# 112 "data/maps/PartnerPlayground/scripts.pory"
	removeobject 2
# 113 "data/maps/PartnerPlayground/scripts.pory"
	setflag FLAG_UNUSED_0x021
# 114 "data/maps/PartnerPlayground/scripts.pory"
	call NicknameBoxMon
	return


PartnerPlayground_EventScript_Chikorita::
# 129 "data/maps/PartnerPlayground/scripts.pory"
	showmonpic SPECIES_CHIKORITA, 10, 3
# 130 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Chikorita_Text_0, MSGBOX_YESNO
# 131 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PartnerPlayground_EventScript_Chikorita_1
# 153 "data/maps/PartnerPlayground/scripts.pory"
	hidemonpic
# 154 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_NotChosen
	end

PartnerPlayground_EventScript_Chikorita_1:
# 132 "data/maps/PartnerPlayground/scripts.pory"
	givemon SPECIES_CHIKORITA, 5, ITEM_MASTER_BALL
# 133 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq PartnerPlayground_EventScript_Chikorita_4
# 140 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq PartnerPlayground_EventScript_Chikorita_5
# 148 "data/maps/PartnerPlayground/scripts.pory"
	hidemonpic
# 149 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_2
	return

PartnerPlayground_EventScript_Chikorita_4:
# 134 "data/maps/PartnerPlayground/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 135 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Chikorita_Text_1
# 136 "data/maps/PartnerPlayground/scripts.pory"
	removeobject 2
# 137 "data/maps/PartnerPlayground/scripts.pory"
	setflag FLAG_UNUSED_0x021
# 138 "data/maps/PartnerPlayground/scripts.pory"
	call NicknamePartyMon
	return

PartnerPlayground_EventScript_Chikorita_5:
# 141 "data/maps/PartnerPlayground/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 142 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Chikorita_Text_1
# 143 "data/maps/PartnerPlayground/scripts.pory"
	removeobject 2
# 144 "data/maps/PartnerPlayground/scripts.pory"
	setflag FLAG_UNUSED_0x021
# 145 "data/maps/PartnerPlayground/scripts.pory"
	call NicknameBoxMon
	return


PartnerPlayground_EventScript_Bulbasaur::
# 160 "data/maps/PartnerPlayground/scripts.pory"
	showmonpic SPECIES_BULBASAUR, 10, 3
# 161 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Bulbasaur_Text_0, MSGBOX_YESNO
# 162 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PartnerPlayground_EventScript_Bulbasaur_1
# 184 "data/maps/PartnerPlayground/scripts.pory"
	hidemonpic
# 185 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_NotChosen
	end

PartnerPlayground_EventScript_Bulbasaur_1:
# 163 "data/maps/PartnerPlayground/scripts.pory"
	givemon SPECIES_BULBASAUR, 5, ITEM_MASTER_BALL
# 164 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq PartnerPlayground_EventScript_Bulbasaur_4
# 171 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq PartnerPlayground_EventScript_Bulbasaur_5
# 179 "data/maps/PartnerPlayground/scripts.pory"
	hidemonpic
# 180 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_2
	return

PartnerPlayground_EventScript_Bulbasaur_4:
# 165 "data/maps/PartnerPlayground/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 166 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Bulbasaur_Text_1
# 167 "data/maps/PartnerPlayground/scripts.pory"
	removeobject 2
# 168 "data/maps/PartnerPlayground/scripts.pory"
	setflag FLAG_UNUSED_0x021
# 169 "data/maps/PartnerPlayground/scripts.pory"
	call NicknamePartyMon
	return

PartnerPlayground_EventScript_Bulbasaur_5:
# 172 "data/maps/PartnerPlayground/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 173 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Bulbasaur_Text_1
# 174 "data/maps/PartnerPlayground/scripts.pory"
	removeobject 2
# 175 "data/maps/PartnerPlayground/scripts.pory"
	setflag FLAG_UNUSED_0x021
# 176 "data/maps/PartnerPlayground/scripts.pory"
	call NicknameBoxMon
	return


PartnerPlayground_EventScript_Torchic::
# 191 "data/maps/PartnerPlayground/scripts.pory"
	showmonpic SPECIES_TORCHIC, 10, 3
# 192 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Torchic_Text_0, MSGBOX_YESNO
# 193 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PartnerPlayground_EventScript_Torchic_1
# 215 "data/maps/PartnerPlayground/scripts.pory"
	hidemonpic
# 216 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_NotChosen
	end

PartnerPlayground_EventScript_Torchic_1:
# 194 "data/maps/PartnerPlayground/scripts.pory"
	givemon SPECIES_TORCHIC, 5, ITEM_MASTER_BALL
# 195 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq PartnerPlayground_EventScript_Torchic_4
# 202 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq PartnerPlayground_EventScript_Torchic_5
# 210 "data/maps/PartnerPlayground/scripts.pory"
	hidemonpic
# 211 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_2
	return

PartnerPlayground_EventScript_Torchic_4:
# 196 "data/maps/PartnerPlayground/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 197 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Torchic_Text_1
# 198 "data/maps/PartnerPlayground/scripts.pory"
	removeobject 3
# 199 "data/maps/PartnerPlayground/scripts.pory"
	setflag FLAG_UNUSED_0x022
# 200 "data/maps/PartnerPlayground/scripts.pory"
	call NicknamePartyMon
	return

PartnerPlayground_EventScript_Torchic_5:
# 203 "data/maps/PartnerPlayground/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 204 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Torchic_Text_1
# 205 "data/maps/PartnerPlayground/scripts.pory"
	removeobject 3
# 206 "data/maps/PartnerPlayground/scripts.pory"
	setflag FLAG_UNUSED_0x022
# 207 "data/maps/PartnerPlayground/scripts.pory"
	call NicknameBoxMon
	return


PartnerPlayground_EventScript_Cyndaquil::
# 222 "data/maps/PartnerPlayground/scripts.pory"
	showmonpic SPECIES_CYNDAQUIL, 10, 3
# 223 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Cyndaquil_Text_0, MSGBOX_YESNO
# 224 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PartnerPlayground_EventScript_Cyndaquil_1
# 246 "data/maps/PartnerPlayground/scripts.pory"
	hidemonpic
# 247 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_NotChosen
	end

PartnerPlayground_EventScript_Cyndaquil_1:
# 225 "data/maps/PartnerPlayground/scripts.pory"
	givemon SPECIES_CYNDAQUIL, 5, ITEM_MASTER_BALL
# 226 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq PartnerPlayground_EventScript_Cyndaquil_4
# 233 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq PartnerPlayground_EventScript_Cyndaquil_5
# 241 "data/maps/PartnerPlayground/scripts.pory"
	hidemonpic
# 242 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_2
	return

PartnerPlayground_EventScript_Cyndaquil_4:
# 227 "data/maps/PartnerPlayground/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 228 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Cyndaquil_Text_1
# 229 "data/maps/PartnerPlayground/scripts.pory"
	removeobject 3
# 230 "data/maps/PartnerPlayground/scripts.pory"
	setflag FLAG_UNUSED_0x022
# 231 "data/maps/PartnerPlayground/scripts.pory"
	call NicknamePartyMon
	return

PartnerPlayground_EventScript_Cyndaquil_5:
# 234 "data/maps/PartnerPlayground/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 235 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Cyndaquil_Text_1
# 236 "data/maps/PartnerPlayground/scripts.pory"
	removeobject 3
# 237 "data/maps/PartnerPlayground/scripts.pory"
	setflag FLAG_UNUSED_0x022
# 238 "data/maps/PartnerPlayground/scripts.pory"
	call NicknameBoxMon
	return


PartnerPlayground_EventScript_Charmander::
# 253 "data/maps/PartnerPlayground/scripts.pory"
	showmonpic SPECIES_CHARMANDER, 10, 3
# 254 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Charmander_Text_0, MSGBOX_YESNO
# 255 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PartnerPlayground_EventScript_Charmander_1
# 277 "data/maps/PartnerPlayground/scripts.pory"
	hidemonpic
# 278 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_NotChosen
	end

PartnerPlayground_EventScript_Charmander_1:
# 256 "data/maps/PartnerPlayground/scripts.pory"
	givemon SPECIES_CHARMANDER, 5, ITEM_MASTER_BALL
# 257 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq PartnerPlayground_EventScript_Charmander_4
# 264 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq PartnerPlayground_EventScript_Charmander_5
# 272 "data/maps/PartnerPlayground/scripts.pory"
	hidemonpic
# 273 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_2
	return

PartnerPlayground_EventScript_Charmander_4:
# 258 "data/maps/PartnerPlayground/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 259 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Charmander_Text_1
# 260 "data/maps/PartnerPlayground/scripts.pory"
	removeobject 3
# 261 "data/maps/PartnerPlayground/scripts.pory"
	setflag FLAG_UNUSED_0x022
# 262 "data/maps/PartnerPlayground/scripts.pory"
	call NicknamePartyMon
	return

PartnerPlayground_EventScript_Charmander_5:
# 265 "data/maps/PartnerPlayground/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 266 "data/maps/PartnerPlayground/scripts.pory"
	msgbox PartnerPlayground_EventScript_Charmander_Text_1
# 267 "data/maps/PartnerPlayground/scripts.pory"
	removeobject 3
# 268 "data/maps/PartnerPlayground/scripts.pory"
	setflag FLAG_UNUSED_0x022
# 269 "data/maps/PartnerPlayground/scripts.pory"
	call NicknameBoxMon
	return


NicknamePartyMon::
# 285 "data/maps/PartnerPlayground/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 286 "data/maps/PartnerPlayground/scripts.pory"
	hidemonpic
# 287 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_2
NicknamePartyMon_1:
# 291 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq NicknamePartyMon_4
	return

NicknamePartyMon_2:
# 288 "data/maps/PartnerPlayground/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 289 "data/maps/PartnerPlayground/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto NicknamePartyMon_1

NicknamePartyMon_4:
	end


NicknameBoxMon::
# 297 "data/maps/PartnerPlayground/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 298 "data/maps/PartnerPlayground/scripts.pory"
	hidemonpic
# 299 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknameBoxMon_2
NicknameBoxMon_1:
# 303 "data/maps/PartnerPlayground/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq NicknameBoxMon_5
# 307 "data/maps/PartnerPlayground/scripts.pory"
	msgbox NicknameBoxMon_Text_0
	return

NicknameBoxMon_2:
# 300 "data/maps/PartnerPlayground/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
	goto NicknameBoxMon_1

NicknameBoxMon_5:
	end


PartnerPlayground_EventScript_Mudkip_Text_0:
# 6 "data/maps/PartnerPlayground/scripts.pory"
	.string "Do you want to choose Mudkip?$"

PartnerPlayground_EventScript_Mudkip_Text_1:
# 11 "data/maps/PartnerPlayground/scripts.pory"
	.string "Recieved Mudkip$"

PartnerPlayground_EventScript_Mudkip_Text_2:
# 25 "data/maps/PartnerPlayground/scripts.pory"
	.string "No More Room$"

PartnerPlayground_EventScript_Totodile_Text_0:
# 37 "data/maps/PartnerPlayground/scripts.pory"
	.string "Do you want to choose Totodile?$"

PartnerPlayground_EventScript_Totodile_Text_1:
# 42 "data/maps/PartnerPlayground/scripts.pory"
	.string "Recieved Totodile$"

PartnerPlayground_EventScript_Squirtle_Text_0:
# 68 "data/maps/PartnerPlayground/scripts.pory"
	.string "Do you want to choose Squirtle?$"

PartnerPlayground_EventScript_Squirtle_Text_1:
# 73 "data/maps/PartnerPlayground/scripts.pory"
	.string "Recieved Squirtle$"

PartnerPlayground_EventScript_Treecko_Text_0:
# 99 "data/maps/PartnerPlayground/scripts.pory"
	.string "Do you want to choose Treecko?$"

PartnerPlayground_EventScript_Treecko_Text_1:
# 104 "data/maps/PartnerPlayground/scripts.pory"
	.string "Recieved Treecko$"

PartnerPlayground_EventScript_Chikorita_Text_0:
# 130 "data/maps/PartnerPlayground/scripts.pory"
	.string "Do you want to choose Chikorita?$"

PartnerPlayground_EventScript_Chikorita_Text_1:
# 135 "data/maps/PartnerPlayground/scripts.pory"
	.string "Recieved Chikorita$"

PartnerPlayground_EventScript_Bulbasaur_Text_0:
# 161 "data/maps/PartnerPlayground/scripts.pory"
	.string "Do you want to choose Bulbasaur?$"

PartnerPlayground_EventScript_Bulbasaur_Text_1:
# 166 "data/maps/PartnerPlayground/scripts.pory"
	.string "Recieved Bulbasaur$"

PartnerPlayground_EventScript_Torchic_Text_0:
# 192 "data/maps/PartnerPlayground/scripts.pory"
	.string "Do you want to choose Torchic?$"

PartnerPlayground_EventScript_Torchic_Text_1:
# 197 "data/maps/PartnerPlayground/scripts.pory"
	.string "Recieved Torchic$"

PartnerPlayground_EventScript_Cyndaquil_Text_0:
# 223 "data/maps/PartnerPlayground/scripts.pory"
	.string "Do you want to choose Cyndaquil?$"

PartnerPlayground_EventScript_Cyndaquil_Text_1:
# 228 "data/maps/PartnerPlayground/scripts.pory"
	.string "Recieved Cyndaquil$"

PartnerPlayground_EventScript_Charmander_Text_0:
# 254 "data/maps/PartnerPlayground/scripts.pory"
	.string "Do you want to choose Charmander?$"

PartnerPlayground_EventScript_Charmander_Text_1:
# 259 "data/maps/PartnerPlayground/scripts.pory"
	.string "Recieved Charmander$"

NicknamePartyMon_Text_0:
# 285 "data/maps/PartnerPlayground/scripts.pory"
	.string "Give a nickname?$"

NicknameBoxMon_Text_0:
# 307 "data/maps/PartnerPlayground/scripts.pory"
	.string "Transferred to PC$"

PartnerPlayground_NotChosen::
	.string "You did not choose the Pokemon$"

