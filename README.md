This purpose of this program was to help me in my homework in my first semetester and it was written in C as it was the only language I was familiar with at the time.

-------------- This is an example output --------------

```The System of Linear Equations can be written as :

    |1  2  3| |x| = |14|
    |2  3  4| |y| = |20|
    |3  4  1| |z| = |14|

	:.AX = B - (1)

by L-U Decomposition Method,
	  A = LU

|1  2  3|     | 1    0   0|  |u11  u12  u13|
|2  3  4|  =  |l21   1   0|  | 0   u22  u23|
|3  4  1|     |l31  l32  1|  | 0    0   u33|

|1  2  3|     |u11      u12                u13                    |
|2  3  4|  =  |l21      l21 u12 + u22      l21 u13 + u23          |
|3  4  1|     |l31 u11  l31 u12 + l32 u22  l31 u12 + l32 u23 + u33|

First Row :
u11=x1 => 1
u12=y1 => 2
u13=z1 => 3

First Column :
l21=x2/u11 => 2/1
l31=x3/u11 => 3/1

Second Row :
u22=y2-(l21*u12) => 1/-1
u23=z2-(l21*u13) => -2/1

Second Column : l32=(y3-(l31*u12))/u22 => 2/1

Third Row : u33=z3-(l31*u13)-(l32*u23) => -4/1


Now,

   A = | 1    0    0 |  |1/1  2/1  3/1|
       |2/1   1    0 |  | 0   1/-1  -2/1|
       |3/1  2/1   1 |  | 0    0   -4/1|

	  :.A = LU

 From (1),
    LUX = B - (2)


Put UX = V, where V =|V1|
                     |V2|
                     |V3|

From (2), LV =B

 => | 1    0    0 | |V1|   |14|
    |2/1   1    0 | |V2| = |20|
    |3/1  2/1   1 | |V3|   |14|

    |V1| = |14|
    |2V1/1 + V2| = |20|
    |3V1/1 + 2V2/1 + V3| = |14|

Now, Evaluate the Values of all V's

  V1 = 14
  V2 = -8/1
  V3 = -12/1

->  V =|V1| = |14|
       |V2| = |-8/1|
       |V3| = |-12/1|

Now, we have -> UX=V

|1/1  2/1  3/1|    |x| = |14|
| 0   1/-1  -2/1|    |y| = |-8/1|
| 0    0   -4/1|    |z| = |-12/1|

Calculating the Values of x,y,z:

  z=3/1
  y=2/1
  x=1/1```
