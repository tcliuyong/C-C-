#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "postgres.h"
#include "fmgr.h"
#include "utils/numeric.h"

#define CRC32_POLYNOMIAL 0xEDB88320UL

static uint32_t crc32(uint32_t crc, void *buffer, int buflen)
{
	uint32_t ret = ~crc;
	unsigned char *ubuffer = (unsigned char *)buffer;
	int i;
	for(i = 0; i < buflen; ++i)
	{
		uint32_t k = ((ret & 0xFF) ^ ubuffer[i]);
		int j;
		for (j = 0; j < 8; ++j)
		{
			if (k & 1)
			{
				k = CRC32_POLYNOMIAL ^ (k >> 1);
			}
			else
			{
				k = k >> 1;
			}
		}
		ret = k ^ (ret >> 8);
	}
	ret = ~ret;
	return ret;
}

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

PG_FUNCTION_INFO_V1(crc32p);
Datum crc32p(PG_FUNCTION_ARGS)
{
	text *t = PG_GETARG_TEXT_P(0);
	int32 crc32v = crc32(0, VARDATA(t), VARSIZE(t) - VARHDRSZ);
	char crc32_cstr[0x10] = {};
	sprintf(crc32_cstr, "%08X", crc32v);

	text *crc32_text = (text *)palloc(VARHDRSZ + 8);
	SET_VARSIZE(crc32_text, VARHDRSZ + 8);
	memcpy(VARDATA(crc32_text), crc32_cstr, 8);
	PG_RETURN_TEXT_P(crc32_text);
}