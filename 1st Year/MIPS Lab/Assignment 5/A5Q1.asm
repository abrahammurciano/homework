.data
	array:	.byte	1 2 2 1 1 2 2 1 1 2 2 1 1 2 2 1 1 2 2 1 
	size:	.word	20
	prompt: .asciiz	"Enter 6 numbers: (-128 to 127)\n"
	text1:	.asciiz	"The code { "
	text2:	.asciiz	"} was found "
	text3:	.asciiz	" time"
	
.text

main:

	la $a0 array
	lw $a1 size

	# Print "Enter 6 numbers:"
	addi $sp $sp -4
	sw $a0 ($sp)
	la $a0 prompt
	addi $v0 $zero 4
	syscall
	lw $a0 ($sp)
	addi $sp $sp 4
	
	# Allocate memory for code
	addi $sp $sp -6
	addi $s1 $sp 0		# s1 = code
	addi $t0 $sp 0
	
	# Read 6 numbers
	addi $t1 $zero 0
	LOOP1_START:
	slti $t2 $t1 6
	beq $t2 $zero LOOP1_END
	
		# Read a number
		addi $v0 $zero 5
		syscall
		
		# Store it into array
		sb $v0 ($t0)
		addi $t0 $t0 1
		addi $t1 $t1 1
		j LOOP1_START
		
	LOOP1_END:
	
	addi $s4 $zero 0	# count = 0
	
	# Check each element of array to see if its the beginning of a code
	addi $s0 $a0 0		# s0 = array
	addi $t0 $zero 0	# i = 0
	LOOP2_START:
	addi $t1 $a1 -5		# t1 = size - 5
	slt $t1 $t0 $t1		# while(i < size - 5)
	beq $t1 $zero LOOP2_END
	
		# Check if this is the beginning of a code
		addi $s2 $s0 0		# s3 = array[i]
		addi $s3 $s1 0		# s4 = code
		addi $t1 $zero 0	# j = 0
		LOOP3_START:
		addi $t2 $zero 6
		slt $t2 $t1 $t2		# while(j < 6)
		beq $t2 $zero LOOP3_END
		
			# if((array+i)[j] != code[j]) branch
			lb $t2 ($s2)
			lb $t3 ($s3)
			bne $t2 $t3 NOT_MATCH
	
			addi $s2 $s2 1		# (array+i)++
			addi $s3 $s3 1		# code++
			addi $t1 $t1 1		# j++
			j LOOP3_START
		
		LOOP3_END:
		
			addi $s4 $s4 1	# count++
		
		NOT_MATCH:
	
		addi $s0 $s0 1		# array++
		addi $t0 $t0 1		# i++
		j LOOP2_START
		
	LOOP2_END:
	
	la $a0 text1
	addi $v0 $zero 4
	syscall
	
	# Print code
	addi $t0 $zero 0	# i = 0
	LOOP4_START:
	slti $t1 $t0 6		# while(i < 6)
	beq $t1 $zero LOOP4_END
	
		# Print a number
		lb $a0 ($s1)
		addi $v0 $zero 1
		syscall
	
		# Print a space
		addi $a0 $zero ' '
		addi $v0 $zero 11
		syscall
		
		addi $t0 $t0 1
		addi $s1 $s1 1
		j LOOP4_START
		
	LOOP4_END:
	
	la $a0 text2
	addi $v0 $zero 4
	syscall
	
	addi $a0 $s4 0
	addi $v0 $zero 1
	syscall
	
	la $a0 text3
	addi $v0 $zero 4
	syscall
	
	addi $t0 $zero 1
	beq $s4 $t0 ENDIF_1
		addi $a0 $zero 's'
		addi $v0 $zero 11
		syscall
	ENDIF_1:
	
	j end

end:
