# include "Serializer.hpp"

int main() {
    Data data = {42};
    Data* dataPtr = &data; 

    uintptr_t raw = Serializer::serialize(dataPtr);

    Data* deserializedPtr = Serializer::deserialize(raw);

    std::cout << "Original Pointer: " << dataPtr << std::endl;
    std::cout << "what does raw has: " << raw  << ", serialized (int) representation of dataPtr"<< std::endl;
    std::cout << "Deserialized Pointer: " << deserializedPtr << std::endl;
    std::cout << "Original Data: " << dataPtr->data << std::endl;
    std::cout << "Deserialized Data: " << deserializedPtr->data << std::endl;
    return 0;
}
// example 
// class MyClass
// {
// private:
//     int x;

// public:
//     MyClass(int value) : x(value) {}
//     int getX() { return x; }
// };

// class Hack
// {
// public:
//     int x;
// };

// int main() {
    
//   MyClass obj(100);
//   std::cout << obj.getX() << std::endl;
  
//   Hack* hk = reinterpret_cast<Hack*>(&obj);
//   hk->x = 500;
  
//   std::cout << obj.getX() << std::endl; 
  
//   return 0;
// }