(define_register_constraint "RXX" "(SFR_REGS)"
     "A system register constraint.")

(define_register_constraint "RYY" "(AIB_REGS)"
     "A system register forcing SET and WFX* alone in bundle.")

(define_constraint "S"
  "An immediate or symbol operand"
  (ior (match_code "const_double,const_int")
       (match_test "kvx_symbol_operand(op,mode)")))

(define_constraint "T"
  "A label reference"
  (match_code "label_ref"))

(define_constraint "U05"
  "An unsigned 5-bit constant."
  (and (match_code "const_int")
       (match_test "UNSIGNED_INT_FITS_N_BITS (ival, 5)")))

(define_constraint "U06"
  "An unsigned 6-bit constant."
  (and (match_code "const_int")
       (match_test "UNSIGNED_INT_FITS_N_BITS (ival, 6)")))

(define_constraint "I10"
  "A signed 10-bit constant."
  (and (match_code "const_int")
       (match_test "ival >= -512 && ival <= 511")))

(define_constraint "H16"
  "A real value that fits on 16bits"
  (and (match_code "const_double")
       (match_test "kvx_float_fits_bits(rval,16,mode)")))

(define_constraint "H32"
  "A real value that fits on 32bits"
  (and (match_code "const_double")
       (match_test "kvx_float_fits_bits(rval,32,mode)")))

(define_constraint "H43"
  "A real value that fits on 43bits"
  (and (match_code "const_double")
       (match_test "kvx_float_fits_bits(rval,43,mode)")))

(define_constraint "I16"  
  "A signed 16-bit non symbolic constant."
  (and (match_code "const_int")
       (match_test "SIGNED_INT_FITS_N_BITS (ival, 16)")))

(define_constraint "I32"  
  "A signed 32-bit non symbolic constant."
  (and (match_code "const_int")
       (match_test "SIGNED_INT_FITS_N_BITS (ival, 32)")))

(define_constraint "I37"
  "A signed 37-bit non symbolic constant."
   (and (match_code "const_int")
       (match_test "SIGNED_INT_FITS_N_BITS (ival, 37)")))

(define_constraint "I43"
  "A signed 43-bit non symbolic constant."
  (and (match_code "const_int")
       (match_test "SIGNED_INT_FITS_N_BITS (ival, 43)")))

(define_constraint "B32"
  "A signed 32-bit constant (possibly symbolic if targeting 32bits addressing))."
   (ior (and (match_test "kvx_symbol_operand(op,mode)")
             (match_test "TARGET_32"))
        (match_test "satisfies_constraint_I32(op)")))

(define_constraint "B37"
  "A signed 37-bit constant (possibly symbolic if targeting 32bits addressing))."
   (ior (and (match_test "kvx_symbol_operand(op,mode)")
             (match_test "TARGET_32"))
        (match_test "satisfies_constraint_I37(op)")))

(define_constraint "v10"
  "A manifest vector constant whose value fits in signed 10 bits."
  (and (match_code "const_vector")
       (match_test "kvx_has_10bit_vector_const_p (op)")))

(define_constraint "v16"
  "A manifest vector constant whose value fits in signed 16 bits."
  (and (match_code "const_vector")
       (match_test "kvx_has_16bit_vector_const_p (op)")))

(define_constraint "v32"
  "A manifest vector constant whose value fits in signed 32 bits."
  (and (match_code "const_vector")
       (match_test "kvx_has_32bit_vector_const_p (op)")))

(define_constraint "v37"
  "A manifest vector constant whose value fits in signed 37 bits."
  (and (match_code "const_vector")
       (match_test "kvx_has_37bit_vector_const_p (op)")))

(define_constraint "v43"
  "A manifest vector constant whose value fits in signed 43 bits."
  (and (match_code "const_vector")
       (match_test "kvx_has_43bit_vector_const_p (op)")))

(define_constraint "vx2"
  "A 64-bit vector constant made of two identical 32-bit manifest values"
  (and (match_code "const_vector")
       (match_test "kvx_has_32x2bit_vector_const_p (op)")))

(define_memory_constraint "a"
  "Memory operands with 10-bit immediates or register"
  (and (match_code "mem")
       (match_test "kvx_has_10bit_imm_or_register_p (op)")))

(define_memory_constraint "b"
  "Memory operands with 37-bit immediates"
  (and (match_code "mem")
       (match_test "kvx_has_37bit_immediate_p (op)")))

(define_memory_constraint "u"
  "Uncached memory operands"
  (and (match_code "mem")
       (match_test "kvx_is_uncached_mem_op_p (op)")))

;; (define_memory_constraint "Q"
;;   "Packed memory operand, need not be correct."
;;   (match_code "mem"))


(define_memory_constraint "Cm"
  "Cached memory operands with 64-bit immediates"
  (and (match_code "mem")
       (match_test "kvx_has_64bit_immediate_p (op)")
       (match_test "!kvx_is_uncached_mem_op_p (op)")))

(define_memory_constraint "Cb"
  "Cached memory operands with 37-bit immediates"
  (and (match_code "mem")
       (match_test "kvx_has_37bit_immediate_p (op)")
       (match_test "!kvx_is_uncached_mem_op_p (op)")))

(define_memory_constraint "Ca"
  "Cached memory operands with 10-bit immediates or register"
  (and (match_code "mem")
       (match_test "kvx_has_10bit_imm_or_register_p (op)")
       (match_test "!kvx_is_uncached_mem_op_p (op)")))

(define_memory_constraint "Zm"
  "Uncached memory operands with 64-bit immediates"
  (and (match_code "mem")
       (match_test "kvx_has_64bit_immediate_p (op)")
       (match_test "kvx_is_uncached_mem_op_p (op)")))

(define_memory_constraint "Zb"
  "Uncached memory operands with 37-bit immediates"
  (and (match_code "mem")
       (match_test "kvx_has_37bit_immediate_p (op)")
       (match_test "kvx_is_uncached_mem_op_p (op)")))

(define_memory_constraint "Za"
  "Uncached memory operands with 10-bit immediates or register"
  (and (match_code "mem")
       (match_test "kvx_has_10bit_imm_or_register_p (op)")
       (match_test "kvx_is_uncached_mem_op_p (op)")))

(define_address_constraint "Aa"
  "Memory address with 10-bit immediates or register"
  (and (match_test "address_operand (op, mode)")
       (match_test "kvx_has_10bit_imm_or_register_p (op)")))

(define_address_constraint "Ab"
  "Memory address with 37-bit immediates"
  (and (match_test "address_operand (op, mode)")
       (match_test "kvx_has_37bit_immediate_p (op)")))
