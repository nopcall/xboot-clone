#ifndef __LLEX_H__
#define __LLEX_H__

#include <lua/luacfg.h>
#include <lua/lobject.h>
#include <lua/lzio.h>


#define FIRST_RESERVED		257

/* maximum length of a reserved word */
#define TOKEN_LEN			(sizeof("function")/sizeof(char))


/*
 * WARNING: if you change the order of this enumeration,
 * grep "ORDER RESERVED"
 */
enum RESERVED {
	/* terminal symbols denoted by reserved words */
	TK_AND = FIRST_RESERVED, TK_BREAK,
	TK_DO, TK_ELSE, TK_ELSEIF, TK_END, TK_FALSE, TK_FOR, TK_FUNCTION,
	TK_IF, TK_IN, TK_LOCAL, TK_NIL, TK_NOT, TK_OR, TK_REPEAT,
	TK_RETURN, TK_THEN, TK_TRUE, TK_UNTIL, TK_WHILE,
	/* other terminal symbols */
	TK_CONCAT, TK_DOTS, TK_EQ, TK_GE, TK_LE, TK_NE, TK_NUMBER,
	TK_NAME, TK_STRING, TK_EOS
};

/* number of reserved words */
#define NUM_RESERVED		(cast(int, TK_WHILE-FIRST_RESERVED+1))

/* array with token `names' */
extern const char *const luaX_tokens [];

typedef union {
	lua_Number r;
	TString *ts;
} SemInfo; /* semantics information */

typedef struct Token {
	int token;
	SemInfo seminfo;
} Token;

typedef struct LexState {
	int current; 				/* current character (charint) */
	int linenumber; 			/* input line counter */
	int lastline;				/* line of last token `consumed' */
	Token t;					/* current token */
	Token lookahead; 			/* look ahead token */
	struct FuncState *fs; 		/* `FuncState' is private to the parser */
	struct lua_State *L;
	ZIO *z; 					/* input stream */
	Mbuffer *buff; 				/* buffer for tokens */
	TString *source; 			/* current source name */
	char decpoint; 				/* locale decimal point */
} LexState;


void luaX_init(lua_State * L);
void luaX_setinput(lua_State * L, LexState * ls, ZIO * z, TString * source);
TString *luaX_newstring(LexState * ls, const char * str, size_t l);
void luaX_next(LexState * ls);
void luaX_lookahead(LexState * ls);
void luaX_lexerror(LexState * ls, const char * msg, int token);
void luaX_syntaxerror(LexState * ls, const char * s);
const char *luaX_token2str(LexState * ls, int token);

#endif /* __LLEX_H__ */
