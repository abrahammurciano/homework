.data
	array: 	.word 5 -3 6 2 -8 1 0 10
	size: 	.word 8
	
.text

main:
	la $s0 array
	lw $s1 size
	add $a0 $zero $s0
	add $a1 $zero $s1
	addi $sp $sp -4
	sw $ra ($sp)
	jal print
	lw $ra ($sp)
	addi $sp $sp 4
	
	add $a0 $zero $s0
	add $a1 $zero $s1
	addi $sp $sp -4
	sw $ra ($sp)
	jal bubbleSort
	lw $ra ($sp)
	addi $sp $sp 4
	
	add $a0 $zero $s0
	add $a1 $zero $s1
	addi $sp $sp -4
	sw $ra ($sp)
	jal print
	lw $ra ($sp)
	addi $sp $sp 4
	
	j exit


# Parameters: 
# $a0 = pointer to array
# $a1 = size of array
print:	
	# Save $s registers
	addi $sp $sp -12
	sw $s0 8($sp)
	sw $s1 4($sp)
	sw $s2 0($sp)
	
	# Move arguments to $s registers
	add $s0 $zero $a0
	add $s1 $zero $a1
	
	addi $s2 $zero 0
	loop1Start:
	slt $t0 $s2 $s1
	beq $t0 $zero loop1End
		# Print next number from array
		addi $v0 $zero 1
		lw $a0 0($s0)
		syscall
		# Print space character
		addi $v0 $zero 11
		addi $a0 $zero ' '
		syscall
		
		# Increment pointer
		addi $s0 $s0 4
		# Increment iterator
		addi $s2 $s2 1
		
		j loop1Start
	loop1End:
	
	# Reastore $s registers
	addi $sp $sp 12
	lw $s0 -4($sp)
	lw $s1 -8($sp)
	lw $s2 -12($sp)
	
	# Return
	jr $ra


# Parameters: 
# $a0 = pointer to array
# $a1 = size of array
bubbleSort:
	# Save $s registers
	addi $sp $sp -16
	sw $s0 12($sp)
	sw $s1 8($sp)
	sw $s2 4($sp)
	sw $s3 0($sp)
	
	# Move arguments to $s registers
	add $s0 $zero $a0
	addi $s1 $a1 -1		# size-=1
	
	addi $s2 $zero 0	# i=0
	loop2Start:
	slt $t0 $s2 $s1
	beq $t0 $zero loop2End
		addi $s3 $zero 0	# j=0
		loop3Start:
		sub $t0 $s1 $s2
		slt $t1 $s3 $t0
		beq $t1 $zero loop3End
			# $t0 = arr + j
			add $t0 $s3 $s3
			add $t0 $t0 $t0
			add $t0 $s0 $t0
			
			lw $t1 0($t0)	# $t1 = arr[j]
			lw $t2 4($t0)	# $t2 = arr[j+1]
			
			slt $t3 $t1 $t2
			beq $t3 $zero endif
				add $a0 $zero $t0
				addi $a1 $t0 4
				
				addi $sp $sp -4
				sw $ra ($sp)
				jal swap
				lw $ra ($sp)
				addi $sp $sp 4
			endif: 
		
			addi $s3 $s3 1	# j++
			j loop3Start
		loop3End:
		
		addi $s2 $s2 1	# i++
		j loop2Start
	loop2End:
	
	# Reastore $s registers
	addi $sp $sp 16
	lw $s0 -4($sp)
	lw $s1 -8($sp)
	lw $s2 -12($sp)
	lw $s3 -16($sp)
	
	# Return
	jr $ra
	
	
# Parameters: 
# $a0 = pointer1
# $a1 = pointer2
swap:
	lw $t0 ($a0)
	lw $t1 ($a1)
	sw $t0 ($a1)
	sw $t1 ($a0)
	jr $ra


exit:
