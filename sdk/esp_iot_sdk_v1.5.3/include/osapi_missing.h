/*
 *  osapi_missing.h
 *
 *  Function prototypes, data types, etc. that are missing in Espressif SDK headers.
 *
 *  Created on: 26 mai 2016
 *      Author: steph
 */

#ifndef INCLUDE_OSAPI_MISSING_H_
#define INCLUDE_OSAPI_MISSING_H_

int os_printf_plus(const char *format, ...)  __attribute__ ((format (printf, 1, 2)));

#endif /* INCLUDE_OSAPI_MISSING_H_ */
