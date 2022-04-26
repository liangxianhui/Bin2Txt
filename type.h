#ifndef __TYPE_H
#define __TYPE_H

//
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef char  s8;
typedef short s16;
typedef int   s32;

#define LOG_ERR(fmt, args...)          printf("[ERROR] "fmt, ##args)
#define LOG_INFO(fmt, args...)         printf("[INFO] " fmt, ##args)

#ifndef TRUE
#define TRUE (1)
#endif

#ifndef FALSE
#define FALSE (1)
#endif

#endif