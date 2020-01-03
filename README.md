# Multiplication-with-Karatsuba-and-Shift-Add-Algorithms
The performance of Karatsuba and Shift+Add function is compared.&nbsp;


The Karatsuba algorithm  utilizes divide and conquer algorithm in order to multiply 2 inputs in reduced time
complexity.&nbsp; First the given inputs are divided into 2 halves, so: 
<br/>
&nbsp;
XY= (Xl* pow(2, n/2) + Xr)(Yl* pow(2, n/2) + Yr)
<br/>
Doing this with the classical method would take 4 separate multiplications, however since the multiplication can also
be written as:
<br/>
XY= XlYl* pow(2, n) + (XlYr + XrYl)* pow(2,n/2) + XrYr 
<br/>
In Karatsuba after calculating the result of XlYl and XrYr multiplications, XlYr + XrYl is found as: 
<br/>
(Xl + Xr)(Yl + Yr) - XlYl- XrYr
<br/>
So, the recurrence becomes: T(n) = 3T(n/2) + O(n) 
<br/>


As a result, the time complexity of Karatsuba is O(n^1.59) whereas this value is O(n^2) for Add+Shift function.


