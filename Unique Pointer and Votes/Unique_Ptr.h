#pragma once
template<typename T>
class UniquePtr
{

private:
	T* address;

public:

	UniquePtr() :address(nullptr)
	{}

	UniquePtr(const UniquePtr&) = delete;
	UniquePtr& operator = (const UniquePtr&) = delete;

	UniquePtr(T* const& address)
	{
		this->address = address;
	}

	T* Get() const
	{
		return address;
	}

	T* operator ->() const
	{
		return address;
	}

	T& operator *() const
	{
		return *address;
	}

	~UniquePtr()
	{
		delete address;
	}

};