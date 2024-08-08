DewfordDojoArena_MapScripts::
	.byte 0


DojoFin::
	lock
	checktrainerflag TRAINER_DOJO_MASTER
	goto_if_eq VAR_RESULT, TRUE, DojoEnd
	goto_if_eq VAR_RESULT, FALSE, DojoFinal
	release
	return


DojoFinal::
	checktrainerflag TRAINER_DOJO1
	goto_if_eq VAR_RESULT, TRUE, DojoFinal1
	goto_if_eq VAR_RESULT, FALSE, DojoFinalNo
	release
	return


DojoFinal1::
	checktrainerflag TRAINER_DOJO2
	goto_if_eq VAR_RESULT, TRUE, DojoFinal2
	goto_if_eq VAR_RESULT, FALSE, DojoFinalNo
	release
	return


DojoFinal2::
	checktrainerflag TRAINER_DOJO3
	goto_if_eq VAR_RESULT, TRUE, DojoFinal3
	goto_if_eq VAR_RESULT, FALSE, DojoFinalNo
	release
	return


DojoFinal3::
	checktrainerflag TRAINER_DOJO4
	goto_if_eq VAR_RESULT, TRUE, DojoFinalFight
	goto_if_eq VAR_RESULT, FALSE, DojoFinalNo
	release
	return


DojoFinalNo::
	msgbox DojoFinalNo_Text_0, MSGBOX_DEFAULT
	waitmessage
	release
	return


DojoEnd::
	msgbox DojoEnd_Text_0, MSGBOX_DEFAULT
	waitmessage
	release
	return


DojoFinalFight::
	msgbox DojoFinalFight_Text_0, MSGBOX_DEFAULT
	waitmessage
	trainerbattle_single TRAINER_DOJO_MASTER, introDojo, outroDojo
	msgbox DojoFinalFight_Text_1, MSGBOX_DEFAULT
	waitmessage
	givemon SPECIES_KUBFU, 22
	msgbox DojoFinalFight_Text_2, MSGBOX_DEFAULT
	waitmessage
	msgbox DojoEnd_Text_0, MSGBOX_DEFAULT
	waitmessage
	release
	return


dojo1::
	lock
	msgbox dojo1_Text_0, MSGBOX_DEFAULT
	waitmessage
	trainerbattle_single TRAINER_DOJO1, introDojo, outroDojo
	release
	return


dojo2::
	lock
	msgbox dojo1_Text_0, MSGBOX_DEFAULT
	waitmessage
	trainerbattle_single TRAINER_DOJO2, introDojo, outroDojo
	release
	return


dojo3::
	lock
	msgbox dojo1_Text_0, MSGBOX_DEFAULT
	waitmessage
	trainerbattle_single TRAINER_DOJO3, introDojo, outroDojo
	release
	return


dojo4::
	lock
	msgbox dojo1_Text_0, MSGBOX_DEFAULT
	waitmessage
	trainerbattle_single TRAINER_DOJO4, introDojo, outroDojo
	release
	return


DojoFinalNo_Text_0:
	.string "DOJO MASTER:If you wish to challenge\n"
	.string "me, you must beat all my students first.$"

DojoEnd_Text_0:
	.string "DOJO MASTER:There is a fellow sensei\n"
	.string "just EAST of MAUVILLE CITY. If you\l"
	.string "beat him he can help you evolve KUBFU.$"

DojoFinalFight_Text_0:
	.string "DOJO MASTER:Time for your final test.$"

DojoFinalFight_Text_1:
	.string "DOJO MASTER:Impresive! You are a\n"
	.string "proper sensei now. You'll need a\l"
	.string "student.$"

DojoFinalFight_Text_2:
	.string "You recieved KUBFU!$"

dojo1_Text_0:
	.string "DOJO FIGHTER:Ready when you are.$"

introDojo::
	.string "Show me what you got!$"

outroDojo::
	.string "Well done!$"
