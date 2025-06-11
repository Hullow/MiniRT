#include "miniRT.h"

void	rt_print_tuple(t_tuple t)
{
	printf("x = %0.3f, y = %0.3f, z = %0.3f ", t.x, t.y, t.z);
	if (t.w == VECTOR)
		printf("of type VECTOR\n");
	if (t.w == POINT)
		printf("of type POINT\n");
	if (t.w == COLOR)
		printf("of type COLOR\n");
}

void	rt_print_matrix(t_matrix m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m.rows)
	{
		printf("row[%d]: | ", i);
		j = 0;
		while (j < m.columns)
		{
			printf("%f | ", m.cell[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	rt_print_cylinder(t_object cylinder)
{
	printf("Cylinder %p\n", &cylinder);
	printf("Radius: %f, ", cylinder.radius);
	printf("Height: %f, ", cylinder.max);
	printf("Origin: ");
	rt_print_tuple(cylinder.origin);
	printf("Normal vector: ");
	rt_print_tuple(cylinder.norm);
	printf("Color: ");
	rt_print_tuple(cylinder.color);
	printf("Material: ");
	rt_print_material(cylinder.material);
	printf("Transform:\n");
	rt_print_matrix(cylinder.transform);
}

void	rt_print_plane(t_object plane)
{
	printf("Plane %p\n", &plane);
	printf("Origin: ");
	rt_print_tuple(plane.origin);
	printf("Normal vector: ");
	rt_print_tuple(plane.norm);
	printf("Color: ");
	rt_print_tuple(plane.color);
	printf("Material: ");
	rt_print_material(plane.material);
	printf("Transform:\n");
	rt_print_matrix(plane.transform);
}

void	rt_print_sphere(t_object sphere)
{
	printf("Sphere %p\n", &sphere);
	printf("Radius: %f\n", sphere.radius);
	printf("Origin: ");
	rt_print_tuple(sphere.origin);
	printf("Color: ");
	rt_print_tuple(sphere.color);
	printf("Material: ");
	rt_print_material(sphere.material);
	printf("Transform:\n");
	if (sphere.transform.columns != 4 || sphere.transform.rows != 4)
		printf("Matrix size error: col: %d row: %d\n", sphere.transform.columns, sphere.transform.rows);
	else
		rt_print_matrix(sphere.transform);
}

void	rt_print_ray(t_ray ray)
{
	printf("Ray origin\n");
	rt_print_tuple(ray.origin);
	printf("Ray direction\n");
	rt_print_tuple(ray.direction);
}

void	rt_print_light(t_light light)
{
	printf("Light\ncoord:\n");
	rt_print_tuple(light.coord);
	printf("color:\n");
	rt_print_tuple(light.color);
	printf("intensity: %f\n", light.intensity);
	printf("Ambient intensity %f\n", light.ambient.ratio);
	printf("Ambient color\n");
	rt_print_tuple(light.ambient.color);
}

void	rt_print_material(t_material mat)
{
	printf("ambient: %f, diffuse: %f, specular: %f, shininess: %f\n", \
		mat.ambient, mat.diffuse, mat.specular, mat.shininess);
}

void	rt_print_camera(t_camera camera)
{
	printf("camera:\n");
	printf("Pixel size: %f\n", camera.pixel_size);
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
	printf("N_OBJ : %d\n", scene.n_obj);
	printf("\n");
	rt_print_light(scene.lux);
	printf("\n");
	rt_print_camera(scene.cam);
	printf("\n");
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
		printf("\n");
		i++;
	}
}
