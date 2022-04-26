#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "type.h"

bool bGetBinSize(const char *pFile, u32 *pSize)
{
    FILE *fp = fopen(pFile, "rb");
    if(!fp) {
        *pSize = 0;
        return false;
    }

    fseek(fp, 0, SEEK_END);
    *pSize = ftell(fp);
    
    fclose(fp);
    return true;
}

bool bReadBinFile(const char *pFile, u8 *u1Buff, u32 u4Size)
{
	FILE *fp = fopen(pFile, "rb");
	if(!fp) {
        return false;
    }
	
	fread(u1Buff, sizeof(u8), u4Size, fp);
	fclose(fp);
	return true;
}

bool bWriteBinFile(const char *pFile, u8 *u1Buff, u32 u4Size)
{
	u32 u4Loop = 0;

	FILE *fp = fopen(pFile, "wb");
	if(!fp) {
        return false;
    }
	
	for(u4Loop = 0; u4Loop < u4Size; u4Loop++)
	{
		fprintf(fp, "%02x ", *(u1Buff+u4Loop));
		if((u4Loop != 0) && !(u4Loop % 0xF))
		{
			fprintf(fp, "\r\n");
		}
	}
	return true;
}

int main(void)
{
	u8 *u8Buff = NULL;
    u32 u4Size = 0;
    bool bRet = false;

    bRet = bGetBinSize("data.bin", &u4Size);
    if (!bRet) {
        LOG_ERR("Get bin size %d failed\r\n", u4Size);
        return -1;
    }
    LOG_INFO("data.bin size = %d(Byte) = %d(KB)\r\n" , u4Size, u4Size/1024);

	u8Buff = (u8 *)malloc(u4Size);
	if(u8Buff == NULL) {
		LOG_ERR("Malloc %d Byte size memory failed!!!\r\n", u4Size);
		return -1;
	}

	bRet = bReadBinFile("data.bin", u8Buff, u4Size);
	if(!bRet) {
		LOG_ERR("read file data to bin failed!!!\r\n");
		free(u8Buff);
		return -1;
	}

	bRet = bWriteBinFile("data.txt", u8Buff, u4Size);
	if(!bRet) {
		LOG_ERR("write file data to txt failed!!!\r\n");
		free(u8Buff);
		return -1;
	}
	LOG_INFO("data.bin convert to data.txt sucess.\r\n");
	
	free(u8Buff);

	return 0;
}

