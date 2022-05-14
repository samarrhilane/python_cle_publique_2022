#include <pybind11/pybind11.h>
#include <string>
#include <stdexcept>
#include "micro-ecc/uECC.h"
#include "micro-ecc/uECC_vli.h"




unsigned char hexchr2bin(const char hex)
{
	unsigned char result;

	if (hex >= '0' && hex <= '9') {
		result = hex - '0';
	} else if (hex >= 'A' && hex <= 'F') {
		result = hex - 'A' + 10;
	} else if (hex >= 'a' && hex <= 'f') {
		result = hex - 'a' + 10;
	} else {
		return 0;
	}
	return result;
}



void hexStringToBin(unsigned char *out,const char * hexPrivate) {
    for (int i=0; i<32; i++){
	out[i] = hexchr2bin(hexPrivate[2*i])<<4 | hexchr2bin(hexPrivate[2*i+1]);
    }
}


char *binToHexString(char *out,const unsigned char *bin, size_t len)
{
    size_t  i;

    if (bin == NULL || len == 0)
	return NULL;

    for (i=0; i<len; i++) {
	out[i*2]   = "0123456789abcdef"[bin[i] >> 4];
	out[i*2+1] = "0123456789abcdef"[bin[i] & 0x0F];
    }
    out[len*2] = '\0';

    return out;
}

/*uECC_curve_private_key_size() function.
Returns the size of a private key for the curve in bytes.
*/
//int uECC_curve_private_key_size(uECC_Curve curve);

/* uECC_curve_public_key_size() function.
Returns the size of a public key for the curve in bytes.
*/
//int uECC_curve_public_key_size(uECC_Curve curve);



// Outputs:
//     public_key  - Will be filled in with the public key. Must be at least 2 * the curve size
//                   (in bytes) long. For example, if the curve is secp256r1, public_key must be 64
//                   bytes long.
//     private_key - Will be filled in with the private key. Must be as long as the curve order; this
//                   is typically the same as the curve size, except for secp160r1. For example, if the
//                   curve is secp256r1, private_key must be 32 bytes long.
//                   For secp160r1, private_key must be 21 bytes long! Note that the first byte will
//                   almost always be 0 (there is about a 1 in 2^80 chance of it being non-zero).



//Returns 1 if the key pair was generated successfully, 0 if an error occurred.
//int uECC_make_key(uint8_t *public_key, uint8_t *private_key, uECC_Curve curve);


class Cle {
  
    private:
        std::string PublicKey;
        std::string PrivateKey;
  
    public:
        ~Cle() {}
	
        void initialize(std::string &Number) { 
		const struct uECC_Curve_t *curve = uECC_secp256k1();
		int Private_Key_Size = uECC_curve_private_key_size(curve);
	        Unit_Private_Key = uint8_t l_secret1[Private_Key_Size];
		std::string &output;
		PrivateKey = hexStringToBin(output, Number);
		std::string &output2;
		int Public_Key_Size = uECC_curve_public_key_size(curve);
		PublicKey = binToHexString(output2, output, ?);
		
		
        //
        }; 
        
        std::string getPrivateKey() { 
         return PrivateKey; }
	std::string getPublicKey()  {
         return PublicKey; }
        
 }
        
        
 namespace py = pybind11;
 
 PYBIND11_MODULE(cle_component,KEY) {
   py::class_<Cle>(KEY, "Cle",py::dynamic_attr())
      	.def(py::init<>())
	.def("initialize", &Key::initialize) 
        .def("getPrivateKey", &Key::getPrivateKey)
        .def("getPublicKey", &Key::getPublicKey);
 }
     
