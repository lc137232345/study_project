/*
 * @Author: your name
 * @Date: 2021-07-15 17:36:53
 * @LastEditTime: 2021-07-15 18:51:48
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /study_project/include/Singleton1.h
 */
#include <memory>
#include <mutex>
template <typename T>
class Magic_Singleton1
{
public:
    template <typename... Args>
    static std::shared_ptr<T> Getinstance(string name, Args &&...args)
    {
        std::cout << name << std::endl;
        if (!m_instance)
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            if (nullptr == m_instance)
            {
                m_instance = std::make_shared<T>(std::forward<Args>(args)...);
            }
        }
        return m_instance;
    }

    static void DesInstance()
    {
        if (m_instance)
        {
            m_instance.reset();
            m_instance = nullptr;
        }
    }

private:
    explicit Magic_Singleton1();
    Magic_Singleton1(const Magic_Singleton1 &) = delete;
    Magic_Singleton1 &operator=(const Magic_Singleton1 &) = delete;
    ~Magic_Singleton1();

private:
    static std::shared_ptr<T> m_instance;
    static std::mutex m_mutex;
};
template <typename T>
std::shared_ptr<T> Magic_Singleton1<T>::m_instance = nullptr;

template <typename T>
std::mutex Magic_Singleton1<T>::m_mutex;