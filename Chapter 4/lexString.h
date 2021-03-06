#ifndef LEXSTRING_H
#define LEXSTRING_H


/**
 *	@defgroup	LexString	Lex Strings.
 *	@{
 */

/**
 *	@file		lexString.h
 *	@author		lgxZJ@outlook.com
 *	@date		5/23/2016
 *
 *	@brief		Functions about extracting strings from yacc used by lex
 *				files.
 *
 *				This module's functionnality is to extract additional
 *				text strings--for example, string literals, ID text
 *				strings, from lexical analyzer generated by lex.
 *				Typically, these functions are used with  yytext and
 *				yyleng.
 *
 *	@note		Tests for these functions may not be enough. If any one
 *				was found, please do contact me!
 *	@see		<a  href="http://dinosaur.compilertools.net/yacc/">yacc</a>
 *
 *	@todo		Change name of freeStrings.
 */



/**
 *	@brief	Make a new string.
 *
 *	@param[in]	ptr		The beginning of the string to be extracted.
 *	@param[in]	length	The length of the string to be extracted.
 *	@return	If the function succeeds, the return value is a pointer
 *			to the new stirng made. If the function fails, the return
 *			value is \b NULL.
 *
 *  @remark	When finished using it, call \b freeStrings() to free.
 *
 *	@note	If the string to make is already made, then the function
 *			simply returns it.
 *
 *	@sa		freeStrings.
 */
char* lexString(char* ptr, int length);


/**
 *	@brief	Free all allocated strings.
 *	@param	void	This function has no parameters.
 *	@return	This function has no return values.
 *	@remark	Once freed, all strings could not be used again!
 */
void freeStrings(void);

/**
 *	@}
 */


/*------------------------------------------------------------------*
 *	uncomment followings for tests
 *	and uncomment typedefs at source file
 * -----------------------------------------------------------------*/

/*
typedef struct StringChain_
{
    char*			str;
    struct StringChain_*	next;
}*	StringChainPtr;

extern StringChainPtr g_head;
*/

#endif
