#drawing stirling and factorial function 


 set term postscript eps color blacktext "Helvetica" 24
 set output 'calculators.eps'


Z(x)= 0.4 * x 
C1(x)= -x + 200

 #stirling(x)=sqrt(2 * pi * x ) * x**x * exp(-x)
 #fact(x) = (x == 0) ? 1 : x * fact(x - 1)
 
 set xrange[0:2000]
 set yrange[0:2000]
 #set log y 
 set sample 15
 plot Z(x)      title "Objective function"  with lines, \
      C1(x)     title "Minimum shipping"             with lines

 set output
 quit

