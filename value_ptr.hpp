#ifndef VALUE_PTR_HPP
#define VALUE_PTR_HPP


// value_ptr automatically dereferences its pointer
// Somewhat similar to std::reference_wrapper
template<typename T>
class value_ptr
{
public:
	value_ptr() {}
	value_ptr(T* ptr) : ptr(ptr) {}

	T* ptr = nullptr;

	// assignment
	T& operator=(const T x) { *ptr = x; return *ptr; };
	T& operator=(const T* x) { *ptr = *x; return *ptr; };

	// access
	operator T& () const noexcept { return *ptr; }
	T& get() const noexcept { return *ptr; }
};


#endif//VALUE_PTR_HPP