# Multiplication-with-Karatsuba-and-Shift-Add-Algorithms
The performance of Karatsuba and Shift+Add function is compared. /


The Karatsuba algorithm  utilizes divide and conquer algorithm in order to multiply 2 inputs in reduced time
complexity. / First the given inputs are divided into 2 halves, so: XY= (Xl* pow(2, n/2) + Xr)(Yl* pow(2, n/2) + Yr)
/Doing this with the classical method would take 4 separate multiplications, however since the multiplication can also
be written as:/ XY= XlYl* pow(2, n) + (XlYr + XrYl)* pow(2,n/2) + XrYr /
In Karatsuba after calculating the result of XlYl and XrYr multiplications, XlYr + XrYl is found as:/
(Xl + Xr)(Yl + Yr) - XlYl- XrYr /
So, the recurrence becomes: T(n) = 3T(n/2) + O(n) /
I

As a result, the time complexity of Karatsuba is O(n^1.59) whereas this value is O(n^2) for Add+Shift function.


