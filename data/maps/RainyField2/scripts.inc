# 1 "data/maps/RainyField2/scripts.pory"

# 2 "data/maps/RainyField2/scripts.pory"
.set LOCALID_Rocket, 1
# 3 "data/maps/RainyField2/scripts.pory"
.set LOCALID_Leaf, 2
# 4 "data/maps/RainyField2/scripts.pory"

# 5 "data/maps/RainyField2/scripts.pory"
RainyField2_MapScripts::
# 6 "data/maps/RainyField2/scripts.pory"
	.byte 0

rocketFightRainy::
# 10 "data/maps/RainyField2/scripts.pory"
	lock
# 11 "data/maps/RainyField2/scripts.pory"
	trainerbattle_single TRAINER_ROCKET_START_FIELD, startField_Text_Rocket1Rainy, startField_Text_Rocket2Rainy
# 12 "data/maps/RainyField2/scripts.pory"
	msgbox rocketFightRainy_Text_0
# 13 "data/maps/RainyField2/scripts.pory"
	waitmessage
# 14 "data/maps/RainyField2/scripts.pory"
	waitbuttonpress
# 15 "data/maps/RainyField2/scripts.pory"
	setvar VAR_UNUSED_0x4101, 1
# 16 "data/maps/RainyField2/scripts.pory"
	release
	return


LeafEndingRainy::
# 19 "data/maps/RainyField2/scripts.pory"
	lock
# 20 "data/maps/RainyField2/scripts.pory"
	msgbox LeafEndingRainy_Text_0
# 21 "data/maps/RainyField2/scripts.pory"
	setvar VAR_UNUSED_0x4101, 2
# 22 "data/maps/RainyField2/scripts.pory"
	release
	return


choiceRainy::
# 26 "data/maps/RainyField2/scripts.pory"
	lock
# 27 "data/maps/RainyField2/scripts.pory"
	compare VAR_UNUSED_0x4101, 0
	goto_if_eq choiceRainy_2
choiceRainy_1:
# 31 "data/maps/RainyField2/scripts.pory"
	compare VAR_UNUSED_0x4101, 1
	goto_if_eq choiceRainy_5
choiceRainy_4:
# 35 "data/maps/RainyField2/scripts.pory"
	compare VAR_UNUSED_0x4101, 2
	goto_if_eq choiceRainy_8
choiceRainy_7:
# 41 "data/maps/RainyField2/scripts.pory"
	release
	return

choiceRainy_2:
# 28 "data/maps/RainyField2/scripts.pory"
	setflag FLAG_UNUSED_0x495
# 29 "data/maps/RainyField2/scripts.pory"
	removeobject LOCALID_Leaf
	goto choiceRainy_1

choiceRainy_5:
# 32 "data/maps/RainyField2/scripts.pory"
	setflag FLAG_UNUSED_0x496
# 33 "data/maps/RainyField2/scripts.pory"
	removeobject LOCALID_Rocket
	goto choiceRainy_4

choiceRainy_8:
# 36 "data/maps/RainyField2/scripts.pory"
	setflag FLAG_UNUSED_0x495
# 37 "data/maps/RainyField2/scripts.pory"
	setflag FLAG_UNUSED_0x496
# 38 "data/maps/RainyField2/scripts.pory"
	removeobject LOCALID_Leaf
# 39 "data/maps/RainyField2/scripts.pory"
	removeobject LOCALID_Rocket
	goto choiceRainy_7


rocketFightRainy_Text_0:
# 12 "data/maps/RainyField2/scripts.pory"
	.string "{PLAYER}:I should go look for LEAF.\n"
	.string "She must be at RAINY FIELDS.$"

LeafEndingRainy_Text_0:
# 20 "data/maps/RainyField2/scripts.pory"
	.string "LEAF:We did it!$"

startField_Text_Rocket1Rainy::
# 44 "data/maps/RainyField2/scripts.pory"
	.string "TEAM ROCKET: Get lost! This doesn't\n"
	.string "consern you.$"

startField_Text_Rocket2Rainy::
# 47 "data/maps/RainyField2/scripts.pory"
	.string "TEAM ROCKET: How di I lose to a\n"
	.string "beginner?$"
