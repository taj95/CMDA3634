#! /bin/bash

#PBS -l walltime=00:01:00
#PBS -l nodes=1:ppn=24
#PBS -W group_list=newriver
#PBS -q dev_q
#PBS -A CMDA3634SP18
#PBS -j oe

cd $PBS_O_WORKDIR

module purge
module load gcc

export OMP_NUM_THREADS=16
./main 
