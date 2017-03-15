all: reservoir_sampling
LIBS = -lpthread
reservoir_sampling: reservoir_sampling.c
	gcc -g -W -Wall $(LIBS) -o $@ $<

clean:
	rm -rf reservoir_sampling core*
