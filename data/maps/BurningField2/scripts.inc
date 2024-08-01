# 1 "data/maps/BurningField2/scripts.pory"
BurningField2_MapScripts::
# 2 "data/maps/BurningField2/scripts.pory"
	.byte 0

rocketFight::
# 5 "data/maps/BurningField2/scripts.pory"
	lock
# 6 "data/maps/BurningField2/scripts.pory"
	trainerbattle_single TRAINER_ROCKET_START_FIELD, startField_Text_Rocket1, startField_Text_Rocket2
# 7 "data/maps/BurningField2/scripts.pory"
	msgbox rocketFight_Text_0
# 8 "data/maps/BurningField2/scripts.pory"
	waitmessage
# 9 "data/maps/BurningField2/scripts.pory"
	waitbuttonpress
# 10 "data/maps/BurningField2/scripts.pory"
	setvar VAR_UNUSED_0x4101, 1
# 11 "data/maps/BurningField2/scripts.pory"
	release
	return


rocketFight_Text_0:
# 7 "data/maps/BurningField2/scripts.pory"
	.string "{PLAYER}:I should go look for LEAF.\n"
	.string "She must be at RAINY FIELDS.$"

startField_Text_Rocket1::
# 14 "data/maps/BurningField2/scripts.pory"
	.string "TEAM ROCKET: Get lost! This doesn't\n"
	.string "consern you.$"

startField_Text_Rocket2::
# 17 "data/maps/BurningField2/scripts.pory"
	.string "TEAM ROCKET: How di I lose to a\n"
	.string "beginner?$"
