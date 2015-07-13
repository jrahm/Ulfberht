#ifndef INCLUDE_PRELUDE_
#define INCLUDE_PRELUDE_

/*
 * Author: jrahm
 * created: 2015/05/22
 * Prelude.hpp: <description>
 */

#include <cstdlib>

typedef   signed char      s8_t;
typedef unsigned char      u8_t;

typedef   signed short int s16_t;
typedef unsigned short int u16_t;

typedef   signed int s32_t;
typedef unsigned int u32_t;

typedef   signed long long s62_t;
typedef unsigned long long u64_t;

typedef unsigned long long llu_t;
typedef unsigned long lu_t;
typedef   signed long l_t;
typedef   signed long long ll_t;

typedef double f64_t;
typedef float  f32_t;

typedef long double lf_t;

typedef u8_t byte;

/* TODO port to Windows. */
typedef int raw_handle_t;


#define ABSTRACT
#define OVERRIDE override

/**
 * @brief A simple class that acts like a pointer, but deletes itself after going out of scope
 *
 * This is very similar to the unique pointer definition from C++ 11,
 * but the support for C++ 11 on these different platforms is shotty at best
 */
template <class T>
class uptr { /* unique pointer definition from C++ 11 */
public:
    template <class U>
    uptr(U* val) {
        mine = val;
        nref = new int(1);
    }


    uptr() {
        mine = NULL;
        nref = NULL;
    }

    uptr(const uptr<T>& oth) {
        mine = oth.mine;
        nref = oth.nref;
        if(nref) (*nref) ++;
    }

    void operator=( const uptr<T>& oth ) {
        unref();
        mine = oth.mine;
        nref = oth.nref;
        if(nref) (*nref) ++;
    }

    bool operator==(T* oth) {
        return mine == oth;
    }

    void unref() {
        if(nref) {
            (*nref) --;
            if( *nref == 0 ) {
                delete mine;
                delete nref;
            }
        }
    }

    void operator=( T* oth ) {
        unref();
        nref = new int(1);
        mine = oth;
    }

    T& operator *() {
        return *mine;
    };

    T* operator ->() {
        return get();
    }

    const T* operator ->() const {
        return mine;
    }

    T*& get() {
        return mine;
    }

    const T*& get() const {
        return mine;
    }

    T*& cleanref() {
        delete mine;
        mine = NULL;
        return mine;
    }

    /* Free the pointer from this structure */
    T* save() {
        T* ret = mine;
        mine = NULL;
        return ret;
    }

    ~uptr() {
        unref();
    }

    bool isNull() const { return mine == NULL; }
private:
    T* mine;
    int* nref;
};

#endif /* INCLUDE_PRELUDE_ */
