all: a.out data.txt plot

a.out: diferential_cross_section.cpp
	g++ -Wall -fsanitize=address -fsanitize=undefined $^

data.txt: a.out
	./$^ > $@

plot: plotfigure.gp
	gnuplot $^

clean:
	-rm -f *~ *# *o *out *x QCD_curve.png *txt *log
