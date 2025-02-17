# MiniRT - Implementation considerations

- Normal vector: depends on point of object (sphere, plane, cylinder) ?

## Sphere ray intersection
- See equation in [Ray Tracing - Wikipedia](https://en.wikipedia.org/wiki/Ray_tracing_(graphics)#Example). N.b.: don't calculate negative value, which is behind us. How to determine which is negative value in advance ?
> If the quantity under the square root (the discriminant) is negative, then the ray does not intersect the sphere. 
- Angle of reflection == -(angle of incidence between the incident ray and the normal to the sphere)
- normal to the sphere: (incidence_point - sphere_center) / norm(incidence_point - sphere_center)
See [Euclidian Norm](https://en.wikipedia.org/wiki/Euclidean_space#Euclidean_norm)
and [Dot product - geometric interpretation (video) (14min)](https://www.youtube.com/watch?v=LyGKycYT2v0)
(n.b.: normal doesn't seem to depend at all on angle of light ray; only the intersection point on the sphere)