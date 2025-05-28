#include "miniRT.h"

t_object    rt_cylinder(t_tuple color)
{
    t_object    cylinder;

    cylinder.diameter = 2.0;
    cylinder.height = 1.0;
    cylinder.color = color;
    cylinder.material = rt_material(0.1, 0.9, 0.9, 200.0);
    cylinder.norm = rt_vector(0, 1, 0);
    cylinder.origin = rt_point(0, 0, 0);
    return (cylinder);
}

void		rt_print_cylinder(t_object cylinder)
{
    ft_printf("Cylinder %p\n", &cylinder);
    ft_printf("Diameter: %f\n", cylinder.diameter);
    ft_printf("Height: %f\n", cylinder.height);
    ft_printf("Origin:\n");
    rt_print_tuple(cylinder.origin);
    ft_printf("Normal vector:\n");
    rt_print_tuple(cylinder.norm);
    ft_printf("Normal color:\n");
    rt_print_tuple(cylinder.color);
    ft_printf("Material:\n");
    rt_print_material(cylinder.material);
    ft_printf("Transformation matrix:\n");
    rt_print_matrix(cylinder.transform);
}
