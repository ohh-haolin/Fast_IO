#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <type_traits>

namespace {
    using namespace std;

    template<size_t _s = 1ll << 23>
    struct Fast_In
    {
        #define _force_inline __attribute__((always_inline))
        #warning Fast_In will take control of the file. Use it on your own!!!
        FILE* _file;
        const size_t _size ;
        char *_buf, *p1, *p2;

        Fast_In(FILE* _f = stdin) : _file(_f), _size(_s)
        {  
            _buf = new char[_size + 1];
            p1 = p2 = _buf;
        }

        ~Fast_In()
        {
            delete[] _buf;
            fclose(_file);
        }

        _force_inline char getc() 
        {
            return p1 == p2 
                && ( p2 = (p1=_buf) + fread(_buf , 1, _size, _file), 
                    p1 == p2 ) 
                ? EOF : *p1++;
        }
        
        _force_inline void _fast_read_char(char& x)
        {
            char ch = getc();
            while(!isalnum(ch)) {
                ch = getc();
            }
            x = ch;
        }

        _force_inline void _fast_read_cstring(char* x)
        {
            char ch = getc();
            while(!isalnum(ch)) {
                ch = getc();
            }
            while(isalnum(ch)) {
                *(x++) = ch;
                ch = getc();
            }      
        }

        template<typename T>
        _force_inline void _fast_read_integer(T& x)
        {
            x = 0; int f = 0; char ch = getc();
            while(!isdigit(ch)) {
                if(ch=='-') f = 1;
                ch = getc();
            }
            while(isdigit(ch)) {
                x = (x<<3) + (x<<1) + (ch - 48);
                ch = getc();
            }
            x = f ? -x : x;
        }

        _force_inline Fast_In& operator>>(char& x)
        {
            _fast_read_char(x);
            return *this;
        } 

        _force_inline Fast_In& operator>>(char* x)
        {
            _fast_read_cstring(x);
            return *this;
        } 

        template<typename T>
        _force_inline Fast_In& operator>>(T& x)
        {
            static_assert(is_integral_v<T>, "Fast_IO only supports Integer");
            _fast_read_integer(x);
            return *this;
        }
    };

    template<size_t _s = 1ll << 23>
    struct Fast_Out
    {
        #define _force_inline __attribute__((always_inline))
        #warning Fast_Out will take control of the file. Use it on your own!!!
        FILE* _file;
        const size_t _size;
        char *_buf, *_int_buf;
        size_t p, ip;

        Fast_Out(FILE* _f = stdout) : _file(_f), _size(_s), p(0), ip(0)
        {  
            _buf = new char[_size + 64];
            _int_buf = new char[64];
        }

        ~Fast_Out()
        {
            flush();
            delete[] _buf;
            delete[] _int_buf;
            fclose(_file);
        }

        _force_inline void flush() 
        {
            fwrite(_buf, 1, p, _file); 
            p = 0;
        }

        _force_inline void _fast_print_char(const char& x)
        {
            if (p >= (1<<20)) flush();
            _buf[p++] = x;
        }

        _force_inline void _fast_print_cstring(const char *x)
        {
            size_t _s_size = strlen(x);
            if(_s_size > _size) puts("Error: Buffer size is not enough!!!"), 
                                exit(1);
            if ((p + _s_size) >= (1<<20)) flush();
            while(*x != '\0') {
                _buf[p++] = *(x++);
            }
        }

        template<typename T>
        _force_inline void _fast_print_integer(T x) 
        {
            if (p >= (1<<20)) flush();
            if(x < 0) _buf[p++] = 45, x = -x;
            do {
                _int_buf[ip++] = x % 10 + 48;
            }while(x /= 10);
            do {
                _buf[p++] = _int_buf[--ip];
            }while(ip);
        }

        _force_inline Fast_Out& operator<<(const char& x)
        {
            _fast_print_char(x);
            return *this;
        } 

        _force_inline Fast_Out& operator<<(const char* x)
        {
            _fast_print_cstring(x);
            return *this;
        } 

        template<typename T>
        _force_inline Fast_Out& operator<<(const T& x)
        {
            static_assert(is_integral_v<T>, "Fast_IO only supports Integer");
            _fast_print_integer(x);
            return *this;
        }
    };
}


int main()
{  
    return 0;
}