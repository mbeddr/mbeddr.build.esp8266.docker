/*
 *  ets_sys_missing.h
 *
 *  Function prototypes, data types, etc. that are missing in Espressif SDK headers.
 *
 *  Created on: 26 mai 2016
 *      Author: steph
 */

#ifndef INCLUDE_ETS_SYS_MISSING_H_
#define INCLUDE_ETS_SYS_MISSING_H_

void ets_bzero(void *s, size_t n);
void ets_delay_us(int ms);
void ets_install_putc1(void *routine);

int ets_memcmp(const void *s1, const void *s2, size_t n);
void *ets_memcpy(void *dest, const void *src, size_t n);
void *ets_memmove(void *dest, const void *src, size_t n);
void *ets_memset(void *ptr, int val, size_t n);

int ets_sprintf(char *str, const char *format, ...)  __attribute__ ((format (printf, 2, 3)));
size_t ets_strlen(const char *s);
char *ets_strstr(const char *haystack, const char *needle);
int ets_strcmp(const char *s1, const char *s2);
int ets_strncmp(const char *s1, const char *s2, int len);
char *ets_strcpy(char *dest, const char *src);
char *ets_strncpy(char *dest, const char *src, size_t n);

void ets_timer_arm_new(ETSTimer *ptimer, uint32 milliseconds, bool repeat_flag, bool is_ms_timer);
void ets_timer_disarm(ETSTimer *ptimer);
void ets_timer_setfn(ETSTimer *ptimer, ETSTimerFunc *pfunction, void* parg);

void ets_intr_lock();
void ets_intr_unlock();
void ets_isr_attach(unsigned int intr, void *handler, void *arg);
void ets_isr_mask(unsigned int intr);
void ets_isr_unmask(unsigned int intr);

int ets_str2macaddr(void *, void *);
void ets_update_cpu_frequency(int freqmhz);

void NmiTimSetFunc(void* handler);

#endif /* INCLUDE_ETS_SYS_MISSING_H_ */
