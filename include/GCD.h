#ifndef GCD_H
#define GCD_H

inline int __gcd(int a , int b) {
   if(b == 0) return a;
   a %= b;
   return __gcd(b,a);
}

#endif // GCD_H
