//Avichai Aziz & Asaf Ben Shabat.
#define _GNU_SOURCE // clears all servers warnings
#include "ProtStats.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
    if(argc != 2){
        fprintf(stderr,"\nUsage : %s <fastafile>\n",argv[0]); // to make sure argv[1] is fasta file !
        return 1;
    }
    unsigned int n =0;
    ProtStats *ProtStat_data = read_fasta_file(argv[1],&n);

    printf("N\tName\tLength\tHydro\tCharged\tPolar\n"); // print file format
    for(int i=0; i < n; i++) {
        printf("%d\t%s\t%d\t%.1lf\t%.1lf\t%.1lf\n",i+1,ProtStat_data[i].name,ProtStat_data[i].length,ProtStat_data[i].aa_freq[0],ProtStat_data[i].aa_freq[1],ProtStat_data[i].aa_freq[2]);
    }
    free(ProtStat_data); //other allocated memories are freed inside the functions
     // frees the memory of the Prostats
    // All heap blocks were freed -- no leaks are possible - checked by valgrind
    return 0;
}
