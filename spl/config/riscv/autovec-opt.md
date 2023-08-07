;; Machine description for optimization of RVV auto-vectorization.
;; Copyright (C) 2023 Free Software Foundation, Inc.
;; Contributed by Juzhe Zhong (juzhe.zhong@rivai.ai), RiVAI Technologies Ltd.

;; This file is part of GCC.

;; GCC is free software; you can redistribute it and/or modify
;; it under the terms of the GNU General Public License as published by
;; the Free Software Foundation; either version 3, or (at your option)
;; any later version.

;; GCC is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.

;; You should have received a copy of the GNU General Public License
;; along with GCC; see the file COPYING3.  If not see
;; <http://www.gnu.org/licenses/>.

;; We don't have vwmul.wv instruction like vwadd.wv in RVV.
;; This pattern is an intermediate RTL IR as a pseudo vwmul.wv to enhance
;; optimization of instructions combine.
(define_insn_and_split "@pred_single_widen_mul<any_extend:su><mode>"
  [(set (match_operand:VWEXTI 0 "register_operand"                  "=&vr,&vr")
	(if_then_else:VWEXTI
	  (unspec:<VM>
	    [(match_operand:<VM> 1 "vector_mask_operand"           "vmWc1,vmWc1")
	     (match_operand 5 "vector_length_operand"              "   rK,   rK")
	     (match_operand 6 "const_int_operand"                  "    i,    i")
	     (match_operand 7 "const_int_operand"                  "    i,    i")
	     (match_operand 8 "const_int_operand"                  "    i,    i")
	     (reg:SI VL_REGNUM)
	     (reg:SI VTYPE_REGNUM)] UNSPEC_VPREDICATE)
	  (mult:VWEXTI
	    (any_extend:VWEXTI
	      (match_operand:<V_DOUBLE_TRUNC> 4 "register_operand" "   vr,   vr"))
	    (match_operand:VWEXTI 3 "register_operand"             "   vr,   vr"))
	  (match_operand:VWEXTI 2 "vector_merge_operand"           "   vu,    0")))]
  "TARGET_VECTOR && can_create_pseudo_p ()"
  "#"
  "&& 1"
  [(const_int 0)]
  {
    insn_code icode = code_for_pred_vf2 (<CODE>, <MODE>mode);
    rtx tmp = gen_reg_rtx (<MODE>mode);
    rtx ops[] = {tmp, operands[4]};
    riscv_vector::emit_vlmax_insn (icode, riscv_vector::RVV_UNOP, ops);

    emit_insn (gen_pred (MULT, <MODE>mode, operands[0], operands[1], operands[2],
			 operands[3], tmp, operands[5], operands[6],
			 operands[7], operands[8]));
    DONE;
  }
  [(set_attr "type" "viwmul")
   (set_attr "mode" "<MODE>")])

;; This pattern it to enchance the instruction combine optimizations for complicate
;; sign and unsigned widening multiplication operations.
(define_insn "*pred_widen_mulsu<mode>"
  [(set (match_operand:VWEXTI 0 "register_operand"                  "=&vr,&vr")
	(if_then_else:VWEXTI
	  (unspec:<VM>
	    [(match_operand:<VM> 1 "vector_mask_operand"           "vmWc1,vmWc1")
	     (match_operand 5 "vector_length_operand"              "   rK,   rK")
	     (match_operand 6 "const_int_operand"                  "    i,    i")
	     (match_operand 7 "const_int_operand"                  "    i,    i")
	     (match_operand 8 "const_int_operand"                  "    i,    i")
	     (reg:SI VL_REGNUM)
	     (reg:SI VTYPE_REGNUM)] UNSPEC_VPREDICATE)
	  (mult:VWEXTI
	    (zero_extend:VWEXTI
	      (match_operand:<V_DOUBLE_TRUNC> 4 "register_operand" "   vr,   vr"))
	    (sign_extend:VWEXTI
	      (match_operand:<V_DOUBLE_TRUNC> 3 "register_operand" "   vr,   vr")))
	  (match_operand:VWEXTI 2 "vector_merge_operand"           "   vu,    0")))]
  "TARGET_VECTOR"
  "vwmulsu.vv\t%0,%3,%4%p1"
  [(set_attr "type" "viwmul")
   (set_attr "mode" "<V_DOUBLE_TRUNC>")])

;; -----------------------------------------------------------------------------
;; ---- Integer Compare Instructions Simplification
;; -----------------------------------------------------------------------------
;; Simplify OP(V, V) Instructions to VMCLR.m Includes:
;; - 1.  VMSNE
;; - 2.  VMSLT
;; - 3.  VMSLTU
;; - 4.  VMSGT
;; - 5.  VMSGTU
;; -----------------------------------------------------------------------------
;; Simplify OP(V, V) Instructions to VMSET.m Includes:
;; - 1.  VMSEQ
;; - 2.  VMSLE
;; - 3.  VMSLEU
;; - 4.  VMSGE
;; - 5.  VMSGEU
;; -----------------------------------------------------------------------------

(define_split
  [(set (match_operand:VB      0 "register_operand")
	(if_then_else:VB
	  (unspec:VB
	    [(match_operand:VB 1 "vector_all_trues_mask_operand")
	     (match_operand    4 "vector_length_operand")
	     (match_operand    5 "const_int_operand")
	     (match_operand    6 "const_int_operand")
	     (reg:SI VL_REGNUM)
	     (reg:SI VTYPE_REGNUM)] UNSPEC_VPREDICATE)
	  (match_operand:VB    3 "vector_move_operand")
	  (match_operand:VB    2 "vector_undef_operand")))]
  "TARGET_VECTOR"
  [(const_int 0)]
  {
    emit_insn (gen_pred_mov (<MODE>mode, operands[0], CONST1_RTX (<MODE>mode),
			     RVV_VUNDEF (<MODE>mode), operands[3],
			     operands[4], operands[5]));
    DONE;
  }
)

;; -------------------------------------------------------------------------
;; ---- [BOOL] Binary logical operations (inverted second input)
;; -------------------------------------------------------------------------
;; Includes:
;; - vmandnot.mm
;; - vmornot.mm
;; -------------------------------------------------------------------------

(define_insn_and_split "*<optab>not<mode>"
  [(set (match_operand:VB 0 "register_operand"           "=vr")
	(bitmanip_bitwise:VB
	  (not:VB (match_operand:VB 2 "register_operand" " vr"))
	  (match_operand:VB 1 "register_operand"         " vr")))]
  "TARGET_VECTOR && can_create_pseudo_p ()"
  "#"
  "&& 1"
  [(const_int 0)]
  {
    insn_code icode = code_for_pred_not (<CODE>, <MODE>mode);
    riscv_vector::emit_vlmax_insn (icode, riscv_vector::RVV_BINOP, operands);
    DONE;
  }
  [(set_attr "type" "vmalu")
   (set_attr "mode" "<MODE>")])

;; -------------------------------------------------------------------------
;; ---- [BOOL] Binary logical operations (inverted result)
;; -------------------------------------------------------------------------
;; Includes:
;; - vmnand.mm
;; - vmnor.mm
;; - vmxnor.mm
;; -------------------------------------------------------------------------

(define_insn_and_split "*n<optab><mode>"
  [(set (match_operand:VB 0 "register_operand"     "=vr")
	(not:VB
	  (any_bitwise:VB
	    (match_operand:VB 1 "register_operand" " vr")
	    (match_operand:VB 2 "register_operand" " vr"))))]
  "TARGET_VECTOR && can_create_pseudo_p ()"
  "#"
  "&& 1"
  [(const_int 0)]
  {
    insn_code icode = code_for_pred_n (<CODE>, <MODE>mode);
    riscv_vector::emit_vlmax_insn (icode, riscv_vector::RVV_BINOP, operands);
    DONE;
  }
  [(set_attr "type" "vmalu")
   (set_attr "mode" "<MODE>")])

;; =========================================================================
;; == Widening Ternary arithmetic
;; =========================================================================

;; -------------------------------------------------------------------------
;; ---- [INT] VWMACC
;; -------------------------------------------------------------------------
;; Includes:
;; - vwmacc.vv
;; - vwmaccu.vv
;; -------------------------------------------------------------------------

;; Combine ext + ext + fma ===> widen fma.
;; Most of circumstantces, LoopVectorizer will generate the following IR:
;;   vect__8.64_40 = (vector([4,4]) int) vect__7.63_41;
;;   vect__11.68_35 = (vector([4,4]) int) vect__10.67_36;
;;   vect__13.70_33 = .FMA (vect__11.68_35, vect__8.64_40, vect__4.60_45);
(define_insn_and_split "*<optab>_fma<mode>"
  [(set (match_operand:VWEXTI 0 "register_operand")
	(plus:VWEXTI
	  (mult:VWEXTI
	    (any_extend:VWEXTI
	      (match_operand:<V_DOUBLE_TRUNC> 2 "register_operand"))
	    (any_extend:VWEXTI
	      (match_operand:<V_DOUBLE_TRUNC> 3 "register_operand")))
	  (match_operand:VWEXTI 1 "register_operand")))]
  "TARGET_VECTOR && can_create_pseudo_p ()"
  "#"
  "&& 1"
  [(const_int 0)]
  {
    riscv_vector::emit_vlmax_ternary_insn (code_for_pred_widen_mul_plus (<CODE>, <MODE>mode),
					   riscv_vector::RVV_WIDEN_TERNOP, operands);
    DONE;
  }
  [(set_attr "type" "viwmuladd")
   (set_attr "mode" "<V_DOUBLE_TRUNC>")])

;; This helps to match ext + fma.
(define_insn_and_split "*single_<optab>mult_plus<mode>"
  [(set (match_operand:VWEXTI 0 "register_operand")
	(plus:VWEXTI
	  (mult:VWEXTI
	    (any_extend:VWEXTI
	      (match_operand:<V_DOUBLE_TRUNC> 2 "register_operand"))
	    (match_operand:VWEXTI 3 "register_operand"))
	  (match_operand:VWEXTI 1 "register_operand")))]
  "TARGET_VECTOR && can_create_pseudo_p ()"
  "#"
  "&& 1"
  [(const_int 0)]
  {
    insn_code icode = code_for_pred_vf2 (<CODE>, <MODE>mode);
    rtx tmp = gen_reg_rtx (<MODE>mode);
    rtx ext_ops[] = {tmp, operands[2]};
    riscv_vector::emit_vlmax_insn (icode, riscv_vector::RVV_UNOP, ext_ops);

    rtx dst = expand_ternary_op (<MODE>mode, fma_optab, tmp, operands[3],
				 operands[1], operands[0], 0);
    emit_move_insn (operands[0], dst);
    DONE;
  }
  [(set_attr "type" "viwmuladd")
   (set_attr "mode" "<V_DOUBLE_TRUNC>")])

;; Combine ext + ext + mult + plus ===> widen fma.
;; We have some special cases generated by LoopVectorizer:
;;   vect__8.18_46 = (vector([8,8]) signed short) vect__7.17_47;
;;   vect__11.22_41 = (vector([8,8]) signed short) vect__10.21_42;
;;   vect__12.23_40 = vect__11.22_41 * vect__8.18_46;
;;   vect__14.25_38 = vect__13.24_39 + vect__5.14_51;
;; This situation doesn't generate FMA IR.
(define_insn_and_split "*double_<optab>mult_plus<mode>"
  [(set (match_operand:VWEXTI 0 "register_operand")
	(if_then_else:VWEXTI
	  (unspec:<VM>
	    [(match_operand:<VM> 1 "vector_mask_operand")
	     (match_operand 6 "vector_length_operand")
	     (match_operand 7 "const_int_operand")
	     (match_operand 8 "const_int_operand")
	     (match_operand 9 "const_int_operand")
	     (reg:SI VL_REGNUM)
	     (reg:SI VTYPE_REGNUM)] UNSPEC_VPREDICATE)
          (plus:VWEXTI
	    (if_then_else:VWEXTI
	      (unspec:<VM>
	        [(match_dup 1)
	         (match_dup 6)
	         (match_dup 7)
	         (match_dup 8)
	         (match_dup 9)
	         (reg:SI VL_REGNUM)
	         (reg:SI VTYPE_REGNUM)] UNSPEC_VPREDICATE)
	      (mult:VWEXTI
	        (any_extend:VWEXTI
	          (match_operand:<V_DOUBLE_TRUNC> 4 "register_operand"))
	        (any_extend:VWEXTI
	          (match_operand:<V_DOUBLE_TRUNC> 5 "register_operand")))
              (match_operand:VWEXTI 2 "vector_undef_operand"))
	    (match_operand:VWEXTI 3 "register_operand"))
          (match_dup 2)))]
  "TARGET_VECTOR && can_create_pseudo_p ()"
  "#"
  "&& 1"
  [(const_int 0)]
  {
    emit_insn (gen_pred_widen_mul_plus (<CODE>, <MODE>mode, operands[0],
					operands[1], operands[3], operands[4],
					operands[5], operands[6], operands[7],
					operands[8], operands[9]));
    DONE;
  }
  [(set_attr "type" "viwmuladd")
   (set_attr "mode" "<V_DOUBLE_TRUNC>")])

;; Combine sign_extend + zero_extend + fma ===> widen fma (su).
(define_insn_and_split "*sign_zero_extend_fma"
  [(set (match_operand:VWEXTI 0 "register_operand")
	(plus:VWEXTI
	  (mult:VWEXTI
	    (sign_extend:VWEXTI
	      (match_operand:<V_DOUBLE_TRUNC> 2 "register_operand"))
	    (zero_extend:VWEXTI
	      (match_operand:<V_DOUBLE_TRUNC> 3 "register_operand")))
	  (match_operand:VWEXTI 1 "register_operand")))]
  "TARGET_VECTOR && can_create_pseudo_p ()"
  "#"
  "&& 1"
  [(const_int 0)]
  {
    riscv_vector::emit_vlmax_ternary_insn (code_for_pred_widen_mul_plussu (<MODE>mode),
					   riscv_vector::RVV_WIDEN_TERNOP, operands);
    DONE;
  }
  [(set_attr "type" "viwmuladd")
   (set_attr "mode" "<V_DOUBLE_TRUNC>")])

;; This helps to match zero_extend + sign_extend + fma.
(define_insn_and_split "*zero_sign_extend_fma"
  [(set (match_operand:VWEXTI 0 "register_operand")
	(plus:VWEXTI
	  (mult:VWEXTI
	    (zero_extend:VWEXTI
	      (match_operand:<V_DOUBLE_TRUNC> 2 "register_operand"))
	    (sign_extend:VWEXTI
	      (match_operand:<V_DOUBLE_TRUNC> 3 "register_operand")))
	  (match_operand:VWEXTI 1 "register_operand")))]
  "TARGET_VECTOR && can_create_pseudo_p ()"
  "#"
  "&& 1"
  [(const_int 0)]
  {
    rtx ops[] = {operands[0], operands[1], operands[3], operands[2]};
    riscv_vector::emit_vlmax_ternary_insn (code_for_pred_widen_mul_plussu (<MODE>mode),
					   riscv_vector::RVV_WIDEN_TERNOP, ops);
    DONE;
  }
  [(set_attr "type" "viwmuladd")
   (set_attr "mode" "<V_DOUBLE_TRUNC>")])

;; -------------------------------------------------------------------------
;; ---- [INT] Binary narrow shifts.
;; -------------------------------------------------------------------------
;; Includes:
;; - vnsrl.wv/vnsrl.wx/vnsrl.wi
;; - vnsra.wv/vnsra.wx/vnsra.wi
;; -------------------------------------------------------------------------

(define_insn_and_split "*v<any_shiftrt:optab><any_extend:optab>trunc<mode>"
  [(set (match_operand:<V_DOUBLE_TRUNC> 0 "register_operand"       "=vr,vr")
    (truncate:<V_DOUBLE_TRUNC>
      (any_shiftrt:VWEXTI
        (match_operand:VWEXTI 1 "register_operand"                 " vr,vr")
	(any_extend:VWEXTI
          (match_operand:<V_DOUBLE_TRUNC> 2 "vector_shift_operand" " vr,vk")))))]
  "TARGET_VECTOR && can_create_pseudo_p ()"
  "#"
  "&& 1"
  [(const_int 0)]
{
  insn_code icode = code_for_pred_narrow (<any_shiftrt:CODE>, <MODE>mode);
  riscv_vector::emit_vlmax_insn (icode, riscv_vector::RVV_BINOP, operands);
  DONE;
}
 [(set_attr "type" "vnshift")
  (set_attr "mode" "<V_DOUBLE_TRUNC>")])

(define_insn_and_split "*<any_shiftrt:optab>trunc<mode>"
  [(set (match_operand:<V_DOUBLE_TRUNC> 0 "register_operand" "=vr")
    (truncate:<V_DOUBLE_TRUNC>
      (any_shiftrt:VWEXTI
        (match_operand:VWEXTI 1 "register_operand"           " vr")
	(match_operand:<VEL> 2 "csr_operand"                 " rK"))))]
  "TARGET_VECTOR && can_create_pseudo_p ()"
  "#"
  "&& 1"
  [(const_int 0)]
{
  operands[2] = gen_lowpart (Pmode, operands[2]);
  insn_code icode = code_for_pred_narrow_scalar (<any_shiftrt:CODE>, <MODE>mode);
  riscv_vector::emit_vlmax_insn (icode, riscv_vector::RVV_BINOP, operands);
  DONE;
}
 [(set_attr "type" "vnshift")
  (set_attr "mode" "<V_DOUBLE_TRUNC>")])

;; -------------------------------------------------------------------------
;; ---- Sign-extension for vmv.x.s.
;; -------------------------------------------------------------------------
(define_insn "*pred_extract_first_sextdi<mode>"
  [(set (match_operand:DI 0 "register_operand"		"=r")
	(sign_extend:DI
          (unspec:<VEL>
	    [(vec_select:<VEL>
	       (match_operand:VI_QHS 1 "register_operand""vr")
	       (parallel [(const_int 0)]))
	     (reg:SI VTYPE_REGNUM)] UNSPEC_VPREDICATE)))]
  "TARGET_VECTOR && Pmode == DImode"
  "vmv.x.s\t%0,%1"
  [(set_attr "type" "vimovvx")
   (set_attr "mode" "<MODE>")])

(define_insn "*pred_extract_first_sextsi<mode>"
  [(set (match_operand:SI 0 "register_operand"		  "=r")
	(sign_extend:SI
          (unspec:<VEL>
	    [(vec_select:<VEL>
	       (match_operand:VI_QH 1 "register_operand"  "vr")
	       (parallel [(const_int 0)]))
	     (reg:SI VTYPE_REGNUM)] UNSPEC_VPREDICATE)))]
  "TARGET_VECTOR && Pmode == SImode"
  "vmv.x.s\t%0,%1"
  [(set_attr "type" "vimovvx")
   (set_attr "mode" "<MODE>")])

;; We don't have vfwmul.wv instruction like vfwadd.wv in RVV.
;; This pattern is an intermediate RTL IR as a pseudo vfwmul.wv to enhance
;; optimization of instructions combine.
(define_insn_and_split "*pred_single_widen_mul<mode>"
  [(set (match_operand:VWEXTF 0 "register_operand"                  "=&vr,  &vr")
       (if_then_else:VWEXTF
         (unspec:<VM>
           [(match_operand:<VM> 1 "vector_mask_operand"           "vmWc1,vmWc1")
            (match_operand 5 "vector_length_operand"              "   rK,   rK")
            (match_operand 6 "const_int_operand"                  "    i,    i")
            (match_operand 7 "const_int_operand"                  "    i,    i")
            (match_operand 8 "const_int_operand"                  "    i,    i")
            (match_operand 9 "const_int_operand"                  "    i,    i")
            (reg:SI VL_REGNUM)
            (reg:SI VTYPE_REGNUM)
            (reg:SI FRM_REGNUM)] UNSPEC_VPREDICATE)
         (mult:VWEXTF
           (float_extend:VWEXTF
             (match_operand:<V_DOUBLE_TRUNC> 4 "register_operand" "   vr,   vr"))
           (match_operand:VWEXTF 3 "register_operand"             "   vr,   vr"))
         (match_operand:VWEXTF 2 "vector_merge_operand"           "   vu,    0")))]
  "TARGET_VECTOR && can_create_pseudo_p ()"
  "#"
  "&& 1"
  [(const_int 0)]
  {
    insn_code icode = code_for_pred_extend (<MODE>mode);
    rtx tmp = gen_reg_rtx (<MODE>mode);
    rtx ops[] = {tmp, operands[4]};
    riscv_vector::emit_vlmax_insn (icode, riscv_vector::RVV_UNOP, ops);

    emit_insn (gen_pred (MULT, <MODE>mode, operands[0], operands[1], operands[2],
                        operands[3], tmp, operands[5], operands[6],
                        operands[7], operands[8], operands[9]));
    DONE;
  }
  [(set_attr "type" "vfwmul")
   (set_attr "mode" "<MODE>")])

;; -------------------------------------------------------------------------
;; ---- [FP] VFWMACC
;; -------------------------------------------------------------------------
;; Includes:
;; - vfwmacc.vv
;; -------------------------------------------------------------------------

;; Combine ext + ext + fma ===> widen fma.
;; Most of circumstantces, LoopVectorizer will generate the following IR:
;; vect__8.176_40 = (vector([2,2]) double) vect__7.175_41;
;; vect__11.180_35 = (vector([2,2]) double) vect__10.179_36;
;; vect__13.182_33 = .FMA (vect__11.180_35, vect__8.176_40, vect__4.172_45);
(define_insn_and_split "*double_widen_fma<mode>"
  [(set (match_operand:VWEXTF 0 "register_operand")
	(fma:VWEXTF
	  (float_extend:VWEXTF
	    (match_operand:<V_DOUBLE_TRUNC> 2 "register_operand"))
	  (float_extend:VWEXTF
	    (match_operand:<V_DOUBLE_TRUNC> 3 "register_operand"))
	  (match_operand:VWEXTF 1 "register_operand")))]
  "TARGET_VECTOR && can_create_pseudo_p ()"
  "#"
  "&& 1"
  [(const_int 0)]
  {
    riscv_vector::emit_vlmax_fp_ternary_insn (code_for_pred_widen_mul (PLUS, <MODE>mode),
					      riscv_vector::RVV_WIDEN_TERNOP, operands);
    DONE;
  }
  [(set_attr "type" "vfwmuladd")
   (set_attr "mode" "<V_DOUBLE_TRUNC>")])

;; This helps to match ext + fma.
(define_insn_and_split "*single_widen_fma<mode>"
  [(set (match_operand:VWEXTF 0 "register_operand")
	(fma:VWEXTF
	  (float_extend:VWEXTF
	    (match_operand:<V_DOUBLE_TRUNC> 2 "register_operand"))
	  (match_operand:VWEXTF 3 "register_operand")
	  (match_operand:VWEXTF 1 "register_operand")))]
  "TARGET_VECTOR && can_create_pseudo_p ()"
  "#"
  "&& 1"
  [(const_int 0)]
  {
    insn_code icode = code_for_pred_extend (<MODE>mode);
    rtx tmp = gen_reg_rtx (<MODE>mode);
    rtx ext_ops[] = {tmp, operands[2]};
    riscv_vector::emit_vlmax_insn (icode, riscv_vector::RVV_UNOP, ext_ops);

    rtx dst = expand_ternary_op (<MODE>mode, fma_optab, tmp, operands[3],
				 operands[1], operands[0], 0);
    emit_move_insn (operands[0], dst);
    DONE;
  }
  [(set_attr "type" "vfwmuladd")
   (set_attr "mode" "<V_DOUBLE_TRUNC>")])

;; -------------------------------------------------------------------------
;; ---- [FP] VFWNMSAC
;; -------------------------------------------------------------------------
;; Includes:
;; - vfwnmsac.vv
;; -------------------------------------------------------------------------

;; Combine ext + ext + fnma ===> widen fnma.
;; Most of circumstantces, LoopVectorizer will generate the following IR:
;; vect__8.176_40 = (vector([2,2]) double) vect__7.175_41;
;; vect__11.180_35 = (vector([2,2]) double) vect__10.179_36;
;; vect__13.182_33 = .FNMA (vect__11.180_35, vect__8.176_40, vect__4.172_45);
(define_insn_and_split "*double_widen_fnma<mode>"
  [(set (match_operand:VWEXTF 0 "register_operand")
	(fma:VWEXTF
	  (neg:VWEXTF
	    (float_extend:VWEXTF
	      (match_operand:<V_DOUBLE_TRUNC> 2 "register_operand")))
	  (float_extend:VWEXTF
	    (match_operand:<V_DOUBLE_TRUNC> 3 "register_operand"))
	  (match_operand:VWEXTF 1 "register_operand")))]
  "TARGET_VECTOR && can_create_pseudo_p ()"
  "#"
  "&& 1"
  [(const_int 0)]
  {
    riscv_vector::emit_vlmax_fp_ternary_insn (code_for_pred_widen_mul_neg (PLUS, <MODE>mode),
					      riscv_vector::RVV_WIDEN_TERNOP, operands);
    DONE;
  }
  [(set_attr "type" "vfwmuladd")
   (set_attr "mode" "<V_DOUBLE_TRUNC>")])

;; This helps to match ext + fnma.
(define_insn_and_split "*single_widen_fnma<mode>"
  [(set (match_operand:VWEXTF 0 "register_operand")
	(fma:VWEXTF
	  (neg:VWEXTF
	    (float_extend:VWEXTF
	      (match_operand:<V_DOUBLE_TRUNC> 2 "register_operand")))
	  (match_operand:VWEXTF 3 "register_operand")
	  (match_operand:VWEXTF 1 "register_operand")))]
  "TARGET_VECTOR && can_create_pseudo_p ()"
  "#"
  "&& 1"
  [(const_int 0)]
  {
    insn_code icode = code_for_pred_extend (<MODE>mode);
    rtx tmp = gen_reg_rtx (<MODE>mode);
    rtx ext_ops[] = {tmp, operands[2]};
    riscv_vector::emit_vlmax_insn (icode, riscv_vector::RVV_UNOP, ext_ops);

    rtx dst = expand_ternary_op (<MODE>mode, fnma_optab, tmp, operands[3],
				 operands[1], operands[0], 0);
    emit_move_insn (operands[0], dst);
    DONE;
  }
  [(set_attr "type" "vfwmuladd")
   (set_attr "mode" "<V_DOUBLE_TRUNC>")])

;; -------------------------------------------------------------------------
;; ---- [FP] VFWMSAC
;; -------------------------------------------------------------------------
;; Includes:
;; - vfwmsac.vv
;; -------------------------------------------------------------------------

;; Combine ext + ext + fms ===> widen fms.
;; Most of circumstantces, LoopVectorizer will generate the following IR:
;; vect__8.176_40 = (vector([2,2]) double) vect__7.175_41;
;; vect__11.180_35 = (vector([2,2]) double) vect__10.179_36;
;; vect__13.182_33 = .FMS (vect__11.180_35, vect__8.176_40, vect__4.172_45);
(define_insn_and_split "*double_widen_fms<mode>"
  [(set (match_operand:VWEXTF 0 "register_operand")
	(fma:VWEXTF
	  (float_extend:VWEXTF
	    (match_operand:<V_DOUBLE_TRUNC> 2 "register_operand"))
	  (float_extend:VWEXTF
	    (match_operand:<V_DOUBLE_TRUNC> 3 "register_operand"))
	  (neg:VWEXTF
	    (match_operand:VWEXTF 1 "register_operand"))))]
  "TARGET_VECTOR && can_create_pseudo_p ()"
  "#"
  "&& 1"
  [(const_int 0)]
  {
    riscv_vector::emit_vlmax_fp_ternary_insn (code_for_pred_widen_mul (MINUS, <MODE>mode),
					      riscv_vector::RVV_WIDEN_TERNOP, operands);
    DONE;
  }
  [(set_attr "type" "vfwmuladd")
   (set_attr "mode" "<V_DOUBLE_TRUNC>")])

;; This helps to match ext + fms.
(define_insn_and_split "*single_widen_fms<mode>"
  [(set (match_operand:VWEXTF 0 "register_operand")
	(fma:VWEXTF
	  (float_extend:VWEXTF
	    (match_operand:<V_DOUBLE_TRUNC> 2 "register_operand"))
	  (match_operand:VWEXTF 3 "register_operand")
	  (neg:VWEXTF
	    (match_operand:VWEXTF 1 "register_operand"))))]
  "TARGET_VECTOR && can_create_pseudo_p ()"
  "#"
  "&& 1"
  [(const_int 0)]
  {
    insn_code icode = code_for_pred_extend (<MODE>mode);
    rtx tmp = gen_reg_rtx (<MODE>mode);
    rtx ext_ops[] = {tmp, operands[2]};
    riscv_vector::emit_vlmax_insn (icode, riscv_vector::RVV_UNOP, ext_ops);

    rtx dst = expand_ternary_op (<MODE>mode, fms_optab, tmp, operands[3],
				 operands[1], operands[0], 0);
    emit_move_insn (operands[0], dst);
    DONE;
  }
  [(set_attr "type" "vfwmuladd")
   (set_attr "mode" "<V_DOUBLE_TRUNC>")])

;; -------------------------------------------------------------------------
;; ---- [FP] VFWNMACC
;; -------------------------------------------------------------------------
;; Includes:
;; - vfwnmacc.vv
;; -------------------------------------------------------------------------

;; Combine ext + ext + fnms ===> widen fnms.
;; Most of circumstantces, LoopVectorizer will generate the following IR:
;; vect__8.176_40 = (vector([2,2]) double) vect__7.175_41;
;; vect__11.180_35 = (vector([2,2]) double) vect__10.179_36;
;; vect__13.182_33 = .FNMS (vect__11.180_35, vect__8.176_40, vect__4.172_45);
(define_insn_and_split "*double_widen_fnms<mode>"
  [(set (match_operand:VWEXTF 0 "register_operand")
	(fma:VWEXTF
	  (neg:VWEXTF
	    (float_extend:VWEXTF
	      (match_operand:<V_DOUBLE_TRUNC> 2 "register_operand")))
	  (float_extend:VWEXTF
	    (match_operand:<V_DOUBLE_TRUNC> 3 "register_operand"))
	  (neg:VWEXTF
	    (match_operand:VWEXTF 1 "register_operand"))))]
  "TARGET_VECTOR && can_create_pseudo_p ()"
  "#"
  "&& 1"
  [(const_int 0)]
  {
    riscv_vector::emit_vlmax_fp_ternary_insn (code_for_pred_widen_mul_neg (MINUS, <MODE>mode),
					      riscv_vector::RVV_WIDEN_TERNOP, operands);
    DONE;
  }
  [(set_attr "type" "vfwmuladd")
   (set_attr "mode" "<V_DOUBLE_TRUNC>")])

;; This helps to match ext + fnms.
(define_insn_and_split "*single_widen_fnms<mode>"
  [(set (match_operand:VWEXTF 0 "register_operand")
	(fma:VWEXTF
	  (neg:VWEXTF
	    (float_extend:VWEXTF
	      (match_operand:<V_DOUBLE_TRUNC> 2 "register_operand")))
	  (match_operand:VWEXTF 3 "register_operand")
	  (neg:VWEXTF
	    (match_operand:VWEXTF 1 "register_operand"))))]
  "TARGET_VECTOR && can_create_pseudo_p ()"
  "#"
  "&& 1"
  [(const_int 0)]
  {
    insn_code icode = code_for_pred_extend (<MODE>mode);
    rtx tmp = gen_reg_rtx (<MODE>mode);
    rtx ext_ops[] = {tmp, operands[2]};
    riscv_vector::emit_vlmax_insn (icode, riscv_vector::RVV_UNOP, ext_ops);

    rtx dst = expand_ternary_op (<MODE>mode, fnms_optab, tmp, operands[3],
				 operands[1], operands[0], 0);
    emit_move_insn (operands[0], dst);
    DONE;
  }
  [(set_attr "type" "vfwmuladd")
   (set_attr "mode" "<V_DOUBLE_TRUNC>")])
