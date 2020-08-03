#include "pcm_to_aac.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


void test()
{
	pcm_to_acc_init(8000, 2, 16);
    FILE* rfd = fopen("../Audio/pcm8k.pcm", "rb+");
    FILE* wfd = fopen("../Audio/convert_out4.aac", "wb+");
    if (rfd && wfd)
    {
        char pcm_buf[4096]; 
        char aac_buf[4096];
        printf("Begin to cnvert .......\n");
        struct timeval adts_start , adts_end;
        gettimeofday(&adts_start , NULL);

        while (!feof(rfd))
        {
            int ret = fread(pcm_buf, 1, 4096, rfd);
            //printf("ret = %d \n", ret);
            int aac_size =pcm_to_acc_encode(pcm_buf, ret, (unsigned char*)aac_buf);
            // printf("ret = %d aac_size = %d\n", ret, aac_size);
            fwrite(aac_buf, 1, aac_size, wfd);
        }
        gettimeofday(&adts_end , NULL);
        fclose(rfd);
        fclose(wfd);
        printf("PCM to AAC Conver Success\n");
    }
    pcm_to_acc_end();
}

int main()
{
	test();
	return 0;
}