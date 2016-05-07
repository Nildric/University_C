/*
 * ruzzle_scheme_parsing.h
 *
 *  Created on: Apr 27, 2016
 *      Author: napalm
 */

#ifndef RUZZLE_SCHEME_PARSING_H_
#define RUZZLE_SCHEME_PARSING_H_

#include "common.h"

ReturnType_t ParseSchemeRow(char **matrix, unsigned int matrixSize, unsigned int rowIndex, char *schemeRow, unsigned int bLetterMatrix);

#endif /* RUZZLE_SCHEME_PARSING_H_ */
