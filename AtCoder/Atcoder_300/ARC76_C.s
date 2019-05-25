	.text
	.const
__ZStL19piecewise_construct:
	.space 1
	.text
	.globl __ZSt3absx
	.weak_definition __ZSt3absx
__ZSt3absx:
LFB923:
	pushq	%rbp
LCFI0:
	movq	%rsp, %rbp
LCFI1:
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	cqto
	movq	%rdx, %rax
	xorq	-8(%rbp), %rax
	subq	%rdx, %rax
	popq	%rbp
LCFI2:
	ret
LFE923:
	.static_data
__ZStL8__ioinit:
	.space	1
	.const
__ZStL13allocator_arg:
	.space 1
__ZStL6ignore:
	.space 1
	.text
	.globl _main
_main:
LFB3155:
	pushq	%rbp
LCFI3:
	movq	%rsp, %rbp
LCFI4:
	pushq	%rbx
	subq	$1600072, %rsp
LCFI5:
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	movq	__ZSt3cin@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__ZNSirsERx
	movq	%rax, %rdx
	leaq	-40(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	__ZNSirsERx
	movl	$100002, -20(%rbp)
	movq	-32(%rbp), %rdx
	movq	-40(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, %rdi
	call	__ZSt3absx
	cmpq	$1, %rax
	setg	%al
	testb	%al, %al
	je	L4
	movl	$0, %esi
	movq	__ZSt4cout@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__ZNSolsEi
	movq	%rax, %rdx
	movq	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	__ZNSolsEPFRSoS_E
	movl	$0, %eax
	jmp	L5
L4:
	leaq	-800064(%rbp), %rax
	movq	%rax, %rdi
	call	__Z4funcIxLx100002EEvRSt5arrayIT_XT0_EE
	leaq	-1600080(%rbp), %rax
	movq	%rax, %rdi
	call	__Z4funcIxLx100002EEvRSt5arrayIT_XT0_EE
	movq	-32(%rbp), %rdx
	movq	-40(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, %rdi
	call	__ZSt3absx
	cmpq	$1, %rax
	sete	%al
	testb	%al, %al
	je	L6
	movq	-32(%rbp), %rax
	movq	%rax, %rdx
	leaq	-800064(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	__ZNSt5arrayIxLm100002EEixEm
	movq	(%rax), %rbx
	movq	-40(%rbp), %rax
	movq	%rax, %rdx
	leaq	-1600080(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	__ZNSt5arrayIxLm100002EEixEm
	movq	(%rax), %rax
	imulq	%rax, %rbx
	movq	%rbx, %rcx
	movabsq	$-8543223828751151131, %rdx
	movq	%rcx, %rax
	imulq	%rdx
	leaq	(%rdx,%rcx), %rax
	sarq	$29, %rax
	movq	%rax, %rdx
	movq	%rcx, %rax
	sarq	$63, %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	imulq	$1000000007, %rax, %rax
	subq	%rax, %rcx
	movq	%rcx, %rax
	movq	%rax, %rsi
	movq	__ZSt4cout@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__ZNSolsEx
	movq	%rax, %rdx
	movq	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	__ZNSolsEPFRSoS_E
	jmp	L7
L6:
	movq	-32(%rbp), %rax
	movq	%rax, %rdx
	leaq	-800064(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	__ZNSt5arrayIxLm100002EEixEm
	movq	(%rax), %rbx
	movq	-40(%rbp), %rax
	movq	%rax, %rdx
	leaq	-1600080(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	__ZNSt5arrayIxLm100002EEixEm
	movq	(%rax), %rax
	imulq	%rbx, %rax
	leaq	(%rax,%rax), %rcx
	movabsq	$-8543223828751151131, %rdx
	movq	%rcx, %rax
	imulq	%rdx
	leaq	(%rdx,%rcx), %rax
	sarq	$29, %rax
	movq	%rax, %rdx
	movq	%rcx, %rax
	sarq	$63, %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	imulq	$1000000007, %rax, %rax
	subq	%rax, %rcx
	movq	%rcx, %rax
	movq	%rax, %rsi
	movq	__ZSt4cout@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__ZNSolsEx
	movq	%rax, %rdx
	movq	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	__ZNSolsEPFRSoS_E
L7:
	movl	$0, %eax
L5:
	addq	$1600072, %rsp
	popq	%rbx
	popq	%rbp
LCFI6:
	ret
LFE3155:
	.globl __Z4funcIxLx100002EEvRSt5arrayIT_XT0_EE
	.weak_definition __Z4funcIxLx100002EEvRSt5arrayIT_XT0_EE
__Z4funcIxLx100002EEvRSt5arrayIT_XT0_EE:
LFB3395:
	pushq	%rbp
LCFI7:
	movq	%rsp, %rbp
LCFI8:
	pushq	%rbx
	subq	$40, %rsp
LCFI9:
	movq	%rdi, -40(%rbp)
	movq	-40(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	__ZNSt5arrayIxLm100002EEixEm
	movq	$1, (%rax)
	movl	$1, -20(%rbp)
L10:
	cmpl	$100001, -20(%rbp)
	jg	L11
	movl	-20(%rbp), %eax
	subl	$1, %eax
	cltq
	movq	-40(%rbp), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	__ZNSt5arrayIxLm100002EEixEm
	movq	(%rax), %rdx
	movl	-20(%rbp), %eax
	cltq
	movq	%rdx, %rbx
	imulq	%rax, %rbx
	movl	-20(%rbp), %eax
	cltq
	movq	-40(%rbp), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	__ZNSt5arrayIxLm100002EEixEm
	movq	%rax, %rcx
	movabsq	$-8543223828751151131, %rdx
	movq	%rbx, %rax
	imulq	%rdx
	leaq	(%rdx,%rbx), %rax
	sarq	$29, %rax
	movq	%rax, %rdx
	movq	%rbx, %rax
	sarq	$63, %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	imulq	$1000000007, %rax, %rax
	subq	%rax, %rbx
	movq	%rbx, %rax
	movq	%rax, (%rcx)
	movl	-20(%rbp), %eax
	cltq
	movq	-40(%rbp), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	__ZNSt5arrayIxLm100002EEixEm
	movq	%rax, %rsi
	movq	(%rsi), %rcx
	movabsq	$-8543223828751151131, %rdx
	movq	%rcx, %rax
	imulq	%rdx
	leaq	(%rdx,%rcx), %rax
	sarq	$29, %rax
	movq	%rax, %rdx
	movq	%rcx, %rax
	sarq	$63, %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	imulq	$1000000007, %rax, %rax
	subq	%rax, %rcx
	movq	%rcx, %rax
	movq	%rax, (%rsi)
	addl	$1, -20(%rbp)
	jmp	L10
L11:
	nop
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
LCFI10:
	ret
LFE3395:
	.align 1,0x90
	.globl __ZNSt5arrayIxLm100002EEixEm
	.weak_definition __ZNSt5arrayIxLm100002EEixEm
__ZNSt5arrayIxLm100002EEixEm:
LFB3396:
	pushq	%rbp
LCFI11:
	movq	%rsp, %rbp
LCFI12:
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	__ZNSt14__array_traitsIxLm100002EE6_S_refERA100002_Kxm
	leave
LCFI13:
	ret
LFE3396:
	.globl __ZNSt14__array_traitsIxLm100002EE6_S_refERA100002_Kxm
	.weak_definition __ZNSt14__array_traitsIxLm100002EE6_S_refERA100002_Kxm
__ZNSt14__array_traitsIxLm100002EE6_S_refERA100002_Kxm:
LFB3508:
	pushq	%rbp
LCFI14:
	movq	%rsp, %rbp
LCFI15:
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	popq	%rbp
LCFI16:
	ret
LFE3508:
__Z41__static_initialization_and_destruction_0ii:
LFB3646:
	pushq	%rbp
LCFI17:
	movq	%rsp, %rbp
LCFI18:
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	L18
	cmpl	$65535, -8(%rbp)
	jne	L18
	leaq	__ZStL8__ioinit(%rip), %rdi
	call	__ZNSt8ios_base4InitC1Ev
	leaq	___dso_handle(%rip), %rdx
	leaq	__ZStL8__ioinit(%rip), %rsi
	movq	__ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	___cxa_atexit
L18:
	nop
	leave
LCFI19:
	ret
LFE3646:
__GLOBAL__sub_I_ARC76_C.cpp:
LFB3647:
	pushq	%rbp
LCFI20:
	movq	%rsp, %rbp
LCFI21:
	movl	$65535, %esi
	movl	$1, %edi
	call	__Z41__static_initialization_and_destruction_0ii
	popq	%rbp
LCFI22:
	ret
LFE3647:
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x1
	.ascii "zR\0"
	.byte	0x1
	.byte	0x78
	.byte	0x10
	.byte	0x1
	.byte	0x10
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.byte	0x90
	.byte	0x1
	.align 3
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB923-.
	.set L$set$2,LFE923-LFB923
	.quad L$set$2
	.byte	0
	.byte	0x4
	.set L$set$3,LCFI0-LFB923
	.long L$set$3
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$4,LCFI1-LCFI0
	.long L$set$4
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$5,LCFI2-LCFI1
	.long L$set$5
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE1:
LSFDE3:
	.set L$set$6,LEFDE3-LASFDE3
	.long L$set$6
LASFDE3:
	.long	LASFDE3-EH_frame1
	.quad	LFB3155-.
	.set L$set$7,LFE3155-LFB3155
	.quad L$set$7
	.byte	0
	.byte	0x4
	.set L$set$8,LCFI3-LFB3155
	.long L$set$8
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$9,LCFI4-LCFI3
	.long L$set$9
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$10,LCFI5-LCFI4
	.long L$set$10
	.byte	0x83
	.byte	0x3
	.byte	0x4
	.set L$set$11,LCFI6-LCFI5
	.long L$set$11
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE3:
LSFDE5:
	.set L$set$12,LEFDE5-LASFDE5
	.long L$set$12
LASFDE5:
	.long	LASFDE5-EH_frame1
	.quad	LFB3395-.
	.set L$set$13,LFE3395-LFB3395
	.quad L$set$13
	.byte	0
	.byte	0x4
	.set L$set$14,LCFI7-LFB3395
	.long L$set$14
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$15,LCFI8-LCFI7
	.long L$set$15
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$16,LCFI9-LCFI8
	.long L$set$16
	.byte	0x83
	.byte	0x3
	.byte	0x4
	.set L$set$17,LCFI10-LCFI9
	.long L$set$17
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE5:
LSFDE7:
	.set L$set$18,LEFDE7-LASFDE7
	.long L$set$18
LASFDE7:
	.long	LASFDE7-EH_frame1
	.quad	LFB3396-.
	.set L$set$19,LFE3396-LFB3396
	.quad L$set$19
	.byte	0
	.byte	0x4
	.set L$set$20,LCFI11-LFB3396
	.long L$set$20
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$21,LCFI12-LCFI11
	.long L$set$21
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$22,LCFI13-LCFI12
	.long L$set$22
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE7:
LSFDE9:
	.set L$set$23,LEFDE9-LASFDE9
	.long L$set$23
LASFDE9:
	.long	LASFDE9-EH_frame1
	.quad	LFB3508-.
	.set L$set$24,LFE3508-LFB3508
	.quad L$set$24
	.byte	0
	.byte	0x4
	.set L$set$25,LCFI14-LFB3508
	.long L$set$25
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$26,LCFI15-LCFI14
	.long L$set$26
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$27,LCFI16-LCFI15
	.long L$set$27
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE9:
LSFDE11:
	.set L$set$28,LEFDE11-LASFDE11
	.long L$set$28
LASFDE11:
	.long	LASFDE11-EH_frame1
	.quad	LFB3646-.
	.set L$set$29,LFE3646-LFB3646
	.quad L$set$29
	.byte	0
	.byte	0x4
	.set L$set$30,LCFI17-LFB3646
	.long L$set$30
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$31,LCFI18-LCFI17
	.long L$set$31
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$32,LCFI19-LCFI18
	.long L$set$32
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE11:
LSFDE13:
	.set L$set$33,LEFDE13-LASFDE13
	.long L$set$33
LASFDE13:
	.long	LASFDE13-EH_frame1
	.quad	LFB3647-.
	.set L$set$34,LFE3647-LFB3647
	.quad L$set$34
	.byte	0
	.byte	0x4
	.set L$set$35,LCFI20-LFB3647
	.long L$set$35
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$36,LCFI21-LCFI20
	.long L$set$36
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$37,LCFI22-LCFI21
	.long L$set$37
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE13:
	.mod_init_func
	.align 3
	.quad	__GLOBAL__sub_I_ARC76_C.cpp
	.constructor
	.destructor
	.align 1
	.subsections_via_symbols
