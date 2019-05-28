.data
	array: 	.byte 1 2 4 8
	size: 	.word 4
	
	str_arithmetic:	.asciiz "Arithmetic progression:\n"
	str_geometric:	.asciiz "Geometric progression:\n"
	
	str_a:	.asciiz "a = "
	str_d:	.asciiz "d = "
	str_r:	.asciiz "r = "
	
.text

main:
	la $s0 array
	lw $s1 size
	
	# Call function arithmetic
	add $a0 $zero $s0
	add $a1 $zero $s1
	addi $sp $sp -4
	sw $ra ($sp)
	jal arithmetic
	lw $ra ($sp)
	addi $sp $sp 4
	
	# If arithmetic, print
	beq $v0 $zero endif1
		# Say it is arithmetic
		la $a0 str_arithmetic
		addi $v0 $zero 4
		syscall
		
		# Print the first term
		la $a0 str_a
		addi $v0 $zero 4
		syscall
		lb $a0 ($s0)
		addi $v0 $zero 1
		syscall
		addi $a0 $zero '\n'
		addi $v0 $zero 11
		syscall
		
		# Print common difference
		la $a0 str_d
		addi $v0 $zero 4
		syscall
		add $a0 $zero $v1
		addi $v0 $zero 1
		syscall
		addi $a0 $zero '\n'
		addi $v0 $zero 11
		syscall
	endif1:
	
	# Call function geometric
	add $a0 $zero $s0
	add $a1 $zero $s1
	addi $sp $sp -4
	sw $ra ($sp)
	jal geometric
	lw $ra ($sp)
	addi $sp $sp 4
	
	# Copy common ratio into $s registers
	add $s2 $zero $v0
	add $s3 $zero $v1
	
	# If geometric, print
	beq $v1 $zero endif2
		# Say it is geometric
		la $a0 str_geometric
		addi $v0 $zero 4
		syscall
		
		# Print the first term
		la $a0 str_a
		addi $v0 $zero 4
		syscall
		lb $a0 ($s0)
		addi $v0 $zero 1
		syscall
		addi $a0 $zero '\n'
		addi $v0 $zero 11
		syscall
		
		# Print common ratio
		la $a0 str_r
		addi $v0 $zero 4
		syscall
		add $a0 $zero $s2
		addi $v0 $zero 1
		syscall
		# if denominator = 1, dont print it
		addi $t0 $zero 1
		beq $s3 $t0 endif4
			addi $a0 $zero '/'
			addi $v0 $zero 11
			syscall
			add $a0 $zero $s3
			addi $v0 $zero 1
			syscall
		endif4:
		addi $a0 $zero '\n'
		addi $v0 $zero 11
		syscall
	endif2:
	
	j exit
	
# Parameters:
# $a0 = array
# $a1 = size
# Return values:
# $v0 = bool: is arithmetic?
# $v1 = common difference
arithmetic:
	# Save $s registers
	addi $sp $sp -20
	sw $s0 0($sp)
	sw $s1 4($sp)
	sw $s2 8($sp)
	sw $s3 12($sp)
	sw $s4 16($sp)
	
	# Save arguments to s registers
	add $s0 $zero $a0
	add $s1 $zero $a1
	
	lb $t0 ($s0)	# $t0 = array[0]
	addi $s0 $s0 1
	lb $t1 ($s0)	# $t1 = array[1]
	sub $s4 $t1 $t0	# $s4 = array[1] - array[0]
	
	addi $s2 $zero 2	# i = 2
	addi $s3 $zero 1	# arithmetic = true
	
	# while (i < size)
	loop1:
	slt $t0 $s2 $s1
	beq $t0 $zero break1
		lb $t0 ($s0)	# $t0 = array[i-1]
		addi $s0 $s0 1
		lb $t1 ($s0)	# $t1 = array[i]
		
		sub $t0 $t1 $t0		# $t0 = array[i] - array[i-1]
		bne $t0 $s4 notArithmetic	# if ($t0 != $s4) break
		
		addi $s2 $s2 1	# i++
		j loop1
		
		notArithmetic:
		addi $s3 $zero 0	# arithmetic = false
	break1:
	
	add $v0 $zero $s3
	add $v1 $zero $s4
	
	# Load $s registers
	lw $s0 0($sp)
	lw $s1 4($sp)
	lw $s2 8($sp)
	lw $s3 12($sp)
	lw $s4 16($sp)
	addi $sp $sp 20
	
	jr $ra
	
# Parameters:
# $a0 = array
# $a1 = size
# Return values:
# $v0 = common ratio numerator
# $v1 = common ratio denominator (0 if not progression)
geometric:
	# Save $s registers
	addi $sp $sp -28
	sw $s0 0($sp)
	sw $s1 4($sp)
	sw $s2 8($sp)
	sw $s3 12($sp)
	sw $s4 16($sp)
	sw $s5 20($sp)
	sw $s6 24($sp)
	
	# Save arguments to s registers
	add $s0 $zero $a0
	add $s1 $zero $a1
	
	addi $s2 $zero 2	# i = 2
	addi $s3 $zero 1	# geometric = true
	
	# while (i < size)
	loop2:
	slt $t0 $s2 $s1
	beq $t0 $zero break2
		lb $t0 0($s0)	# $t0 = array[i-2]
		lb $t1 1($s0)	# $t1 = array[i-1]
		lb $t2 2($s0)	# $t1 = array[i]
		addi $s0 $s0 1
		
		# Cross Multiply
		mult $t0 $t2
		mflo $t0
		mult $t1 $t1
		mflo $t1
		bne $t0 $t1 notGeometric	# if (ratio(array[i-2], array[i-1]) != ratio(array[i-1], array[i])) break
		
		addi $s2 $s2 1	# i++
		j loop2
		
		notGeometric:
		addi $s3 $zero 0	# geometric = false
	break2:
	
	# if(geometric)
	beq $s3 $zero else3
		lb $s1 0($s0)	# $s1 = array[size-2]
		lb $s2 1($s0)	# $s2 = array[size-1]
		
		# Call function hcf
		add $a0 $zero $s1
		add $a1 $zero $s2
		addi $sp $sp -4
		sw $ra ($sp)
		jal hcf
		lw $ra ($sp)
		addi $sp $sp 4
		
		add $s3 $zero $v0
		div $s2 $s3	# array[size-1] / hcf
		mflo $v0	# Put numerator in $v0
		div $s1 $s3	# array[size-2] / hcf
		mflo $v1	# Put denominator in $v1
		
	j endif3
	else3:
		addi $v1 $zero 0
	endif3:
	
	# Load $s registers
	lw $s0 0($sp)
	lw $s1 4($sp)
	lw $s2 8($sp)
	lw $s3 12($sp)
	lw $s4 16($sp)
	lw $s5 20($sp)
	lw $s6 24($sp)
	addi $sp $sp 28
	
	jr $ra
	

# Parameters:
# $a0, $a1 = numbers to find HCF of
# Return values:
# $v0 = HCF
hcf:
	# Save $s registers
	addi $sp $sp -4
	sw $s0 0($sp)
	
	loop3:   
	beq  $a1 $zero break3 # branch loop
		add $t4 $zero $a1	# c = b
		div $a0 $a1
		mfhi $a1	# b = a % b
		add $a0 $zero $t4	# a = c
		j loop3
	break3: 

	add $v0 $zero $a0    # Move a to $v0

	# Load $s registers
	lw $s0 0($sp)
	add $sp $sp 4
	
	jr $ra

exit: