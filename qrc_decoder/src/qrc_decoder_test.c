#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pbm.h"

#include "qrc_decoder.h"


#define large 21
// please, refer to DOCUMENTATION for technical details




int main()
{
	//scanner_t scanner;
	//scanner.c = 0;
	//scanner.verbosity = 0;
    unsigned char   pdata[large*large]  ;unsigned char dataout;
		//FILE* f = fopen("hw.pbm", "r");
            FILE* f;
            f = fopen("test_data/hw.pbm", "r");
	//	load_pbm(&scanner, f);

        load_pbm2(pdata, f);
		qrc_decoder(pdata, dataout);
		data_write(dataout);
		 int ret = system("diff --brief -w test_data/output.dat  test_data/output.golden.dat");
		 //printf("%d",ret);
	//}
	//free(scanner.d);
		   if (ret != 0) {
		      printf("Test failed!!!\n");
		      return 1;
		   } else {
		      printf("Test passed!\n");
		      return 0;
		   }

}
