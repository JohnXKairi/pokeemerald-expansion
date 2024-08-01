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
	msgbox LeafTalk_Text_0
# 11 "data/maps/GrassyField/scripts.pory"
	waitmessage
# 12 "data/maps/GrassyField/scripts.pory"
	waitbuttonpress
# 13 "data/maps/GrassyField/scripts.pory"
	setvar VAR_UNUSED_0x4101, 1
# 14 "data/maps/GrassyField/scripts.pory"
	release
	return


LeafTalk1::
# 18 "data/maps/GrassyField/scripts.pory"
	lock
# 19 "data/maps/GrassyField/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, faceLeaf
# 20 "data/maps/GrassyField/scripts.pory"
	msgbox LeafTalk_Text_0
# 21 "data/maps/GrassyField/scripts.pory"
	waitmessage
# 22 "data/maps/GrassyField/scripts.pory"
	waitbuttonpress
# 23 "data/maps/GrassyField/scripts.pory"
	setvar VAR_UNUSED_0x4101, 1
# 24 "data/maps/GrassyField/scripts.pory"
	release
	return


# 26 "data/maps/GrassyField/scripts.pory"
faceLeaf:
# 27 "data/maps/GrassyField/scripts.pory"
	face_left
	step_end

LeafTalk_Text_0:
# 10 "data/maps/GrassyField/scripts.pory"
	.string "LEAF:{PLAYER}! There's two of those\n"
	.string "thugs. One went towards the BURNING\l"
	.string "FIELDS up ahead and to the left and the\l"
	.string "other went to the RAINY FIELDS, up\l"
	.string "ahead and to the right. You get one of\l"
	.string "them and I'll get the other.$"
