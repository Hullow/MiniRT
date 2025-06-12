# Problems

## Acne on rotated plane
- commit f61158bc13cee0da8898bc871ef0ca3b416cf1a8 (Problems: note - render-worked)
- scenePlane.rt:
```
L   0,5,-10                        0.7 255,255,255
A   0.2                            0,255,0
C   0.0,0.0,-5       0,0,1           70
pl  0,0,5          -0.8,0,-0.8     255,0,0

(even worse with pl  0,0,5          -0.8,0.8,-0.8     255,0,0)
```

## NULL orientation vector 
- Never checked
- fix found `Add a check for 3 null values in parsed norm`
in `rt_validate_input.c`
```c
static int	is_null_vector(char **orient)
{
	return (!ft_strtof(*orient) && !ft_strtof(*(orient + 1)) \
		&& !ft_strtof(*(orient + 2)));
}

int	rt_valid_orient(char **orient)
{
	int		i;
	float	ver;

	i = 3;
	errno = 0;
	if (is_null_vector(orient))
		return (rt_handle_error(RT_VALID_ORIENT, EINVAL, "Null Orient"), 0);
		/* rest of code */
}
```

## Cylinder translation doesn´t match
- commit f61158bc13cee0da8898bc871ef0ca3b416cf1a8 (Problems: note - render-worked)
-fix found `default cylinder located at 0,0,0`:
in `rt_assign_objects.c`
```c
//Then:
	cylinder->max = cylinder.origin.y + ft_strtof(*(needle + 3)) / 2;
	cylinder->min = cylinder.origin.y - ft_strtof(*(needle + 3)) / 2;

//Now:
	cylinder->max = ft_strtof(*(needle + 3)) / 2;
	cylinder->min = -ft_strtof(*(needle + 3)) / 2;
```
