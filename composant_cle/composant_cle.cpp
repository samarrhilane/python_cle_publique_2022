#include <pybind11/pybind11.h>

char version[]="1.0";

class Cle {
  
    private:
        std::string PublicKey;
        std::string PrivateKey;
  
    public:
         Cle() {}
        ~Cle() {}

        void initialize(std::string Number) { 
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
     
