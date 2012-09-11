/* @file   fix_utils.h
   @author Dmitry S. Melnikov, dmitryme@gmail.com
   @date   Created on: 07/26/2012 04:14:35 PM
*/

#ifndef FIX_PARSER_FIX_UTILS_H
#define FIX_PARSER_FIX_UTILS_H

#include <stdint.h>

#define LIKE(x)    __builtin_expect(!!(x), 1)
#define UNLIKE(x)  __builtin_expect(!!(x), 0)

uint32_t fix_utils_hash_string(char const* s);
int32_t fix_utils_numdigits(long val);
long fix_utils_lpow10(int n);
int32_t fix_utils_ltoa(long val, char* buff, uint32_t buffLen);
int32_t fix_utils_dtoa(double val, char* buff, uint32_t buffLen);
int32_t fix_utils_atoi32(char const* buff, uint32_t buffLen, int32_t* val);
int32_t fix_utils_atoi64(char const* buff, uint32_t buffLen, int64_t* val);
int32_t fix_utils_atod(char const* buff, uint32_t buffLen, double* val);

#endif /* FIX_PARSER_FIX_UTILS_H */