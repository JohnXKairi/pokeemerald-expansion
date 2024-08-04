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
	faceplayer
# 11 "data/maps/GrassyField/scripts.pory"
	msgbox LeafTalk_Text_0, MSGBOX_DEFAULT
# 12 "data/maps/GrassyField/scripts.pory"
	waitmessage
# 13 "data/maps/GrassyField/scripts.pory"
	applymovement LOCALID_Leaf, leafLeavegrassy
# 14 "data/maps/GrassyField/scripts.pory"
	waitmovement 0
# 15 "data/maps/GrassyField/scripts.pory"
	setflag FLAG_UNUSED_0x497
# 16 "data/maps/GrassyField/scripts.pory"
	removeobject LOCALID_Leaf
# 17 "data/maps/GrassyField/scripts.pory"
	release
	return


LeafTalk1::
# 21 "data/maps/GrassyField/scripts.pory"
	lock
# 22 "data/maps/GrassyField/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, faceLeaf
# 23 "data/maps/GrassyField/scripts.pory"
	applymovement LOCALID_Leaf, LeafFacePlayerGrassy
# 24 "data/maps/GrassyField/scripts.pory"
	waitmovement 0
# 25 "data/maps/GrassyField/scripts.pory"
	msgbox LeafTalk_Text_0, MSGBOX_DEFAULT
# 26 "data/maps/GrassyField/scripts.pory"
	waitmessage
# 27 "data/maps/GrassyField/scripts.pory"
	applymovement LOCALID_Leaf, leafLeavegrassy
# 28 "data/maps/GrassyField/scripts.pory"
	waitmovement 0
# 29 "data/maps/GrassyField/scripts.pory"
	setflag FLAG_UNUSED_0x497
# 30 "data/maps/GrassyField/scripts.pory"
	removeobject LOCALID_Leaf
# 31 "data/maps/GrassyField/scripts.pory"
	release
	return


# 33 "data/maps/GrassyField/scripts.pory"
leafLeavegrassy:
# 34 "data/maps/GrassyField/scripts.pory"
	walk_up
# 34 "data/maps/GrassyField/scripts.pory"
	walk_up
# 34 "data/maps/GrassyField/scripts.pory"
	walk_up
# 34 "data/maps/GrassyField/scripts.pory"
	walk_up
# 34 "data/maps/GrassyField/scripts.pory"
	walk_up
# 34 "data/maps/GrassyField/scripts.pory"
	walk_up
	step_end

# 37 "data/maps/GrassyField/scripts.pory"
faceLeaf:
# 38 "data/maps/GrassyField/scripts.pory"
	face_left
	step_end

# 40 "data/maps/GrassyField/scripts.pory"
LeafFacePlayerGrassy:
# 41 "data/maps/GrassyField/scripts.pory"
	face_right
	step_end

LeafTalk_Text_0:
# 11 "data/maps/GrassyField/scripts.pory"
	.string "LEAF:{PLAYER}! There are two of\n"
	.string "those thugs. One went towards the\l"
	.string "BURNING FIELDS up ahead and to the\l"
	.string "left, and the other went to the RAINY\l"
	.string "FIELDS, up ahead and to the right. You\l"
	.string "get one of them, and I'll get the other.$"
