.data

prompt1: .asciiz "ENTER VALUE\n"
prompt2: .asciiz "ENTER OP-CODE\n"
error1: .asciiz "Overflow detected\n"
error2: .asciiz "Op-Code not recognised"
	
.text

# Set op code to +
li $s2 '+'

# Print "ENTER VALUE"
printPrompt1:
la $a0 prompt1
addi $v0 $zero 4
syscall

# Read in an integer into $s1
readInt:
addi $v0 $zero 5
syscall
add $s1 $zero $v0

# Check which op code was input
if:
li $t0 '*'
beq $s2 $t0 multiply

li $t0 '-'
beq $s2 $t0 subtract

li $t0 '+'
beq $s2 $t0 sum

# Op Code not recognised
la $a0 error2
addi $v0 $zero 4
syscall

j printPrompt2

	multiply:
	mult $s0 $s1
	# If $s0 or $s1 are 0, result is 0
	beq $s0 $zero multiplyByZero
	beq $s1 $zero multiplyByZero
	# Else
	# Is $s0 negative
	slt $t0 $s0 $zero
	# Is $s1 negative
	slt $t1 $s1 $zero
	beq $t0 $t1 sameSign
	j differentSign
		multiplyByZero:
		add $s0 $zero $zero
		j printPrompt2
	
		sameSign:
		# If HI is negative, overflow
		mfhi $t0
		slt $t0 $t0 $zero
		bne $t0 $zero overflow
		# Else if LO is negative, overflow
		mflo $s0
		slt $t0 $s0 $zero
		bne $t0 $zero overflow
		j printPrompt2
		
		differentSign:
		# If HI is not -1, overflow
		mfhi $t0
		addi $t1 $zero -1
		bne $t0 $t1 overflow
		# Else if LO is positive, overflow
		mflo $s0
		slt $t0 $s0 $zero
		bne $t0 $zero printPrompt2
		j overflow
	
	subtract:
	# Flip sign of right side operand
	subu $s1 $zero $s1
	# Then continue to sum
	
	sum:
	slt $t0 $s0 $zero
	slt $t1 $s1 $zero
	addu $s0 $s0 $s1
	# If two operands are different signs, no overflow possible
	bne $t0 $t1 printPrompt2
	# Else check for overflow: If signs of operands != sign of result, overflow
	slt $t0 $s0 $zero
	bne $t0 $t1 overflow
	j printPrompt2

# Print "ENTER OP-CODE"
printPrompt2:
la $a0 prompt2
addi $v0 $zero 4
syscall

# Read op code into $s2
readOp:
addi $v0 $zero 12
syscall
add $s2 $zero $v0

# Print new line
li $a0 '\n'
addi $v0 $zero 11
syscall

# If op code isn't @ read in another number
li $t0 '@'
bne $s2 $t0 printPrompt1

# Print result
add $a0 $zero $s0
addi $v0 $zero 1
syscall

j exit

overflow:
la $a0 error1
addi $v0 $zero 4
syscall

exit:



