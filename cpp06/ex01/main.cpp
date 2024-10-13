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
