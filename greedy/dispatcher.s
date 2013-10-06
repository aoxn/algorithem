	.file	"dispatcher.c"
	.text
	.globl	min
	.type	min, @function
min:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -8(%ebp)
	movl	$1, -4(%ebp)
	jmp	.L2
.L4:
	movl	-4(%ebp), %eax
	sall	$2, %eax
	addl	8(%ebp), %eax
	movl	(%eax), %eax
	cmpl	-8(%ebp), %eax
	jge	.L3
	movl	-4(%ebp), %eax
	sall	$2, %eax
	addl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -8(%ebp)
.L3:
	addl	$1, -4(%ebp)
.L2:
	movl	-4(%ebp), %eax
	cmpl	12(%ebp), %eax
	jl	.L4
	movl	-8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	min, .-min
	.section	.rodata
	.align 4
.LC0:
	.string	"Task [%d] dispatch to server num [%d]\n "
	.text
	.globl	task_dispatch
	.type	task_dispatch, @function
task_dispatch:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %eax
	subl	$1, %eax
	movl	%eax, 12(%esp)
	movl	$0, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	bubble_sort
	movl	12(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -16(%ebp)
	jmp	.L6
.L7:
	movl	20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	min
	movl	%eax, -12(%ebp)
	movl	-16(%ebp), %eax
	sall	$2, %eax
	addl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	$.LC0, %eax
	movl	-12(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	subl	$1, -16(%ebp)
.L6:
	cmpl	$0, -16(%ebp)
	jns	.L7
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	task_dispatch, .-task_dispatch
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$48, %esp
	movl	$4, 20(%esp)
	movl	$8, 24(%esp)
	movl	$6, 28(%esp)
	movl	$5, 32(%esp)
	movl	$3, 12(%esp)
	leal	36(%esp), %eax
	movl	%eax, 8(%esp)
	movl	$4, 4(%esp)
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	task_dispatch
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
