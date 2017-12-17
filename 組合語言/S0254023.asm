# UNTITLED PROGRAM

	.data	# Data declaration section
array:	.word 0,0,0,0,0,0,0,0,0,0
size:	.word 10
str1:	.asciiz "請輸入有幾個數字(小於10):"
str2:	.asciiz "請輸入一串數字:"
str3:	.asciiz "排序後結果:"
strn:	.asciiz "\n"
strs:	.asciiz " "
	.text

main:	
	addi	$sp, $sp, -16
	sw		$ra, 12($sp)
	sw		$s6, 8($sp)
	sw		$s7, 4($sp)
	sw		$s1, 0($sp)
	
	li		$v0, 4
	la		$a0, str1
	syscall
	li		$v0, 5			#input n
	syscall
	move	$s7, $v0
	addi	$t0, $t0, 10
	sub		$s7, $t0, $s7	#i = 10 - n
	move	$s6, $s7		#s6 = i
	sll		$t0, $s7, 2		#j = i * 4 (4 bytes)
	la		$t1, array		#load $t1 = array
	lw		$t2, size		#load $t2 = size
	
	li		$v0, 4
	la		$a0, strn
	syscall
	li		$v0, 4
	la		$a0, str2
	syscall
inputi:
	li		$v0, 5
	syscall
	add		$t3, $t0, $t1	#$t3 = array + j
	sw		$v0, 0($t3)		#array + t3 = v0
	addi	$t0, $t0, 4		#4 bytes
	addi	$s7, $s7, 1		#i = i + 1
	bne		$s7, $t2, inputi
	
	la		$a1, array
	lw		$a0, size
	jal		sel_sort
	
	move	$s7, $s6
	sll		$t0, $s7, 2		#j = i * 4 (4 bytes)
	la		$t1, array		#load $t1 = array
	lw		$t2, size		#load $t2 = size
	
	
	li		$v0, 4			#print
	la		$a0, str3
	syscall
outputi:
	beq		$s7, $zero, spaceprint
	li		$v0, 4
	la		$a0, strs
	syscall
spaceprint:
	li		$v0, 1
	add		$t3, $t0, $t1	#t3 = array + t0
	lw		$a0, 0($t3)		#print($a0)
	syscall
	
	addi	$t0, $t0, 4		#4 bytes
	addi	$s7, $s7, 1		#i = i + 1
	bne		$s7, $t2, outputi
	#end
	lw		$ra, 12($sp)
	lw		$s6, 8($sp)
	lw		$s7, 4($sp)
	lw		$s1, 0($sp)
	jr		$ra
	
sel_sort:	
	addi	$sp, $sp, -28
	sw		$ra, 24($sp)
	sw		$s5, 20($sp)
	sw		$s4, 16($sp)
	sw		$s3, 12($sp)
	sw		$s2, 8($sp)
	sw		$s1, 4($sp)
	sw		$s0, 0($sp)
	
	move	$s4, $a0		#n
	move	$s5, $a1		#a[]
	move	$s0, $zero		#i = 0
for1:
	slt		$t0, $s0, $s4
	beq		$t0, $zero, exit1
	move	$s3, $s0		#index = i
	addi	$s1, $s0, 1		#j = i + 1
for2:
	slt		$t0, $s1, $s4
	beq		$t0, $zero, exit2
	sll		$t1, $s1, 2		#t1 = j * 4
	add		$t2, $a1, $t1	#t2 = address of a[j]
	sll		$t3, $s3, 2		#t3 = index * 4
	add		$t4, $a1, $t3	#t4 = address of a[index]
	lw		$t5, 0($t2)		#t5 = a[j]
	lw		$t6, 0($t4)		#t6 = a[index]
if_1:
	slt		$t0, $t5, $t6
	beq		$t0, $zero, if_2
	move	$s3, $s1		#index = j
if_2:
	addi	$s1, $s1, 1
	j		for2
exit2:
	sll		$t1, $s0, 2		#t1 = i * 4
	add		$t1, $a1, $t1	#address of a[i]
	lw		$t5, 0($t1)		#t5 = a[i]
	sll		$t3, $s3, 2		#t3 = index * 4
	add		$t4, $a1, $t3	#t4 = address of a[index]
	lw		$t6, 0($t4)		#t6 = a[index]
	sw		$t5, 0($t4)		#array[i] = &t6
	sw		$t6, 0($t1)		#array[index] = &t5
	addi	$s0, $s0, 1
	j		for1
exit1:
	lw		$s0, 0($sp)
	lw		$s1, 4($sp)
	lw		$s2, 8($sp)
	lw		$s3, 12($sp)
	lw		$s4, 16($sp)
	lw		$s5, 20($sp)
	lw		$ra, 24($sp)
	addi	$sp, $sp, 28
	jr		$ra
	
# END OF PROGRAM