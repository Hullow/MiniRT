# Mini Ray Tracer 42 Lausanne
## Scene file formatting
### File extension

The Scene file is a text file with ".rt" extension. Example: `scene.rt`

### Scene objects
There are only six defined objects: Camera (C), point light (L), ambient light (A), sphere (sp), plane (pl) and cylinder (cy). Objects are defined by the abreviation given in parenthesis.

C, L and A are unique objects. The Scene can contain only one of each.
sp, pl, cy may exist in any amount, up to 100 total objects in the scene. The reason behind this limitation is performance. The rules for building the base project does not allow for multithreading and other optimisation methods. The 42 Norm, libmlx and pedagogical constraints do rise other barriers to an unlimited amount of objects.

### `t_tuple` Data structure
The user should be familiar with the `t_tuple` data structure. It is defined as such:
```c
typedef struct s_tuple
{
    float   x;
    float   y;
    float   z;
    t_type  w;
}   t_tuple;
```
`t_type` is an enum that help identify the type of tuple we are dealing with. It is defined as such:
```c
typedef enum e_type
{
    VECTOR,
    POINT,
    COLOR
}   t_type;
```
If the `t_type` is `COLOR`, the user must specify values as `int` from the interval `[0-255]`.

### Define objects
#### Camera
#### Point light
#### Ambient light
#### Sphere
A sphere is defined by its identifier (`char *`), center coordinates (`t_tuple`), diameter (`float`), color (`t_tuple`). All parameters shall be defined in this specific order on one single line. separated by spaces. `t_tuple` values are comma separated without spaces.
Of course, the diameter shall be greater than 0.
Summary: `(char*) (t_tuple)POINT (float) (t_tuple)COLOR`
Example: `sp 3.4,1.0,255 42.24 255,6,234`

#### Plane
#### Cylinder
