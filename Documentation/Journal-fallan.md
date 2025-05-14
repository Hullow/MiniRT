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

# 10/4/25
- Worked on missing chapter 5 items: rt_transform_ray and set_sphere_transform (transform and set_transform in the book)
=> to finish
- Ideas for avoiding too many frees:
	- everything on stack at initialization
	- transformations:
		- init them in a struct and point towards them
		- encapsulate transformations in a function that mallocs a transformation matrix, performs the transformation, then frees everything

# 11/4/25
- Intersections (+rays, positions): wrote tests and fixed rt_ray_sphere_x's formula +
added ray modification using matrix_inversion(sphere->transform)
- Note on intersection(), intersections(), intersect(), hit() (pp. 63-66):
	- we implemented only intersect, not intersection(s) per se, nor hit()

From book p. 66:
> Scenario: The hit is always the lowest nonnegative intersection<br>
&emsp; Given s ← sphere()<br>
&emsp; And i1 ← intersection(5, s)<br>
&emsp; And i2 ← intersection(7, s)<br>
&emsp; And i3 ← intersection(-3, s)<br>
&emsp; And i4 ← intersection(2, s)<br>
&emsp; And xs ← intersections(i1, i2, i3, i4)<br>
When i ← hit(xs)<br>
Then i = i4<br><br>
Don’t let that last test trip you up! The intersections are intentionally given
in random order; it’s up to your intersections() function to maintain a sorted list
or, at the very least, sort the list on demand. This will be important down the
road when you have more complicated scenes with multiple objects. It won’t
be feasible for each shape to manually preserve the sort order of that intersection list.

=> so there are more than two intersections, so we need this functionality. Let's build it.

# 14/4/25
- Tested ray sphere intersections, but not functions combining them
=> Moving on to "putting it together"
- wrote function `rgb_to_int()` to convert a value from tuple (1, 0, 0) to int (16711680)
via hex (FF0000)
- Managed to draw a fully red window

# 17/4/25
- Working on ray-sphere intersection: finished writing formula, updated Makefile
while discussing it with pberset
- No success running it so far, and surprise: segfault, likely from numerous matrix calculation mallocs.
Will look at pberset's malloc-less version instead of fixing it at this current stage.

to do: add t_matrix *inverse_transform in t_sphere 

# 18/4/25
- Forked pberset's branch to new branch "no-malloc", reorganized tests in that 
branch, rewrote test_tuple to remove mallocs and validated these tests from miniRT's main using make rather than ad-hoc compilation
- To rewrite: rt_ray_sphere_x => need to add intersections to intersection linked list
- Next: finish other tests (test_matrix, test_transforms_and_rays)

# 19/4/25
- Tests (continued): rewrote test_matrix but waiting on pberset to finish his updates on matrices
- Ordered functions, files and folders.
- Norm: done everywhere where code writing is finished (excluding tests)
- Note - possible optimization down the line (if necessary): remove some mallocs
from some matrix operations functions, like cofactor/minor:
```c
int result;
int mat_contents[2][2];
mat_contents[0][0] = ...
(..)
mat_contents[1][1] = ...

(computation)

return result;
```

- To do: fix `test_transforms_and_rays()`, run `test_matrix()` when pberset finishes, then
make `test_ray_sphere()` finally work

# 21/4/25
- MLX env and drawing function: cut into pieces for clarity
- Worked on drawing a disk (end of Ch.5), alone, then with pberset, but it draws
a square or a cross (??!!) rather than a disk, and loses the address of the sphere
for some reason.
- Commit made in this stage, but decision made to just return a t-value, then compute which
object is intersected.
=> or return a modified t_intersect struct with only one t-value, or zero t-values.

# 1/5/25
- debugging: rt_ray_sphere_intersection (issue with lstnew/memcpy not copying the intersection properly). Using printf
- `rt_draw` and `rt_define_ray_to_wall`: x_mlx, y_mly types to float, leading to less fixed discriminant down the line (in `rt_ray_sphere_x`)
- Fixed segfaults so far. Now the issue is only black pixels are drawn (no intersection found with sphere).
- Need to check the implementation while re-reading the book. Even if sphere has diam = 100.0, no hit, weirdly.
- Changed t_intersect data structure from pair + t-count + object to single t-value + object 
(also removed member "ray" which was not needed)
=> rewrote rt_intersections.c and rt_test_ray_sphere (to check/finish) to fit this
=> compiles but still doesn't make a difference. at least now easier to debug

- To do: finish re-implementing book-mentioned features. incl. previous tests that were skipped for intersection

# 2/5/25
- Tests ch.5 : passed `test_ray_intersections_hits();`, (ray touches sphere in two points, tangent, misses sphere, ...)
- Next: tracking intersections => tests. Didn't implement it exactly like prescribed in the book, but tests pass for hits (`rt_find_ray_hits`)
- TL;DR ch.5 tests passed, except for 1-2 specific intersect functions not implemented.
- Red disk success! Ayaaaaaa ! Japan flag too ! Issou

# 8/5/25
- Fixed makefile for macOS
- Debugging in the afternoon at 42 but not for very long (I think)

# 9/5/25
- Reading through Light and Reflection (ch. 6)

# 11/5/25
- Trying to printf debug rt_lighting; pberset fixes the "hole" in the sphere, then add
reinhard tone. It works ! Diffuse, ambient, specular :)
- Makefile macOS: added conditional flag (ifeq...endif)
- Git ordering: deleted no-malloc, polymorph branches, merged the other 3 together from
pberset's work
- Folder order: removed fdf folder in Documentation/, it's pollution
- To do tomorrow: finish re-reading chapter and code, then order and re-add comments on functions

# 13/4/25
- Playing with sphere transformations (installed Blender to understand shearing better). All seems to work

# 14/4/25
- Started merging Render_Engine_Only with rest of project => will do it tomorrow with pberset
- Started reading Chapter 7 Making a Scene. Created world type, also wrote the first tests to satisfy. Initialization works, with variadic arguments (should probably be removed later...)
- Retouched `rt_discriminant` in Render_engine a bit (renamed `rt_ray_sphere_intersects` because that's what it is). (doesn't break sphere rendering).
- Moved the contents of the inner loop of `test_light_render()` to a new function `rt_render_sphere_pixel()`
- Started working on threaded version of this function `rt_thread_render_sphere_pixel()`. It compiles but is very slow, doesn't seem to work. Debugging with Gemini in Copilot
