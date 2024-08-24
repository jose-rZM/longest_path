# longest_path

Last level exercise of the 42 Piscine final exam. It prints the length of the longest path in a undirected graph.
The program uses an adjacency list to store the graph.

### Compiling
A Makefile is provided.

### Running the Program
The program is called g_diam and takes one argument, the graph in the following format: `v1-v2`, which represents an edge from v1 to v2. The vertices must be `unsigned int` and no specific order is required.
Example:
~~~
./g_diam "1-2 2-3 4-5 5-6 6-7"
~~~
It would output:
~~~
Max len: 4
~~~
### Considerations
- The code does not adhere strictly to The Norm (files contain more than 5 functions).
- Due to exercise restrictions, the program is not the most efficient and may use a lot of memory if the graph is dense.
- The program has no memory leaks even when the input is incorrect.
