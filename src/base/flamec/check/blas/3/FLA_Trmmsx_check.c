
#include "FLAME.h"

FLA_Error FLA_Trmmsx_check( FLA_Side side, FLA_Uplo uplo, FLA_Trans trans, FLA_Diag diag, FLA_Obj alpha, FLA_Obj A, FLA_Obj B, FLA_Obj beta, FLA_Obj C )
{
  FLA_Error e_val;

  e_val = FLA_Check_valid_leftright_side( side );
  FLA_Check_error_code( e_val );

  e_val = FLA_Check_valid_uplo( uplo );
  FLA_Check_error_code( e_val );

  e_val = FLA_Check_valid_trans( trans );
  FLA_Check_error_code( e_val );

  e_val = FLA_Check_valid_diag( diag );
  FLA_Check_error_code( e_val );

  e_val = FLA_Check_floating_object( A );
  FLA_Check_error_code( e_val );

  e_val = FLA_Check_nonconstant_object( A );
  FLA_Check_error_code( e_val );

  e_val = FLA_Check_identical_object_datatype( A, B );
  FLA_Check_error_code( e_val );

  e_val = FLA_Check_identical_object_datatype( A, C );
  FLA_Check_error_code( e_val );

  e_val = FLA_Check_consistent_object_datatype( A, alpha );
  FLA_Check_error_code( e_val );

  e_val = FLA_Check_consistent_object_datatype( A, beta );
  FLA_Check_error_code( e_val );

  e_val = FLA_Check_if_scalar( alpha );
  FLA_Check_error_code( e_val );

  e_val = FLA_Check_if_scalar( beta );
  FLA_Check_error_code( e_val );

  e_val = FLA_Check_square( A );
  FLA_Check_error_code( e_val );

  if ( side == FLA_LEFT )
  {
    e_val = FLA_Check_matrix_matrix_dims( FLA_NO_TRANSPOSE, FLA_NO_TRANSPOSE, A, B, C );
    FLA_Check_error_code( e_val );
  }
  else
  {
    e_val = FLA_Check_matrix_matrix_dims( FLA_NO_TRANSPOSE, FLA_NO_TRANSPOSE, B, A, C );
    FLA_Check_error_code( e_val );
  }

  return FLA_SUCCESS;
}
