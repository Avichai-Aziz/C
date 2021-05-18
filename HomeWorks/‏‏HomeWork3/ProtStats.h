#define _GNU_SOURCE // clears all servers warnings
#ifndef PROTSTATS_H
#define PROTSTATS_H

 typedef struct
{
    char name[33];
    int length;
    double aa_freq[3]; //hydro polar charged
}ProtStats;

typedef enum {Hydrophobic, Charged, Polar} aa_type; //enumarted types of amino acid

int num_prots(char* fasta_file_name); // counting the number of prots in fasta file

ProtStats* ProtStatsCreate(char* protname,char* protSequence); // creating a protein data

void ProtStatsInit(char* protname,char* protSequence,ProtStats* protID); // initialize protein data to the address delivered

void ProtStatsCopy(ProtStats* protID1, ProtStats* protID2); // copying data of protein data to another

void ProtStatsSwap(ProtStats* protID1, ProtStats* protID2);// swapping data of protein datas

ProtStats* read_fasta_file(char* fastafilename,unsigned int* number); // collects  and creates data from protein fasata file

aa_type find_type(char type); // finding the type of the amino acid by the letter delivered

#endif