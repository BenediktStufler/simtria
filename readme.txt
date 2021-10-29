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


Each generated map is represented by a list of half edge data structures in the format {next, previous, opposite}. The total output is a list of lists, each element corresponding to a map.


*
* 3. Example
*
simtria -s 10
{{{5,28,2},{3,2,1},{4,2,26},{2,3,21},{28,1,16},{23,24,11},{18,19,8},{9,30,7},{30,8,10},{11,12,9},{12,10,6},{10,11,13},{14,29,12},{29,13,15},{16,17,14},{17,15,5},{15,16,18},{19,7,17},{7,18,20},{21,20,19},{22,20,4},{20,21,23},{24,23,22},{6,23,25},{26,25,24},{27,25,3},{25,26,28},{1,28,27},{13,14,30},{8,9,29}}}


*
* 4. License
*

Copyright (C) 2021 Benedikt Stufler

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

