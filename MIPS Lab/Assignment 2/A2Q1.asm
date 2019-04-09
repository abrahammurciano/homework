.data

	list: .byte 16 -45 9 78 53 120 -6 85 -128 -9 54 12 5
	size: .word 13
	
.text

	la $a0 list
	lw $a1 size
	addi $s1 $zero 0xffffffff
	
	# While $s0 is less than size
	while: 
	slt $t0 $s0 $a1
	beq $t0 $zero exit
		
		# If $s1 < next value
		lb $t0 ($a0)
		slt $t1 $s1 $t0
		beq $t1 $zero endif
			# Store highest so far into $s1
			add $s1 $t0 $zero
		endif:
		
		# Increment list pointer ($a0) and iteration variable ($s0)
		addi $a0 $a0 1
		addi $s0 $s0 1
		
		j while
		
	exit:
	
	# Print highest value
	add $a0 $s1 $zero
	addi $v0 $zero 1
	syscall
	
	# Put result in register $v0
	add $v0 $s1 $zero
	