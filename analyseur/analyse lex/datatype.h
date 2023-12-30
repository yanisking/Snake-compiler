#ifndef __dataType__
	#define __dataType__

/* Token definitions */
typedef enum {
    TOKEN_SNK_BEGIN,
	TOKEN_INT,
	TOKEN_REAL,
	TOKEN_BEGIN,
	TOKEN_SET,
	TOKEN_IF,
	TOKEN_ELSE,
	TOKEN_SNK_PRINT,
    TOKEN_COMMENT,
	TOKEN_IDENTIFIER,
	TOKEN_NUMBER,
    TOKEN_REAL_NUMBER,
    TOKEN_SNK_END
}tokenType;



//strcuteur d'un id
typedef struct{
	tokenType type;
	char *value;
}token;

#endif
