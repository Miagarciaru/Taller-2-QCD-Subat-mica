set term epslatex color colortext
set output 'QCD_curve.tex'
set title "Fitting $G_E$ and $G_M$" font ',20' 
set key box
set xlabel '$\tan^{2} (\theta / 2)$' 
set ylabel '$\frac{d \sigma}{d \Omega} \left/ \left(\frac{d \sigma}{d \Omega}\right)_{Mott} \right.$' 
set xtics 1
set ytics 0.5
set key top left box
set key width 1
#set key font ',14'
set border 3
set tics nomirror
set grid
set border lw 2
f(x)=m*x+b
fit f(x) "data.txt" using 1:2 via m,b
plot "data.txt" using 1:2 title '$Q^{2}=0.5$ $GeV^2$' lw 2 ps 2 lt 7 lc 7 w p, f(x) lw 3 lc 3 title 'Linear fit $y = mx + b$', f(x) lt 0 lc 3 title '$m = 0.25663 \pm 0.00957$', f(x) lt 0 lc 3 title '$b = 0.32564 \pm 0.02852$'
