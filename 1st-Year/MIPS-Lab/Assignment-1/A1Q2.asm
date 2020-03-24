.data
prompt: .asciiz "Enter a number between -99 and 99:\n"
error: .asciiz "Number must be between -99 and 99!\n"
result: .asciiz "Sum of numbers is "

.text

loop:
# Prompt for user input
la $a0 prompt
addi $v0 $zero 4
syscall

# Read user input
addi $v0 $zero 5
syscall

# If input is 0, exit loop
beq $v0 $zero exit

# Check if input is between -99 and 99
slti $t0 $v0 -99
slti $t1 $v0 100
xor $t0 $t0 $t1
# If within range, continue
bne $t0 $zero continue
	# If out of range, print error and input number again
	la $a0 error
	addi $v0 $zero 4
	syscall
	j loop

continue:
# Add input to sum
add $s0 $s0 $v0
j loop

exit:
# Print sum of all inputs
la $a0 result
addi $v0 $zero 4
syscall

move $a0 $s0
addi $v0 $zero 1
syscall