# MiniRT - general project to-do list

## Proposed project task decomposition
- Setup Minilibx => pberset
- Input handling + parsing => pberset
	- clear main leaks (i.e. free(scene)) => 07.03 noch nicht
	- Do not malloc missing objects => 07.03 noch nicht
	- Error on object without stats => 07.03 noch nicht
- Implement Tuples, points, vectors (chapter 1 RT Challenge) => fallan
- Implement color operations (chapter 2 RT Challenge) => pberset (needed only hadamard in addition to tuple operations)
- Implement matrices and matrix operations (chapter 3 RT Challenge) => fallan
- Matrix transformations (chapter 4 RT Challenge) => fallan
	- Translation and scaling => pberset
	- Rotation and shearing => fallan
- Ray-Sphere intersections (chapter 5 RT Challenge) => pberset
- Light and shading (chapter 6 RT Challenge) => fallan
- Making a scene: implement world, view transformation (matrix transformation), camera (chapter 7 RT Challenge)
- Shadows (chapter 8 RT Challenge) => fallan
- Planes (chapter 9 RT Challenge) => pberset
- Cylinders (chapter 13 RT Challenge) => pberset
