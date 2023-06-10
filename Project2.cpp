#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


#define MAX 256

  int main() 
  {
        FILE *fptr1, *fptr2;
        int lno, linectr = 0;
        char str[MAX],fname[MAX];        
        char newln[MAX], temp[] = "temp.txt";
       static char savefile[MAX];
		
		printf("\n\n REPLACE A WRONGLY WRITTEN INFORMATION IN TEXT FILE WITH A NEW TEXT:\n");
		printf("-------------------------------------------------------------\n"); 
		printf(" INPUT THE FILE NAME YOU WANT TO BE OPENED : ");
        fgets(fname, MAX, stdin);
        fname[strlen(fname) - 1] = '\0';
        fptr1 = fopen(fname, "r");
        int fd = open(fname, O_RDONLY);
        if (!fptr1) 
        {
                printf("ERROR !!!!!!------UNABLE TO OPEN THE INPUT FILE!!\n");
                return 0;
        }
        if(fd != -1)
        {
        
        	printf("-----------------------------EXIXTING DATA FROM FILE WITH WRONG INFORMATION :--------------------------------\n");
        	printf("\n");
        	read(fd, savefile, 256);
        	
        	printf("%s", savefile);
        	     	
        }

        
        fptr2 = fopen(temp, "w");
        if (!fptr2) 
        {
                printf("ERROR!!!!!-------UNABLE TO OPEN A TEMPORARY FILE TO WRITE !!\n");
                fclose(fptr1);
                return 0;
        }
        /* get the new line from the user */
        printf(" INPUT THE CORRECT THE CORRECT INFORMATION IN NEW LINE : ");
        fgets(newln, MAX, stdin);
        /* get the line number to delete the specific line */
        printf(" INPUT THE LINE NO. YOU WANT OT REPLACE :");
        scanf("%d", &lno);
        lno++;
         // copy all contents to the temporary file other except specific line
        while (!feof(fptr1)) 
        {
            strcpy(str, "\0");
            fgets(str, MAX, fptr1);
            if (!feof(fptr1)) 
            {
                linectr++;
                if (linectr != lno) 
                    {
                        fprintf(fptr2, "%s", str);
                    } 
                    else 
                    {
                        fprintf(fptr2, "%s", newln);
                    }
                }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(fname);
        rename(temp, fname);
        printf("---------DATA REPLACE SUCCESSFULLY---------- \n");
        return 0;
  }
