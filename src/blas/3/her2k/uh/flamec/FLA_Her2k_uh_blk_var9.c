
#include "FLAME.h"

FLA_Error FLA_Her2k_uh_blk_var9( FLA_Obj alpha, FLA_Obj A, FLA_Obj B, FLA_Obj beta, FLA_Obj C, fla_her2k_t* cntl )
{
  FLA_Obj AT,              A0,
          AB,              A1,
                           A2;

  FLA_Obj BT,              B0,
          BB,              B1,
                           B2;

  dim_t b;

  FLA_Scalr_internal( FLA_UPPER_TRIANGULAR, beta, C,
                      FLA_Cntl_sub_scalr( cntl ) );

  FLA_Part_2x1( A,    &AT, 
                      &AB,            0, FLA_TOP );

  FLA_Part_2x1( B,    &BT, 
                      &BB,            0, FLA_TOP );

  while ( FLA_Obj_length( AT ) < FLA_Obj_length( A ) ){

    b = FLA_Determine_blocksize( AB, FLA_BOTTOM, FLA_Cntl_blocksize( cntl ) );

    FLA_Repart_2x1_to_3x1( AT,                &A0, 
                        /* ** */            /* ** */
                                              &A1, 
                           AB,                &A2,        b, FLA_BOTTOM );

    FLA_Repart_2x1_to_3x1( BT,                &B0, 
                        /* ** */            /* ** */
                                              &B1, 
                           BB,                &B2,        b, FLA_BOTTOM );

    /*------------------------------------------------------------*/

    /* C = C + A1' * B1 + B1' * A1 */             
    FLA_Her2k_internal( FLA_UPPER_TRIANGULAR, FLA_CONJ_TRANSPOSE, 
                        alpha, A1, B1, FLA_ONE, C,
                        FLA_Cntl_sub_her2k( cntl ) );

    /*------------------------------------------------------------*/

    FLA_Cont_with_3x1_to_2x1( &AT,                A0, 
                                                  A1, 
                            /* ** */           /* ** */
                              &AB,                A2,     FLA_TOP );

    FLA_Cont_with_3x1_to_2x1( &BT,                B0, 
                                                  B1, 
                            /* ** */           /* ** */
                              &BB,                B2,     FLA_TOP );

  }

  return FLA_SUCCESS;
}
