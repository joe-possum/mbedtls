#include <stdio.h>
#include <string.h>
#include <mbedtls/md.h>
#include <assert.h>

int main(int argc, char *const*argv) {
  mbedtls_md_context_t ctx;
  const mbedtls_md_info_t *md_info;
  mbedtls_md_init(&ctx);
  md_info = mbedtls_md_info_from_type(MBEDTLS_MD_MD5);
  assert(0 == mbedtls_md_setup(&ctx,md_info,0));
  assert(0 == mbedtls_md_starts(&ctx));
  assert(0 == mbedtls_md_update(&ctx,(unsigned char*)"Hello, World!",13));
  unsigned char buf[64];
  memset(buf,0,64);
  assert(0 == mbedtls_md_finish(&ctx,buf));
  for(int i = 0; i < 64; i++) printf("%02x",buf[i]);
  printf("\n");
  return 0;
}
