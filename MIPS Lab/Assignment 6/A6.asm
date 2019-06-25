.data
	prompt1:	.asciiz	"Enter number of rows for first matrix:\n> "
	prompt2:	.asciiz	"Enter number of columns for first matrix:\n> "
	prompt3:	.asciiz	"Enter number of rows for second matrix:\n> "
	prompt4:	.asciiz	"Enter number of columns for second matrix:\n> "
	error1:		.asciiz	"Error: Matrix 1 must have the same number of columns as matrix 2 has rows.\n"
	
	prompt5:	.asciiz	"Enter the values for the first matrix:\n"
	prompt6:	.asciiz	"Enter the values for the second matrix:\n"
	
	msg1:		.asciiz "Matrix 1:\n"
	msg2:		.asciiz "Matrix 2:\n"
	msg3:		.asciiz "Product matrix:\n"
	
.text

MAIN:

	# Size of matrix 1: s0*s1
	# Size of matrix 2: s1*s2
	
	# Input sizes of matrix
	LOOP_1:
		la $a0 prompt1
		li $v0 4
		syscall
	
		li $v0 5
		syscall
		addi $s0 $v0 0

		la $a0 prompt2
		li $v0 4
		syscall
	
		li $v0 5
		syscall
		addi $s1 $v0 0

		la $a0 prompt3
		li $v0 4
		syscall
	
		li $v0 5
		syscall
		
		# if sizes are multiplyable, don't ask for input again
		beq $s1 $v0 ENDIF_1
		
		la $a0 error1
		li $v0 4
		syscall
		
		j LOOP_1
		ENDIF_1:
	
		la $a0 prompt4
		li $v0 4
		syscall
	
		li $v0 5
		syscall
		addi $s2 $v0 0
	LOOP_1_EXIT:
	
	
	
	# s3 = size1 = nRows1*nCols1
	multu $s0 $s1
	mflo $s3
	
	li $t0 4
	multu $s3 $t0
	mflo $t0
	sub $sp $sp $t0		# Allocate size1*4 bytes
	addi $s4 $sp 0		# s4 = pointer to matrix1
	
	# Prompt for values of matrix1
	la $a0 prompt5
	li $v0 4
	syscall
	
	addi $a0 $s4 0
	addi $a1 $s3 0
	jal INPUT_ARRAY
	
	
	
	# s5 = size2 = nRows2*nCols2
	multu $s1 $s2
	mflo $s5
	
	li $t0 4
	multu $s5 $t0
	mflo $t0
	sub $sp $sp $t0		# Allocate size2*4 bytes
	addi $s6 $sp 0		# s6 = pointer to matrix2
	
	# Prompt for values of matrix2
	la $a0 prompt6
	li $v0 4
	syscall
	
	addi $a0 $s6 0
	addi $a1 $s5 0
	jal INPUT_ARRAY
	
	# Print Matrix1
	la $a0 msg1
	li $v0 4
	syscall
	
	addi $a0 $s4 0
	addi $a1 $s0 0
	addi $a2 $s1 0
	jal PRINT_MATRIX
	
	# Print Matrix2
	la $a0 msg2
	li $v0 4
	syscall
	
	addi $a0 $s6 0
	addi $a1 $s1 0
	addi $a2 $s2 0
	jal PRINT_MATRIX
	
	# Print result
	la $a0 msg3
	li $v0 4
	syscall
	
	# for(i=0; i < nRows1; i++)
	li $t0 0
	LOOP_4:
	slt $t1 $t0 $s0
	beq $t1 $zero LOOP_4_END
	
		# for (j=0; j < nCols2; j++)
		li $t1 0
		LOOP_5:
		slt $t2 $t1 $s2
		beq $t2 $zero LOOP_5_END
		
			# sum = 0
			li $t3 0
			
			# for (k=0; k < nCols1; k++)
			li $t2 0
			LOOP_6:
			slt $t4 $t2 $s1
			beq $t4 $zero LOOP_6_END
			
				# sum += matrix1[i][k] * matrix2[j][k]
				lw $t4 ($s4)
				lw $t5 ($s6)
				mult $t4 $t5
				mflo $t4
				add $t3 $t3 $t4
				
				addi $s4 $s4 4		# s4++
				
				# move s6 pointer 1 row down
				# s6 += 4*nCols2
				add $t4 $s2 $s2
				add $t4 $t4 $t4
				add $s6 $s6 $t4
				
				addi $t2 $t2 1		# k++
				j LOOP_6
				
			LOOP_6_END:
			
			# Print sum
			addi $a0 $t3 0
			li $v0 1
			syscall
			
			# Print space
			li $a0 ' '
			li $v0 11
			syscall
			
			# move s4 1 column up
			# s4 -= 4*nCols1
			add $t3 $s1 $s1
			add $t3 $t3 $t3
			sub $s4 $s4 $t3
			
			# move s6 pointer nRows2 rows up and 1 column across
			# s6 -= nRows2*(4*nCols2) - 4
			add $t3 $s2 $s2
			add $t3 $t3 $t3
			mult $t3 $s1
			mflo $t3
			addi $t3 $t3 -4
			sub $s6 $s6 $t3
				
			addi $t1 $t1 1	# j++
			j LOOP_5
		LOOP_5_END:
			
		# Print a newline
		li $a0 '\n'
		li $v0 11
		syscall
		
		# Move s4 1 column down
		# s4 += 4*nCols1
		add $t1 $s1 $s1
		add $t1 $t1 $t1
		add $s4 $s4 $t1
					
		# move s6 1 column up
		# s6 -= 4*nCols2
		add $t1 $s2 $s2
		add $t1 $t1 $t1
		sub $s6 $s6 $t1
		
		addi $t0 $t0 1	# i++
		j LOOP_4
	LOOP_4_END:
	
	
	
	# Dealocate matrix2 from stack
	mult $s1 $s2
	mflo $t0
	add $t0 $t0 $t0
	add $t0 $t0 $t0
	add $sp $sp $t0
	
	# Dealocate matrix1 from stack
	mult $s0 $s1
	mflo $t0
	add $t0 $t0 $t0
	add $t0 $t0 $t0
	add $sp $sp $t0
	
	
	j EXIT
	
	
	
INPUT_ARRAY:

	# a0 is pointer to array
	# a1 is size of array
	
	addi $sp $sp -12
	sw $s0 0($sp)
	sw $s1 4($sp)
	sw $s2 8($sp)
	
	addi $s0 $a0 0
	addi $s1 $a1 0

	# for(i=0; i < size; i++)
	li $s2 0	# i=0
	LOOP_2:
	slt $t0 $s2 $s1
	beq $t0 $zero LOOP_2_END
			
		# Read in a number to the array
		li $v0 5
		syscall
		sw $v0 ($s0)
		
		addi $s0 $s0 4		# ptr++
		addi $s2 $s2 1		# i++
		j LOOP_2
	LOOP_2_END:
	
	lw $s0 0($sp)
	lw $s1 4($sp)
	lw $s2 8($sp)
	addi $sp $sp 12
	
jr $ra
	
	
	
PRINT_MATRIX:

	# a0 is pointer to matrix
	# a1 is number of rows
	# a2 is number of columns
	
	addi $sp $sp -20
	sw $s0 0($sp)
	sw $s1 4($sp)
	sw $s2 8($sp)
	sw $s3 12($sp)
	sw $s4 16($sp)
	
	addi $s0 $a0 0
	addi $s1 $a1 0
	addi $s2 $a2 0
	
	# for(i=0; i < nRows; i++)
	li $s3 0	# i=0
	LOOP_3:
	slt $t0 $s3 $s1
	beq $t0 $zero LOOP_3_END
	
		li $s4 0	# j=0
		LOOP_7:
		slt $t0 $s4 $s2
		beq $t0 $zero LOOP_7_END
		
			# Print a number of the matrix
			lw $a0 ($s0)
			li $v0 1
			syscall
			
			# Print a space
			li $a0 ' '
			li $v0 11
			syscall
			
			addi $s0 $s0 4		# ptr1++
			addi $s4 $s4 1		# j++
			j LOOP_7
		LOOP_7_END:
			
		# Print a newline
		li $a0 '\n'
		li $v0 11
		syscall
		
		addi $s3 $s3 1		# i++
		j LOOP_3
	LOOP_3_END:
		
	lw $s0 0($sp)
	lw $s1 4($sp)
	lw $s2 8($sp)
	lw $s3 12($sp)
	lw $s4 16($sp)
	addi $sp $sp 20

jr $ra



EXIT:	
