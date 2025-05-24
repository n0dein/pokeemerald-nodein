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

PartnerPlayground_EventScript_Mudkip::
# 5 "data/scripts/scripts.pory"
	showmonpic SPECIES_MUDKIP, 10, 3
# 6 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_0, MSGBOX_YESNO
# 7 "data/scripts/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PartnerPlayground_EventScript_Mudkip_1
# 29 "data/scripts/scripts.pory"
	hidemonpic
# 30 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_NotChosen
	return

PartnerPlayground_EventScript_Mudkip_1:
# 8 "data/scripts/scripts.pory"
	givemon SPECIES_MUDKIP, 50, ITEM_MASTER_BALL
# 9 "data/scripts/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq PartnerPlayground_EventScript_Mudkip_4
# 16 "data/scripts/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq PartnerPlayground_EventScript_Mudkip_5
# 24 "data/scripts/scripts.pory"
	hidemonpic
# 25 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_2
	return

PartnerPlayground_EventScript_Mudkip_4:
# 10 "data/scripts/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 11 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_1
# 12 "data/scripts/scripts.pory"
	removeobject 1
# 13 "data/scripts/scripts.pory"
	setflag FLAG_UNUSED_0x020
# 14 "data/scripts/scripts.pory"
	call NicknamePartyMon
	return

PartnerPlayground_EventScript_Mudkip_5:
# 17 "data/scripts/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 18 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_1
# 19 "data/scripts/scripts.pory"
	removeobject 1
# 20 "data/scripts/scripts.pory"
	setflag FLAG_UNUSED_0x020
# 21 "data/scripts/scripts.pory"
	call NicknameBoxMon
	return


PartnerPlayground_EventScript_Totodile::
# 36 "data/scripts/scripts.pory"
	showmonpic SPECIES_TOTODILE, 10, 3
# 37 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Totodile_Text_0, MSGBOX_YESNO
# 38 "data/scripts/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PartnerPlayground_EventScript_Totodile_1
# 60 "data/scripts/scripts.pory"
	hidemonpic
# 61 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_NotChosen
	return

PartnerPlayground_EventScript_Totodile_1:
# 39 "data/scripts/scripts.pory"
	givemon SPECIES_TOTODILE, 50, ITEM_MASTER_BALL
# 40 "data/scripts/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq PartnerPlayground_EventScript_Totodile_4
# 47 "data/scripts/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq PartnerPlayground_EventScript_Totodile_5
# 55 "data/scripts/scripts.pory"
	hidemonpic
# 56 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_2
	return

PartnerPlayground_EventScript_Totodile_4:
# 41 "data/scripts/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 42 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Totodile_Text_1
# 43 "data/scripts/scripts.pory"
	removeobject 1
# 44 "data/scripts/scripts.pory"
	setflag FLAG_UNUSED_0x020
# 45 "data/scripts/scripts.pory"
	call NicknamePartyMon
	return

PartnerPlayground_EventScript_Totodile_5:
# 48 "data/scripts/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 49 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Totodile_Text_1
# 50 "data/scripts/scripts.pory"
	removeobject 1
# 51 "data/scripts/scripts.pory"
	setflag FLAG_UNUSED_0x020
# 52 "data/scripts/scripts.pory"
	call NicknameBoxMon
	return


PartnerPlayground_EventScript_Squirtle::
# 67 "data/scripts/scripts.pory"
	showmonpic SPECIES_SQUIRTLE, 10, 3
# 68 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Squirtle_Text_0, MSGBOX_YESNO
# 69 "data/scripts/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PartnerPlayground_EventScript_Squirtle_1
# 91 "data/scripts/scripts.pory"
	hidemonpic
# 92 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_NotChosen
	return

PartnerPlayground_EventScript_Squirtle_1:
# 70 "data/scripts/scripts.pory"
	givemon SPECIES_SQUIRTLE, 50, ITEM_MASTER_BALL
# 71 "data/scripts/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq PartnerPlayground_EventScript_Squirtle_4
# 78 "data/scripts/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq PartnerPlayground_EventScript_Squirtle_5
# 86 "data/scripts/scripts.pory"
	hidemonpic
# 87 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_2
	return

PartnerPlayground_EventScript_Squirtle_4:
# 72 "data/scripts/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 73 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Squirtle_Text_1
# 74 "data/scripts/scripts.pory"
	removeobject 1
# 75 "data/scripts/scripts.pory"
	setflag FLAG_UNUSED_0x020
# 76 "data/scripts/scripts.pory"
	call NicknamePartyMon
	return

PartnerPlayground_EventScript_Squirtle_5:
# 79 "data/scripts/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 80 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Squirtle_Text_1
# 81 "data/scripts/scripts.pory"
	removeobject 1
# 82 "data/scripts/scripts.pory"
	setflag FLAG_UNUSED_0x020
# 83 "data/scripts/scripts.pory"
	call NicknameBoxMon
	return


PartnerPlayground_EventScript_Treecko::
# 98 "data/scripts/scripts.pory"
	showmonpic SPECIES_TREECKO, 10, 3
# 99 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Treecko_Text_0, MSGBOX_YESNO
# 100 "data/scripts/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PartnerPlayground_EventScript_Treecko_1
# 122 "data/scripts/scripts.pory"
	hidemonpic
# 123 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_NotChosen
	return

PartnerPlayground_EventScript_Treecko_1:
# 101 "data/scripts/scripts.pory"
	givemon SPECIES_TREECKO, 50, ITEM_MASTER_BALL
# 102 "data/scripts/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq PartnerPlayground_EventScript_Treecko_4
# 109 "data/scripts/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq PartnerPlayground_EventScript_Treecko_5
# 117 "data/scripts/scripts.pory"
	hidemonpic
# 118 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_2
	return

PartnerPlayground_EventScript_Treecko_4:
# 103 "data/scripts/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 104 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Treecko_Text_1
# 105 "data/scripts/scripts.pory"
	removeobject 2
# 106 "data/scripts/scripts.pory"
	setflag FLAG_UNUSED_0x021
# 107 "data/scripts/scripts.pory"
	call NicknamePartyMon
	return

PartnerPlayground_EventScript_Treecko_5:
# 110 "data/scripts/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 111 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Treecko_Text_1
# 112 "data/scripts/scripts.pory"
	removeobject 2
# 113 "data/scripts/scripts.pory"
	setflag FLAG_UNUSED_0x021
# 114 "data/scripts/scripts.pory"
	call NicknameBoxMon
	return


PartnerPlayground_EventScript_Chikorita::
# 129 "data/scripts/scripts.pory"
	showmonpic SPECIES_CHIKORITA, 10, 3
# 130 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Chikorita_Text_0, MSGBOX_YESNO
# 131 "data/scripts/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PartnerPlayground_EventScript_Chikorita_1
# 153 "data/scripts/scripts.pory"
	hidemonpic
# 154 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_NotChosen
	return

PartnerPlayground_EventScript_Chikorita_1:
# 132 "data/scripts/scripts.pory"
	givemon SPECIES_CHIKORITA, 50, ITEM_MASTER_BALL
# 133 "data/scripts/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq PartnerPlayground_EventScript_Chikorita_4
# 140 "data/scripts/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq PartnerPlayground_EventScript_Chikorita_5
# 148 "data/scripts/scripts.pory"
	hidemonpic
# 149 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_2
	return

PartnerPlayground_EventScript_Chikorita_4:
# 134 "data/scripts/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 135 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Chikorita_Text_1
# 136 "data/scripts/scripts.pory"
	removeobject 2
# 137 "data/scripts/scripts.pory"
	setflag FLAG_UNUSED_0x021
# 138 "data/scripts/scripts.pory"
	call NicknamePartyMon
	return

PartnerPlayground_EventScript_Chikorita_5:
# 141 "data/scripts/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 142 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Chikorita_Text_1
# 143 "data/scripts/scripts.pory"
	removeobject 2
# 144 "data/scripts/scripts.pory"
	setflag FLAG_UNUSED_0x021
# 145 "data/scripts/scripts.pory"
	call NicknameBoxMon
	return


PartnerPlayground_EventScript_Bulbasaur::
# 160 "data/scripts/scripts.pory"
	showmonpic SPECIES_BULBASAUR, 10, 3
# 161 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Bulbasaur_Text_0, MSGBOX_YESNO
# 162 "data/scripts/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PartnerPlayground_EventScript_Bulbasaur_1
# 184 "data/scripts/scripts.pory"
	hidemonpic
# 185 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_NotChosen
	return

PartnerPlayground_EventScript_Bulbasaur_1:
# 163 "data/scripts/scripts.pory"
	givemon SPECIES_BULBASAUR, 50, ITEM_MASTER_BALL
# 164 "data/scripts/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq PartnerPlayground_EventScript_Bulbasaur_4
# 171 "data/scripts/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq PartnerPlayground_EventScript_Bulbasaur_5
# 179 "data/scripts/scripts.pory"
	hidemonpic
# 180 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_2
	return

PartnerPlayground_EventScript_Bulbasaur_4:
# 165 "data/scripts/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 166 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Bulbasaur_Text_1
# 167 "data/scripts/scripts.pory"
	removeobject 2
# 168 "data/scripts/scripts.pory"
	setflag FLAG_UNUSED_0x021
# 169 "data/scripts/scripts.pory"
	call NicknamePartyMon
	return

PartnerPlayground_EventScript_Bulbasaur_5:
# 172 "data/scripts/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 173 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Bulbasaur_Text_1
# 174 "data/scripts/scripts.pory"
	removeobject 2
# 175 "data/scripts/scripts.pory"
	setflag FLAG_UNUSED_0x021
# 176 "data/scripts/scripts.pory"
	call NicknameBoxMon
	return


PartnerPlayground_EventScript_Torchic::
# 191 "data/scripts/scripts.pory"
	showmonpic SPECIES_TORCHIC, 10, 3
# 192 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Torchic_Text_0, MSGBOX_YESNO
# 193 "data/scripts/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PartnerPlayground_EventScript_Torchic_1
# 215 "data/scripts/scripts.pory"
	hidemonpic
# 216 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_NotChosen
	return

PartnerPlayground_EventScript_Torchic_1:
# 194 "data/scripts/scripts.pory"
	givemon SPECIES_TORCHIC, 50, ITEM_MASTER_BALL
# 195 "data/scripts/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq PartnerPlayground_EventScript_Torchic_4
# 202 "data/scripts/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq PartnerPlayground_EventScript_Torchic_5
# 210 "data/scripts/scripts.pory"
	hidemonpic
# 211 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_2
	return

PartnerPlayground_EventScript_Torchic_4:
# 196 "data/scripts/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 197 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Torchic_Text_1
# 198 "data/scripts/scripts.pory"
	removeobject 3
# 199 "data/scripts/scripts.pory"
	setflag FLAG_UNUSED_0x022
# 200 "data/scripts/scripts.pory"
	call NicknamePartyMon
	return

PartnerPlayground_EventScript_Torchic_5:
# 203 "data/scripts/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 204 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Torchic_Text_1
# 205 "data/scripts/scripts.pory"
	removeobject 3
# 206 "data/scripts/scripts.pory"
	setflag FLAG_UNUSED_0x022
# 207 "data/scripts/scripts.pory"
	call NicknameBoxMon
	return


PartnerPlayground_EventScript_Cyndaquil::
# 222 "data/scripts/scripts.pory"
	showmonpic SPECIES_CYNDAQUIL, 10, 3
# 223 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Cyndaquil_Text_0, MSGBOX_YESNO
# 224 "data/scripts/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PartnerPlayground_EventScript_Cyndaquil_1
# 246 "data/scripts/scripts.pory"
	hidemonpic
# 247 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_NotChosen
	return

PartnerPlayground_EventScript_Cyndaquil_1:
# 225 "data/scripts/scripts.pory"
	givemon SPECIES_CYNDAQUIL, 50, ITEM_MASTER_BALL
# 226 "data/scripts/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq PartnerPlayground_EventScript_Cyndaquil_4
# 233 "data/scripts/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq PartnerPlayground_EventScript_Cyndaquil_5
# 241 "data/scripts/scripts.pory"
	hidemonpic
# 242 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_2
	return

PartnerPlayground_EventScript_Cyndaquil_4:
# 227 "data/scripts/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 228 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Cyndaquil_Text_1
# 229 "data/scripts/scripts.pory"
	removeobject 3
# 230 "data/scripts/scripts.pory"
	setflag FLAG_UNUSED_0x022
# 231 "data/scripts/scripts.pory"
	call NicknamePartyMon
	return

PartnerPlayground_EventScript_Cyndaquil_5:
# 234 "data/scripts/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 235 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Cyndaquil_Text_1
# 236 "data/scripts/scripts.pory"
	removeobject 3
# 237 "data/scripts/scripts.pory"
	setflag FLAG_UNUSED_0x022
# 238 "data/scripts/scripts.pory"
	call NicknameBoxMon
	return


PartnerPlayground_EventScript_Charmander::
# 253 "data/scripts/scripts.pory"
	showmonpic SPECIES_CHARMANDER, 10, 3
# 254 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Charmander_Text_0, MSGBOX_YESNO
# 255 "data/scripts/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PartnerPlayground_EventScript_Charmander_1
# 277 "data/scripts/scripts.pory"
	hidemonpic
# 278 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_NotChosen
	return

PartnerPlayground_EventScript_Charmander_1:
# 256 "data/scripts/scripts.pory"
	givemon SPECIES_CHARMANDER, 50, ITEM_MASTER_BALL
# 257 "data/scripts/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq PartnerPlayground_EventScript_Charmander_4
# 264 "data/scripts/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq PartnerPlayground_EventScript_Charmander_5
# 272 "data/scripts/scripts.pory"
	hidemonpic
# 273 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Mudkip_Text_2
	return

PartnerPlayground_EventScript_Charmander_4:
# 258 "data/scripts/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 259 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Charmander_Text_1
# 260 "data/scripts/scripts.pory"
	removeobject 3
# 261 "data/scripts/scripts.pory"
	setflag FLAG_UNUSED_0x022
# 262 "data/scripts/scripts.pory"
	call NicknamePartyMon
	return

PartnerPlayground_EventScript_Charmander_5:
# 265 "data/scripts/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 266 "data/scripts/scripts.pory"
	msgbox PartnerPlayground_EventScript_Charmander_Text_1
# 267 "data/scripts/scripts.pory"
	removeobject 3
# 268 "data/scripts/scripts.pory"
	setflag FLAG_UNUSED_0x022
# 269 "data/scripts/scripts.pory"
	call NicknameBoxMon
	return


NicknamePartyMon::
# 285 "data/scripts/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 286 "data/scripts/scripts.pory"
	hidemonpic
# 287 "data/scripts/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_1
	return

NicknamePartyMon_1:
# 288 "data/scripts/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 289 "data/scripts/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	return


NicknameBoxMon::
# 296 "data/scripts/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 297 "data/scripts/scripts.pory"
	hidemonpic
# 298 "data/scripts/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknameBoxMon_2
NicknameBoxMon_1:
# 301 "data/scripts/scripts.pory"
	msgbox NicknameBoxMon_Text_0
	return

NicknameBoxMon_2:
# 299 "data/scripts/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
	goto NicknameBoxMon_1


PartnerPlayground_EventScript_Mudkip_Text_0:
# 6 "data/scripts/scripts.pory"
	.string "Do you want to choose Mudkip?$"

PartnerPlayground_EventScript_Mudkip_Text_1:
# 11 "data/scripts/scripts.pory"
	.string "Recieved Mudkip$"

PartnerPlayground_EventScript_Mudkip_Text_2:
# 25 "data/scripts/scripts.pory"
	.string "No More Room$"

PartnerPlayground_EventScript_Totodile_Text_0:
# 37 "data/scripts/scripts.pory"
	.string "Do you want to choose Totodile?$"

PartnerPlayground_EventScript_Totodile_Text_1:
# 42 "data/scripts/scripts.pory"
	.string "Recieved Totodile$"

PartnerPlayground_EventScript_Squirtle_Text_0:
# 68 "data/scripts/scripts.pory"
	.string "Do you want to choose Squirtle?$"

PartnerPlayground_EventScript_Squirtle_Text_1:
# 73 "data/scripts/scripts.pory"
	.string "Recieved Squirtle$"

PartnerPlayground_EventScript_Treecko_Text_0:
# 99 "data/scripts/scripts.pory"
	.string "Do you want to choose Treecko?$"

PartnerPlayground_EventScript_Treecko_Text_1:
# 104 "data/scripts/scripts.pory"
	.string "Recieved Treecko$"

PartnerPlayground_EventScript_Chikorita_Text_0:
# 130 "data/scripts/scripts.pory"
	.string "Do you want to choose Chikorita?$"

PartnerPlayground_EventScript_Chikorita_Text_1:
# 135 "data/scripts/scripts.pory"
	.string "Recieved Chikorita$"

PartnerPlayground_EventScript_Bulbasaur_Text_0:
# 161 "data/scripts/scripts.pory"
	.string "Do you want to choose Bulbasaur?$"

PartnerPlayground_EventScript_Bulbasaur_Text_1:
# 166 "data/scripts/scripts.pory"
	.string "Recieved Bulbasaur$"

PartnerPlayground_EventScript_Torchic_Text_0:
# 192 "data/scripts/scripts.pory"
	.string "Do you want to choose Torchic?$"

PartnerPlayground_EventScript_Torchic_Text_1:
# 197 "data/scripts/scripts.pory"
	.string "Recieved Torchic$"

PartnerPlayground_EventScript_Cyndaquil_Text_0:
# 223 "data/scripts/scripts.pory"
	.string "Do you want to choose Cyndaquil?$"

PartnerPlayground_EventScript_Cyndaquil_Text_1:
# 228 "data/scripts/scripts.pory"
	.string "Recieved Cyndaquil$"

PartnerPlayground_EventScript_Charmander_Text_0:
# 254 "data/scripts/scripts.pory"
	.string "Do you want to choose Charmander?$"

PartnerPlayground_EventScript_Charmander_Text_1:
# 259 "data/scripts/scripts.pory"
	.string "Recieved Charmander$"

NicknamePartyMon_Text_0:
# 285 "data/scripts/scripts.pory"
	.string "Give a nickname?$"

NicknameBoxMon_Text_0:
# 301 "data/scripts/scripts.pory"
	.string "Transferred to PC$"

PartnerPlayground_NotChosen::
# 304 "data/scripts/scripts.pory"
	.string "You did not choose the Pokemon$"

	