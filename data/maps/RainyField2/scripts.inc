# 1 "data/maps/RainyField2/scripts.pory"

# 2 "data/maps/RainyField2/scripts.pory"
.set LOCALID_Leaf, 1
# 3 "data/maps/RainyField2/scripts.pory"

# 4 "data/maps/RainyField2/scripts.pory"
RainyField2_MapScripts::
# 5 "data/maps/RainyField2/scripts.pory"
	.byte 0

LeafRainy::
# 9 "data/maps/RainyField2/scripts.pory"
	lock
# 10 "data/maps/RainyField2/scripts.pory"
	faceplayer
# 11 "data/maps/RainyField2/scripts.pory"
	msgbox LeafRainy_Text_0, MSGBOX_DEFAULT
# 12 "data/maps/RainyField2/scripts.pory"
	waitmessage
# 13 "data/maps/RainyField2/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 14 "data/maps/RainyField2/scripts.pory"
	message eggstart
# 15 "data/maps/RainyField2/scripts.pory"
	waitfanfare
# 16 "data/maps/RainyField2/scripts.pory"
	giveegg SPECIES_ZORUA
# 17 "data/maps/RainyField2/scripts.pory"
	msgbox LeafRainy_Text_1, MSGBOX_DEFAULT
# 18 "data/maps/RainyField2/scripts.pory"
	waitmessage
# 19 "data/maps/RainyField2/scripts.pory"
	msgbox LeafRainy_Text_2, MSGBOX_DEFAULT
# 20 "data/maps/RainyField2/scripts.pory"
	waitmessage
# 21 "data/maps/RainyField2/scripts.pory"
	msgbox LeafRainy_Text_3, MSGBOX_DEFAULT
# 22 "data/maps/RainyField2/scripts.pory"
	waitmessage
# 23 "data/maps/RainyField2/scripts.pory"
	msgbox LeafRainy_Text_4, MSGBOX_DEFAULT
# 24 "data/maps/RainyField2/scripts.pory"
	waitmessage
# 25 "data/maps/RainyField2/scripts.pory"
	msgbox LeafRainy_Text_5, MSGBOX_DEFAULT
# 26 "data/maps/RainyField2/scripts.pory"
	waitmessage
# 27 "data/maps/RainyField2/scripts.pory"
	msgbox LeafRainy_Text_6, MSGBOX_DEFAULT
# 28 "data/maps/RainyField2/scripts.pory"
	waitmessage
# 29 "data/maps/RainyField2/scripts.pory"
	giveitem ITEM_POKE_BALL, 15
# 30 "data/maps/RainyField2/scripts.pory"
	msgbox LeafRainy_Text_7, MSGBOX_DEFAULT
# 31 "data/maps/RainyField2/scripts.pory"
	waitmessage
# 32 "data/maps/RainyField2/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MoveAsideStart
# 33 "data/maps/RainyField2/scripts.pory"
	applymovement LOCALID_Leaf, LeafExitStart
# 34 "data/maps/RainyField2/scripts.pory"
	waitmovement 0
# 35 "data/maps/RainyField2/scripts.pory"
	setflag FLAG_UNUSED_0x495
# 36 "data/maps/RainyField2/scripts.pory"
	removeobject LOCALID_Leaf
# 37 "data/maps/RainyField2/scripts.pory"
	release
	return


# 44 "data/maps/RainyField2/scripts.pory"
MoveAsideStart:
# 45 "data/maps/RainyField2/scripts.pory"
	walk_left
# 46 "data/maps/RainyField2/scripts.pory"
	face_right
	step_end

# 49 "data/maps/RainyField2/scripts.pory"
LeafExitStart:
# 50 "data/maps/RainyField2/scripts.pory"
	walk_down
# 50 "data/maps/RainyField2/scripts.pory"
	walk_down
# 50 "data/maps/RainyField2/scripts.pory"
	walk_down
# 50 "data/maps/RainyField2/scripts.pory"
	walk_down
# 50 "data/maps/RainyField2/scripts.pory"
	walk_down
# 50 "data/maps/RainyField2/scripts.pory"
	walk_down
# 50 "data/maps/RainyField2/scripts.pory"
	walk_down
	step_end

LeafRainy_Text_0:
# 11 "data/maps/RainyField2/scripts.pory"
	.string "LEAF:Oh! Hey, {PLAYER}. Looks like\n"
	.string "we've both driven TEAM ROCKET away. The\l"
	.string "guy I beat dropped this.$"

LeafRainy_Text_1:
# 17 "data/maps/RainyField2/scripts.pory"
	.string "LEAF:I want you to have it. I'm sure\n"
	.string "you'll look after it.$"

LeafRainy_Text_2:
# 19 "data/maps/RainyField2/scripts.pory"
	.string "LEAF:Like I said before, I'm here on\n"
	.string "PROF OAK's request.$"

LeafRainy_Text_3:
# 21 "data/maps/RainyField2/scripts.pory"
	.string "LEAF:OH! You're helping PROF BIRCH?\n"
	.string "That's perfect. We can work together.$"

LeafRainy_Text_4:
# 23 "data/maps/RainyField2/scripts.pory"
	.string "LEAF:PROF OAK wanted to find out why\n"
	.string "so many POKéMON from so many regions\l"
	.string "gathered here. It's also a once in a\l"
	.string "lifetime opportunity to study so many\l"
	.string "species in one region.$"

LeafRainy_Text_5:
# 25 "data/maps/RainyField2/scripts.pory"
	.string "LEAF:I'll tell you what. I'll be at\n"
	.string "SLATEPORT RESORT in SLATEPORT CITY.\l"
	.string "Come find me there, and I'll give you\l"
	.string "rewards depending on how many POKéMON\l"
	.string "you've seen and caught. How does that\l"
	.string "sound?$"

LeafRainy_Text_6:
# 27 "data/maps/RainyField2/scripts.pory"
	.string "LEAF:Here. Start with these. I'm sure\n"
	.string "you know how to use them.$"

LeafRainy_Text_7:
# 30 "data/maps/RainyField2/scripts.pory"
	.string "LEAF:And don't worry about TEAM\n"
	.string "ROCKET. I have a friend of mine on the\l"
	.string "case. OK! See you at SLATEPORT RESORT.$"

eggstart::
# 40 "data/maps/RainyField2/scripts.pory"
	.string "{PLAYER} received the EGG$"
