#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstring>

namespace Utils {
    
    #define getSize(arr) (sizeof(arr)/sizeof((arr)[0]))
    
    template<typename T>
    class ArrayList {
    private:
        size_t m_Size;
        T* m_Array = nullptr;
        
        void init() {
            m_Size = 0;
            m_Array = new T[m_Size];
        }
    public:
        void resize(size_t newSize) {
            int* newArr = new int[newSize];
        
            memcpy(newArr, m_Array, m_Size * sizeof(T));
        
            m_Size = newSize;
            delete [] m_Array;
            m_Array = newArr;
        }
        
        size_t size() {
            return m_Size + 1;
        }
        
        void add_back(const T& element) {
            if(m_Array == nullptr) {
                init();
                m_Array[0] = element;
                return;
            }
            
            m_Size++;
            resize(m_Size);
            m_Array[m_Size] = element;
        }
        
        void add_front(const T& element) {
            if(m_Array == nullptr) {
                init();
                m_Array[0] = element;
                return;
        }
            
            m_Size++;
            resize(m_Size);
            for(int i = size(); i > 0; i--) {
                m_Array[i] = m_Array[i - 1];
            }
            m_Array[0] = element;
        }
        
        void for_each(void (*callback)(T&)) {
            for(int i = 0; i < size(); i++) {
                callback(m_Array[i]);
            }
        }
        
        T& operator[](int index) {
            return m_Array[index];
        }
        
        ArrayList() {}
        ArrayList(const ArrayList& other) {
            resize(other.size());
            for(int i = 0; i < other.size(); i++) {
                m_Array[i] = other.m_Array[i];
            }
        }
    };
    
}

#endif
