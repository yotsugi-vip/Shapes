#pragma once

template<class T>
class Singleton {
protected:
	Singleton() = default;
	virtual ~Singleton() = default;
	Singleton(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;

public:
	static void Create();
	static void Destroy();
	static T* GetInstance();

private:
	static T* pInstance;
};

template<class T>
T* Singleton<T>::pInstance = nullptr;

template<class T>
void Singleton<T>::Create() 
{
	if (nullptr == Singleton<T>::pInstance)
	{
		Singleton<T>::pInstance = new T();
	}
}

template<class T>
void Singleton<T>::Destroy()
{
	delete Singleton<T>::pInstance;
	Singleton<T>::pInstance = nullptr;
}

template<class T>
T* Singleton<T>::GetInstance()
{
	return Singleton<T>::pInstance;
}