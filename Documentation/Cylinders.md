# Ray-Tracer Challenge 
CHAPTER 13
Cylinders
Next  up  is  the  mighty  cylinder.  It  plays  nicely  with  your  existing  suite  of
graphics primitives, and it’s fantastic for representing all sorts of things: arms,
legs,  necks,  fingers,  and  torsos,  as  well  as  columns,  pipes,  and  table  legs.
Here’s an example of cylinders in various configurations to give you a taste
of how versatile this shape can be:
As with all your other shapes, you’ll use cylinders by instantiating them at
the origin and then transforming them into the size and position you need.
For convenience, you’ll give the cylinders a default radius of 1, but the way
the math works out they’ll all be infinitely long, extending to infinity in both
+y and -y. Since trying to do anything useful with an infinitely long cylinder
is tricky, you’ll also implement controls to allow your cylinders to be truncated
at one or both ends, and to be either open or capped.
report erratum  •  discuss
You’ll tackle all of this in a few steps:
1. Implement  the  basic  intersection  algorithm  for  an  infinite  cylinder  of
radius 1.
2. Compute the normal vector for a cylinder.
3. Add support for truncating the cylinder. By default, a truncated cylinder
is open, or hollow.
4. Add support for end caps, to allow the cylinder to be closed, or solid.
5. Compute the normal vector on the end caps.
Lastly, as a bonus, you’ll see, briefly, how to intersect a ray with a cone, the
algorithm for which just happens to be very similar to that of a cylinder.
Are you ready for this? Here goes!
Intersecting a Ray with a Cylinder
Either  the  ray  misses  the  cylinder  or  it  hits  the  cylinder.  Right?  This
dichotomy neatly describes the tests you’ll write first. You’ll start by confirming
that a ray misses a cylinder. Such tests can be made to pass trivially, but
rather  than  passing  them  by  making  your  local_intersect  method  do  nothing,
this provides a good opportunity to start actually implementing the intersection
routines.
Test #1: A Ray Misses a Cylinder
Show that the local_intersect() function correctly identifies when a ray misses a
cylinder.
This test creates a cylinder and casts three different rays at it. The first ray
is  positioned  on  the  surface  and  points  along  the  +y  axis,  parallel  to  the
cylinder. The second is inside the cylinder and also points along the +y axis.
The third ray is positioned outside the cylinder and oriented askew from all
axes. All three should miss the cylinder.
features/cylinders.feature
Scenario Outline: A ray misses a cylinder
Given cyl ← cylinder()
And direction ← normalize(<direction>)
And r ← ray(<origin>, direction)
When xs ← local_intersect(cyl, r)
Then xs.count = 0

Examples:
| origin | direction |
| point(1, 0, 0) | vector(0, 1, 0) |
| point(0, 0, 0) | vector(0, 1, 0) |
| point(0, 0, -5) | vector(1, 1, 1) |
The algorithm that implements this shares some features with the ray-sphere
intersection algorithm on page 57. As with the sphere algorithm, you’ll com-
pute a discriminant value, which will be negative if the ray does not intersect.
Here’s some pseudocode:
function local_intersect(cylinder, ray)
a ← ray.direction.x² + ray.direction.z²
# ray is parallel to the y axis
return () if a is approximately zero
b ← 2 * ray.origin.x * ray.direction.x +
2 * ray.origin.z * ray.direction.z
c ← ray.origin.x² + ray.origin.z² - 1
disc ← b² - 4 * a * c
# ray does not intersect the cylinder
return () if disc < 0
# this is just a placeholder, to ensure the tests
# pass that expect the ray to miss.
return ( intersection(1, cylinder) )
end function
Note that the last line of the function, returning a single intersection at t=1,
ensures that the tests pass because the ray truly misses the cylinder and not
simply because the function wasn’t doing anything else. You’ll flesh that bit
out next, in test #2.
Test #2: A Ray Hits a Cylinder
Show  that  the  local_intersect()  function  correctly  identifies  when  a  ray  hits  a
cylinder.
Once again, the scenario outline creates three different rays, each of which
is  expected  to  intersect  the  cylinder.  The  first  is  configured  to  strike  the
cylinder on a tangent, but even though the actual intersection is at a single
point, you’ll still make your code return two intersections, both at t=5. (This
mimics  how  you  handled  tangent  intersections  in  Chapter  5,  Ray-Sphere
Intersections, on page 57, and will help with determining object overlaps in
Chapter 16, Constructive Solid Geometry (CSG), on page 227.) The second ray
report erratum  •  discuss
Intersecting a Ray with a Cylinder • 179
intersects the cylinder perpendicularly through the middle and results in two
intersections at 4 and 6. The last ray is skewed so that it strikes the cylinder
at an angle.
features/cylinders.feature
Scenario Outline: A ray strikes a cylinder
Given cyl ← cylinder()
And direction ← normalize(<direction>)
And r ← ray(<origin>, direction)
When xs ← local_intersect(cyl, r)
Then xs.count = 2
And xs[0].t = <t0>
And xs[1].t = <t1>
Examples:
| origin | direction | t0 | t1 |
| point(1, 0, -5) | vector(0, 0, 1) | 5 | 5 |
| point(0, 0, -5) | vector(0, 0, 1) | 4 | 6 |
| point(0.5, 0, -5) | vector(0.1, 1, 1) | 6.80798 | 7.08872 |
Make this pass by using the discriminant to find the t values for the points
of intersection. The highlighted lines in the following pseudocode demonstrate
the calculation you need:
function local_intersect(cylinder, ray)
a ← ray.direction.x² + ray.direction.z²
# ray is parallel to the y axis
return () if a is approximately zero
b ← 2 * ray.origin.x * ray.direction.x +
2 * ray.origin.z * ray.direction.z
c ← ray.origin.x² + ray.origin.z² - 1
disc ← b² - 4 * a * c
# ray does not intersect the cylinder
return () if disc < 0
t0 ← (-b - √(disc)) / (2 * a)➤
t1 ← (-b + √(disc)) / (2 * a)➤
➤
return ( intersection(t0, cylinder), intersection(t1, cylinder) )➤
end function
All that’s left before you can actually render this cylinder is to compute the
normal vector.
Finding the Normal on a Cylinder
Once you know the points of intersection, the normal vector is used to help
shade the surface appropriately. You’ll only need one scenario to cover this bit

Test #3: Normal Vector on a Cylinder
Show that the normal vector on the surface of a cylinder is computed correctly.
This scenario chooses four points on the surface of the cylinder, one each at
+x,  -x,  +z  and  -z,  and  shows  that  the  normal  is  the  expected  value  at  each
point.
features/cylinders.feature
Scenario Outline: Normal vector on a cylinder
Given cyl ← cylinder()
When n ← local_normal_at(cyl, <point>)
Then n = <normal>
Examples:
| point | normal |
| point(1, 0, 0) | vector(1, 0, 0) |
| point(0, 5, -1) | vector(0, 0, -1) |
| point(0, -2, 1) | vector(0, 0, 1) |
| point(-1, 1, 0) | vector(-1, 0, 0) |
To accomplish this, take the point in question and remove the y component.
Treating the result as a vector gives you the normal. In pseudocode, it looks
like this:
function local_normal_at(cylinder, point)
return vector(point.x, 0, point.z)
end function
With  those  tests  passing,  your  ray  tracer  can  render  cylinders!  They’ll  be
infinitely long, which might be a bit unwieldy, but with a bit of imagination
you can do all kinds of interesting things with them. Give it a try! When you
come back, we will look at truncating those cylinders to make them easier
to use.
Truncating Cylinders
Imagine  a  world  where  table  legs  stretch  forever  in  both  directions,  where
pencils can never be sharpened because they have no end, and where cars
roll around on wheels that are infinitely wide. What a mess! Perhaps Salvador
Dalí could make something out of that, but for the rest of us, such cylinders
are  hard  to  use  well.  To  make  them  more  useful  you  can  truncate  them,
chopping them off at one or both ends.
For  your  ray  tracer,  you’ll  implement  truncated  cylinders  by  permitting  a
minimum and a maximum y value to be given for each cylinder. For example,
the cylinder only exists between y=-1 and y=2 as shown in the figure on page 182.
report erratum  •  discuss
Truncating Cylinders • 181
Note that the extents are exclusive, meaning if the cylinder is truncated at
y=2, the cylinder extends up to—but not including—that limit.
You’ll need just two tests for this feature: one that adds the new attributes
and one that updates the intersection logic to support the truncated cylinders.
Start with the new attributes.
Test #4: Minimum and Maximum Bounds
Demonstrate the default values for a cylinder’s minimum and maximum bounds.
This scenario creates a new cylinder and shows that the minimum defaults
to negative infinity and the maximum defaults to positive infinity.
features/cylinders.feature
Scenario: The default minimum and maximum for a cylinder
Given cyl ← cylinder()
Then cyl.minimum = -infinity
And cyl.maximum = infinity
The  minimum  and  maximum  always  refer  to  units  on  the  y  axis  and  are
defined in object space. The next test shows how you use these attributes to
actually truncate a cylinder.
Test #5: Truncated Cylinders
Show that the cylinders in your ray tracer can be truncated at either end.
This scenario sets up a cylinder, truncates it at y=1 and y=2, and then casts
several rays at it in order to make sure that the truncated cylinder is being
intersected correctly.
features/cylinders.feature
Scenario Outline: Intersecting a constrained cylinder
Given cyl ← cylinder()
And cyl.minimum ← 1
Chapter 13. Cylinders • 182
report erratum  •  discuss
And cyl.maximum ← 2
And direction ← normalize(<direction>)
And r ← ray(<point>, direction)
When xs ← local_intersect(cyl, r)
Then xs.count = <count>
Examples:
| | point | direction | count |
| 1 | point(0, 1.5, 0) | vector(0.1, 1, 0) | 0 |
| 2 | point(0, 3, -5) | vector(0, 0, 1) | 0 |
| 3 | point(0, 0, -5) | vector(0, 0, 1) | 0 |
| 4 | point(0, 2, -5) | vector(0, 0, 1) | 0 |
| 5 | point(0, 1, -5) | vector(0, 0, 1) | 0 |
| 6 | point(0, 1.5, -2) | vector(0, 0, 1) | 2 |
Specifically, the examples cast the following rays:
• Example 1 casts a ray diagonally from inside the cylinder, with the ray
escaping without intersecting the cylinder.
• Examples 2 and 3 cast rays perpendicularly to the y axis, but from above
and below the cylinder, and also miss.
• Examples 4 and 5 are edge cases, showing that the minimum and maxi-
mum y values are themselves outside the bounds of the cylinder.
• The final example casts a ray perpendicularly through the middle of the
cylinder and produces two intersections.
The following figure shows how the scene is configured, with the correspond-
ing rays:
To make this work, change your local_intersect method so that it computes the
y coordinate at each point of intersection. If the y coordinate is between the
minimum  and  maxmium  values,  then  the  intersection  is  valid.  The  following
pseudocode shows how this comes together:
report erratum  •  discuss
Truncating Cylinders • 183
t0 ← (-b - √(disc)) / (2 * a)
t1 ← (-b + √(disc)) / (2 * a)
if t0 > t1 then swap(t0, t1)
xs = ()➤
➤
y0 ← ray.origin.y + t0 * ray.direction.y➤
if cylinder.minimum < y0 and y0 < cylinder.maximum➤
add intersection(t0, cylinder) to xs➤
end if➤
➤
y1 ← ray.origin.y + t1 * ray.direction.y➤
if cylinder.minimum < y1 and y1 < cylinder.maximum➤
add intersection(t1, cylinder) to xs➤
end if➤
➤
return xs➤
With that change, your tests should all be passing. Next up: solid cylinders!
Capped Cylinders
If you’ve played with your new truncated cylinders at all, you’ll have noticed
that they’re hollow, like lengths of PVC pipe or empty toilet paper rolls. This
can be exactly the effect you need sometimes, but at other times you really
want the cylinders to be capped, or closed at each end. To do that, you need
to add end caps—discs that exactly cover each end of the cylinder.
These discs are planes that are constrained to the cylinder’s cross-section—and
you implemented planes way back in Chapter 9, Planes, on page 117. While
you can’t exactly reuse your plane code for this, the concepts will (hopefully!)
look familiar.
You’ll add end caps to your cylinders in three steps:
1. Add a closed attribute to your cylinders, indicating that the cylinders should
be capped.
2. Update your cylinder’s local_intersect method to add checks for the top and
bottom end caps (if closed is true).
3. Update  your  cylinder’s  local_normal_at  method  to  compute  the  normal  on
the end caps (again, if closed is true).
First, the closed attribute.
Test #6: Closed Cylinders
Show that your cylinders possess a closed attribute, which defaults to false.
Set up a new cylinder and show that the closed attribute is false, by default.
Chapter 13. Cylinders • 184
report erratum  •  discuss
features/cylinders.feature
Scenario: The default closed value for a cylinder
Given cyl ← cylinder()
Then cyl.closed = false
Make  that  pass,  and  then  you  can  move  on  to  updating  the  intersection
algorithm.
Test #7: Intersecting a Cylinder’s End Caps
Show  that  your  intersection  routine  correctly  finds  the  points  of  intersection
between a ray and a cylinder’s end caps.
This scenario outline sets up the same truncated cylinder as before, between
y=1 and y=2, but also makes the cylinder closed before throwing rays at it.
features/cylinders.feature
Scenario Outline: Intersecting the caps of a closed cylinder
Given cyl ← cylinder()
And cyl.minimum ← 1
And cyl.maximum ← 2
And cyl.closed ← true
And direction ← normalize(<direction>)
And r ← ray(<point>, direction)
When xs ← local_intersect(cyl, r)
Then xs.count = <count>
Examples:
| | point | direction | count |
| 1 | point(0, 3, 0) | vector(0, -1, 0) | 2 |
| 2 | point(0, 3, -2) | vector(0, -1, 2) | 2 |
| 3 | point(0, 4, -2) | vector(0, -1, 1) | 2 | # corner case
| 4 | point(0, 0, -2) | vector(0, 1, 2) | 2 |
| 5 | point(0, -1, -2) | vector(0, 1, 1) | 2 | # corner case
The ray in the first example starts above the cylinder and points down through
the  cylinder’s  middle,  along  the  y  axis.  It  should  intersect  both  end  caps,
resulting in two intersections.
Examples 2 and 4 originate (respectively) above and below the cylinder and
cast a ray diagonally through it, intersecting one end cap before exiting out
the far side of the cylinder. This also results in two intersections.
Examples 3 and 5 are corner cases. These also originate (respectively) above
and below the cylinder, intersecting an end cap, but they exit the cylinder at
the point where the other end cap intersects the side of the cylinder. In this
case, there should still be only two intersections: one with the first end cap
and the other where the second end cap meets the cylinder wall.
report erratum  •  discuss
Capped Cylinders • 185
To implement this, you’ll add a new function, intersect_caps(cyl, ray, xs). It checks
to see if the given ray intersects the end caps of the given cylinder, and adds
the points of intersection (if any) to the xs collection. Here it is in pseudocode:
# a helper function to reduce duplication.
# checks to see if the intersection at `t` is within a radius
# of 1 (the radius of your cylinders) from the y axis.
function check_cap(ray, t)
x ← ray.origin.x + t * ray.direction.x
z ← ray.origin.z + t * ray.direction.z
return (x² + z²) <= 1
end
function intersect_caps(cyl, ray, xs)
# caps only matter if the cylinder is closed, and might possibly be
# intersected by the ray.
if cyl is not closed or ray.direction.y is close to zero
return
end if
# check for an intersection with the lower end cap by intersecting
# the ray with the plane at y=cyl.minimum
t ← (cyl.minimum - ray.origin.y) / ray.direction.y
if check_cap(ray, t)
add intersection(t, cyl) to xs
end if
# check for an intersection with the upper end cap by intersecting
# the ray with the plane at y=cyl.maximum
t ← (cyl.maximum - ray.origin.y) / ray.direction.y
if check_cap(ray, t)
add intersection(t, cyl) to xs
end if
end function
First, the ray is intersected with a plane at the minimum extent. Then, the
point of intersection is tested (via the check_cap() helper function) to see if it
lies within the radius of the cylinder. If it does, the intersection is added to
the collection. The same process follows for the maximum extent.
Make sure your cylinder’s local_intersect function calls this new function after
it checks for intersections with the cylinder’s walls. You’ll also need to change
the logic at the beginning of the function so it doesn’t actually return when
a is zero, otherwise your cap intersection will be skipped and at least one of
your tests will fail. Instead, if a is zero, skip the cylinder intersection logic and
just call intersect_caps().
Chapter 13. Cylinders • 186
report erratum  •  discuss
You’re almost done, but before you can render these closed cylinders, you
need to update the calculation for the normal vector to account for the end
caps. That’s the very next test.
Test #8: Computing the Normal Vector at the End Caps
Show  that  the  normal  vector  calculation  accounts  for  closed  cylinders,  and
returns the correct normal at the end caps.
This scenario outline creates a closed, truncated cylinder and computes the
normal at various points on each end cap:
features/cylinders.feature
Scenario Outline: The normal vector on a cylinder's end caps
Given cyl ← cylinder()
And cyl.minimum ← 1
And cyl.maximum ← 2
And cyl.closed ← true
When n ← local_normal_at(cyl, <point>)
Then n = <normal>
Examples:
| point | normal |
| point(0, 1, 0) | vector(0, -1, 0) |
| point(0.5, 1, 0) | vector(0, -1, 0) |
| point(0, 1, 0.5) | vector(0, -1, 0) |
| point(0, 2, 0) | vector(0, 1, 0) |
| point(0.5, 2, 0) | vector(0, 1, 0) |
| point(0, 2, 0.5) | vector(0, 1, 0) |
The end caps are planes, which means an end cap has the same normal at
every point on it. The algorithm must check to see which end cap the point
corresponds to, or see if it lies on the cylinder itself, and return the appropriate
normal vector. In pseudocode, it looks like this:
function local_normal_at(cylinder, point)
# compute the square of the distance from the y axis
dist ← point.x² + point.z²
if dist < 1 and point.y >= cylinder.maximum - EPSILON
return vector(0, 1, 0)
else if dist < 1 and point.y <= cylinder.minimum + EPSILON
return vector(0, -1, 0)
else
return vector(point.x, 0, point.z)
end if
end function
report erratum  •  discuss
Capped Cylinders • 187
If the point lies less than 1 unit from the y axis, and it lies within EPSILON (see
Comparing Floating Point Numbers,  on page 5) of the minimum or maximum
extent, then it must be on one of the end caps. It’s important that you include
EPSILON here; if you don’t, you’ll wind up with rendering glitches caused by
the  wrong  normal  vector  being  calculated  when  floating  point  round-off
causes the point to be slightly inside an end cap.
That’s it, though. When that passes, you’ll be rendering capped, truncated
cylinders. Give it a shot!
The feature isn’t quite over yet, though. You’re going to wrap it up by imple-
menting the cone primitive.