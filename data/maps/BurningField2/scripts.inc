# 1 "data/maps/BurningField2/scripts.pory"

# 2 "data/maps/BurningField2/scripts.pory"
.set LOCALID_Rocket, 1
# 3 "data/maps/BurningField2/scripts.pory"
.set LOCALID_Leaf, 2
# 4 "data/maps/BurningField2/scripts.pory"

# 5 "data/maps/BurningField2/scripts.pory"
BurningField2_MapScripts::
# 6 "data/maps/BurningField2/scripts.pory"
	.byte 0

rocketFight::
# 9 "data/maps/BurningField2/scripts.pory"
	lock
# 10 "data/maps/BurningField2/scripts.pory"
	trainerbattle_single TRAINER_ROCKET_START_FIELD, startField_Text_Rocket1, startField_Text_Rocket2
# 11 "data/maps/BurningField2/scripts.pory"
	msgbox rocketFight_Text_0
# 12 "data/maps/BurningField2/scripts.pory"
	waitmessage
# 13 "data/maps/BurningField2/scripts.pory"
	waitbuttonpress
# 14 "data/maps/BurningField2/scripts.pory"
	setvar VAR_UNUSED_0x4101, 1
# 15 "data/maps/BurningField2/scripts.pory"
	release
	return


LeafEnding::
# 18 "data/maps/BurningField2/scripts.pory"
	lock
# 19 "data/maps/BurningField2/scripts.pory"
	msgbox LeafEnding_Text_0
# 20 "data/maps/BurningField2/scripts.pory"
	setvar VAR_UNUSED_0x4101, 2
# 21 "data/maps/BurningField2/scripts.pory"
	release
	return


choice::
# 25 "data/maps/BurningField2/scripts.pory"
	lock
# 26 "data/maps/BurningField2/scripts.pory"
	compare VAR_UNUSED_0x4101, 0
	goto_if_eq choice_2
choice_1:
# 30 "data/maps/BurningField2/scripts.pory"
	compare VAR_UNUSED_0x4101, 1
	goto_if_eq choice_5
choice_4:
# 34 "data/maps/BurningField2/scripts.pory"
	compare VAR_UNUSED_0x4101, 2
	goto_if_eq choice_8
choice_7:
# 40 "data/maps/BurningField2/scripts.pory"
	release
	return

choice_2:
# 27 "data/maps/BurningField2/scripts.pory"
	setflag FLAG_UNUSED_0x495
# 28 "data/maps/BurningField2/scripts.pory"
	removeobject LOCALID_Leaf
	goto choice_1

choice_5:
# 31 "data/maps/BurningField2/scripts.pory"
	setflag FLAG_UNUSED_0x496
# 32 "data/maps/BurningField2/scripts.pory"
	removeobject LOCALID_Rocket
	goto choice_4

choice_8:
# 35 "data/maps/BurningField2/scripts.pory"
	setflag FLAG_UNUSED_0x495
# 36 "data/maps/BurningField2/scripts.pory"
	setflag FLAG_UNUSED_0x496
# 37 "data/maps/BurningField2/scripts.pory"
	removeobject LOCALID_Leaf
# 38 "data/maps/BurningField2/scripts.pory"
	removeobject LOCALID_Rocket
	goto choice_7


rocketFight_Text_0:
# 11 "data/maps/BurningField2/scripts.pory"
	.string "{PLAYER}:I should go look for LEAF.\n"
	.string "She must be at RAINY FIELDS.$"

LeafEnding_Text_0:
# 19 "data/maps/BurningField2/scripts.pory"
	.string "LEAF:We did it!$"

startField_Text_Rocket1::
# 43 "data/maps/BurningField2/scripts.pory"
	.string "TEAM ROCKET: Get lost! This doesn't\n"
	.string "consern you.$"

startField_Text_Rocket2::
# 46 "data/maps/BurningField2/scripts.pory"
	.string "TEAM ROCKET: How di I lose to a\n"
	.string "beginner?$"
