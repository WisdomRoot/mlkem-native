/*
 * Copyright (c) The mlkem-native project authors
 * SPDX-License-Identifier: Apache-2.0 OR ISC OR MIT
 */

#ifndef MLK_DEV_FIPS202_AARCH64_X2_V84A_H
#define MLK_DEV_FIPS202_AARCH64_X2_V84A_H

#if !defined(__ARM_FEATURE_SHA3)
#error This backend can only be used if SHA3 extensions are available.
#endif

/* Part of backend API */
#define MLK_USE_FIPS202_X4_NATIVE
/* Guard for assembly file */
#define MLK_FIPS202_AARCH64_NEED_X2_V84A

#if !defined(__ASSEMBLER__)
#include "../api.h"
#include "src/fips202_native_aarch64.h"
static MLK_INLINE int mlk_keccak_f1600_x4_native(uint64_t *state)
{
  if (!mlk_is_native_capable())
  {
    return MLK_NATIVE_FUNC_FALLBACK;
  }

  mlk_keccak_f1600_x2_v84a_asm(state + 0 * 25, mlk_keccakf1600_round_constants);
  mlk_keccak_f1600_x2_v84a_asm(state + 2 * 25, mlk_keccakf1600_round_constants);
  return MLK_NATIVE_FUNC_SUCCESS;
}
#endif /* !__ASSEMBLER__ */

#endif /* !MLK_DEV_FIPS202_AARCH64_X2_V84A_H */
