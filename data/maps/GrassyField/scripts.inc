# 1 "data/maps/GrassyField/scripts.pory"

# 2 "data/maps/GrassyField/scripts.pory"
.set LOCALID_Leaf, 1
# 3 "data/maps/GrassyField/scripts.pory"

# 4 "data/maps/GrassyField/scripts.pory"
GrassyField_MapScripts::
# 5 "data/maps/GrassyField/scripts.pory"
	.byte 0

LeafTalk::
# 9 "data/maps/GrassyField/scripts.pory"
	lock
# 10 "data/maps/GrassyField/scripts.pory"
	msgbox LeafTalk_Text_0, MSGBOX_DEFAULT
# 11 "data/maps/GrassyField/scripts.pory"
	waitmessage
# 12 "data/maps/GrassyField/scripts.pory"
	setvar VAR_UNUSED_0x4101, 1
# 13 "data/maps/GrassyField/scripts.pory"
	release
	return


LeafTalk1::
# 17 "data/maps/GrassyField/scripts.pory"
	lock
# 18 "data/maps/GrassyField/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, faceLeaf
# 19 "data/maps/GrassyField/scripts.pory"
	applymovement LOCALID_Leaf, LeafFacePlayerGrassy
# 20 "data/maps/GrassyField/scripts.pory"
	waitmovement 0
# 21 "data/maps/GrassyField/scripts.pory"
	msgbox LeafTalk_Text_0, MSGBOX_DEFAULT
# 22 "data/maps/GrassyField/scripts.pory"
	waitmessage
# 23 "data/maps/GrassyField/scripts.pory"
	applymovement LOCALID_Leaf, leafLeavegrassy
# 24 "data/maps/GrassyField/scripts.pory"
	waitmovement 0
# 25 "data/maps/GrassyField/scripts.pory"
	setflag FLAG_UNUSED_0x497
# 26 "data/maps/GrassyField/scripts.pory"
	removeobject LOCALID_Leaf
# 27 "data/maps/GrassyField/scripts.pory"
	release
	return


# 29 "data/maps/GrassyField/scripts.pory"
leafLeavegrassy:
# 30 "data/maps/GrassyField/scripts.pory"
	walk_up
# 30 "data/maps/GrassyField/scripts.pory"
	walk_up
# 30 "data/maps/GrassyField/scripts.pory"
	walk_up
# 30 "data/maps/GrassyField/scripts.pory"
	walk_up
# 30 "data/maps/GrassyField/scripts.pory"
	walk_up
# 30 "data/maps/GrassyField/scripts.pory"
	walk_up
	step_end

# 33 "data/maps/GrassyField/scripts.pory"
faceLeaf:
# 34 "data/maps/GrassyField/scripts.pory"
	face_left
	step_end

# 36 "data/maps/GrassyField/scripts.pory"
LeafFacePlayerGrassy:
# 37 "data/maps/GrassyField/scripts.pory"
	face_right
	step_end

LeafTalk_Text_0:
# 10 "data/maps/GrassyField/scripts.pory"
	.string "LEAF:{PLAYER}! There are two of\n"
	.string "those thugs. One went towards the\l"
	.string "BURNING FIELDS up ahead and to the\l"
	.string "left, and the other went to the RAINY\l"
	.string "FIELDS, up ahead and to the right. You\l"
	.string "get one of them, and I'll get the other.$"
