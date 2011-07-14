#drawing stirling and factorial function 


 set term postscript eps color blacktext "Helvetica" 24
 set output 'functions.eps'

 stirling(x)=sqrt(2 * pi * x ) * x**x * exp(-x)
 fact(x) = (x == 0) ? 1 : x * fact(x - 1)
 
 set xrange[1:15]
 set yrange[1:1e+10]
 set log y 
 set sample 15
 plot stirling(x) title "stirling function"  with lines, \
 fact(x)          title "factorial"          with points, \
 exp(x)           title "exponential"        with lines, \
 log(x)           title "logarithmic"        with lines, \
 x                title "linear"             with lines, \
 x * log(x)       title "log-linear"         with lines, \
 x * x            title "quadratic"          with lines, \
 log(fact(x))     title "Log(Fact(x))"       with lines, \
 exp(fact(x))     title "Exp(Fact(x))"       with lines, \
 2 ** x           title "2 to the n"         with lines

 set output
 quit

