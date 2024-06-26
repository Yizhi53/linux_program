#include "encryption.h"
#include "encryption_p.h"
#include "elsysteminfo.h"
#include <clog.h>

#define LOG_TAG "[Encryption]"


const uint8_t StaticKey[16] = {'a','b','c','d','e','f','g','h',
							   'i','j','k','l','m','n','o','p'
							  };

Encryption::Encryption()
{
	testFunction();
}

void Encryption::DecryptData(char* input, char* output)
{
	AES_set_decrypt_key(StaticKey, 128, &aesKey); //set key
	AES_ecb_encrypt((unsigned char*)input,(unsigned char*)output,&aesKey,AES_DECRYPT); //do decrypt
}

void Encryption::EncryptData(char* input, char* output)
{
	AES_set_encrypt_key(StaticKey, 128, &aesKey); //set key
	AES_ecb_encrypt((unsigned char*)input,(unsigned char*)output,&aesKey,AES_ENCRYPT); //do encrypt
}

bool Encryption::generateKey()
{
	//do something.
	return 0;
}

uint8_t* Encryption::getKey()
{
	//do something.
	return NULL;
}

bool Encryption::setKey()
{
	//do something.
	return 0;
}

void Encryption::reset()
{

}

void Encryption::testFunction()
{
	QString test_str = "EL-886C-MGD3";
	QByteArray outText;
	outText.resize(test_str.size());
	EncryptData(test_str.toLatin1().data(),outText.data());

	MLOGD(__FUNCTION__ << test_str << "==>" << outText.toHex().toUpper());
	QByteArray origi_txt;
	origi_txt.resize(test_str.size());
	DecryptData(outText.data(),origi_txt.data());
	QString origi_str = QString::fromLatin1(origi_txt);

	MLOGD(__FUNCTION__ << outText.toHex().toUpper() << "==>" << origi_str);
}


EncryptionPrivate::EncryptionPrivate()
{

}
