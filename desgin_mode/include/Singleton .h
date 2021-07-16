/*
 * @Author: your name
 * @Date: 2021-07-15 04:37:06
 * @LastEditTime: 2021-07-15 18:50:51
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /study_project/include/Singleton .h
 */
#ifndef MAGIC_SINGLETON_H
#define MAGIC_SINGLETON_H

#include <mutex>
#include <memory>

template <typename T>
class Magic_Singleton
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
    explicit Magic_Singleton();
    Magic_Singleton(const Magic_Singleton &) = delete;
    Magic_Singleton &operator=(const Magic_Singleton &) = delete;
    ~Magic_Singleton();

private:
    static std::shared_ptr<T> m_instance;
    static std::mutex m_mutex;
};

template <typename T>
std::shared_ptr<T> Magic_Singleton<T>::m_instance = nullptr;

template <typename T>
std::mutex Magic_Singleton<T>::m_mutex;
#endif
