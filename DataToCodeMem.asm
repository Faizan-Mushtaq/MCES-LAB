ORG 0000H
	MOV R1,#5
	MOV R0,#50H
	MOV DPTR,#0100H

	L1:CLR A
	MOVC A,@A+DPTR
	MOV @R0,A
	INC DPTR
	INC R0
	DJNZ R1,L1

ORG 0100H
	BLOCK1: DB 10H,11H,12H,13H,14H
	END
