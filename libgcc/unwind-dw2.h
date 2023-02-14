/* DWARF2 frame unwind data structure. */

enum {
  REG_UNSAVED,
  REG_SAVED_OFFSET,
  REG_SAVED_REG,
  REG_SAVED_EXP,
  REG_SAVED_VAL_OFFSET,
  REG_SAVED_VAL_EXP,
  REG_UNSAVED_ARCHEXT,		/* Target specific extension.  */
  REG_UNDEFINED
};

/* The result of interpreting the frame unwind info for a frame.
   This is all symbolic at this point, as none of the values can
   be resolved until the target pc is located.  */
typedef struct
{
  /* Each register save state can be described in terms of a CFA slot,
     another register, or a location expression.  */
  struct frame_state_reg_info
  {
    struct {
      union {
	_Unwind_Word reg;
	_Unwind_Sword offset;
	const unsigned char *exp;
      } loc;
    } reg[__LIBGCC_DWARF_FRAME_REGISTERS__+1];
    unsigned char how[__LIBGCC_DWARF_FRAME_REGISTERS__+1];

    enum {
      CFA_UNSET,
      CFA_REG_OFFSET,
      CFA_EXP
    } cfa_how : 8;

    /* Used to implement DW_CFA_remember_state.  */
    struct frame_state_reg_info *prev;

    /* The CFA can be described in terms of a reg+offset or a
       location expression.  */
    _Unwind_Sword cfa_offset;
    _Unwind_Word cfa_reg;
    const unsigned char *cfa_exp;
  } regs;

  /* The PC described by the current frame state.  */
  void *pc;

  /* The information we care about from the CIE/FDE.  */
  _Unwind_Personality_Fn personality;
  _Unwind_Sword data_align;
  _Unwind_Word code_align;
  _Unwind_Word retaddr_column;
  unsigned char fde_encoding;
  unsigned char lsda_encoding;
  unsigned char saw_z;
  unsigned char signal_frame;
  void *eh_ptr;
} _Unwind_FrameState;

