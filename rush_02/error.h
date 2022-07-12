#ifndef ERROR_H
#define ERROR_H

enum e_err { UINT_ERROR, DICT_ERROR, GET_ERROR, FLUSH_ERROR };

char *error(enum e_err error);

#endif
