template<typename T>
T randVector(const std::vector<T>& list) {
    return list[randInt(0, list.size()-1)];
}