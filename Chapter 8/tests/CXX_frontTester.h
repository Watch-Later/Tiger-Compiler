#ifndef MY_FRONT_TESTER_H
#define MY_FRONT_TESTER_H

extern "C"
{

#include "../CXX_myIRTree.h"

/**
 *  @brief	Do the front tests for a given source file.
 *  @remark filename must be a valid filename.
 */
IR_myStatement frontTester(const char* filename);

}

#endif

