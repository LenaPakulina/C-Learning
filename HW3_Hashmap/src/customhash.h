#ifndef CUSTOMHASH_H
#define CUSTOMHASH_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <ctype.h>

typedef struct CellHash {
	char			*key; // word
	unsigned int	value; // count
} CellHash;

typedef struct CustomHash {
	CellHash			**table;
	int					size;
} CustomHash;

void		closeApp(char *str);
void		printHash(CustomHash *hash);
int			hashCode(char *str, CustomHash *hash);
CellHash*	createCellHash(char *str);

void		insertKey(char *str, CustomHash *hash);
void		rebaseKey(char *str, CustomHash *hash);

#endif // CUSTOMHASH_H
