#include <iostream>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <cstring>

using namespace std;

int main()
{
    // Generate a 256-bit key
    unsigned char key[32];
    RAND_bytes(key, 32);

    // Generate a 128-bit IV
    unsigned char iv[AES_BLOCK_SIZE];
    RAND_bytes(iv, AES_BLOCK_SIZE);

    // Encrypt the data
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    // Input data
    unsigned char input[] = "test.mp3";
    int input_len = strlen((const char *)input);

    // Output buffer for encrypted data
    unsigned char output[128];
    int len;

    // Encrypt the data
    EVP_EncryptUpdate(ctx, output, &len, input, input_len);
    int encrypted_len = len;

    // Finalize the encryption
    EVP_EncryptFinal_ex(ctx, output + len, &len);
    encrypted_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    cout << "Encrypted data: " << output << endl;

    // Decrypt the data
    ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    // Output buffer for decrypted data
    unsigned char decrypted[encrypted_len];

    // Decrypt the data
    EVP_DecryptUpdate(ctx, decrypted, &len, output, encrypted_len);
    int decrypted_len = len;

    // Finalize the decryption
    EVP_DecryptFinal_ex(ctx, decrypted + len, &len);
    decrypted_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    cout << "Decrypted data: " << decrypted << endl;

    return 0;
}
