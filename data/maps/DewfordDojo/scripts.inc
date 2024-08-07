DewfordDojo_MapScripts::
	.byte 0


OnlyFight::
# 4 "data/maps/DewfordDojo/scripts.pory"
	lock
# 5 "data/maps/DewfordDojo/scripts.pory"
	goto_if_set FLAG_UNUSED_0x4A0, OnlyFight_1
	return

OnlyFight_1:
# 6 "data/maps/DewfordDojo/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, dojolook
# 7 "data/maps/DewfordDojo/scripts.pory"
	waitmovement 0
# 8 "data/maps/DewfordDojo/scripts.pory"
	msgbox OnlyFight_Text_0
# 9 "data/maps/DewfordDojo/scripts.pory"
	waitmessage
# 10 "data/maps/DewfordDojo/scripts.pory"
	specialvar VAR_RESULT, CheckDojo
# 11 "data/maps/DewfordDojo/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne OnlyFight_4
# 15 "data/maps/DewfordDojo/scripts.pory"
	msgbox OnlyFight_Text_2
# 16 "data/maps/DewfordDojo/scripts.pory"
	waitmessage
# 17 "data/maps/DewfordDojo/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, dojoOut
# 18 "data/maps/DewfordDojo/scripts.pory"
	waitmovement 0
OnlyFight_3:
# 20 "data/maps/DewfordDojo/scripts.pory"
	release
	return

OnlyFight_4:
# 12 "data/maps/DewfordDojo/scripts.pory"
	msgbox OnlyFight_Text_1
# 13 "data/maps/DewfordDojo/scripts.pory"
	waitmessage
	goto OnlyFight_3


leftDojo::
# 25 "data/maps/DewfordDojo/scripts.pory"
	lock
# 26 "data/maps/DewfordDojo/scripts.pory"
	setflag FLAG_UNUSED_0x4A0
# 27 "data/maps/DewfordDojo/scripts.pory"
	release
	return


enterDojo::
# 30 "data/maps/DewfordDojo/scripts.pory"
	lock
# 31 "data/maps/DewfordDojo/scripts.pory"
	clearflag FLAG_UNUSED_0x4A0
# 32 "data/maps/DewfordDojo/scripts.pory"
	release
	return


# 35 "data/maps/DewfordDojo/scripts.pory"
dojoOut:
# 36 "data/maps/DewfordDojo/scripts.pory"
	walk_down
	step_end

# 39 "data/maps/DewfordDojo/scripts.pory"
dojolook:
# 40 "data/maps/DewfordDojo/scripts.pory"
	face_right
	step_end

OnlyFight_Text_0:
# 8 "data/maps/DewfordDojo/scripts.pory"
	.string "DOJO GUARDIAN:Welcome to DEWFORD\n"
	.string "DOJO. You can challenge the dojo\l"
	.string "masters for a very special prize.\l"
	.string "However, only fighting type pokemon are\l"
	.string "allowed inside.$"

OnlyFight_Text_1:
# 12 "data/maps/DewfordDojo/scripts.pory"
	.string "DOJO GUARDIAN:You may proceed!$"

OnlyFight_Text_2:
# 15 "data/maps/DewfordDojo/scripts.pory"
	.string "DOJO GUARDIAN:Only fighting types are\n"
	.string "allowed in the dojo. Sorry.$"
