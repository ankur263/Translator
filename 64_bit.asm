	.file	"add.c"
	.section	.rodata
.LC0:
	.string	"%d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	%rsp, %rbp
	.cfi_def_cfa_register 6
	andl	$-16, %rsp
	subq	$32, %rsp
	movl	$6, 20(%rsp)
	movl	$6, 27(%rsp)
	movl	27(%rsp), %eax
	movl	20(%rsp), %edx
	addl	%edx, %eax
	movl	%eax, 216(%rsp)
	movl	216(%rsp), %eax
	movl	%eax, 7(%rsp)
	movl	$.LC0, (%rsp)
	call	printf
	movl	$0, %eax
	leave
	.cfi_restore 6
	.cfi_def_cfa 7, 7
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: 
	.section	.note.GNU-stack,"",@progbits
