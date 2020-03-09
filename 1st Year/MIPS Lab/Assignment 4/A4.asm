.data
	PROMPT_1:	.asciiz "Enter an expression:\n"

.text

main:
	# Prompt for input
	la $a0 PROMPT_1
	addi $v0 $zero 4
	syscall
	
	# Get first number into $a0
	addi $v0 $zero 5
	syscall
	addi $a0 $v0 0
	
	# Get op character into $s0
	addi $v0 $zero 12
	syscall
	addi $s0 $v0 0
	
	# Get second number into $a1
	addi $v0 $zero 5
	syscall
	addi $a1 $v0 0
	
	# If/Else block to call appropriate function
	addi $t0 $zero '+'
	bne $s0 $t0 ELSE_1A
		jal ADD
		j ENDIF_1
	ELSE_1A:
	addi $t0 $zero '*'
	bne $s0 $t0 ELSE_1B
		jal MUL
		j ENDIF_1
	ELSE_1B:
	addi $t0 $zero '^'
	bne $s0 $t0 ENDIF_1
		jal POW
	ENDIF_1:
	
	# Print result
	addi $a0 $v0 0
	addi $v0 $zero 1
	syscall
	
	# Print new line
	addi $a0 $zero '\n'
	addi $v0 $zero 11
	syscall
	
	# Start Over
	j main


# Function adds $a0 and $a1
# Stores result in $v0	
ADD:
	add $v0 $a0 $a1
	jr $ra


# Function multiplies $a0 and $a1
# Stores result in $v0	
MUL:
	# Save registers
	addi $sp $sp -36
	sw $ra 0($sp)
	sw $s0 4($sp)
	sw $s1 8($sp)
	sw $s2 12($sp)
	sw $s3 16($sp)
	sw $s4 20($sp)
	sw $t0 24($sp)
	sw $a0 28($sp)
	sw $a1 32($sp)
	
	# Copy args to s registers
	addi $s3 $a0 0
	addi $s4 $a1 0
	
	# Calculate sign of result
	srl $t0 $s3 31		# $t0 = n1<0
	srl $t1 $s4 31		# $t1 = n2<0
	xor $s2 $t0 $t1		# $s2 is 1 if product is negative
	
	# Make arguments positive
	beq $t0 $zero ENDIF_2		# if(n1 < 0)
		sub $s3 $zero $s3	# n1 = -n1
	ENDIF_2:
	beq $t1 $zero ENDIF_3		# if(n2 < 0)
		sub $s4 $zero $s4	# n2 = -n2
	ENDIF_3:
	
	addi $s0 $zero 0	# sum=0
	addi $s1 $zero 0	# i=0
	LOOP_1:
	slt $t0 $s1 $s3		# while i < n1
	beq $t0 $zero LOOPEND_1
		addi $a0 $s0 0
		addi $a1 $s4 0
		jal ADD		# sum + n2
		addi $s0 $v0 0	# sum = sum+n2
		addi $s1 $s1 1	# i++
		j LOOP_1
	LOOPEND_1:
	
	addi $v0 $s0 0		# return sum
	
	# If product must be negative, make it so
	beq $s2 $zero ENDIF_4
		sub $v0 $zero $v0	# sum = -sum
	ENDIF_4:
	
	# Restore registers
	lw $ra 0($sp)
	lw $s0 4($sp)
	lw $s1 8($sp)
	lw $s2 12($sp)
	lw $s3 16($sp)
	lw $s4 20($sp)
	lw $t0 24($sp)
	lw $a0 28($sp)
	lw $a1 32($sp)
	addi $sp $sp 36
	
	jr $ra


# Function calculates $a0 to the power of $a1
# Stores result in $v0	
POW:
	# Save registers
	addi $sp $sp -20
	sw $ra 0($sp)
	sw $a1 4($sp)
	sw $s0 8($sp)
	sw $s1 12($sp)
	sw $t0 16($sp)
	
	addi $s0 $zero 1	# product=1
	addi $s1 $zero 0	# i=0
	LOOP_2:
	slt $t0 $s1 $a1		# while i < exponent
	beq $t0 $zero LOOPEND_2
		addi $a1 $s0 0
		jal MUL		# product * base
		addi $s0 $v0 0	# product = product*base
		lw $a1 4($sp)	# restore $a0 register
		addi $s1 $s1 1	# i++
		j LOOP_2
	LOOPEND_2:
	
	addi $v0 $s0 0		# return product
	
	# Restore registers
	lw $ra 0($sp)
	lw $a0 4($sp)
	lw $s0 8($sp)
	lw $s1 12($sp)
	lw $t0 16($sp)
	addi $sp $sp 20
	
	jr $ra
