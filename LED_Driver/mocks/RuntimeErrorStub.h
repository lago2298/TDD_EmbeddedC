// Stub for production code RuntimeError funcitonality

#ifndef RUNTIMEERRORSTUB_H
#define RUNTIMEERRORSTUB_H

#include <stdint.h>

void RuntimeErrorStub_Reset(void);

char * RuntimeErrorStub_GetLastError(void);

int RuntimeErrorStub_GetLastParameter(void); 

/*void RuntimeError (const char *m, int p, const char *f, int l);*/ // don't need this because we're using the declaration in production code in RuntimeError.h in include/util

#endif /* RUNTIMEERRORSTUB_H */
