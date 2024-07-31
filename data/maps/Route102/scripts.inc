# 1 "data/maps/Route102/scripts.pory"
Route102_MapScripts::
# 2 "data/maps/Route102/scripts.pory"
	.byte 0
# 3 "data/maps/Route102/scripts.pory"

# 4 "data/maps/Route102/scripts.pory"
Route102_EventScript_LittleBoy::
# 5 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
# 6 "data/maps/Route102/scripts.pory"
	end
# 7 "data/maps/Route102/scripts.pory"

# 8 "data/maps/Route102/scripts.pory"
Route102_EventScript_RouteSignOldale::
# 9 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
# 10 "data/maps/Route102/scripts.pory"
	end
# 11 "data/maps/Route102/scripts.pory"

# 12 "data/maps/Route102/scripts.pory"
Route102_EventScript_RouteSignPetalburg::
# 13 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
# 14 "data/maps/Route102/scripts.pory"
	end
# 15 "data/maps/Route102/scripts.pory"

# 16 "data/maps/Route102/scripts.pory"
Route102_EventScript_Boy::
# 17 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
# 18 "data/maps/Route102/scripts.pory"
	end
# 19 "data/maps/Route102/scripts.pory"

# 20 "data/maps/Route102/scripts.pory"
Route102_EventScript_Calvin::
# 21 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
# 22 "data/maps/Route102/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 23 "data/maps/Route102/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
# 24 "data/maps/Route102/scripts.pory"
	setvar VAR_0x8004, TRAINER_CALVIN_1
# 25 "data/maps/Route102/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 26 "data/maps/Route102/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
# 27 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
# 28 "data/maps/Route102/scripts.pory"
	release
# 29 "data/maps/Route102/scripts.pory"
	end
# 30 "data/maps/Route102/scripts.pory"

# 31 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
# 32 "data/maps/Route102/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 33 "data/maps/Route102/scripts.pory"
	waitmovement 0
# 34 "data/maps/Route102/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
# 35 "data/maps/Route102/scripts.pory"
	release
# 36 "data/maps/Route102/scripts.pory"
	end
# 37 "data/maps/Route102/scripts.pory"

# 38 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegisterMatchCall::
# 39 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
# 40 "data/maps/Route102/scripts.pory"
	register_matchcall TRAINER_CALVIN_1
# 41 "data/maps/Route102/scripts.pory"
	release
# 42 "data/maps/Route102/scripts.pory"
	end
# 43 "data/maps/Route102/scripts.pory"

# 44 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinTryRegister::
# 45 "data/maps/Route102/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
# 46 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
# 47 "data/maps/Route102/scripts.pory"
	release
# 48 "data/maps/Route102/scripts.pory"
	end
# 49 "data/maps/Route102/scripts.pory"

# 50 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegister::
# 51 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
# 52 "data/maps/Route102/scripts.pory"
	register_matchcall TRAINER_CALVIN_1
# 53 "data/maps/Route102/scripts.pory"
	release
# 54 "data/maps/Route102/scripts.pory"
	end
# 55 "data/maps/Route102/scripts.pory"

# 56 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRematch::
# 57 "data/maps/Route102/scripts.pory"
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
# 58 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
# 59 "data/maps/Route102/scripts.pory"
	end
# 60 "data/maps/Route102/scripts.pory"

# 61 "data/maps/Route102/scripts.pory"
Route102_EventScript_Rick::
# 62 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
# 63 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
# 64 "data/maps/Route102/scripts.pory"
	end
# 65 "data/maps/Route102/scripts.pory"

# 66 "data/maps/Route102/scripts.pory"
Route102_EventScript_Tiana::
# 67 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
# 68 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
# 69 "data/maps/Route102/scripts.pory"
	end
# 70 "data/maps/Route102/scripts.pory"

# 71 "data/maps/Route102/scripts.pory"
Route102_EventScript_Allen::
# 72 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
# 73 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
# 74 "data/maps/Route102/scripts.pory"
	end
# 75 "data/maps/Route102/scripts.pory"

# 76 "data/maps/Route102/scripts.pory"
Route102_Text_WatchMeCatchPokemon:
# 77 "data/maps/Route102/scripts.pory"
	.string "WALLY: {PLAYER}…\n"
# 78 "data/maps/Route102/scripts.pory"
	.string "POKéMON hide in tall grass like this,\l"
# 79 "data/maps/Route102/scripts.pory"
	.string "don't they?\p"
# 80 "data/maps/Route102/scripts.pory"
	.string "Please watch me and see if I can\n"
# 81 "data/maps/Route102/scripts.pory"
	.string "catch one properly.\p"
# 82 "data/maps/Route102/scripts.pory"
	.string "…Whoa!$"
# 83 "data/maps/Route102/scripts.pory"

# 84 "data/maps/Route102/scripts.pory"
Route102_Text_WallyIDidIt:
# 85 "data/maps/Route102/scripts.pory"
	.string "WALLY: I did it… It's my…\n"
# 86 "data/maps/Route102/scripts.pory"
	.string "My POKéMON!$"
# 87 "data/maps/Route102/scripts.pory"

# 88 "data/maps/Route102/scripts.pory"
Route102_Text_LetsGoBack:
# 89 "data/maps/Route102/scripts.pory"
	.string "{PLAYER}, thank you!\n"
# 90 "data/maps/Route102/scripts.pory"
	.string "Let's go back to the GYM!$"
# 91 "data/maps/Route102/scripts.pory"

# 92 "data/maps/Route102/scripts.pory"
Route102_Text_ImNotVeryTall:
# 93 "data/maps/Route102/scripts.pory"
	.string "I'm…not very tall, so I sink right\n"
# 94 "data/maps/Route102/scripts.pory"
	.string "into tall grass.\p"
# 95 "data/maps/Route102/scripts.pory"
	.string "The grass goes up my nose and…\n"
# 96 "data/maps/Route102/scripts.pory"
	.string "Fwafwafwafwafwa…\p"
# 97 "data/maps/Route102/scripts.pory"
	.string "Fwatchoo!$"
# 98 "data/maps/Route102/scripts.pory"

# 99 "data/maps/Route102/scripts.pory"
Route102_Text_CatchWholeBunchOfPokemon:
# 100 "data/maps/Route102/scripts.pory"
	.string "I'm going to catch a whole bunch of\n"
# 101 "data/maps/Route102/scripts.pory"
	.string "POKéMON!$"
# 102 "data/maps/Route102/scripts.pory"

# 103 "data/maps/Route102/scripts.pory"
Route102_Text_RouteSignOldale:
# 104 "data/maps/Route102/scripts.pory"
	.string "ROUTE 102\n"
# 105 "data/maps/Route102/scripts.pory"
	.string "{RIGHT_ARROW} OLDALE TOWN$"
# 106 "data/maps/Route102/scripts.pory"

# 107 "data/maps/Route102/scripts.pory"
Route102_Text_RouteSignPetalburg:
# 108 "data/maps/Route102/scripts.pory"
	.string "ROUTE 102\n"
# 109 "data/maps/Route102/scripts.pory"
	.string "{LEFT_ARROW} PETALBURG CITY$"

MeetLeaf1::
# 113 "data/maps/Route102/scripts.pory"
	lockall
# 114 "data/maps/Route102/scripts.pory"
	applymovement 10, rocketRun
# 115 "data/maps/Route102/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, playerMove
# 116 "data/maps/Route102/scripts.pory"
	applymovement 11, leafRun
# 117 "data/maps/Route102/scripts.pory"
	setflag FLAG_UNUSED_0x494
# 118 "data/maps/Route102/scripts.pory"
	removeobject 10
# 119 "data/maps/Route102/scripts.pory"
	waitmovement 0
# 120 "data/maps/Route102/scripts.pory"
	goto MeetLeaf
	return


MeetLeaf2::
# 123 "data/maps/Route102/scripts.pory"
	lockall
# 124 "data/maps/Route102/scripts.pory"
	applymovement 10, rocketRun
# 125 "data/maps/Route102/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, playerMove2
# 126 "data/maps/Route102/scripts.pory"
	applymovement 11, leafRun
# 127 "data/maps/Route102/scripts.pory"
	setflag FLAG_UNUSED_0x494
# 128 "data/maps/Route102/scripts.pory"
	removeobject 10
# 129 "data/maps/Route102/scripts.pory"
	waitmovement 0
# 130 "data/maps/Route102/scripts.pory"
	goto MeetLeaf
	return


MeetLeaf3::
# 133 "data/maps/Route102/scripts.pory"
	lockall
# 134 "data/maps/Route102/scripts.pory"
	applymovement 10, rocketRun
# 135 "data/maps/Route102/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, playerMove3
# 136 "data/maps/Route102/scripts.pory"
	applymovement 11, leafRun
# 137 "data/maps/Route102/scripts.pory"
	setflag FLAG_UNUSED_0x494
# 138 "data/maps/Route102/scripts.pory"
	removeobject 10
# 139 "data/maps/Route102/scripts.pory"
	waitmovement 0
# 140 "data/maps/Route102/scripts.pory"
	goto MeetLeaf
	return


MeetLeaf::
# 144 "data/maps/Route102/scripts.pory"
	setvar VAR_UNUSED_0x4100, 1
# 145 "data/maps/Route102/scripts.pory"
	msgbox MeetLeaf_Text_0
# 146 "data/maps/Route102/scripts.pory"
	waitmessage
# 147 "data/maps/Route102/scripts.pory"
	waitbuttonpress
# 148 "data/maps/Route102/scripts.pory"
	msgbox MeetLeaf_Text_1
# 149 "data/maps/Route102/scripts.pory"
	waitmessage
# 150 "data/maps/Route102/scripts.pory"
	waitbuttonpress
# 151 "data/maps/Route102/scripts.pory"
	msgbox MeetLeaf_Text_2
# 152 "data/maps/Route102/scripts.pory"
	waitmessage
# 153 "data/maps/Route102/scripts.pory"
	waitbuttonpress
# 154 "data/maps/Route102/scripts.pory"
	msgbox MeetLeaf_Text_3
# 155 "data/maps/Route102/scripts.pory"
	waitmessage
# 156 "data/maps/Route102/scripts.pory"
	waitbuttonpress
# 157 "data/maps/Route102/scripts.pory"
	msgbox MeetLeaf_Text_4
# 158 "data/maps/Route102/scripts.pory"
	waitmessage
# 159 "data/maps/Route102/scripts.pory"
	waitbuttonpress
# 160 "data/maps/Route102/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, playerMove4
# 161 "data/maps/Route102/scripts.pory"
	applymovement 11, leafRun2
# 162 "data/maps/Route102/scripts.pory"
	waitmovement 0
# 163 "data/maps/Route102/scripts.pory"
	setflag FLAG_UNUSED_0x494
# 164 "data/maps/Route102/scripts.pory"
	removeobject 11
# 165 "data/maps/Route102/scripts.pory"
	releaseall
	return


# 167 "data/maps/Route102/scripts.pory"
rocketRun:
# 168 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 168 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 168 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 168 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 168 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 168 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 168 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 168 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 168 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 168 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 168 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 168 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 168 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 168 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 168 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 168 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 168 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 168 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 169 "data/maps/Route102/scripts.pory"
	walk_fast_up
# 169 "data/maps/Route102/scripts.pory"
	walk_fast_up
# 169 "data/maps/Route102/scripts.pory"
	walk_fast_up
# 169 "data/maps/Route102/scripts.pory"
	walk_fast_up
# 169 "data/maps/Route102/scripts.pory"
	walk_fast_up
	step_end

# 171 "data/maps/Route102/scripts.pory"
playerMove:
# 172 "data/maps/Route102/scripts.pory"
	walk_up
# 172 "data/maps/Route102/scripts.pory"
	walk_up
# 173 "data/maps/Route102/scripts.pory"
	face_left
	step_end

# 175 "data/maps/Route102/scripts.pory"
playerMove2:
# 176 "data/maps/Route102/scripts.pory"
	walk_right
# 177 "data/maps/Route102/scripts.pory"
	walk_up
# 177 "data/maps/Route102/scripts.pory"
	walk_up
# 178 "data/maps/Route102/scripts.pory"
	face_left
	step_end

# 180 "data/maps/Route102/scripts.pory"
playerMove3:
# 181 "data/maps/Route102/scripts.pory"
	walk_up
# 181 "data/maps/Route102/scripts.pory"
	walk_up
# 182 "data/maps/Route102/scripts.pory"
	walk_left
# 182 "data/maps/Route102/scripts.pory"
	walk_left
# 182 "data/maps/Route102/scripts.pory"
	walk_left
# 182 "data/maps/Route102/scripts.pory"
	walk_left
	step_end

# 184 "data/maps/Route102/scripts.pory"
leafRun:
# 185 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 185 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 185 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 185 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 185 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 185 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 185 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 185 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 185 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 185 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 185 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 185 "data/maps/Route102/scripts.pory"
	walk_fast_right
	step_end

# 187 "data/maps/Route102/scripts.pory"
leafRun2:
# 188 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 188 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 188 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 188 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 188 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 188 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 188 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 188 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 188 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 188 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 188 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 188 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 188 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 188 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 188 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 188 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 188 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 188 "data/maps/Route102/scripts.pory"
	walk_fast_right
# 189 "data/maps/Route102/scripts.pory"
	walk_fast_up
# 189 "data/maps/Route102/scripts.pory"
	walk_fast_up
# 189 "data/maps/Route102/scripts.pory"
	walk_fast_up
# 189 "data/maps/Route102/scripts.pory"
	walk_fast_up
# 189 "data/maps/Route102/scripts.pory"
	walk_fast_up
	step_end

# 191 "data/maps/Route102/scripts.pory"
playerMove4:
# 192 "data/maps/Route102/scripts.pory"
	walk_fast_down
# 193 "data/maps/Route102/scripts.pory"
	face_right
	step_end

MeetLeaf_Text_0:
# 145 "data/maps/Route102/scripts.pory"
	.string "???:Did you see a man in black run by?$"

MeetLeaf_Text_1:
# 148 "data/maps/Route102/scripts.pory"
	.string "???:Oh!Sorry. My name is Leaf.$"

MeetLeaf_Text_2:
# 151 "data/maps/Route102/scripts.pory"
	.string "Leaf:I was sent here on a mission by\n"
	.string "PROF OAK. Then I came across this guy\l"
	.string "dressed in a TEAM ROCKET outfit. They\l"
	.string "are a bunch of criminals from Kanto.$"

MeetLeaf_Text_3:
# 154 "data/maps/Route102/scripts.pory"
	.string "Leaf:They went north? Oh, no! They\n"
	.string "went to STARTER FIELDS. You are a\l"
	.string "trainner too, right? Please Help me find\l"
	.string "them.$"

MeetLeaf_Text_4:
# 157 "data/maps/Route102/scripts.pory"
	.string "Leaf:You will!? That's great. Follow me!$"
