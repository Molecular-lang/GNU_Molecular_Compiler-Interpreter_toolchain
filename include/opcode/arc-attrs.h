#ifndef ATTRS_ARC_H
#define ATTRS_ARC_H

#ifndef FEATURE_LIST_NAME
#define FEATURE_LIST_NAME feature_list
#endif

/* A table with cpu features.  */
const struct feature_type
{
  unsigned feature;
  unsigned cpus;
  const char *attr;
  const char *name;
}  FEATURE_LIST_NAME [] =
  {
    { BTSCN,    ARC_OPCODE_ARCALL,   "BITSCAN",  "bit-scan" },
    { CD,       ARC_OPCODE_ARCV2,    "CD",       "code-density" },
    { DIV,      ARC_OPCODE_ARCV2,    "DIV_REM",  "div/rem" },
    { DP,       ARC_OPCODE_ARCv2HS,  "FPUD",     "double-precision FPU" },
    { DPA,      ARC_OPCODE_ARCv2EM,  "FPUDA",    "double assist FP" },
    { DPX,      ARC_OPCODE_ARCFPX,   "DPFP",     "double-precision FPX" },
    { LL64,     ARC_OPCODE_ARCv2HS,  "LL64",     "double load/store" },
    { NPS400,   ARC_OPCODE_ARC700,   "NPS400",   "nps400" },
    { QUARKSE1, ARC_OPCODE_ARCv2EM,  "QUARKSE1", "QuarkSE-EM" },
    { QUARKSE2, ARC_OPCODE_ARCv2EM,  "QUARKSE2", "QuarkSE-EM" },
    { SHFT1,    ARC_OPCODE_ARCALL,   "SA",       "shift assist" },
    { SHFT2,    ARC_OPCODE_ARCALL,   "BS",       "barrel-shifter" },
    { SWAP,     ARC_OPCODE_ARCALL,   "SWAP",     "swap" },
    { SP,       ARC_OPCODE_ARCV2,    "FPUS",     "single-precision FPU" },
    { SPX,      ARC_OPCODE_ARCFPX,   "SPFP",     "single-precision FPX" }
  };

#ifndef CONFLICT_LIST
#define CONFLICT_LIST conflict_list
#endif

/* A table with conflicting features.  */
const unsigned CONFLICT_LIST [] = {
  NPS400 | SPX,
  NPS400 | DPX,
  DPX | DPA,
  SP | DPX,
  SP | SPX,
  DP | DPX,
  DP | SPX,
  QUARKSE1 | DP,
  QUARKSE1 | SP
};
#endif
