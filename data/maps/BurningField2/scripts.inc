# 1 "data/maps/BurningField2/scripts.pory"

# 2 "data/maps/BurningField2/scripts.pory"
.set LOCALID_Rocket, 1
# 3 "data/maps/BurningField2/scripts.pory"

# 4 "data/maps/BurningField2/scripts.pory"
BurningField2_MapScripts::
# 5 "data/maps/BurningField2/scripts.pory"
	.byte 0

rocketFightBurn::
# 8 "data/maps/BurningField2/scripts.pory"
	lock
# 9 "data/maps/BurningField2/scripts.pory"
	faceplayer
# 10 "data/maps/BurningField2/scripts.pory"
	trainerbattle_single TRAINER_ROCKET_START_FIELD, startField_Text_Rocket1, startField_Text_Rocket2, rocketFightBurn2
# 11 "data/maps/BurningField2/scripts.pory"
	release
	return


rocketFightBurn2::
# 15 "data/maps/BurningField2/scripts.pory"
	msgbox rocketFightBurn2_Text_0, MSGBOX_DEFAULT
# 16 "data/maps/BurningField2/scripts.pory"
	waitmessage
# 17 "data/maps/BurningField2/scripts.pory"
	waitbuttonpress
# 18 "data/maps/BurningField2/scripts.pory"
	fadescreen FADE_TO_BLACK
# 19 "data/maps/BurningField2/scripts.pory"
	setflag FLAG_UNUSED_0x496
# 20 "data/maps/BurningField2/scripts.pory"
	removeobject LOCALID_Rocket
# 21 "data/maps/BurningField2/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 22 "data/maps/BurningField2/scripts.pory"
	msgbox rocketFightBurn2_Text_1, MSGBOX_DEFAULT
# 23 "data/maps/BurningField2/scripts.pory"
	waitmessage
# 24 "data/maps/BurningField2/scripts.pory"
	waitbuttonpress
# 25 "data/maps/BurningField2/scripts.pory"
	setvar VAR_UNUSED_0x4101, 1
# 26 "data/maps/BurningField2/scripts.pory"
	release
	return


rocketFightBurn2_Text_0:
# 15 "data/maps/BurningField2/scripts.pory"
	.string "TEAM ROCKET: You'll pay for this.$"

rocketFightBurn2_Text_1:
# 22 "data/maps/BurningField2/scripts.pory"
	.string "{PLAYER}:I should go look for LEAF.\n"
	.string "She must be at RAINY FIELDS.$"

startField_Text_Rocket1::
# 29 "data/maps/BurningField2/scripts.pory"
	.string "TEAM ROCKET: Get lost! This doesn't\n"
	.string "consern you.$"

startField_Text_Rocket2::
# 32 "data/maps/BurningField2/scripts.pory"
	.string "TEAM ROCKET: How do I lose to a\n"
	.string "beginner?$"
