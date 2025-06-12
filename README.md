# MiniRT
Project done at [Ecole 42 Lausanne](https://42lausanne.ch/), by PBerset ([@Sukori](https://github.com/Sukori)) and FAllan ([@Hullow](https://github.com/Hullow)).

## Description
A raytracing rendering engine in C using 42's [minilibX](https://github.com/42paris/minilibx-linux) graphical library.

The program takes in an input [scene](/Sources/scenes/), which can contain spheres, cylinders and planes, and has a defined camera position. The minilibx handles windows and the drawing of pixels.

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
A camera is defined by its identifier (`char *`), origin coordinates (`t_tuple`), direction vector (`t_tuple`) and field of view (`float`). All parameters shall be defined in this specific order on one single line. separated by spaces. `t_tuple` values are comma separated without spaces.

Summary: `(char*) (t_tuple)POINT (t_tuple)VECTOR (float)`

Example: `C -50.0,0,20 0,0,1 70`

#### Point light
A point light is defined by its identifier (`char *`), origin coordinates (`t_tuple`), intensity value (`float`) and color (`t_tuple`). All parameters shall be defined in this specific order on one single line. separated by spaces. `t_tuple` values are comma separated without spaces.

Summary: `(char*) (t_tuple)POINT (float) (t_tuple)COLOR`

Example: `L -40.0,50.0,0.0 0.6 10,0,255`

#### Ambient light
An ambient light is defined by its identifier (`char *`), intensity value (`float`) and color (`t_tuple`). All parameters shall be defined in this specific order on one single line. separated by spaces. `t_tuple` values are comma separated without spaces.

Summary: `(char*) (float) (t_tuple)COLOR`

Example: `A 0.2 255,255,255`

#### Sphere
A sphere is defined by its identifier (`char *`), center coordinates (`t_tuple`), diameter (`float`), color (`t_tuple`). All parameters shall be defined in this specific order on one single line. separated by spaces. `t_tuple` values are comma separated without spaces.

Summary: `(char*) (t_tuple)POINT (float) (t_tuple)COLOR`

Example: `sp 3.4,1.0,255 42.24 255,6,234`

#### Plane
A plane is defined by its identifier (`char *`), one point coordinates (`t_tuple`), the normal vector (`t_tuple`) and color (`t_tuple`). All parameters shall be defined in this specific order on one single line. separated by spaces. `t_tuple` values are comma separated without spaces.

Summary: `(char*) (t_tuple)POINT (t_tuple)VECTOR (t_tuple)COLOR`

Example: `pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,255`

#### Cylinder
A cylinder is defined by its identifier (`char *`), center coordinates (`t_tuple`), the normal vector (`t_tuple`), diameter (`float`), height (`float`) and color (`t_tuple`). All parameters shall be defined in this specific order on one single line. separated by spaces. `t_tuple` values are comma separated without spaces.

Summary: `(char*) (t_tuple)POINT (t_tuple)VECTOR (float) (float) (t_tuple)COLOR`

Example: `cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255`

#### Example scene
```rt
L  -10.0,10.0,-16.0     0.6                   255,255,255
A  0.2                                        255,255,255
C  0,3.5,-7             0,-0.5,1              60

sp  -0.5,1,0.5          2                     25,255,127
sp  1.5,0.5,-0.5        1                     255,0,10
sp  -1.5,2,-0.75        0.67                  10,0,255

pl  0,0,0               0.0,1.0,0.0           255,230,230
pl  0,0,5               -0.7071,0.0,0.7071    255,230,230
pl  0,0,5               0.7071,0.0,0.7071     255,230,230

cy  3,0,-2              -0.5,1,0    1    2    100,100,255
```