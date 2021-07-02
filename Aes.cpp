#include "pch.h"
#include <iostream>
#include "aes.h"
#include <Windows.h>

#include "osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <string>
using std::string;

#include <cstdlib>
using std::exit;

#include "cryptlib.h"
using CryptoPP::Exception;

#include "hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;

#include "filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;

#include "aes.h"
using CryptoPP::AES;

#include "ccm.h"
using CryptoPP::CBC_Mode;

#include "assert.h"

int main(int argc, char* argv[])
{
    AutoSeededRandomPool prng;

    byte key[AES::DEFAULT_KEYLENGTH];
    prng.GenerateBlock(key, sizeof(key));

    byte iv[AES::BLOCKSIZE];
    prng.GenerateBlock(iv, sizeof(iv));

    string plain = "CBC Mode Test";
    string cipher, encoded, recovered;

    /*********************************\
    \*********************************/

    // Pretty print key
    encoded.clear();
    StringSource(key, sizeof(key), true,
        new HexEncoder(
            new StringSink(encoded)
        ) // HexEncoder
    ); // StringSource
    cout << "key: " << encoded << endl;

    // Pretty print iv
    encoded.clear();
    StringSource(iv, sizeof(iv), true,
        new HexEncoder(
            new StringSink(encoded)
        ) // HexEncoder
    ); // StringSource
    cout << "iv: " << encoded << endl;

    /*********************************\
    \*********************************/

    try
    {
        cout << "plain text: " << plain << endl;

        CBC_Mode< AES >::Encryption e;
        e.SetKeyWithIV(key, sizeof(key), iv);

        // The StreamTransformationFilter removes
        //  padding as required.
        StringSource s(plain, true,
            new StreamTransformationFilter(e,
                new StringSink(cipher)
            ) // StreamTransformationFilter
        ); // StringSource

#if 0
        StreamTransformationFilter filter(e);
        filter.Put((const byte*)plain.data(), plain.size());
        filter.MessageEnd();

        const size_t ret = filter.MaxRetrievable();
        cipher.resize(ret);
        filter.Get((byte*)cipher.data(), cipher.size());
#endif
    }
    catch (const CryptoPP::Exception& e)
    {
        cerr << e.what() << endl;
        exit(1);
    }

    /*********************************\
    \*********************************/

    // Pretty print
    encoded.clear();
    StringSource(cipher, true,
        new HexEncoder(
            new StringSink(encoded)
        ) // HexEncoder
    ); // StringSource
    cout << "cipher text: " << encoded << endl;

    /*********************************\
    \*********************************/

    try
    {
        CBC_Mode< AES >::Decryption d;
        d.SetKeyWithIV(key, sizeof(key), iv);

        // The StreamTransformationFilter removes
        //  padding as required.
        StringSource s(cipher, true,
            new StreamTransformationFilter(d,
                new StringSink(recovered)
            ) // StreamTransformationFilter
        ); // StringSource

#if 0
        StreamTransformationFilter filter(d);
        filter.Put((const byte*)cipher.data(), cipher.size());
        filter.MessageEnd();

        const size_t ret = filter.MaxRetrievable();
        recovered.resize(ret);
        filter.Get((byte*)recovered.data(), recovered.size());
#endif

        cout << "recovered text: " << recovered << endl;
    }
    catch (const CryptoPP::Exception& e)
    {
        cerr << e.what() << endl;
        exit(1);
    }

    /*********************************\
    \*********************************/

    return 0;
}


//#include<stdio.h>
//#include<math.h>


//// Returns gcd of a and b
//int gcd(int a, int h)
//{
//    int temp;
//    while (1)
//    {
//        temp = a%h;
//        if (temp == 0)
//          return h;
//        a = h;
//        h = temp;
//    }
//}


//// Code to demonstrate RSA algorithm
//int main()
//{
//    // Two random prime numbers
//    double p = 3;
//    double q = 7;

//    // First part of public key:
//    double n = p*q;

//    // Finding other part of public key.
//    // e stands for encrypt
//    double e = 2;
//    double phi = (p-1)*(q-1);
//    while (e < phi)
//    {
//        // e must be co-prime to phi and
//        // smaller than phi.
//        if (gcd(e, phi)==1)
//            break;
//        else
//            e++;
//    }

//    // Private key (d stands for decrypt)
//    // choosing d such that it satisfies
//    // d*e = 1 + k * totient
//    int k = 2;  // A constant value
//    double d = (1 + (k*phi))/e;

//    // Message to be encrypted
//    double msg = 20;

//    printf("Message data = %lf", msg);

//    // Encryption c = (msg ^ e) % n
//    double c = pow(msg, e);
//    c = fmod(c, n);
//    printf("\nEncrypted data = %lf", c);

//    // Decryption m = (c ^ d) % n
//    double m = pow(c, d);
//    m = fmod(m, n);
//    printf("\nOriginal Message Sent = %lf", m);

//    return 0;
//}
