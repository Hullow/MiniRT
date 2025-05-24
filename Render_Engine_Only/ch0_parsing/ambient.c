effective_color = material.color * light.intensity

ambient = effective_color * material.ambient (--> float)


t_tuple ambient_final = effective_color * material.ambient.color
