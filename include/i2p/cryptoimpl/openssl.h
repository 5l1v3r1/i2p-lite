#ifndef I2P_CRYPTOIMPL_OPENSSL_H
#define I2P_CRYPTOIMPL_OPENSSL_H

#include <i2p/crypto.h>
#include <openssl/bn.h>
#ifdef __cplusplus
extern "C" {
#endif


/** initialize i2p crypto subsystem using openssl and no threading */
void i2p_crypto_openssl_singlethreaded(struct i2p_crypto *, struct i2p_allocator *);

struct i2p_cryptoimpl_openssl_st
{
  struct i2p_allocator * alloc;
  BIGNUM * elgp;
  BIGNUM * elgg;
};

void i2p_openssl_elg_encrypt(struct i2p_crypto *, struct elg_op *);
void i2p_openssl_elg_decrypt(struct i2p_crypto *, struct elg_op *);
void i2p_openssl_elg_keygen(struct i2p_crypto *, struct elg_keygen_op *);
void i2p_openssl_randbytes(struct i2p_crypto *, uint8_t *, size_t);

int bn2buf(BIGNUM *, uint8_t *, size_t);

#ifdef __cplusplus
}
#endif

  
#endif
