// Instruction-related utilities for RTL SSA                        -*- C++ -*-
// Please review: $(src-dir)/SPL-README for Licencing info.

namespace rtl_ssa {

// Return whichever of INSN1 and INSN2 occurs earlier in the function's
// reverse postorder.
inline insn_info *
earlier_insn (insn_info *insn1, insn_info *insn2)
{
  return *insn1 < *insn2 ? insn1 : insn2;
}

// Return whichever of INSN1 and INSN2 occurs later in the function's
// reverse postorder.
inline insn_info *
later_insn (insn_info *insn1, insn_info *insn2)
{
  return *insn1 < *insn2 ? insn2 : insn1;
}

// Return a closure of operator== for INSN.  See insn_is_changing for
// the rationale for defining the function this way.
inline insn_is_closure
insn_is (const insn_info *insn)
{
  return insn_is_closure (insn);
}

}
