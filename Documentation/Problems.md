# Problems

## Fixed (12-6-18:28)

## Weird triangle on plane
==> seems fixed with `local_normal_at()`:
```c
	else if (obj.shape == PLANE)
		normal = rt_vector(0,1,0);
```
- commit ID: e9a23afbc4fb70 ("Fix: acne (playing with EPSILON)")
- SceneWall-bug.rt:
```
L  -10.0,10.0,-16.0     0.6                  255,255,255
A  0.2                                       255,255,255
C  7,3.5,-7            -0.9,-0.1,1      60

pl  0,0,5               -0.7071,0.0,0.7071   255,230,230
pl  0,0,5               0.7071,0.0,0.7071    255,230,230
pl  0,0,0               0.0,1.0,0.0          255,230,230
```

### Weird triangle on plane + acne
- commit ID: 1c27ca5f1a9ad9 ("Fix acne" - render-worked)
- SceneExample with:
```
L  -50.0,10.0,-46.0     0.6                  255,255,255
A  0.3                                       255,255,255
C  7.5,3.5,-7            -0.9,-0.5,1      60

sp  -0.5,1,0.5          2                    25,255,127
sp  1.5,0.5,-0.5        1                    255,0,10
sp  -1.5,2,-0.75        0.67                 10,0,255

pl  0,0,0               0.0,1.0,0.0          255,230,230
pl  0,0,5               -0.8,0.0,0.7071   255,230,230
pl  0,0,5               0.7071,0.0,0.7071    255,230,230

cy  3,0,-2              -0.5,1,0   1    2    100,100,255
```


### acne (lots) on shadow of large sphere + weird triangle/whiter part of plane
- SceneExample with only one plane and rotated camera
```
L  -10.0,10.0,-16.0     0.6                  255,255,255
A  0.2                                       255,255,255
C  7,3.5,-7            -0.5,-0.5,1      60

sp  -0.5,1,0.5          2                    25,255,127
sp  1.5,0.5,-0.5        1                    255,0,10
sp  -1.5,2,-0.75        0.67                 10,0,255

pl  0,0,5               -0.7071,0.0,0.7071   255,230,230

cy  3,0,-2              -0.5,1,0   1    2    100,100,255
```