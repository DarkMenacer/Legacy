#1. Take a string as an input from the user.
#Create a MIPS function called VOWCONS. This function receives as a parameter the init address of the input string. 
#The function calculates the number of vowels and consonants in the string and returns two values – the number of vowels and the number of consonants
#When the null string is passed, the function returns -1.
#Write the MIPS code for the program. Display as output the string taken as an input from the user and the number of vowels and consonants in it.

.data 
	prompt: .asciiz "Enter the string: "
	input: .space 25
	a: .byte 'a'
	e: .byte 'e'
	i: .byte 'i'
	o: .byte 'o'
	u: .byte 'u'
	null: .byte '\0'
	out1: .asciiz "Vowels: "
	out2: .asciiz "Consonants: "
	nl: .asciiz "\n"
.text
main:	
	li $v0 4
	la $a0 prompt
	syscall
	
	li $v0 8
	la $a0 input
	li $a1 25
	syscall
	
	la $a1 input
	jal VOWCONS
	
	beq $v1,-1,empty
	
	li $v0 4
	la $a0 out1
	syscall
	
	li $v0 1
	move $a0, $v1
	syscall
	
	li $v0 4
	la $a0 nl
	syscall
	
	li $v0 4
	la $a0 out2
	syscall
	
	li $v0 1
	move $a0, $s1
	syscall
	
	j skip_empty
	
	
empty:	li $v0 1
	move $a0, $v1
	syscall

skip_empty:
	li $v0 10
	syscall
	
VOWCONS:
	move $t2,$a1
	lb $s0, null
	lb $t3, a
	lb $t4, e
	lb $t5, i
	lb $t6, o
	lb $t7, u
	add $v1,$zero,1
	add $s1,$zero,-1
	
	lb $t1, 0($t2)
	bne $t1, $s0, while
	li $v1, -1
	jr $ra 
	
while:	lb $t1, 0($t2)
	
	beq $t1, $s0, exit
	
	beq $t1, $t3, here
	beq $t1, $t4, here
	beq $t1, $t5, here
	beq $t1, $t6, here
	beq $t1, $t7, here
	add $s1, $s1, 1
	j skip_here
here:	add $v1, $v1 ,1	

skip_here:
	add $t2,$t2,1
	j while
exit:	
	bnez $v1, notzero
	bnez $s1, notzero
	li $v1, -1
	
notzero:
	sub $v1, $v1, 1
	jr $ra
