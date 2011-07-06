#====================================================================
# Gnuplot script file for plotting data in file "gauss.dat"
#to plot the data start gnuplot and issue "  load 'gaussian.p'"
#or gnuplot < gaussian.p
#====================================================================

      set term postscript eps color blacktext "Helvetica" 24
      set output 'gaussian.eps'
      set   autoscale                        # scale axes automatically
      #unset log                             # remove any log-scaling
      set log x                              # log scale on x
      unset label                            # remove any previous labels
      set xtic auto                          # set xtics automatically
      set ytic auto                          # set ytics automatically
      set title "Gaussian curve"
      set xlabel "x"
      set ylabel "y"
      #set key 14,90

      #set label "Adequate gauss for Go 7x7" at 11,65
      #set arrow from 11,65 to 10,80

      #set xr [8:15]
      #set yr [0:100]

      plot  "gauss.dat" using 1:2 title 'Bell curve' with linespoints pointtype 5 


        set output
        quit
