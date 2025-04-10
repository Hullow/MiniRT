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

# 21/3/25
- Wrote shearing function + tests for transformations
- Testing transformations : wrote all tests, edited rotation functions a bit

```bash
~/42/MiniRT/Sources/src/transforms
 % g *.c ../matrices/*.c ../tuples/*tuple*.c ../utils/*.c -lm
```

- Transformation matrices: I wonder if not better to pass parameter directly,
as such `rt_scaling(5, 5, 5)` rather than the current `rt_scaling(rt_point(5, 5, 5))`
=> lighter
=> we'll see, depending on how we use the transformation matrices

- Added a function `matrix_tuple_multiplication` to directly modify a tuple without
having to convert it to a matrix


# 24/3/25
- Weird makefile and header issue: stuff disappeared at some point, need to readd manually.
Faulty merges ?
- Rewrote `handle_error` with pberset, and corresponding header enums/defines.
Edited the function call from many functions, but still need to add it in many places
where I simply return NULL (like tuples mallocs)
- Pberset started replacing mallocs with ft_calloc
- Analog clock (end of chapter 4 - "Chaining it together"): started to write code
with pberset. Decided against function pointers due to differing prototypes of the
transformation functions 

# 3/4/25
- Read (diagonally) ch. 5 "Ray-sphere intersections": for intersect(), which takes an object
and a ray, two ways to implement. Either encapsulate each object in a new type t_obj,
or add an enum variable to specify the object used as argument, and (void *) cast
the actual pointer given as argument (then recast it as the appropriate type
inside the intersect() function).
- Hit is the intersection with the lowest nonnegative t value


- To check with pberset: p. 68. Inverting matrices => need determinant 
> whatever transformation you want to apply to the sphere, apply the inverse of
that transformation to the ray, instead.<br>
> first, make sure your ray is transformable<br>
> Make sure it returns a new ray, rather than modifying the ray in place !


# 4/4/25
- Working on ch.6 "Light and Shading": normal vector
- Discussed pberset's work on ch. 5 (intersections), recoded the object loop (but not tested yet),
and said I might write the tests for the chapter