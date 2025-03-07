---
subject: Personal journal for MiniRT project
---

# 20/2/25
- At 42 with pberset, discussed task list
- Going through Ch.1 RT Challenge: *Tuples, Points, Vectors*
- Coordinate choice: left-handed, like the book (see Implementation.md)
- Implemented math functions abs_float() and is_equal_float()
- Tuples: implemented tuple type, tuple init functions point() and vector(), 
tuple manipulation functions add_tuple(), subtract_tuple() and is_equal_tuple()
- To do next time: test tuple manipulation functions

# 21/2/25
- Discussed floats vs double with pberset, decided to use float (less space)
- Tuples: wrote some basic tests of functions, added NULL checks, finished writing functions, need final tests for dot-product and cross-product
- Preparing to merge
- Merged with pberset's branch

# 25/2/25
- Tested magnitude, dot product, cross product functions
- Wrote projectile simulations tests (a set of functions that tests tuple
functions)

# 26/2/25
- Moving to Matrices (chapter 3 RT Challenge): data structures (struct with
row, columns count, and a 2d array of floats)

# 27/2/25
- Ok with basic matrix initialization and comparison
- Matrix multiplication: editing tuple operations to allow for 4d tuples (->type becomes ->w; 
commented out error handling for nonsensical things like adding/subtracting point to/from vector, just letting it be).
	=> finally, wrote the operation directly using matrix components multiplication, without using tuple data structures and functions (dot product), because it would imply using a malloc (`vector()`, `point()`, or some new function `init_tuple()` for 4d tuple) as a step
	in the multiplication. We'll see later on if tuples simplify life and we have to change this again
- Identity matrix: wrote function
- Tested mat_mul and identity function, work correctly (maybe some edge cases ? I don't see what exactly, except maybe very large numbers)

# 28/2/25
- Wrote `convert_tuple_to_matrix()` which can be used by `matrix_multiplication()`
- Wrote matrix transpose, determinant (for 2x2 matrix), submatrix
- Next up: minors

# 4/3/25
- Discussed parsing with pberset
- Note on implementation: typecast structs (cf. cdorig's minishell)
- Wrote matrix minors, cofactors
- Determinant of larger matrices: works for 3x3, but need to add some steps
to cover 4x4 (see book). Segfaults for now

# 7/3/25
- 