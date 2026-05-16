*This activity has been created as part of the 42 curriculum by berferna, marad*

<h3>Description</h3> 
push_swap as part of the 42 curriculum is ment to sort a given amount of numbers using the less amount of operations.

We count with two stacks, a and b.
We use the following operations:
|Code | Ation|
|-----|------|
|pa | Moves element from stack a to b
|pb| Moves element of stack b to a
|sa|Swap top elements of stack a|
|sb|Swap top elements of stack b|
|ss|sa and sb|
|ra|shift all elements of the stack from bottom to top|
|rb|shift all elements of stack b from bottom to top|
|rr|Both ra and rb|
|rra|shift all elements from stack a from top to bottom|
|rrb|shifts all elements of stack b from top to bottom|
|rrr|Both rra and rrb|

We can choose from four different sorting strategies:
simple, medium, complex and adaptive.
Adaptive chooses the strategy according of the level of disorder of the numbers.

The simple algorithm is O(n2) 

The medium algorithm is O(n√n)

The complex algorithm is O(n log n)

<h3>Instructions</h3>

To use push_swap you need to clone the [repository](https://github.com/betferna/push_swap.git) with 'git clone' and run 'make' to compile all the files, then you can run the executable 'push_swap' with the desired amount of integers.

> ./push_swap 1 5 3 8 2 9 

You can also choose the strategy by using the flags: 

> --simple --medium --complex

And display the benchmark information with:

> --bench

> ./push_swap --bench --medium 1 4 2 </br>
>pb</br>
>rb</br>
>pb</br>
>pb</br>
>rb</br>
>pa</br>
>rb</br>
>pa</br>
>pa</br>
>[bench] disorder:  33.33 %</br>
>[bench] strategy: Medium</br>
>[bench] complexity: O(n√n)</br>
>[bench] total_ops: 9</br>
>[bench] sa: 0  sb: 0  ss: 0  pa: 3  pb: 3</br>
>[bench] ra: 0  rb: 3  rr: 0  rra: 0  rrb: 0  rrr: 0</br>

**<h3>Additinal rules:</h3>**
**`make clean`** to clean up objects files (.o)</br>
**`make fclean`** to remove object files and the executable(.a)</br>
**`make re`** Often defined as fclean all, recompiles everything from scratch</br>

Compilation with flags : **-Wall -Wextra -Werror**

**Sorting algorithms**
- The simple algorithm is O(n2), contains a three sorst and five sort and a quick sort that check the min value and according to its position it decides if rotate or reverse rotate.

- The medium algorithm is O(n√n), we indexed all the numers in to its actual position if ordered, and divided in chunks according to the total amount, if 100 integers 5 chunks of 20, if more 35. We create a window between an increasing counter + chunk and we give three conditions, if index < counter pb, rb, if between counter + chunk, pb, else ra, and continue until 'a' is empty, then we look for the biggest and pa, we rb or rrb until all integers passed sorted back to a.

- The complex algorithm is O(n log n)




<h3>Resources </h3>


- Sorting algorithms videos
- man pages
- Peer exchange
- AI for understanding sorting algorithms