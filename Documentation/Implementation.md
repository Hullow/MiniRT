# MiniRT - Implementation considerations

- Normal vector: depends on point of object (sphere, plane, cylinder) ?

## Coordinate system
- From the book, "left-handed coordinates" (RT Challenge p.3):
	- x: pointing to the right
	- y: pointing up
	- z: pointing away from us

## Colors
- From the subject RGB 0-255 (int)
- From the book 0-1 (float)
	- x = r
	- y = g
	- z = b
- Use t_tuple	*divide_tuple_by_scalar(t_tuple *a, float scalar)

## Comparing numbers
- Two floats : use `|a - b| < e`, where e is a very small number like 0.0001 (`1e-4` in C)
- Comparing to infinity: use a very large number, like `1e10`

## Matrix operation (e.g. rotation) implementation
- Function pointers ? (`do_operation(func_pointer, target_matrix)` ?)

## Sphere ray intersection
- See equation in [Ray Tracing - Wikipedia](https://en.wikipedia.org/wiki/Ray_tracing_(graphics)#Example). N.b.: don't calculate negative value, which is behind us. How to determine which is negative value in advance ?
> If the quantity under the square root (the discriminant) is negative, then the ray does not intersect the sphere. 
- Angle of reflection == -(angle of incidence between the incident ray and the normal to the sphere)
- normal to the sphere: (incidence_point - sphere_center) / norm(incidence_point - sphere_center)
See [Euclidian Norm](https://en.wikipedia.org/wiki/Euclidean_space#Euclidean_norm)
and [Dot product - geometric interpretation (video) (14min)](https://www.youtube.com/watch?v=LyGKycYT2v0)
(n.b.: normal doesn't seem to depend at all on angle of light ray; only the intersection point on the sphere)


## New C syntax/tools
- Tagged union ?
- Typecast structs ? (like cdorig's minishell)
```c
struct s_cmd {
	int type;
}	t_cmd;

struct s_pipe {
	int type;
	fdjdffd
	fddff
}	t_pipe;
struct s_redir {
	int type;
	ddff
}	t_redir;

struct s_exec {
	int type;
	dffdjdfd
	dffdfgf
}	t_exec;


// first, malloc as t_pipe, t_redir, t_exec;
// then typecast as t_cmd to use them indifferently
// then, re-typecast as t_pipe, t_redir, or t_exec as necessary, and data is still there as it hasn't been freed

void	function(int type, t_cmd *command)
{
	if (type == PIPE)
		make_pipe_node((t_pipe *) command)
	// ...
}
```