#define __L0_Normalize_10to18( X_hi, X_lo )            \
{                                                      \
UINT64 L0_tmp;                                         \
L0_tmp = (X_lo) + Twoto60_m_10to18;                    \
if (L0_tmp & Twoto60)                                  \
 {(X_hi)=(X_hi)+1;(X_lo)=((L0_tmp<<4)>>4);}            \
}


#define __L0_Normalize_10to9( X_hi, X_lo )             \
{                                                      \
UINT32 L0_tmp;                                         \
L0_tmp = (X_lo) + Twoto30_m_10to9;                     \
if (L0_tmp & 0x40000000)                               \
 {(X_hi)=(X_hi)+1;(X_lo)=((L0_tmp<<2)>>2);}            \
}


#define __L0_Split_MiDi_2( X, ptr )                    \
{                                                      \
UINT32 L0_head, L0_tail, L0_tmp;                       \
 L0_head = (X) >> 10;                                  \
 L0_tail = ((X)&(0x03FF))+(L0_head<<5)-(L0_head<<3);   \
 L0_tmp  = (L0_tail)>>10; L0_head += L0_tmp;           \
 L0_tail = (L0_tail&(0x03FF))+(L0_tmp<<5)-(L0_tmp<<3); \
 if (L0_tail > 999){L0_tail -= 1000; L0_head += 1;}    \
 *((ptr)++) = L0_head; *((ptr)++) = L0_tail;           \
}


#define __L0_Split_MiDi_3( X, ptr )                    \
{                                                      \
UINT32 L0_X, L0_head, L0_mid, L0_tail, L0_tmp;         \
 L0_X    = (UINT32)((X));                              \
 L0_head = ((L0_X>>17)*34359)>>18;                     \
 L0_X   -= L0_head*1000000;                            \
 if (L0_X >= 1000000){L0_X -= 1000000;L0_head+=1;}     \
 L0_mid  = L0_X >> 10;                                 \
 L0_tail = (L0_X & (0x03FF))+(L0_mid<<5)-(L0_mid<<3);  \
 L0_tmp  = (L0_tail)>>10; L0_mid += L0_tmp;            \
 L0_tail = (L0_tail&(0x3FF))+(L0_tmp<<5)-(L0_tmp<<3);  \
 if (L0_tail>999){L0_tail-=1000;L0_mid+=1;}            \
 *((ptr)++)=L0_head;*((ptr)++)=L0_mid;                 \
 *((ptr)++)=L0_tail;                                   \
}

#define __L1_Split_MiDi_6( X, ptr )                    \
{                                                      \
UINT32 L1_X_hi, L1_X_lo;                               \
UINT64 L1_Xhi_64, L1_Xlo_64;                           \
L1_Xhi_64 = ( ((X)>>28)*Inv_Tento9 ) >> 33;            \
L1_Xlo_64 = (X) - L1_Xhi_64*(UINT64)Tento9;            \
if (L1_Xlo_64 >= (UINT64)Tento9)                       \
 {L1_Xlo_64-=(UINT64)Tento9;L1_Xhi_64+=1;}             \
L1_X_hi=(UINT32)L1_Xhi_64; L1_X_lo=(UINT32)L1_Xlo_64;  \
__L0_Split_MiDi_3(L1_X_hi,(ptr));                      \
__L0_Split_MiDi_3(L1_X_lo,(ptr));                      \
}

#define __L1_Split_MiDi_6_Lead( X, ptr )               \
{                                                      \
UINT32 L1_X_hi, L1_X_lo;                               \
UINT64 L1_Xhi_64, L1_Xlo_64;                           \
if ((X)>=(UINT64)Tento9){                              \
  L1_Xhi_64 = ( ((X)>>28)*Inv_Tento9 ) >> 33;          \
  L1_Xlo_64 = (X) - L1_Xhi_64*(UINT64)Tento9;          \
  if (L1_Xlo_64 >= (UINT64)Tento9)                     \
   {L1_Xlo_64-=(UINT64)Tento9;L1_Xhi_64+=1;}           \
  L1_X_hi=(UINT32)L1_Xhi_64;                           \
  L1_X_lo=(UINT32)L1_Xlo_64;                           \
  if (L1_X_hi>=Tento6){                                \
     __L0_Split_MiDi_3(L1_X_hi,(ptr));                 \
     __L0_Split_MiDi_3(L1_X_lo,(ptr));                 \
  }                                                    \
  else if (L1_X_hi>=Tento3){                           \
     __L0_Split_MiDi_2(L1_X_hi,(ptr));                 \
     __L0_Split_MiDi_3(L1_X_lo,(ptr));                 \
  }                                                    \
  else {                                               \
       *((ptr)++) = L1_X_hi;                           \
       __L0_Split_MiDi_3(L1_X_lo,(ptr));               \
  }                                                    \
}                                                      \
else {                                                 \
  L1_X_lo = (UINT32)(X);                               \
  if (L1_X_lo>=Tento6){                                \
     __L0_Split_MiDi_3(L1_X_lo,(ptr));                 \
  }                                                    \
  else if (L1_X_lo>=Tento3){                           \
     __L0_Split_MiDi_2(L1_X_lo,(ptr));                 \
  }                                                    \
  else {                                               \
       *((ptr)++) = L1_X_lo;                           \
  }                                                    \
}                                                      \
}


#define __L0_MiDi2Str( X, c_ptr )              \
{                                              \
char *L0_src;                                  \
 L0_src = midi_tbl[(X)];                       \
 *((c_ptr)++) = *(L0_src++);                   \
 *((c_ptr)++) = *(L0_src++);                   \
 *((c_ptr)++) = *(L0_src);                     \
}

#define __L0_MiDi2Str_Lead( X, c_ptr )         \
{                                              \
char *L0_src;                                  \
 L0_src = midi_tbl[(X)];                       \
 if ((X)>=100){                                \
 *((c_ptr)++) = *(L0_src++);                   \
 *((c_ptr)++) = *(L0_src++);                   \
 *((c_ptr)++) = *(L0_src);                     \
 }                                             \
 else if ((X)>=10){                            \
 L0_src++;                                     \
 *((c_ptr)++) = *(L0_src++);                   \
 *((c_ptr)++) = *(L0_src);                     \
 }                                             \
 else {                                        \
 L0_src++;L0_src++;                            \
 *((c_ptr)++) = *(L0_src);                     \
}                                              \
}
