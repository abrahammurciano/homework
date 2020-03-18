.data
Array1:	.word 1, 8, 3, 4, 9, 5, 0, 9
Array2:	.space 240


.text
# Load pointers to arrays into $a0 and $a1
la $a0 Array1
la $a1 Array2

do:
# Copy value in address $a0 to address $a1
lw $t0 ($a0)
sw $t0 ($a1)

# Check if value in address $a0 is 0
beq $t0 $zero end

# Increment count $s0
addi $s0 $s0 1

# Increment pointers $a0 and $a1
addi $a0 $a0 4
addi $a1 $a1 4

j do

end:
