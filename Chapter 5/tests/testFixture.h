#ifndef TEST_FIXTURE_H
#define TEST_FIXTURE_H

#include "../mySymbol.h"
#include "../myAbstractSyntax.h"
#include "../myTypes.h"

mySymbol makeOneSymbol(void);
mySymbol makeSymbol_Int(void);
mySymbol makeSymbol_String(void);

myPos makeOnePos();

myExp makeOneExp_Integer(void);
myExp makeOneExp_String(void);
myExp makeOneExp_Nil(void);
myExp makeOneExp_Break(void);
myExp makeOneExp_NoValue(void);
myExp makeOneExp_Record(mySymbol recordTypeName);
myExp makeOneIllegalExp_Integer(void);
myExp makeOneExp_NoParamprocedureCall(mySymbol funcName);

myLValueExp makeOneLegalLValueExp_SimpleVar_Int(
    myTable varAndFuncEnv, myTable typeEnv);
myLValueExp makeOneLegalLValueExp_Record(
    myTable varAndFuncEnv, myType recordType);
myNoFieldRecordCreationExp makeOneNoFieldCreationExp(void);
myLValueExp makeOneLValueExp_TwoIntArraySubscript(
    mySymbol arrayName, myExp subscript1, myExp subscript2);
    
myType makeOneArray_StringArrayArray(void);
myType makeAndAddOneType_NoFieldRecord(myTable typeEnv, mySymbol recordTypeName);

myProcedureDec makeOneProcedureDec_Body(myExp body);
myFunctionDec makeOneFunctionDec_Body(myExp body, mySymbol returnTypeName);
myFunctionDec makeOneFunctionDec_Int(
    mySymbol functionName, myExp body, mySymbol returnTypeName);
myProcedureDec makeOneProcedureDec_NoReturn(void);
myProcedureDec makeOneProcedureDec_Integer(void);

myDecList makeLegalVars(void);
myDecList makeIllegalVars(void);
myDecList makeLegalRecursiveNamedDecs(mySymbol A, mySymbol B, mySymbol C);
myDecList makeIllegalRecursiveNamedDecs_Manual(
    mySymbol typeNameA, mySymbol typeNameB, mySymbol typeNameC);
myDecList makeIllegalRecursiveNamedDecs_Recursive(void);
myDecList makeLegalRecursiveFuncDecs(
    mySymbol funcNameA, mySymbol funcNameB, mySymbol funcNameC);
myDecList makeIllegalRecursiveFuncDecs(void);


#endif