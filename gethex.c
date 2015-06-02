#include <stdio.h>
#include <stdlib.h>

static void print_byte_array (char *description, unsigned char *array, int length, int linewidth) {
	int i;

	fputs(description, stdout);
	if ( length < linewidth) {
		printf("[ ");
	}
	for (i = 0; i < length; i++) {
		if(i % linewidth == 0 && length > linewidth) {
			printf("\t");
		}
		printf("%02X", array[i]);
		if(i % linewidth == linewidth - 1) {
//			printf("\n");
		}
	}
	if ( length < linewidth) {
		printf("]");
	}
	if(i % linewidth != 0) {
//		printf("\n");
	}
}

int main (int argc, char *argv[])
{
		if(argc < 3){
			printf("Usage: %s <length> <string>\n", argv[0]);
			return -1;
		}
		
		int length = atoi(argv[1]);
		print_byte_array("", (unsigned char*)argv[2], length, length);
		return 0;
}
