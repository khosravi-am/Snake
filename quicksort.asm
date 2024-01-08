.global _start
.word 4
.word 3
.word 2
.word 1

//.word 3
//.word 5
//.word 2
//.word 8
//.word 6

.balign 4
_start:
mov r7, #4
mov r1, #0
mov r2, #3
push {r0,r1,r2,lr}
bl quicksort
pop {r0,r1,r2,lr}


here1: b here1


	
	
partition:


//r1 //low
//r2// high
//r0 //address array
	mul r9, r2, r7   //2
	ldr r5 ,[r0,r9] //pivot   2
	sub r6 , r1,#1 // i	



	for:
		mul r8, r1, r7	//2
		ldr r4 ,[r0,r8] //arr[low]		2
		cmp r5, r4
		Bhi l1
		B l3
		l1:
			
			add r6, r6,#1	//i
			push {r0,r1,r2,lr}
			mul r8, r1, r7
			ldr r2, [r0,r8]
			mul r8, r6, r7
			ldr r1, [r0,r8]
			Bl swap
			pop {r0}
			mul r8, r6, r7
			str r1, [r0,r8]
			pop {r1}
			mul r8, r1, r7
			str r2, [r0,r8]
			pop {r2,lr}
			
		l3:
			add r1, r1, #1
			cmp r1, r2
			Bhi l2
			B for
		

	l2:

		add r6, r6, #1	//?
		push {r0,r1,r2,lr}
		mul r8, r6, r7
		ldr r1, [r0,r8]
		mul r8, r2, r7
		ldr r2, [r0,r8]
		Bl swap
		pop {r0}
		mul r8, r6, r7
		str r1, [r0,r8]
		mov r3, r2
		pop {r1,r2}
		mul r8, r2, r7
		str r3, [r0,r8]
		pop {lr}
		mov r0, r6  //return 
		
	bx lr
	



swap:

	mov r0, r1
	mov r1, r2
	mov r2, r0
	
	
	bx lr
	
	
	
quicksort:
// r0 -> array address
// r1 -> low
// r2 -> high

	cmp r1, r2
	Bge here
	push {r0,r1,r2,lr}
	Bl partition
	mov r3,r0 //pi
	pop {r0,r1,r2,lr}
	push {r0,r1,r2,r3,lr}
	sub r2, r3, #1
	Bl quicksort
	pop {r0,r1,r2,r3,lr}
	push {r0,r1,r2,r3,lr}
	add r1, r3, #1
	Bl quicksort
	pop {r0,r1,r2,r3,lr}
	
here:	
	bx lr
	
	


