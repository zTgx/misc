/// Concatenate the contents of a container onto a vector
template <class T, class U> std::vector<T>& operator+=(std::vector<T>& _a, U const& _b)
{
    for (auto const& i: _b)
        _a.push_back(i);
    return _a;
}
/// Concatenate the contents of a container onto a vector, move variant.
template <class T, class U> std::vector<T>& operator+=(std::vector<T>& _a, U&& _b)
{
    std::move(_b.begin(), _b.end(), std::back_inserter(_a));
    return _a;
}
/// Concatenate the contents of a container onto a set
template <class T, class U> std::set<T>& operator+=(std::set<T>& _a, U const& _b)
{
    _a.insert(_b.begin(), _b.end());
    return _a;
}


/*
std::vector<uint8_t> a;
std::vector<uint8_t> b;

a += b;
*/
