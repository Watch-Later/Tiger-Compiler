#include "myControlable.h"
#include "../CXX_myFrame.h"

using namespace std;

namespace lgxZJ
{
    namespace IS
    {
        /////////////////////////////////////////////////////////////////////////
        //
        //                              Macros

#define DEFINE_JUMP_LIKE(CLSNAME, CLSSTR)       \
        CLSNAME::CLSNAME(myLabel oneDstLabel)   \
        {                                       \
            dstLabel = oneDstLabel;             \
        }                                       \
                                                \
        string CLSNAME::ToString() const        \
        {                                       \
            return ToCommonString(#CLSSTR);     \
        }

        /////////////////////////////////////////////////////////////////////////
        //                              Label
        /////////////////////////////////////////////////////////////////////////

        Label::Label(myLabel oneLabel) : label(oneLabel)    {}

        string Label::ToString() const
        {
            return string(MySymbol_GetName(label)) + ":";
        }

        /////////////////////////////////////////////////////////////////////////
        //                              Cmp
        /////////////////////////////////////////////////////////////////////////

        DEFINE_TWOCOMPUTE_CTOR(Cmp);

        string Cmp::ToString() const
        {
            return ToCommonString("cmp");
        }

        Registers Cmp::GetDstRegs() const
        {
            return {};
        }

        Registers Cmp::GetSrcRegs() const
        {
            Registers result(1, dstReg);

            if (srcRep.kind == BinaryUnion::Kind::Reg)
                result.push_back(srcRep.u.reg);
            
            return result;
        }

        /////////////////////////////////////////////////////////////////////////
        //                              Jmp
        /////////////////////////////////////////////////////////////////////////

        DEFINE_JUMP_LIKE(Jmp, jmp);

        ///////////////////////////////////////////////////////////////////////////
        //                              Je
        ///////////////////////////////////////////////////////////////////////////

        DEFINE_JUMP_LIKE(Je, je);

        ///////////////////////////////////////////////////////////////////////////
        //                              Jne
        ///////////////////////////////////////////////////////////////////////////

        DEFINE_JUMP_LIKE(Jne, jne);

        ///////////////////////////////////////////////////////////////////////////
        //                              jg
        ///////////////////////////////////////////////////////////////////////////

        DEFINE_JUMP_LIKE(Jg, jg);

        //////////////////////////////////////////////////////////////////////////
        //                              jge
        //////////////////////////////////////////////////////////////////////////

        DEFINE_JUMP_LIKE(Jge, jge);

        //////////////////////////////////////////////////////////////////////////
        //                              jl
        //////////////////////////////////////////////////////////////////////////

        DEFINE_JUMP_LIKE(Jl, jl);

        //////////////////////////////////////////////////////////////////////////
        //                              jle
        //////////////////////////////////////////////////////////////////////////

        DEFINE_JUMP_LIKE(Jle, jle);

        /////////////////////////////////////////////////////////////////////////
        //                              Call
        /////////////////////////////////////////////////////////////////////////

        Call::Call(myLabel oneFuncLabel, myTempList oneRegList)
            : funcLabel(oneFuncLabel), regList(oneRegList)
        {}

        string Call::ToString() const
        {
            myTempList regs = regList;

            string result = "call " + string(MySymbol_GetName(funcLabel)) + "(";
            while (regs)
                result += " register" + to_string(Temp_getTempNum(regs->head)) + ",",
                regs = regs->tail;

            result += ")";
            return result;
        }

        Registers Call::GetDstRegs() const
        {
            Registers result;
        
            //  caller-save contains eax register which is also the result value register.
            myTempList temps = Frame_callerSaveRegs();
            while (temps)
                result.push_back(temps->head),
                temps = temps->tail;

            return result;
        }

        void Call::ReplaceReg(Register oldReg, Register newReg)
        {
            while (regList != nullptr)
            {
                if (regList->head == oldReg)
                    regList->head = newReg;
                regList = regList->tail;
            }
        }

        ////////////////////////////////////////////////////////////////////////////////

        #undef DEFINE_JUMP_LIKE
    }
}