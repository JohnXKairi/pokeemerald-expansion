# 1 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_MapScripts::
# 2 "data/maps/RustboroCity_Gym/scripts.pory"
	.byte 0
# 3 "data/maps/RustboroCity_Gym/scripts.pory"

# 4 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Roxanne::
# 5 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
# 6 "data/maps/RustboroCity_Gym/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 7 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
# 8 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
# 9 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
# 10 "data/maps/RustboroCity_Gym/scripts.pory"
	release
# 11 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 12 "data/maps/RustboroCity_Gym/scripts.pory"

# 13 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RoxanneDefeated::
# 14 "data/maps/RustboroCity_Gym/scripts.pory"
	message RustboroCity_Gym_Text_ReceivedStoneBadge
# 15 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmessage
# 16 "data/maps/RustboroCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 17 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
# 18 "data/maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 19 "data/maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_BADGE01_GET
# 20 "data/maps/RustboroCity_Gym/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 1
# 21 "data/maps/RustboroCity_Gym/scripts.pory"
	addvar VAR_PETALBURG_GYM_STATE, 1
# 22 "data/maps/RustboroCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 23 "data/maps/RustboroCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 24 "data/maps/RustboroCity_Gym/scripts.pory"
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
# 25 "data/maps/RustboroCity_Gym/scripts.pory"
	goto RustboroCity_Gym_EventScript_GiveRockTomb
# 26 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 27 "data/maps/RustboroCity_Gym/scripts.pory"

# 28 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GiveRockTomb::
# 29 "data/maps/RustboroCity_Gym/scripts.pory"
	giveitem ITEM_TM_ROCK_TOMB
# 30 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 31 "data/maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
# 32 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
# 33 "data/maps/RustboroCity_Gym/scripts.pory"
	release
# 34 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 35 "data/maps/RustboroCity_Gym/scripts.pory"

# 36 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RoxanneRematch::
# 37 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
# 38 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
# 39 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 40 "data/maps/RustboroCity_Gym/scripts.pory"

# 41 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Josh::
# 42 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
# 43 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
# 44 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 45 "data/maps/RustboroCity_Gym/scripts.pory"

# 46 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Tommy::
# 47 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
# 48 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
# 49 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 50 "data/maps/RustboroCity_Gym/scripts.pory"

# 51 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Marc::
# 52 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
# 53 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
# 54 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 55 "data/maps/RustboroCity_Gym/scripts.pory"

# 56 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymGuide::
# 57 "data/maps/RustboroCity_Gym/scripts.pory"
	lock
# 58 "data/maps/RustboroCity_Gym/scripts.pory"
	faceplayer
# 59 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
# 60 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 61 "data/maps/RustboroCity_Gym/scripts.pory"
	release
# 62 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 63 "data/maps/RustboroCity_Gym/scripts.pory"

# 64 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymGuidePostVictory::
# 65 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 66 "data/maps/RustboroCity_Gym/scripts.pory"
	release
# 67 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 68 "data/maps/RustboroCity_Gym/scripts.pory"

# 69 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_LeftGymStatue::
# 70 "data/maps/RustboroCity_Gym/scripts.pory"
	lockall
# 71 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
# 72 "data/maps/RustboroCity_Gym/scripts.pory"
	goto RustboroCity_Gym_EventScript_GymStatue
# 73 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 74 "data/maps/RustboroCity_Gym/scripts.pory"

# 75 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RightGymStatue::
# 76 "data/maps/RustboroCity_Gym/scripts.pory"
	lockall
# 77 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
# 78 "data/maps/RustboroCity_Gym/scripts.pory"
	goto RustboroCity_Gym_EventScript_GymStatue
# 79 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 80 "data/maps/RustboroCity_Gym/scripts.pory"

# 81 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymStatueCertified::
# 82 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 83 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 84 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 85 "data/maps/RustboroCity_Gym/scripts.pory"

# 86 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymStatue::
# 87 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 88 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 89 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 90 "data/maps/RustboroCity_Gym/scripts.pory"

# 91 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RegisterRoxanne::
# 92 "data/maps/RustboroCity_Gym/scripts.pory"
	lockall
# 93 "data/maps/RustboroCity_Gym/scripts.pory"
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
# 94 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmessage
# 95 "data/maps/RustboroCity_Gym/scripts.pory"
	delay 30
# 96 "data/maps/RustboroCity_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 97 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
# 98 "data/maps/RustboroCity_Gym/scripts.pory"
	waitfanfare
# 99 "data/maps/RustboroCity_Gym/scripts.pory"
	closemessage
# 100 "data/maps/RustboroCity_Gym/scripts.pory"
	delay 30
# 101 "data/maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
# 102 "data/maps/RustboroCity_Gym/scripts.pory"
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
# 103 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 104 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 105 "data/maps/RustboroCity_Gym/scripts.pory"

# 106 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymGuideAdvice:
# 107 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Yo, how's it going?\p"
# 108 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Listen, my friend!\n"
# 109 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Would you like to become the CHAMPION?\p"
# 110 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm no TRAINER, not me, but I can\n"
# 111 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "sure give you winning advice.\p"
# 112 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "That's settled, then! We'll aim for the\n"
# 113 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "POKéMON CHAMPIONSHIP together!\p"
# 114 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It's your job as a TRAINER to collect\n"
# 115 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "GYM BADGES, am I right?\p"
# 116 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "But GYM LEADERS aren't pushovers!\p"
# 117 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "And that's where I come in!\n"
# 118 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm here to provide expert advice!\p"
# 119 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE, the GYM LEADER, is a user\n"
# 120 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "of ROCK-type POKéMON.\p"
# 121 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "The ROCK type is very durable, but\n"
# 122 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "it can't stand WATER-type and\l"
# 123 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "GRASS-type moves.\p"
# 124 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Come see me afterwards, if you beat\n"
# 125 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "the GYM LEADER.\p"
# 126 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Well, go for it!$"
# 127 "data/maps/RustboroCity_Gym/scripts.pory"

# 128 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymGuidePostVictory:
# 129 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Whoa! What a breathtaking victory!\n"
# 130 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "My cheering must've worked!\p"
# 131 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Great!\n"
# 132 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Check your TRAINER CARD.\p"
# 133 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "The STONE BADGE you got should be\n"
# 134 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "properly recorded on it.\p"
# 135 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "In other words…\p"
# 136 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You've climbed the first step on\n"
# 137 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "the stairs to the CHAMPIONSHIP!\p"
# 138 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "That's got to feel awesome!$"
# 139 "data/maps/RustboroCity_Gym/scripts.pory"

# 140 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_JoshIntro:
# 141 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Don't take us GYM TRAINERS lightly!\n"
# 142 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'll show you why we're better!$"
# 143 "data/maps/RustboroCity_Gym/scripts.pory"

# 144 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_JoshDefeat:
# 145 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You were too good for me…$"
# 146 "data/maps/RustboroCity_Gym/scripts.pory"

# 147 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_JoshPostBattle:
# 148 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You haven't seen anything of the ROCK\n"
# 149 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "type's terrifying power!$"
# 150 "data/maps/RustboroCity_Gym/scripts.pory"

# 151 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_TommyIntro:
# 152 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "If you can't beat me, you won't stand\n"
# 153 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "a chance against ROXANNE!$"
# 154 "data/maps/RustboroCity_Gym/scripts.pory"

# 155 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_TommyDefeat:
# 156 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Wow! You've got some potential!$"
# 157 "data/maps/RustboroCity_Gym/scripts.pory"

# 158 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_TommyPostBattle:
# 159 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE is stronger than me by\n"
# 160 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "several times.\p"
# 161 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You'd better be on your guard!$"
# 162 "data/maps/RustboroCity_Gym/scripts.pory"

# 163 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_MarcIntro:
# 164 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "We might be in the middle of town,\n"
# 165 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "but so what?\p"
# 166 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "My ROCK POKéMON need room to\n"
# 167 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "rampage!$"
# 168 "data/maps/RustboroCity_Gym/scripts.pory"

# 169 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_MarcDefeat:
# 170 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Oh, man oh man!\n"
# 171 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Our challenger is one feisty customer!$"
# 172 "data/maps/RustboroCity_Gym/scripts.pory"

# 173 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_MarcPostBattle:
# 174 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I have to hand it to our LEADER.\p"
# 175 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It took smarts and sense for her to\n"
# 176 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "pick the ROCK type at her young age.$"
# 177 "data/maps/RustboroCity_Gym/scripts.pory"

# 178 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneIntro:
# 179 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Hello, I am ROXANNE, the RUSTBORO\n"
# 180 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "POKéMON GYM LEADER.\p"
# 181 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I became a GYM LEADER so that I might\n"
# 182 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "apply what I learned at the POKéMON\l"
# 183 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "TRAINER'S SCHOOL in battle.\p"
# 184 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Would you kindly demonstrate how you\n"
# 185 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "battle, and with which POKéMON?$"
# 186 "data/maps/RustboroCity_Gym/scripts.pory"

# 187 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneDefeat:
# 188 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "So…\n"
# 189 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I lost…\p"
# 190 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It seems that I still have much more\n"
# 191 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "to learn…\p"
# 192 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I understand.\p"
# 193 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "The POKéMON LEAGUE's rules state\n"
# 194 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "that TRAINERS are to be given this\l"
# 195 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "if they defeat a GYM LEADER.\p"
# 196 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Please accept the official POKéMON\n"
# 197 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "LEAGUE STONE BADGE.$"
# 198 "data/maps/RustboroCity_Gym/scripts.pory"

# 199 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_ReceivedStoneBadge:
# 200 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "{PLAYER} received the STONE BADGE\n"
# 201 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "from ROXANNE.$"
# 202 "data/maps/RustboroCity_Gym/scripts.pory"

# 203 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
# 204 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "The STONE BADGE heightens the ATTACK\n"
# 205 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "power of your POKéMON.\p"
# 206 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It also enables them to use the HM move\n"
# 207 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "CUT outside of battle.\p"
# 208 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Please take this with you, too.$"
# 209 "data/maps/RustboroCity_Gym/scripts.pory"

# 210 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_ExplainRockTomb:
# 211 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "That TECHNICAL MACHINE, TM39,\n"
# 212 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "contains ROCK TOMB.\p"
# 213 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It not only inflicts damage by dropping\n"
# 214 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "rocks, it also lowers SPEED.\p"
# 215 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "If you use a TM, it instantly teaches\n"
# 216 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "the move to a POKéMON.\p"
# 217 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Remember, a TM can be used only once,\n"
# 218 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "so think before you use it.$"
# 219 "data/maps/RustboroCity_Gym/scripts.pory"

# 220 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxannePostBattle:
# 221 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Since you are so strong, you should\n"
# 222 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "challenge other GYM LEADERS.\p"
# 223 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "By battling many TRAINERS, you should\n"
# 224 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "learn many things.$"
# 225 "data/maps/RustboroCity_Gym/scripts.pory"

# 226 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymStatue:
# 227 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM$"
# 228 "data/maps/RustboroCity_Gym/scripts.pory"

# 229 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymStatueCertified:
# 230 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM\p"
# 231 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE'S CERTIFIED TRAINERS:\n"
# 232 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 233 "data/maps/RustboroCity_Gym/scripts.pory"

# 234 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneRegisterCall:
# 235 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … …\n"
# 236 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … Beep!\p"
# 237 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: Oh, hello, {PLAYER}?\n"
# 238 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "This is ROXANNE of RUSTBORO CITY.\p"
# 239 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I heard from BRAWLY that you're\n"
# 240 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "moving up through the ranks of\l"
# 241 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "TRAINERS at an incredible clip.\p"
# 242 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Well, I'd rather not think that\n"
# 243 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I can't beat you.\p"
# 244 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I promise, I will shape up my GYM\n"
# 245 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "so that you may challenge us again.\p"
# 246 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I hope you'll be looking forward to\n"
# 247 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "that occasion as much as me!\p"
# 248 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … …\n"
# 249 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … Click!$"
# 250 "data/maps/RustboroCity_Gym/scripts.pory"

# 251 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RegisteredRoxanne:
# 252 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Registered GYM LEADER ROXANNE\n"
# 253 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "in the POKéNAV.$"
# 254 "data/maps/RustboroCity_Gym/scripts.pory"

# 255 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxannePreRematch:
# 256 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: I'm so glad to see you again.\n"
# 257 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
# 258 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm sure we've both experienced many\n"
# 259 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "battles since we last met.\p"
# 260 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I would like to see how much better\n"
# 261 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "we've become. Let us battle!$"
# 262 "data/maps/RustboroCity_Gym/scripts.pory"

# 263 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneRematchDefeat:
# 264 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Grr…\n"
# 265 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Again, I have lost…$"
# 266 "data/maps/RustboroCity_Gym/scripts.pory"

# 267 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxannePostRematch:
# 268 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: I still have much to learn\n"
# 269 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "when it comes to battling POKéMON.\p"
# 270 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "That awareness makes me love battling\n"
# 271 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "all that much more!$"
# 272 "data/maps/RustboroCity_Gym/scripts.pory"

# 273 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
# 274 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: I'm so glad to see you again.\n"
# 275 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
# 276 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm sure we've both experienced many\n"
# 277 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "battles since we last met.\p"
# 278 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I would like to see how much better\n"
# 279 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "we've become…\p"
# 280 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Oh, no…\n"
# 281 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You only have one POKéMON with you?\p"
# 282 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Please return with at least one more\n"
# 283 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "POKéMON.$"

preRoxanne::
# 286 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_ROCKY_PRE_ROXANNE, prerox1, prerox2, prerox3
# 287 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox preRoxanne_Text_0, MSGBOX_DEFAULT
# 288 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmessage
	return


preRoxanne_Text_0:
# 287 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROCKY:You have earned the right to\n"
	.string "challenge ROXANNE.$"

prerox1::
# 291 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROCKY:Let's see what you've got.$"

prerox2::
# 295 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROCKY:Well done.$"

prerox3::
# 299 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROCKY:You should catch some more\n"
	.string "Pokemon.$"
