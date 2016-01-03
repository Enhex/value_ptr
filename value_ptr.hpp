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

	void reset(T* new_ptr) { ptr = new_ptr; }

	// assignment
	T& operator=(const T x) { *ptr = x; return *ptr; };
	T& operator=(const T* x) { *ptr = *x; return *ptr; };

	// access
	operator T& () const noexcept { return *ptr; }
	T& get() const noexcept { return *ptr; }

private:
	T* ptr = nullptr;
};


#endif//VALUE_PTR_HPP