.data
str1: .asciiz "Please enter a number:\n"

.globl main
.text
main:

# Request some user input:
li $v0, 4
la $a0, str1
syscall #Ask for input
# Read some user input:
li $v0, 5 #get user integer
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

#put number of iterations in $a0, inputs that are <= 0 will output 1
fibinaci:

#setup before loop
addiu $t0, $zero, 1 #first number in fibinaci
addiu $t1, $zero, 1 #second number in fibinaci
j condition

loop:
addiu $t5, $t0, 0 # save temp value
addiu $t0, $t1, 0 #put t1 value into t0
addu $t1, $t5, $t1 #calculate next value in fibinaci sequence

increment:
addiu $a0, $a0, -1

condition:
sgt $t2, $a0, 2
#not nessary instruction included for clarity
addiu $v0, $t1, 0
bne $t2, $zero, loop

jr $ra

