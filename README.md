# push_swap

The push_swap program generates a list of instructions that sort a stack of integers using the original stack A and a second  stack B. The goal is to sort in ascending order numbers into stack A.

## The goal is to write two programms in C

• The first, named checker which takes integer arguments and reads instructions on the standard output. Once read, checker executes them and displays OK if integers are sorted. Otherwise, it will display KO.

• The second one called push_swap which calculates and displays on the standard output the smallest progam using Push_swap instruction language that sorts integer arguments received.

## The following functions are allowed:

* __write__

* __read__
* __malloc__
* __free__
* __exit__

## The following manipulations are allowed:

* __sa__ - swaps the order of the first two values in stack A.
* __sb__ - swaps the order of the first two values in stack B.
* __ss__ - swaps the order of the first two values in both stacks.
* __pa__ - moves the first element of stack A to the top of stack B.
* __pb__ - moves the first element of stack B to the top of stack A.
* __ra__ - moves the first element of stack A to the bottom of stack A.
* __rb__ - moves the first element of stack B to the bottom of stack B.
* __rr__ - performs __ra__ and __rb__ simultaneously.
* __rra__ - moves the last element of stack A to the top of stack A.
* __rrb__ - moves the last element of stack B to the top of stack B.
* __rrr__ - performs __rra__ and __rrb__ simultaneously.
