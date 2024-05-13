.data
str1: .asciiz "Please enter a number:\n"

.globl main
.text
main:

#print out string
li $v0, 4
la $a0, str1
syscall

#get user input
li $v0, 5
syscall
addiu $a0, $v0, 0

jal fibinaci

addiu $s0, $v0, 0 # for getting the return value

# Print output
li $v0, 1 
addiu $a0, $s0, 0
syscall # print s1
# Exit program
li $v0, 10
syscall 

fibinaci:
slti $t0, $a0, 2 	# if(n <= 1)
beq $t0, $zero, else	# if(n > 2)
add $v0, $zero, $a0 
jr $ra

else:
addi $sp, $sp, -16
sw $a0, 0($sp)		#save $a0
sw $ra, 8($sp)		#save $ra

addi $a0, $a0, -1	# n-1
jal fibinaci		#return
 
sw $v0, 4($sp)		#save $v0
lw $a0, 0($sp)		#load in
addi $a0, $a0, -2	#n -2 
jal fibinaci 		#return 

lw $t1, 4($sp)		#Get Fn-1
add $v0, $v0, $t1 	#$v0 = fib(n-1) + fib(n-2)
lw $ra, 8($sp)		#get return address

addi $sp, $sp, 16	#give back space
jr $ra 			#return
