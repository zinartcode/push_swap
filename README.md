# push_swap

The push_swap program generates a list of instructions that sort a stack of integers using the original stack A and a second  stack B. The goal is to sort integers in ascending order into stack A in as few operation as possible. 5 random numbers must be sortes in less than 12 operations, 100 random numbers in less than 700 operations and 500 numbers in less than 5300.

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
* __pa__ - moves the first element of stack B to the top of stack A.
* __pb__ - moves the first element of stack A to the top of stack B.
* __ra__ - moves the first element of stack A to the bottom of stack A.
* __rb__ - moves the first element of stack B to the bottom of stack B.
* __rr__ - performs __ra__ and __rb__ simultaneously.
* __rra__ - moves the last element of stack A to the top of stack A.
* __rrb__ - moves the last element of stack B to the top of stack B.
* __rrr__ - performs __rra__ and __rrb__ simultaneously.

## Usage:

Run make command.
```
make
```
You will get push_swap and checker file.

To run the push_swap,
```
./push_swap [numbers]
```
The program will output the operations using to sort the numbers, for example:
```
$> ./push_swap 3 2 1 | cat -e
sa$
ra$
```

To run the checker,
```
./checker [numbers]
```
Then, you have to input operations. One operation each time then press Enter. After finished, press command + D or CTRL + D. For example:
```
$>./checker 3 2 1
sa
ra
OK
$> ./checker 3 2 1
ra
sa
KO
```

You can run push_swap and then send the result to the checker to check it.
```
ARG="3 2 1"; ./push_swap $ARG | ./checker $ARG
```

I also have 2 debug mode:
* -v show stack a and stack b in each operation
```
./push_swap -v [numbers]
```


Push_swap subject:<br/>
https://cdn.intra.42.fr/pdf/pdf/944/push_swap.en.pdf
