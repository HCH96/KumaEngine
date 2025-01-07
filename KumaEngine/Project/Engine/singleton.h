#pragma once

template <typename T>
class CSingleton
{
public:
	static T* GetInst();

protected:
	CSingleton() = default;

	CSingleton(const CSingleton&) = delete;
	CSingleton& operator=(const CSingleton&) = delete;

	CSingleton(CSingleton&&) = delete;
	CSingleton& operator=(CSingleton&&) = delete;

	virtual ~CSingleton() = default;
};

template <typename T>
T* CSingleton<T>::GetInst()
{
	static T Instance;
	return &Instance;
}