#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void error(char* msg){

	fprintf(stderr,"%s: %s\n",msg,strerror(errno));
	exit(1);
}

int main(int argc, char const *argv[])
{
	FILE* in_file = fopen("input.txt","r");
	if(in_file==NULL){
		error("cannot open input file");
	}
	FILE* out_file = fopen("output.txt","w");
	if(out_file==NULL){
		error("cannot open output file");
	}
	char line[100];
	int number_of_lines=0;
	while(fscanf(in_file,"%99[^\n]\n",line)==1){
		number_of_lines++;
		fprintf(stderr, "Number of lines: %i\n",number_of_lines);
		fprintf(out_file, "%s\n",line);
	}

	return 0;
}