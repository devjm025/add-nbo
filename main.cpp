#include <stdio.h>
#include <stdint.h>
# include <netinet/in.h>

int printFileSize(FILE* fp){
	int f_size = 0;	
	
	if(fp != NULL){
		fseek(fp, 0, SEEK_END);
		f_size = ftell(fp);
	}
	
	return f_size;
	
}

int main(int argc, char *argv[]){

	char buf1[4];
	char buf2[4];
	int size1;
	int size2;
	
	uint32_t n1;
	uint32_t n2;
	
	uint32_t result;
	
	if(argc != 3){
		printf("You need to pass two arguments!");
	}
	else
	{
		FILE* fp1 = fopen(argv[1], "rb");
		FILE* fp2 = fopen(argv[2], "rb");
		
		if(fp1 == NULL)
		{
			printf("We can't open frist file!");
		}
		else if(fp2 == NULL){
			printf("We can't open second file!");
		}
		
		else{
			
			fread(&n1, sizeof(n1),1, fp1);
			fread(&n2, sizeof(n2),1, fp2);

			size1 = printFileSize(fp1);
			size2 = printFileSize(fp2);
			
			if(size1 < 4){
				printf("The first file's size is too small!");
			}
			
			else if(size2 < 4){
				printf("The second file's size is too small!");
			}
			else
			{	
				n1 = ntohl(n1);
				n2 = ntohl(n2);
				
				result = n1 + n2;
				
				printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", n1, n1, n2, n2, result, result);
			}
			
			fclose(fp1);
			fclose(fp2);
		}
	}
}
