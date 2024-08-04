# 1 "data/maps/GrassyField2/scripts.pory"
GrassyField2_MapScripts::
# 2 "data/maps/GrassyField2/scripts.pory"
	.byte 0

beatRocketStarter::
# 5 "data/maps/GrassyField2/scripts.pory"
	lock
# 6 "data/maps/GrassyField2/scripts.pory"
	compare VAR_UNUSED_0x4101, 0
	goto_if_eq beatRocketStarter_2
beatRocketStarter_1:
# 12 "data/maps/GrassyField2/scripts.pory"
	release
	return

beatRocketStarter_2:
# 7 "data/maps/GrassyField2/scripts.pory"
	msgbox beatRocketStarter_Text_0, MSGBOX_DEFAULT
# 8 "data/maps/GrassyField2/scripts.pory"
	waitmessage
# 9 "data/maps/GrassyField2/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, goBurning
# 10 "data/maps/GrassyField2/scripts.pory"
	waitmovement 0
	goto beatRocketStarter_1


# 15 "data/maps/GrassyField2/scripts.pory"
goBurning:
# 16 "data/maps/GrassyField2/scripts.pory"
	walk_down
# 17 "data/maps/GrassyField2/scripts.pory"
	walk_left
	step_end

beatRocketStarter_Text_0:
# 7 "data/maps/GrassyField2/scripts.pory"
	.string "{PLAYER}:LEAF said I should stop the\n"
	.string "TEAM ROCKET guy in BURNING FIELDS\l"
	.string "first. I think it's to the left.$"
