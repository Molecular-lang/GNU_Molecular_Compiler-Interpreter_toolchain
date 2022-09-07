/* Names of various DWARF tags.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "dwarf2.h"

#define DW_FIRST_TAG(name, value) \
  const char *get_DW_TAG_name (unsigned int tag)	\
  { switch (tag) { \
  DW_TAG (name, value)
#define DW_END_TAG } return 0; }
#define DW_FIRST_FORM(name, value) \
  const char *get_DW_FORM_name (unsigned int form)	\
  { switch (form) { \
  DW_FORM (name, value)
#define DW_END_FORM } return 0; }
#define DW_FIRST_AT(name, value) \
  const char *get_DW_AT_name (unsigned int attr) {	\
  switch (attr) { \
  DW_AT (name, value)
#define DW_END_AT } return 0; }
#define DW_FIRST_OP(name, value) \
  const char *get_DW_OP_name (unsigned int op) {	\
  switch (op) { \
  DW_OP (name, value)
#define DW_END_OP } return 0; }
#define DW_FIRST_ATE(name, value)			\
  const char *get_DW_ATE_name (unsigned int enc) {	\
  switch (enc) { \
  DW_ATE (name, value)
#define DW_END_ATE } return 0; }
#define DW_FIRST_CFA(name, value) \
  const char *get_DW_CFA_name (unsigned int opc) {	\
  switch (opc) {					\
  DW_CFA (name, value)
#define DW_END_CFA } return 0; }
#define DW_FIRST_IDX(name, value) \
  const char *get_DW_IDX_name (unsigned int idx) {	\
  switch (idx) {					\
  DW_IDX (name, value)
#define DW_END_IDX } return 0; }
#define DW_FIRST_UT(name, value) \
  const char *get_DW_UT_name (unsigned int ut) {	\
  switch (ut) {					\
  DW_UT (name, value)
#define DW_END_UT } return 0; }

#define DW_TAG(name, value) case name: return # name ;
#define DW_TAG_DUP(name, value)
#define DW_FORM(name, value) case name: return # name ;
#define DW_AT(name, value) case name: return # name ;
#define DW_AT_DUP(name, value)
#define DW_OP(name, value) case name: return # name ;
#define DW_OP_DUP(name, value)
#define DW_ATE(name, value) case name: return # name ;
#define DW_ATE_DUP(name, value)
#define DW_CFA(name, value) case name: return # name ;
#define DW_CFA_DUP(name, value)
#define DW_IDX(name, value) case name: return # name ;
#define DW_IDX_DUP(name, value)
#define DW_UT(name, value) case name: return # name ;

#include "dwarf2.def"

#undef DW_FIRST_TAG
#undef DW_END_TAG
#undef DW_FIRST_FORM
#undef DW_END_FORM
#undef DW_FIRST_AT
#undef DW_END_AT
#undef DW_FIRST_OP
#undef DW_END_OP
#undef DW_FIRST_ATE
#undef DW_END_ATE
#undef DW_FIRST_CFA
#undef DW_END_CFA
#undef DW_FIRST_IDX
#undef DW_END_IDX
#undef DW_END_UT

#undef DW_TAG
#undef DW_TAG_DUP
#undef DW_FORM
#undef DW_AT
#undef DW_AT_DUP
#undef DW_OP
#undef DW_OP_DUP
#undef DW_ATE
#undef DW_ATE_DUP
#undef DW_CFA
#undef DW_CFA_DUP
#undef DW_IDX
#undef DW_IDX_DUP
