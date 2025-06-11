Your ray tracer is really starting to come together. Just look at it! You’ve got
spheres,  realistic  shading,  a  powerful  camera,  and  a  world  that  supports
scenes with many objects.
It’s a pity those objects don’t cast shadows, though. Shadows add a delightful
dash of realism to a scene. Check out the following figure which shows the
same scene both with and without shadows:
Your brain uses those shadows as cues for depth perception. Without shadows,
the image looks artificial and shallow, and that will never do.
Thus, the time has come to add shadows, and the best part is that you’ve
already written most of the infrastructure to support this. The first step is to
adjust your lighting() function to handle the case where a point is in shadow.
Then you’ll implement a new method for determining whether a point is in
shadow  or  not,  and  last  you’ll  tie  those  pieces  together  so  your  ray  tracer
actually renders the shadows.
Let’s dig into it!
report erratum  •  discuss
Lighting in Shadows
Given  some  point,  you  can  know  that  it  lies  in  shadow  if  there  is  another
object sitting between it and the light source, as shown in the following figure.
The light source is unable to contribute anything to that point. Take a moment
and recall how your lighting() function works, from The Phong Reflection Model,
on page 83. The diffuse component relies on the vector to the light source, and
the specular component depends on the reflection vector. Since both components
have a dependency on the light source, the lighting() function should ignore them
when the point is in shadow and use only the ambient component.
Add the following test to the others you wrote for the lighting() function. It’s
identical to the one titled “Lighting with the eye between the light and the
surface” on page 86, where the specular and diffuse components were both
at their maximum values, but this time you’re going to pass a new argument
to the lighting() function indicating that the point is in shadow. It should cause
the diffuse and specular components to be ignored, resulting in the ambient
value alone contributing to the lighting.
(Recall that the m and position variables being passed to the lighting() function
are defined in the “Background” block on page 86.)
features/materials.feature
Scenario: Lighting with the surface in shadow
Given eyev ← vector(0, 0, -1)
And normalv ← vector(0, 0, -1)
And light ← point_light(point(0, 0, -10), color(1, 1, 1))
And in_shadow ← true
When result ← lighting(m, light, position, eyev, normalv, in_shadow)
Then result = color(0.1, 0.1, 0.1)
You may need to fix your other tests to accommodate the addition of that new
parameter. Go ahead and address that, and then make this new test pass as
well by making your lighting() function ignore the specular and diffuse compo-
nents when in_shadow is true.
Chapter 8. Shadows • 110
report erratum  •  discuss
Once things are all passing again, let’s teach your ray tracer how to tell when
a point is in shadow.
Testing for Shadows
A ray tracer computes shadows by casting a ray, called a shadow ray, from each
point of intersection toward the light source. If something intersects that shadow
ray between the point and the light source, then the point is considered to be
in shadow. You’re going to write a new function, is_shadowed(world,point), which will
do just this.
Implement the following four tests, which demonstrate four different scenarios.
Each assumes the existence of the default world that was defined in Building
a World, on page 92.
In the first test, the world is set up like the following figure.
Nothing at all lies along the line connecting the point and the light source,
and the point should therefore not be in shadow.
features/world.feature
Scenario: There is no shadow when nothing is collinear with point and light
Given w ← default_world()
And p ← point(0, 10, 0)
Then is_shadowed(w, p) is false
In the second test, the point is placed on the far side of the default world’s
spheres, putting them between it and the light source, like this:
report erratum  •  discuss
Testing for Shadows • 111
The point should be in the shadow cast by the spheres.
features/world.feature
Scenario: The shadow when an object is between the point and the light
Given w ← default_world()
And p ← point(10, -10, 10)
Then is_shadowed(w, p) is true
The next test positions the point so the light lies between it and the spheres.
Once again, the point should not be in shadow, because nothing lies between
the point and the light.
features/world.feature
Scenario: There is no shadow when an object is behind the light
Given w ← default_world()
And p ← point(-20, 20, -20)
Then is_shadowed(w, p) is false
The last test is similar, but it positions the point to lie between the light and
the spheres, like this:
And again, even in this configuration nothing lies between the light and the
point, so the point is still not shadowed.
features/world.feature
Scenario: There is no shadow when an object is behind the point
Given w ← default_world()
And p ← point(-2, 2, -2)
Then is_shadowed(w, p) is false
Chapter 8. Shadows • 112
report erratum  •  discuss
The algorithm for is_shadowed() goes like this:
1. Measure  the  distance  from  point  to  the  light  source  by  subtracting  point
from the light position, and taking the magnitude of the resulting vector.
Call this distance.
2. Create a ray from point toward the light source by normalizing the vector
from step 1.
3. Intersect the world with that ray.
4. Check to see if there was a hit, and if so, whether t is less than distance. If
so, the hit lies between the point and the light source, and the point is in
shadow.
In pseudocode it might look like this:
function is_shadowed(world, point)
v ← world.light.position - point
distance ← magnitude(v)
direction ← normalize(v)
r ← ray(point, direction)
intersections ← intersect_world(world, r)
h ← hit(intersections)
if h is present and h.t < distance
return true
else
return false
end if
end function
Recall from Identifying Hits, on page 64, that the hit() function returns the
intersection with the lowest nonnegative t value. Thus, the hit’s t will never
be negative, so you don’t need to worry about checking for intersections that
occur behind the point.
Implement that function, make those tests pass, and then move on. Just one
more thing needs changing to actually render those shadows!
Rendering Shadows
The final bit to actually render the shadows requires a small change to your
shade_hit()  function  from  Building  a  World,  on  page  92.  You  need  to  check
whether the point is in shadow or not, and then pass that state to your lighting()
function.
Add the following test to those that you wrote for the shade_hit() function. To
demonstrate the case where some object is shadowing the point of intersection,
it creates a world and two spheres, and positions a light so that the second
report erratum  •  discuss
Rendering Shadows • 113
sphere is in the shadow of the first. Then, a ray and an intersection are cre-
ated such that the point of intersection is in the shadow. The shade_hit() function
should return only the ambient color of the second sphere in this case.
features/world.feature
Scenario: shade_hit() is given an intersection in shadow
Given w ← world()
And w.light ← point_light(point(0, 0, -10), color(1, 1, 1))
And s1 ← sphere()
And s1 is added to w
And s2 ← sphere() with:
| transform | translation(0, 0, 10) |
And s2 is added to w
And r ← ray(point(0, 0, 5), vector(0, 0, 1))
And i ← intersection(4, s2)
When comps ← prepare_computations(i, r)
And c ← shade_hit(w, comps)
Then c = color(0.1, 0.1, 0.1)
Now,  making  this  test  pass  may  seem  to  be  merely  a  matter  of  taking  the
point of intersection and sending it directly to the is_shadowed() function. But
if you do this, you’re liable to wind up with a rendered picture that looks like
it’s been attacked by fleas, as in the following figure.
This effect is called acne, and it happens because computers cannot represent
floating point numbers very precisely. In general they do okay, but because
of rounding errors, it will be impossible to say exactly where a ray intersects
a surface. The answer you get will be close—generally within a tiny margin
of error—but that wiggle is sometimes just  enough to cause the calculated
point of intersection to lie beneath the actual surface of the sphere.
Chapter 8. Shadows • 114
report erratum  •  discuss
As a result, the shadow ray intersects the sphere itself, causing the sphere
to cast a shadow on its own point of intersection. This is obviously not ideal.
The solution is to adjust the point just slightly in the direction of the normal,
before you test for shadows. This will bump it above the surface and prevent
self-shadowing.
Add the following test, which sets up a sphere and an intersection such that
the intersection occurs at z=0. After calling the prepare_computations() function
you wrote in Chapter 7, Making a Scene, on page 91, there should be a new
attribute, over_point, which will be almost identical to point, with the z component
slightly less than z=0.
features/intersections.feature
Scenario: The hit should offset the point
Given r ← ray(point(0, 0, -5), vector(0, 0, 1))
And shape ← sphere() with:
| transform | translation(0, 0, 1) |
And i ← intersection(5, shape)
When comps ← prepare_computations(i, r)
Then comps.over_point.z < -EPSILON/2
And comps.point.z > comps.over_point.z
Note that the test compares the over_point’s z component to half of -EPSILON to
make sure the point has been adjusted in the correct direction.
In pseudocode, your prepare_computations() function will need to do something
like this:
# after computing and (if appropriate) negating
# the normal vector...
comps.over_point ← comps.point + comps.normalv * EPSILON
EPSILON is the tiny number discussed in Comparing Floating Point Numbers,
on page 5, and is used here to bump the point just a bit in the direction of
the normal.
Next, modify your shade_hit() function so that it invokes is_shadowed() with the
hit’s newly offset over_point attribute, and then call the lighting() function (again
with over_point) with the result. It’ll look like this in pseudocode:
function shade_hit(world, comps)
shadowed ← is_shadowed(world, comps.over_point)
return lighting(comps.object.material,
world.light,
comps.over_point, comps.eyev, comps.normalv,
shadowed)
end function
report erratum  •  discuss
Rendering Shadows • 115
Go ahead and make that change to your shade_hit() function and make sure
your tests are all passing. Once they are, it’ll be time to wrap this chapter up
and render some shadows!