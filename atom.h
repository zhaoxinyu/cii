#ifndef ATOM_INCLUDED
#define ATOM_INCLUDED

#include "except.h"

extern int Atom_length(const char *str);
extern const char *Atom_new(const char *str, int len);
extern const char *Atom_string(const char *str);
extern const char *Atom_int(long n);
extern void Atom_free(const char *str);
extern void Atom_reset(void);
extern void Atom_vload(const char *str, ...);
extern void Atom_aload(const char *str[]);
#endif
