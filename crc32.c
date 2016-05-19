#include <string.h>
#include  <stdio.h>
static unsigned int CRC32[256];
static int nIsInit = 0;

static void init_table()
{
    int  i = 0, j =0 ;
    unsigned int crc;
    for(i = 0;i < 256; i++)
    {
        crc = i;
        for(j = 0;j < 8; j++)
        {
            if(crc & 1)
            {
                crc = (crc >> 1) ^ 0xEDB88320;
            }
            else
            {
                crc = crc >> 1;
            }
        }
        CRC32[i] = crc;
    }
}

unsigned int crc32(unsigned char *buf, int len)
{
    unsigned int ret = 0xFFFFFFFF;
    int i = 0;
    if( nIsInit != 1 )
    {
        init_table();
        nIsInit = 1;
    }
    for(i = 0; i < len; i++)
    {
        ret = CRC32[((ret & 0xFF) ^ buf[i])] ^ (ret >> 8);
    }
    ret = ~ret;
    return ret;
}

int main()
{
	printf("%u\n",crc32("test",4));
	return 0;
}
