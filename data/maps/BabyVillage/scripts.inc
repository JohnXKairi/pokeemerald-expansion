# 1 "data/maps/BabyVillage/scripts.pory"

# 2 "data/maps/BabyVillage/scripts.pory"
.set LOCALID_Pinsir, 7
# 3 "data/maps/BabyVillage/scripts.pory"
.set LOCALID_Smoochum, 6
# 4 "data/maps/BabyVillage/scripts.pory"
.set LOCALID_Magby, 4
# 5 "data/maps/BabyVillage/scripts.pory"
.set LOCALID_Elekid, 5
# 6 "data/maps/BabyVillage/scripts.pory"
.set LOCALID_Pichu, 2
# 7 "data/maps/BabyVillage/scripts.pory"
.set LOCALID_Mime_jr, 3
# 8 "data/maps/BabyVillage/scripts.pory"
.set LOCALID_Celebi, 1

BabyVillage_MapScripts::
	.byte 0


pinsirL::
# 13 "data/maps/BabyVillage/scripts.pory"
	lock
# 14 "data/maps/BabyVillage/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FacePinsirL
# 15 "data/maps/BabyVillage/scripts.pory"
	waitmovement 0
# 16 "data/maps/BabyVillage/scripts.pory"
	msgbox pinsirL_Text_0, MSGBOX_YESNO
# 17 "data/maps/BabyVillage/scripts.pory"
	waitmessage
# 18 "data/maps/BabyVillage/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq pinsirL_2
# 47 "data/maps/BabyVillage/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq pinsirL_3
pinsirL_1:
# 50 "data/maps/BabyVillage/scripts.pory"
	release
	return

pinsirL_2:
# 19 "data/maps/BabyVillage/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FacePinsir
# 20 "data/maps/BabyVillage/scripts.pory"
	waitmovement 0
# 21 "data/maps/BabyVillage/scripts.pory"
	applymovement LOCALID_Pinsir, PinsirDown
# 22 "data/maps/BabyVillage/scripts.pory"
	waitmovement 0
# 23 "data/maps/BabyVillage/scripts.pory"
	playmoncry SPECIES_PINSIR, CRY_MODE_ENCOUNTER
# 24 "data/maps/BabyVillage/scripts.pory"
	waitmoncry
# 25 "data/maps/BabyVillage/scripts.pory"
	settotemboost 1, 6, 6, -4, 0, 6
# 26 "data/maps/BabyVillage/scripts.pory"
	setwildbattle SPECIES_PINSIR, 15
# 27 "data/maps/BabyVillage/scripts.pory"
	dowildbattle
# 28 "data/maps/BabyVillage/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 29 "data/maps/BabyVillage/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq pinsirL_6
# 35 "data/maps/BabyVillage/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq pinsirL_7
# 41 "data/maps/BabyVillage/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq pinsirL_8
# 44 "data/maps/BabyVillage/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq pinsirL_9
	goto pinsirL_1

pinsirL_3:
# 48 "data/maps/BabyVillage/scripts.pory"
	call RanAway
	goto pinsirL_1

pinsirL_6:
# 30 "data/maps/BabyVillage/scripts.pory"
	setvar VAR_UNUSED_0x4103, 1
# 31 "data/maps/BabyVillage/scripts.pory"
	setflag FLAG_UNUSED_0x49E
# 32 "data/maps/BabyVillage/scripts.pory"
	removeobject LOCALID_Pinsir
# 33 "data/maps/BabyVillage/scripts.pory"
	call Won
	goto pinsirL_1

pinsirL_7:
# 36 "data/maps/BabyVillage/scripts.pory"
	setvar VAR_UNUSED_0x4103, 1
# 37 "data/maps/BabyVillage/scripts.pory"
	setflag FLAG_UNUSED_0x49E
# 38 "data/maps/BabyVillage/scripts.pory"
	removeobject LOCALID_Pinsir
# 39 "data/maps/BabyVillage/scripts.pory"
	call Won
	goto pinsirL_1

pinsirL_8:
# 42 "data/maps/BabyVillage/scripts.pory"
	call RanAway
	goto pinsirL_1

pinsirL_9:
# 45 "data/maps/BabyVillage/scripts.pory"
	call RanAway
	goto pinsirL_1


pinsirR::
# 54 "data/maps/BabyVillage/scripts.pory"
	lock
# 55 "data/maps/BabyVillage/scripts.pory"
	msgbox pinsirL_Text_0, MSGBOX_YESNO
# 56 "data/maps/BabyVillage/scripts.pory"
	waitmessage
# 57 "data/maps/BabyVillage/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq pinsirR_2
# 86 "data/maps/BabyVillage/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq pinsirR_3
pinsirR_1:
# 89 "data/maps/BabyVillage/scripts.pory"
	release
	return

pinsirR_2:
# 58 "data/maps/BabyVillage/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FacePinsir
# 59 "data/maps/BabyVillage/scripts.pory"
	waitmovement 0
# 60 "data/maps/BabyVillage/scripts.pory"
	applymovement LOCALID_Pinsir, PinsirDown
# 61 "data/maps/BabyVillage/scripts.pory"
	waitmovement 0
# 62 "data/maps/BabyVillage/scripts.pory"
	playmoncry SPECIES_PINSIR, CRY_MODE_ENCOUNTER
# 63 "data/maps/BabyVillage/scripts.pory"
	waitmoncry
# 64 "data/maps/BabyVillage/scripts.pory"
	settotemboost 1, 6, 6, -4, 0, 6
# 65 "data/maps/BabyVillage/scripts.pory"
	setwildbattle SPECIES_PINSIR, 15
# 66 "data/maps/BabyVillage/scripts.pory"
	dowildbattle
# 67 "data/maps/BabyVillage/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 68 "data/maps/BabyVillage/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq pinsirR_6
# 74 "data/maps/BabyVillage/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq pinsirR_7
# 80 "data/maps/BabyVillage/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq pinsirR_8
# 83 "data/maps/BabyVillage/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq pinsirR_9
	goto pinsirR_1

pinsirR_3:
# 87 "data/maps/BabyVillage/scripts.pory"
	call RanAway
	goto pinsirR_1

pinsirR_6:
# 69 "data/maps/BabyVillage/scripts.pory"
	setvar VAR_UNUSED_0x4103, 1
# 70 "data/maps/BabyVillage/scripts.pory"
	setflag FLAG_UNUSED_0x49E
# 71 "data/maps/BabyVillage/scripts.pory"
	removeobject LOCALID_Pinsir
# 72 "data/maps/BabyVillage/scripts.pory"
	call Won
	goto pinsirR_1

pinsirR_7:
# 75 "data/maps/BabyVillage/scripts.pory"
	setvar VAR_UNUSED_0x4103, 1
# 76 "data/maps/BabyVillage/scripts.pory"
	setflag FLAG_UNUSED_0x49E
# 77 "data/maps/BabyVillage/scripts.pory"
	removeobject LOCALID_Pinsir
# 78 "data/maps/BabyVillage/scripts.pory"
	call Won
	goto pinsirR_1

pinsirR_8:
# 81 "data/maps/BabyVillage/scripts.pory"
	call RanAway
	goto pinsirR_1

pinsirR_9:
# 84 "data/maps/BabyVillage/scripts.pory"
	call RanAway
	goto pinsirR_1


SerebihelpScriptD::
# 92 "data/maps/BabyVillage/scripts.pory"
	lock
# 93 "data/maps/BabyVillage/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SerebihelpD
# 94 "data/maps/BabyVillage/scripts.pory"
	release
	return


SerebihelpScriptR::
# 98 "data/maps/BabyVillage/scripts.pory"
	lock
# 99 "data/maps/BabyVillage/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SerebihelpR
# 100 "data/maps/BabyVillage/scripts.pory"
	release
	return


SerebihelpScriptL::
# 104 "data/maps/BabyVillage/scripts.pory"
	lock
# 105 "data/maps/BabyVillage/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SerebihelpL
# 106 "data/maps/BabyVillage/scripts.pory"
	release
	return


CelebiTalk::
# 109 "data/maps/BabyVillage/scripts.pory"
	lock
# 110 "data/maps/BabyVillage/scripts.pory"
	faceplayer
# 111 "data/maps/BabyVillage/scripts.pory"
	compare VAR_UNUSED_0x4103, 1
	goto_if_eq CelebiTalk_2
CelebiTalk_1:
# 115 "data/maps/BabyVillage/scripts.pory"
	compare VAR_UNUSED_0x4103, 2
	goto_if_eq CelebiTalk_5
CelebiTalk_4:
# 124 "data/maps/BabyVillage/scripts.pory"
	release
	return

CelebiTalk_2:
# 112 "data/maps/BabyVillage/scripts.pory"
	msgbox CelebiTalk_Text_0, MSGBOX_DEFAULT
# 113 "data/maps/BabyVillage/scripts.pory"
	waitmessage
	goto CelebiTalk_1

CelebiTalk_5:
# 116 "data/maps/BabyVillage/scripts.pory"
	msgbox CelebiTalk_Text_1, MSGBOX_DEFAULT
# 117 "data/maps/BabyVillage/scripts.pory"
	waitmessage
# 118 "data/maps/BabyVillage/scripts.pory"
	fadescreen FADE_TO_BLACK
# 119 "data/maps/BabyVillage/scripts.pory"
	setflag FLAG_UNUSED_0x49D
# 120 "data/maps/BabyVillage/scripts.pory"
	removeobject LOCALID_Celebi
# 121 "data/maps/BabyVillage/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 122 "data/maps/BabyVillage/scripts.pory"
	givemon SPECIES_CELEBI, 15
	goto CelebiTalk_4


BabiesHidding::
# 127 "data/maps/BabyVillage/scripts.pory"
	lock
# 128 "data/maps/BabyVillage/scripts.pory"
	msgbox BabiesHidding_Text_0, MSGBOX_DEFAULT
# 129 "data/maps/BabyVillage/scripts.pory"
	waitmessage
# 130 "data/maps/BabyVillage/scripts.pory"
	release
	return


foundPichu::
# 133 "data/maps/BabyVillage/scripts.pory"
	lock
# 134 "data/maps/BabyVillage/scripts.pory"
	faceplayer
# 135 "data/maps/BabyVillage/scripts.pory"
	msgbox foundPichu_Text_0, MSGBOX_DEFAULT
# 136 "data/maps/BabyVillage/scripts.pory"
	waitmessage
# 137 "data/maps/BabyVillage/scripts.pory"
	goto_if_unset FLAG_UNUSED_0x498, foundPichu_2
foundPichu_1:
# 148 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x498, foundPichu_7
foundPichu_4:
# 153 "data/maps/BabyVillage/scripts.pory"
	release
	return

foundPichu_2:
# 139 "data/maps/BabyVillage/scripts.pory"
	setflag FLAG_UNUSED_0x498
# 140 "data/maps/BabyVillage/scripts.pory"
	fadescreen FADE_TO_BLACK
# 141 "data/maps/BabyVillage/scripts.pory"
	setobjectxyperm LOCALID_Pichu, 14, 15
# 142 "data/maps/BabyVillage/scripts.pory"
	removeobject LOCALID_Pichu
# 143 "data/maps/BabyVillage/scripts.pory"
	addobject LOCALID_Pichu
# 144 "data/maps/BabyVillage/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 145 "data/maps/BabyVillage/scripts.pory"
	msgbox foundPichu_Text_1, MSGBOX_DEFAULT
# 146 "data/maps/BabyVillage/scripts.pory"
	waitmessage
	goto foundPichu_1

foundPichu_5:
# 149 "data/maps/BabyVillage/scripts.pory"
	msgbox foundPichu_Text_2, MSGBOX_DEFAULT
# 150 "data/maps/BabyVillage/scripts.pory"
	waitmessage
# 151 "data/maps/BabyVillage/scripts.pory"
	setvar VAR_UNUSED_0x4103, 2
	goto foundPichu_4

foundPichu_6:
# 148 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x49A, foundPichu_11
	goto foundPichu_4

foundPichu_7:
# 148 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x499, foundPichu_6
	goto foundPichu_4

foundPichu_10:
# 148 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x49C, foundPichu_5
	goto foundPichu_4

foundPichu_11:
# 148 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x49B, foundPichu_10
	goto foundPichu_4


foundMagby::
# 156 "data/maps/BabyVillage/scripts.pory"
	lock
# 157 "data/maps/BabyVillage/scripts.pory"
	faceplayer
# 158 "data/maps/BabyVillage/scripts.pory"
	msgbox foundMagby_Text_0, MSGBOX_DEFAULT
# 159 "data/maps/BabyVillage/scripts.pory"
	waitmessage
# 160 "data/maps/BabyVillage/scripts.pory"
	goto_if_unset FLAG_UNUSED_0x499, foundMagby_2
foundMagby_1:
# 171 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x498, foundMagby_7
foundMagby_4:
# 176 "data/maps/BabyVillage/scripts.pory"
	release
	return

foundMagby_2:
# 162 "data/maps/BabyVillage/scripts.pory"
	setflag FLAG_UNUSED_0x499
# 163 "data/maps/BabyVillage/scripts.pory"
	fadescreen FADE_TO_BLACK
# 164 "data/maps/BabyVillage/scripts.pory"
	setobjectxyperm LOCALID_Magby, 14, 14
# 165 "data/maps/BabyVillage/scripts.pory"
	removeobject LOCALID_Magby
# 166 "data/maps/BabyVillage/scripts.pory"
	addobject LOCALID_Magby
# 167 "data/maps/BabyVillage/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 168 "data/maps/BabyVillage/scripts.pory"
	msgbox foundMagby_Text_1, MSGBOX_DEFAULT
# 169 "data/maps/BabyVillage/scripts.pory"
	waitmessage
	goto foundMagby_1

foundMagby_5:
# 172 "data/maps/BabyVillage/scripts.pory"
	msgbox foundPichu_Text_2, MSGBOX_DEFAULT
# 173 "data/maps/BabyVillage/scripts.pory"
	waitmessage
# 174 "data/maps/BabyVillage/scripts.pory"
	setvar VAR_UNUSED_0x4103, 2
	goto foundMagby_4

foundMagby_6:
# 171 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x49A, foundMagby_11
	goto foundMagby_4

foundMagby_7:
# 171 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x499, foundMagby_6
	goto foundMagby_4

foundMagby_10:
# 171 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x49C, foundMagby_5
	goto foundMagby_4

foundMagby_11:
# 171 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x49B, foundMagby_10
	goto foundMagby_4


foundElekid::
# 179 "data/maps/BabyVillage/scripts.pory"
	lock
# 180 "data/maps/BabyVillage/scripts.pory"
	faceplayer
# 181 "data/maps/BabyVillage/scripts.pory"
	msgbox foundElekid_Text_0, MSGBOX_DEFAULT
# 182 "data/maps/BabyVillage/scripts.pory"
	waitmessage
# 183 "data/maps/BabyVillage/scripts.pory"
	goto_if_unset FLAG_UNUSED_0x49A, foundElekid_2
foundElekid_1:
# 194 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x498, foundElekid_7
foundElekid_4:
# 199 "data/maps/BabyVillage/scripts.pory"
	release
	return

foundElekid_2:
# 185 "data/maps/BabyVillage/scripts.pory"
	setflag FLAG_UNUSED_0x49A
# 186 "data/maps/BabyVillage/scripts.pory"
	fadescreen FADE_TO_BLACK
# 187 "data/maps/BabyVillage/scripts.pory"
	setobjectxyperm LOCALID_Elekid, 15, 14
# 188 "data/maps/BabyVillage/scripts.pory"
	removeobject LOCALID_Elekid
# 189 "data/maps/BabyVillage/scripts.pory"
	addobject LOCALID_Elekid
# 190 "data/maps/BabyVillage/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 191 "data/maps/BabyVillage/scripts.pory"
	msgbox foundElekid_Text_1, MSGBOX_DEFAULT
# 192 "data/maps/BabyVillage/scripts.pory"
	waitmessage
	goto foundElekid_1

foundElekid_5:
# 195 "data/maps/BabyVillage/scripts.pory"
	msgbox foundPichu_Text_2, MSGBOX_DEFAULT
# 196 "data/maps/BabyVillage/scripts.pory"
	waitmessage
# 197 "data/maps/BabyVillage/scripts.pory"
	setvar VAR_UNUSED_0x4103, 2
	goto foundElekid_4

foundElekid_6:
# 194 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x49A, foundElekid_11
	goto foundElekid_4

foundElekid_7:
# 194 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x499, foundElekid_6
	goto foundElekid_4

foundElekid_10:
# 194 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x49C, foundElekid_5
	goto foundElekid_4

foundElekid_11:
# 194 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x49B, foundElekid_10
	goto foundElekid_4


foundSmoochum::
# 202 "data/maps/BabyVillage/scripts.pory"
	lock
# 203 "data/maps/BabyVillage/scripts.pory"
	faceplayer
# 204 "data/maps/BabyVillage/scripts.pory"
	msgbox foundSmoochum_Text_0, MSGBOX_DEFAULT
# 205 "data/maps/BabyVillage/scripts.pory"
	waitmessage
# 206 "data/maps/BabyVillage/scripts.pory"
	goto_if_unset FLAG_UNUSED_0x49C, foundSmoochum_2
foundSmoochum_1:
# 217 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x498, foundSmoochum_7
foundSmoochum_4:
# 222 "data/maps/BabyVillage/scripts.pory"
	release
	return

foundSmoochum_2:
# 208 "data/maps/BabyVillage/scripts.pory"
	setflag FLAG_UNUSED_0x49C
# 209 "data/maps/BabyVillage/scripts.pory"
	fadescreen FADE_TO_BLACK
# 210 "data/maps/BabyVillage/scripts.pory"
	setobjectxyperm LOCALID_Smoochum, 16, 14
# 211 "data/maps/BabyVillage/scripts.pory"
	removeobject LOCALID_Smoochum
# 212 "data/maps/BabyVillage/scripts.pory"
	addobject LOCALID_Smoochum
# 213 "data/maps/BabyVillage/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 214 "data/maps/BabyVillage/scripts.pory"
	msgbox foundSmoochum_Text_1, MSGBOX_DEFAULT
# 215 "data/maps/BabyVillage/scripts.pory"
	waitmessage
	goto foundSmoochum_1

foundSmoochum_5:
# 218 "data/maps/BabyVillage/scripts.pory"
	msgbox foundPichu_Text_2, MSGBOX_DEFAULT
# 219 "data/maps/BabyVillage/scripts.pory"
	waitmessage
# 220 "data/maps/BabyVillage/scripts.pory"
	setvar VAR_UNUSED_0x4103, 2
	goto foundSmoochum_4

foundSmoochum_6:
# 217 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x49A, foundSmoochum_11
	goto foundSmoochum_4

foundSmoochum_7:
# 217 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x499, foundSmoochum_6
	goto foundSmoochum_4

foundSmoochum_10:
# 217 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x49C, foundSmoochum_5
	goto foundSmoochum_4

foundSmoochum_11:
# 217 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x49B, foundSmoochum_10
	goto foundSmoochum_4


foundMimeJr::
# 225 "data/maps/BabyVillage/scripts.pory"
	lock
# 226 "data/maps/BabyVillage/scripts.pory"
	faceplayer
# 227 "data/maps/BabyVillage/scripts.pory"
	msgbox foundMimeJr_Text_0, MSGBOX_DEFAULT
# 228 "data/maps/BabyVillage/scripts.pory"
	waitmessage
# 229 "data/maps/BabyVillage/scripts.pory"
	goto_if_unset FLAG_UNUSED_0x49A, foundMimeJr_2
foundMimeJr_1:
# 240 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x498, foundMimeJr_7
foundMimeJr_4:
# 245 "data/maps/BabyVillage/scripts.pory"
	release
	return

foundMimeJr_2:
# 231 "data/maps/BabyVillage/scripts.pory"
	setflag FLAG_UNUSED_0x49A
# 232 "data/maps/BabyVillage/scripts.pory"
	fadescreen FADE_TO_BLACK
# 233 "data/maps/BabyVillage/scripts.pory"
	setobjectxyperm LOCALID_Mime_jr, 16, 15
# 234 "data/maps/BabyVillage/scripts.pory"
	removeobject LOCALID_Mime_jr
# 235 "data/maps/BabyVillage/scripts.pory"
	addobject LOCALID_Mime_jr
# 236 "data/maps/BabyVillage/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 237 "data/maps/BabyVillage/scripts.pory"
	msgbox foundMimeJr_Text_1, MSGBOX_DEFAULT
# 238 "data/maps/BabyVillage/scripts.pory"
	waitmessage
	goto foundMimeJr_1

foundMimeJr_5:
# 241 "data/maps/BabyVillage/scripts.pory"
	msgbox foundPichu_Text_2, MSGBOX_DEFAULT
# 242 "data/maps/BabyVillage/scripts.pory"
	waitmessage
# 243 "data/maps/BabyVillage/scripts.pory"
	setvar VAR_UNUSED_0x4103, 2
	goto foundMimeJr_4

foundMimeJr_6:
# 240 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x49A, foundMimeJr_11
	goto foundMimeJr_4

foundMimeJr_7:
# 240 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x499, foundMimeJr_6
	goto foundMimeJr_4

foundMimeJr_10:
# 240 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x49C, foundMimeJr_5
	goto foundMimeJr_4

foundMimeJr_11:
# 240 "data/maps/BabyVillage/scripts.pory"
	goto_if_set FLAG_UNUSED_0x49B, foundMimeJr_10
	goto foundMimeJr_4


Won::
# 248 "data/maps/BabyVillage/scripts.pory"
	applymovement LOCALID_Celebi, SerebihelpD
# 249 "data/maps/BabyVillage/scripts.pory"
	msgbox Won_Text_0, MSGBOX_DEFAULT
# 250 "data/maps/BabyVillage/scripts.pory"
	waitmessage
# 251 "data/maps/BabyVillage/scripts.pory"
	msgbox Won_Text_1, MSGBOX_DEFAULT
# 252 "data/maps/BabyVillage/scripts.pory"
	waitmessage
# 253 "data/maps/BabyVillage/scripts.pory"
	msgbox Won_Text_2, MSGBOX_DEFAULT
# 254 "data/maps/BabyVillage/scripts.pory"
	waitmessage
# 255 "data/maps/BabyVillage/scripts.pory"
	setvar VAR_UNUSED_0x40F7, 1
	return


# 257 "data/maps/BabyVillage/scripts.pory"
SerebihelpL:
# 258 "data/maps/BabyVillage/scripts.pory"
	walk_fast_left
	step_end

# 260 "data/maps/BabyVillage/scripts.pory"
SerebihelpR:
# 261 "data/maps/BabyVillage/scripts.pory"
	walk_fast_right
	step_end

# 263 "data/maps/BabyVillage/scripts.pory"
PinsirDown:
# 264 "data/maps/BabyVillage/scripts.pory"
	face_down
	step_end

# 266 "data/maps/BabyVillage/scripts.pory"
FacePinsir:
# 267 "data/maps/BabyVillage/scripts.pory"
	walk_up
# 267 "data/maps/BabyVillage/scripts.pory"
	walk_up
	step_end

# 269 "data/maps/BabyVillage/scripts.pory"
FacePinsirL:
# 270 "data/maps/BabyVillage/scripts.pory"
	walk_right
# 271 "data/maps/BabyVillage/scripts.pory"
	face_up
	step_end

RanAway::
# 274 "data/maps/BabyVillage/scripts.pory"
	msgbox RanAway_Text_0
# 275 "data/maps/BabyVillage/scripts.pory"
	waitmessage
# 276 "data/maps/BabyVillage/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, GoBack
# 277 "data/maps/BabyVillage/scripts.pory"
	waitmovement 0
	return


# 279 "data/maps/BabyVillage/scripts.pory"
GoBack:
# 280 "data/maps/BabyVillage/scripts.pory"
	walk_fast_down
# 280 "data/maps/BabyVillage/scripts.pory"
	walk_fast_down
# 280 "data/maps/BabyVillage/scripts.pory"
	walk_fast_down
	step_end

# 282 "data/maps/BabyVillage/scripts.pory"
SerebihelpD:
# 283 "data/maps/BabyVillage/scripts.pory"
	walk_fast_down
	step_end

pinsirL_Text_0:
# 16 "data/maps/BabyVillage/scripts.pory"
	.string "There is a small Pokemon in danger up\n"
	.string "ahead. It's fighting a big scary one.\l"
	.string "This Pokemon seems stronger, somehow.\l"
	.string "Do you still want to fight it?$"

CelebiTalk_Text_0:
# 112 "data/maps/BabyVillage/scripts.pory"
	.string "CELEBI:Please find the five missing\n"
	.string "baby Pokemon. They must be around here.$"

CelebiTalk_Text_1:
# 116 "data/maps/BabyVillage/scripts.pory"
	.string "CELEBI:Thank you, friend. The babies\n"
	.string "will be safe now. I'd love to travel with\l"
	.string "a kind soul like you.$"

BabiesHidding_Text_0:
# 128 "data/maps/BabyVillage/scripts.pory"
	.string "There are baby Pokemon hidding here.\n"
	.string "Best to not disturb them.$"

foundPichu_Text_0:
# 135 "data/maps/BabyVillage/scripts.pory"
	.string "PICHU:Pi-chu-pi.$"

foundPichu_Text_1:
# 145 "data/maps/BabyVillage/scripts.pory"
	.string "PICHU returned to CELEBI$"

foundPichu_Text_2:
# 149 "data/maps/BabyVillage/scripts.pory"
	.string "{PLAYER}:That must me all. Time to go\n"
	.string "back to CELEBI.$"

foundMagby_Text_0:
# 158 "data/maps/BabyVillage/scripts.pory"
	.string "MAGBY:Mag-mag-by.$"

foundMagby_Text_1:
# 168 "data/maps/BabyVillage/scripts.pory"
	.string "MAGBY returned to CELEBI$"

foundElekid_Text_0:
# 181 "data/maps/BabyVillage/scripts.pory"
	.string "ELEKID:E-le-kid.$"

foundElekid_Text_1:
# 191 "data/maps/BabyVillage/scripts.pory"
	.string "ELEKID returned to CELEBI$"

foundSmoochum_Text_0:
# 204 "data/maps/BabyVillage/scripts.pory"
	.string "SMOOCHUM:Smoo-chum.$"

foundSmoochum_Text_1:
# 214 "data/maps/BabyVillage/scripts.pory"
	.string "SMOOCHUM returned to CELEBI$"

foundMimeJr_Text_0:
# 227 "data/maps/BabyVillage/scripts.pory"
	.string "MIME JR:Mime Mime.$"

foundMimeJr_Text_1:
# 237 "data/maps/BabyVillage/scripts.pory"
	.string "MIME JR returned to CELEBI$"

Won_Text_0:
# 249 "data/maps/BabyVillage/scripts.pory"
	.string "The small green Pokemon is using some\n"
	.string "kind of power!$"

Won_Text_1:
# 251 "data/maps/BabyVillage/scripts.pory"
	.string "You can hear a voice in your head!$"

Won_Text_2:
# 253 "data/maps/BabyVillage/scripts.pory"
	.string "CELEBI:Thank you, friend. My name is\n"
	.string "CELEBI. This is the BABY VILLAGE were\l"
	.string "baby Pokemon can grow safely.\l"
	.string "Unfortunately the youngest of them\l"
	.string "got scared by that pinsir and run away.\l"
	.string "Please help me find them. There's 5 of\l"
	.string "them. They must be around here,\l"
	.string "somewhere.$"

RanAway_Text_0:
# 274 "data/maps/BabyVillage/scripts.pory"
	.string "You run away. You can fight again when\n"
	.string "you are ready!$"
