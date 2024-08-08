# 1 "data/maps/Route102/scripts.pory"

# 2 "data/maps/Route102/scripts.pory"
.set LOCALID_Rocket, 10
# 3 "data/maps/Route102/scripts.pory"
.set LOCALID_Leaf, 11
# 4 "data/maps/Route102/scripts.pory"

# 5 "data/maps/Route102/scripts.pory"
Route102_MapScripts::
# 6 "data/maps/Route102/scripts.pory"
	.byte 0
# 7 "data/maps/Route102/scripts.pory"

# 8 "data/maps/Route102/scripts.pory"
Route102_EventScript_LittleBoy::
# 9 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
# 10 "data/maps/Route102/scripts.pory"
	end
# 11 "data/maps/Route102/scripts.pory"

# 12 "data/maps/Route102/scripts.pory"
Route102_EventScript_RouteSignOldale::
# 13 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
# 14 "data/maps/Route102/scripts.pory"
	end
# 15 "data/maps/Route102/scripts.pory"

# 16 "data/maps/Route102/scripts.pory"
Route102_EventScript_RouteSignPetalburg::
# 17 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
# 18 "data/maps/Route102/scripts.pory"
	end
# 19 "data/maps/Route102/scripts.pory"

# 20 "data/maps/Route102/scripts.pory"
Route102_EventScript_Boy::
# 21 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
# 22 "data/maps/Route102/scripts.pory"
	end
# 23 "data/maps/Route102/scripts.pory"

# 24 "data/maps/Route102/scripts.pory"
Route102_EventScript_Calvin::
# 25 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
# 26 "data/maps/Route102/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 27 "data/maps/Route102/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
# 28 "data/maps/Route102/scripts.pory"
	setvar VAR_0x8004, TRAINER_CALVIN_1
# 29 "data/maps/Route102/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 30 "data/maps/Route102/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
# 31 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
# 32 "data/maps/Route102/scripts.pory"
	release
# 33 "data/maps/Route102/scripts.pory"
	end
# 34 "data/maps/Route102/scripts.pory"

# 35 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
# 36 "data/maps/Route102/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 37 "data/maps/Route102/scripts.pory"
	waitmovement 0
# 38 "data/maps/Route102/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
# 39 "data/maps/Route102/scripts.pory"
	release
# 40 "data/maps/Route102/scripts.pory"
	end
# 41 "data/maps/Route102/scripts.pory"

# 42 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegisterMatchCall::
# 43 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
# 44 "data/maps/Route102/scripts.pory"
	register_matchcall TRAINER_CALVIN_1
# 45 "data/maps/Route102/scripts.pory"
	release
# 46 "data/maps/Route102/scripts.pory"
	end
# 47 "data/maps/Route102/scripts.pory"

# 48 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinTryRegister::
# 49 "data/maps/Route102/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
# 50 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
# 51 "data/maps/Route102/scripts.pory"
	release
# 52 "data/maps/Route102/scripts.pory"
	end
# 53 "data/maps/Route102/scripts.pory"

# 54 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegister::
# 55 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
# 56 "data/maps/Route102/scripts.pory"
	register_matchcall TRAINER_CALVIN_1
# 57 "data/maps/Route102/scripts.pory"
	release
# 58 "data/maps/Route102/scripts.pory"
	end
# 59 "data/maps/Route102/scripts.pory"

# 60 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRematch::
# 61 "data/maps/Route102/scripts.pory"
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
# 62 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
# 63 "data/maps/Route102/scripts.pory"
	end
# 64 "data/maps/Route102/scripts.pory"

# 65 "data/maps/Route102/scripts.pory"
Route102_EventScript_Rick::
# 66 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
# 67 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
# 68 "data/maps/Route102/scripts.pory"
	end
# 69 "data/maps/Route102/scripts.pory"

# 70 "data/maps/Route102/scripts.pory"
Route102_EventScript_Tiana::
# 71 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
# 72 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
# 73 "data/maps/Route102/scripts.pory"
	end
# 74 "data/maps/Route102/scripts.pory"

# 75 "data/maps/Route102/scripts.pory"
Route102_EventScript_Allen::
# 76 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
# 77 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
# 78 "data/maps/Route102/scripts.pory"
	end
# 79 "data/maps/Route102/scripts.pory"

# 80 "data/maps/Route102/scripts.pory"
Route102_Text_WatchMeCatchPokemon:
# 81 "data/maps/Route102/scripts.pory"
	.string "WALLY: {PLAYER}…\n"
# 82 "data/maps/Route102/scripts.pory"
	.string "POKéMON hide in tall grass like this,\l"
# 83 "data/maps/Route102/scripts.pory"
	.string "don't they?\p"
# 84 "data/maps/Route102/scripts.pory"
	.string "Please watch me and see if I can\n"
# 85 "data/maps/Route102/scripts.pory"
	.string "catch one properly.\p"
# 86 "data/maps/Route102/scripts.pory"
	.string "…Whoa!$"
# 87 "data/maps/Route102/scripts.pory"

# 88 "data/maps/Route102/scripts.pory"
Route102_Text_WallyIDidIt:
# 89 "data/maps/Route102/scripts.pory"
	.string "WALLY: I did it… It's my…\n"
# 90 "data/maps/Route102/scripts.pory"
	.string "My POKéMON!$"
# 91 "data/maps/Route102/scripts.pory"

# 92 "data/maps/Route102/scripts.pory"
Route102_Text_LetsGoBack:
# 93 "data/maps/Route102/scripts.pory"
	.string "{PLAYER}, thank you!\n"
# 94 "data/maps/Route102/scripts.pory"
	.string "Let's go back to the GYM!$"
# 95 "data/maps/Route102/scripts.pory"

# 96 "data/maps/Route102/scripts.pory"
Route102_Text_ImNotVeryTall:
# 97 "data/maps/Route102/scripts.pory"
	.string "I'm…not very tall, so I sink right\n"
# 98 "data/maps/Route102/scripts.pory"
	.string "into tall grass.\p"
# 99 "data/maps/Route102/scripts.pory"
	.string "The grass goes up my nose and…\n"
# 100 "data/maps/Route102/scripts.pory"
	.string "Fwafwafwafwafwa…\p"
# 101 "data/maps/Route102/scripts.pory"
	.string "Fwatchoo!$"
# 102 "data/maps/Route102/scripts.pory"

# 103 "data/maps/Route102/scripts.pory"
Route102_Text_CatchWholeBunchOfPokemon:
# 104 "data/maps/Route102/scripts.pory"
	.string "I'm going to catch a whole bunch of\n"
# 105 "data/maps/Route102/scripts.pory"
	.string "POKéMON!$"
# 106 "data/maps/Route102/scripts.pory"

# 107 "data/maps/Route102/scripts.pory"
Route102_Text_RouteSignOldale:
# 108 "data/maps/Route102/scripts.pory"
	.string "ROUTE 102\n"
# 109 "data/maps/Route102/scripts.pory"
	.string "{RIGHT_ARROW} OLDALE TOWN$"
# 110 "data/maps/Route102/scripts.pory"

# 111 "data/maps/Route102/scripts.pory"
Route102_Text_RouteSignPetalburg:
# 112 "data/maps/Route102/scripts.pory"
	.string "ROUTE 102\n"
# 113 "data/maps/Route102/scripts.pory"
	.string "{LEFT_ARROW} PETALBURG CITY$"

HelpLeaf::
# 116 "data/maps/Route102/scripts.pory"
	lock
# 117 "data/maps/Route102/scripts.pory"
	msgbox HelpLeaf_Text_0
# 118 "data/maps/Route102/scripts.pory"
	waitmessage
# 119 "data/maps/Route102/scripts.pory"
	waitbuttonpress
# 120 "data/maps/Route102/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, playerMove2
# 121 "data/maps/Route102/scripts.pory"
	waitmovement 0
# 122 "data/maps/Route102/scripts.pory"
	release
# 123 "data/maps/Route102/scripts.pory"
	release
	return


MeetLeaf1::
# 127 "data/maps/Route102/scripts.pory"
	lock
# 128 "data/maps/Route102/scripts.pory"
	applymovement LOCALID_Rocket, rocketRun
# 129 "data/maps/Route102/scripts.pory"
	waitmovement 0
# 130 "data/maps/Route102/scripts.pory"
	addobject LOCALID_Leaf
# 131 "data/maps/Route102/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, playerMove
# 132 "data/maps/Route102/scripts.pory"
	applymovement LOCALID_Leaf, leafRun
# 133 "data/maps/Route102/scripts.pory"
	setflag FLAG_UNUSED_0x494
# 134 "data/maps/Route102/scripts.pory"
	removeobject LOCALID_Rocket
# 135 "data/maps/Route102/scripts.pory"
	waitmovement 0
# 136 "data/maps/Route102/scripts.pory"
	goto MeetLeaf
	return


MeetLeaf::
# 141 "data/maps/Route102/scripts.pory"
	setvar VAR_UNUSED_0x4100, 1
# 142 "data/maps/Route102/scripts.pory"
	msgbox MeetLeaf_Text_0, MSGBOX_DEFAULT
# 143 "data/maps/Route102/scripts.pory"
	waitmessage
# 144 "data/maps/Route102/scripts.pory"
	waitbuttonpress
# 145 "data/maps/Route102/scripts.pory"
	msgbox MeetLeaf_Text_1
# 146 "data/maps/Route102/scripts.pory"
	waitmessage
# 147 "data/maps/Route102/scripts.pory"
	waitbuttonpress
# 148 "data/maps/Route102/scripts.pory"
	msgbox MeetLeaf_Text_2, MSGBOX_DEFAULT
# 149 "data/maps/Route102/scripts.pory"
	waitmessage
# 150 "data/maps/Route102/scripts.pory"
	waitbuttonpress
# 151 "data/maps/Route102/scripts.pory"
	msgbox MeetLeaf_Text_3, MSGBOX_DEFAULT
# 152 "data/maps/Route102/scripts.pory"
	waitmessage
# 153 "data/maps/Route102/scripts.pory"
	waitbuttonpress
# 154 "data/maps/Route102/scripts.pory"
	msgbox MeetLeaf_Text_4, MSGBOX_DEFAULT
# 155 "data/maps/Route102/scripts.pory"
	waitmessage
# 156 "data/maps/Route102/scripts.pory"
	waitbuttonpress
# 157 "data/maps/Route102/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, playerMove4
# 158 "data/maps/Route102/scripts.pory"
	applymovement LOCALID_Leaf, leafRun2
# 159 "data/maps/Route102/scripts.pory"
	waitmovement 0
# 160 "data/maps/Route102/scripts.pory"
	setflag FLAG_UNUSED_0x493
# 161 "data/maps/Route102/scripts.pory"
	removeobject LOCALID_Leaf
# 162 "data/maps/Route102/scripts.pory"
	release
	return


# 164 "data/maps/Route102/scripts.pory"
rocketRun:
# 165 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 165 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 165 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 165 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 165 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 165 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 165 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 165 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 165 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 165 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 166 "data/maps/Route102/scripts.pory"
	walk_fast_up
# 166 "data/maps/Route102/scripts.pory"
	walk_fast_up
# 166 "data/maps/Route102/scripts.pory"
	walk_fast_up
# 166 "data/maps/Route102/scripts.pory"
	walk_fast_up
	step_end

# 168 "data/maps/Route102/scripts.pory"
playerMove:
# 169 "data/maps/Route102/scripts.pory"
	walk_up
# 169 "data/maps/Route102/scripts.pory"
	walk_up
# 170 "data/maps/Route102/scripts.pory"
	walk_left
# 170 "data/maps/Route102/scripts.pory"
	walk_left
# 170 "data/maps/Route102/scripts.pory"
	walk_left
# 170 "data/maps/Route102/scripts.pory"
	walk_left
	step_end

# 172 "data/maps/Route102/scripts.pory"
playerMove2:
# 173 "data/maps/Route102/scripts.pory"
	walk_right
	step_end

# 175 "data/maps/Route102/scripts.pory"
leafRun:
# 176 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 176 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 176 "data/maps/Route102/scripts.pory"
	walk_fast_right
	step_end

# 178 "data/maps/Route102/scripts.pory"
leafRun2:
# 179 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 179 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 179 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 179 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 179 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 179 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 179 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 179 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 180 "data/maps/Route102/scripts.pory"
	walk_fast_up
# 180 "data/maps/Route102/scripts.pory"
	walk_fast_up
# 180 "data/maps/Route102/scripts.pory"
	walk_fast_up
# 180 "data/maps/Route102/scripts.pory"
	walk_fast_up
# 180 "data/maps/Route102/scripts.pory"
	walk_fast_up
	step_end

# 182 "data/maps/Route102/scripts.pory"
playerMove4:
# 183 "data/maps/Route102/scripts.pory"
	walk_fast_down
# 184 "data/maps/Route102/scripts.pory"
	face_right
	step_end

HelpLeaf_Text_0:
# 117 "data/maps/Route102/scripts.pory"
	.string "{PLAYER}: I should help LEAF.$"

MeetLeaf_Text_0:
# 142 "data/maps/Route102/scripts.pory"
	.string "???:Did you see a man in black run by?$"

MeetLeaf_Text_1:
# 145 "data/maps/Route102/scripts.pory"
	.string "???:Oh!Sorry. My name is Leaf.$"

MeetLeaf_Text_2:
# 148 "data/maps/Route102/scripts.pory"
	.string "LEAF:I was sent here on a mission by\n"
	.string "PROF OAK. Then I came across this guy\l"
	.string "dressed in a TEAM ROCKET outfit. They\l"
	.string "are a bunch of criminals from Kanto.$"

MeetLeaf_Text_3:
# 151 "data/maps/Route102/scripts.pory"
	.string "LEAF:They went north? Oh, no! They\n"
	.string "went to STARTER FIELDS. You are a\l"
	.string "trainner too, right? Please Help me find\l"
	.string "them.$"

MeetLeaf_Text_4:
# 154 "data/maps/Route102/scripts.pory"
	.string "LEAF:You will!? That's great. Follow me!$"
