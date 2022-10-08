#2. Take one number from the user and compute the sum of squares of consecutive integers starting from that number until the total exceeds 200. Print the list of numbers.

.data
	prompt: .asciiz "Enter the number: "
	nl: .asciiz "\n"
	out: .asciiz "The list of numbers is: \n"

.text
main:
	li $v0 4
	la $a0 prompt
	syscall
	
	#taking input
	li $v0 5
	syscall
	move $s0, $v0
	
	addi $s1, $zero, 0
	addi $t0, $zero, 0
	
	li $v0 4
	la $a0 out
	syscall
	
while:	mul $t0, $s0, $s0
	add $s0, $s0, 1
	add $s1, $s1, $t0
	
	bgt $s1, 200, exit
	
	li $v0 1
	move $a0, $t0
	#move $a0, $s1
	syscall
	
	li $v0 4
	la $a0 nl
	syscall
	
	j while
	
exit:	li $v0 10
	syscall
	
	
	
	