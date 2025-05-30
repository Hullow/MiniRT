#include "miniRT.h"

void	rt_print_tuple(t_tuple t)
{
	ft_printf("x = %f y = %f z = %f ", t.x, t.y, t.z);
	if (t.w == VECTOR)
		ft_printf("of type VECTOR\n");
	if (t.w == POINT)
		ft_printf("of type POINT\n");
	if (t.w == COLOR)
		ft_printf("of type COLOR\n");
}

void	rt_print_matrix(t_matrix m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m.rows)
	{
		ft_printf("row[%d]: | ", i);
		j = 0;
		while (j < m.columns)
		{
			ft_printf("%f | ", m.cell[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	rt_print_cylinder(t_object cylinder)
{
	ft_printf("Cylinder %p\n", &cylinder);
	ft_printf("Diameter: %f, ", cylinder.diameter);
	ft_printf("Height: %f, ", cylinder.height);
	ft_printf("Origin: ");
	rt_print_tuple(cylinder.origin);
	ft_printf("Normal vector: ");
	rt_print_tuple(cylinder.norm);
	ft_printf("Color: ");
	rt_print_tuple(cylinder.color);
	ft_printf("Material: ");
	rt_print_material(cylinder.material);
	ft_printf("Transform:\n");
	rt_print_matrix(cylinder.transform);
}

void	rt_print_plane(t_object plane)
{
	ft_printf("Plane %p\n", &plane);
	ft_printf("Origin: ");
	rt_print_tuple(plane.origin);
	ft_printf("Color: ");
	rt_print_tuple(plane.color);
	ft_printf("Material: ");
	rt_print_material(plane.material);
	ft_printf("Transform:\n");
	rt_print_matrix(plane.transform);
}

void	rt_print_sphere(t_object sphere)
{
	ft_printf("Sphere %p\n", &sphere);
	ft_printf("Diameter: %f\n", sphere.diameter);
	ft_printf("Origin: ");
	rt_print_tuple(sphere.origin);
	ft_printf("Color: ");
	rt_print_tuple(sphere.color);
	ft_printf("Material: ");
	rt_print_material(sphere.material);
	ft_printf("Transform:\n");
	rt_print_matrix(sphere.transform);
}

void	rt_print_ray(t_ray ray)
{
	ft_printf("Ray origin\n");
	rt_print_tuple(ray.origin);
	ft_printf("Ray direction\n");
	rt_print_tuple(ray.direction);
}

void	rt_print_light(t_light light)
{
	ft_printf("Light\ncoord:\n");
	rt_print_tuple(light.coord);
	ft_printf("color:\n");
	rt_print_tuple(light.color);
	ft_printf("intensity: %f\n", light.intensity);
}

void	rt_print_material(t_material mat)
{
	printf("ambient: %f, diffuse: %f, specular: %f, shininess: %f\n", \
		mat.ambient, mat.diffuse, mat.specular, mat.shininess);
}

void	rt_print_camera(t_camera camera)
{
	printf("camera:\n");
	printf("- hsize: %d\n", camera.hsize);
	printf("- vsize: %d\n", camera.vsize);
	printf("- field of view: %f\n", camera.field_of_view);
	printf("- transform:\n");
	rt_print_matrix(camera.transform);
}

void	rt_print_scene(t_scene scene)
{
	int	i;

	i = 0;
	while (i < scene.n_obj)
	{
		if (scene.objects[i].shape == SPHERE)
		{
			rt_print_sphere(scene.objects[i]);
		}
		else if (scene.objects[i].shape == PLANE)
		{
			rt_print_plane(scene.objects[i]);
		}
		else if (scene.objects[i].shape == CYLINDER)
		{
			rt_print_cylinder(scene.objects[i]);
		}
		ft_printf("\n");
		i++;
	}
}
