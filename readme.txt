simtria -- generate uniform simple triangulations

* 
* 1. Introduction
* 

This project implements a random generator for uniform simple triangulations of the 2-sphere with a given number of triangles. It is based on the bijection between simple triangulations and blossoming trees by Poulalhon and Schaeffer (2006, Algorithmica), and a generating procedure for random blossoming trees by Addario-Berry and Albenque (2017, The Annals of Probability).
 

*
* 2. Usage
*

Usage: simtria [OPTION...] 
simtria -- generate uniform simple triangulations

  -N, --num=NUM              Simulate NUM many samples.
  -r, --randgen=RANDGEN      Use the pseudo random generator RANDGEN. Available
                             options are taus2, gfsr4, mt19937, ranlux,
                             ranlxs0, ranlxs1, ranlxs2, ranlxd1, ranlxd2, mrg,
                             cmrg, ranlux389. The default is taus2.
  -s, --size=SIZE            Generate a uniform planted simple triangulation
                             with s >= 4 faces, 2 + s/2 vertices, and 3s/2
                             edges. Has to be divisible by two and has to be
                             greater than or equal to four.
  -S, --seed=SEED            Specify the seed of the random generator in the
                             first thread. Thread number k will receive SEED +
                             k - 1 as seed. The default is to set SEED to the
                             systems timestamp (in seconds).
  -t, --threads=THREADS      Distribute the workload on THREADS many threads.
                             The default value is the number of CPU cores.
  -?, --help                 Give this help list
      --usage                Give a short usage message
  -V, --version              Print program version

Mandatory or optional arguments to long options are also mandatory or optional
for any corresponding short options.

Report bugs to <benedikt.stufler@posteo.net>.



*
* 3. Examples
*


simtria -s 100
