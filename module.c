#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <janet.h>

JANET_FN(cfun_sha512,
         "(openssl/sha512 message)",
         "Calculate sha512 of the given message.") {
    janet_fixarity(argc, 1);
    const uint8_t* message = janet_getstring(argv, 0);

    uint8_t* hashcode = janet_string_begin(SHA512_DIGEST_LENGTH);

    SHA512(message, janet_string_length(message), hashcode);

    janet_string_end(hashcode);
    return janet_wrap_string(hashcode);
}

JANET_FN(cfun_sha256,
         "(openssl/sha256 message)",
         "Calculate sha256 of the given message.") {
    janet_fixarity(argc, 1);
    const uint8_t* message = janet_getstring(argv, 0);

    uint8_t* hashcode = janet_string_begin(SHA256_DIGEST_LENGTH);

    SHA256(message, janet_string_length(message), hashcode);

    janet_string_end(hashcode);
    return janet_wrap_string(hashcode);
}

JANET_FN(cfun_hmac_sha512,
         "(openssl/hmac-sha512 message secret)",
         "Calculate hmac based on sha512 of the given message.") {
    janet_fixarity(argc, 2);
    const uint8_t* message = janet_getstring(argv, 0);
    const uint8_t* secret = janet_getstring(argv, 1);

    unsigned int md_len = SHA512_DIGEST_LENGTH;
    uint8_t* md = janet_string_begin(md_len);

    HMAC(EVP_sha512(), secret, janet_string_length(secret),
         message, janet_string_length(message),
         md, &md_len);

    janet_string_end(md);
    return janet_wrap_string(md);
}

JANET_MODULE_ENTRY(JanetTable *env) {
    JanetRegExt cfuns[] = {
        JANET_REG("sha512", cfun_sha512),
        JANET_REG("sha256", cfun_sha256),
        JANET_REG("hmac-sha512", cfun_hmac_sha512),
        JANET_REG_END
    };
    janet_cfuns_ext(env, "openssl", cfuns);
}
