.data
	prompt:	.asciiz	"Enter a number:\n"
	error:	.asciiz	"Error: Invalid number."

.text

main:
	# Print prompt
	la $a0 prompt
	addi $v0 $zero 4
	syscall
	
	# Read int into s0
	addi $v0 $zero 5
	syscall
	addi $s0 $v0 0
	
	# If 0, exit
	beq $s0 $zero exit
	
	# Get 8 leftmost bits into s1
	srl $s1 $s0 24
	
	addi $t0 $zero 0x31
	beq $s1 $t0 CASE_1A
	
	addi $t0 $zero 0x30
	beq $s1 $t0 CASE_1B
	
	addi $t0 $zero 0x48
	beq $s1 $t0 CASE_1C
	
	addi $t0 $zero 0x74
	beq $s1 $t0 CASE_1D
	
	j CASE_1_DEFAULT
	
	CASE_1A:
		ori $s0 $s0 0x000000C3
		j CASE_1_END
		
	CASE_1B:
		addi $t0 $zero 0xffffff3C
		and $s0 $s0 $t0
		j CASE_1_END
		
	CASE_1C:
		xori $s0 $s0 0x0000ff00
		j CASE_1_END
		
	CASE_1D:
		srl $t0 $s0 20
		sllv $s0 $s0 $t0
		j CASE_1_END
		
	CASE_1_DEFAULT:
		la $a0 error
		addi $v0 $zero 4
		syscall
		j main
		
	CASE_1_END:
	
	addi $a0 $s0 0
	addi $v0 $zero 1
	syscall
	
	addi $a0 $zero '\n'
	addi $v0 $zero 11
	syscall
	
	j main
	
exit: